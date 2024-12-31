#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
struct person {            
    string lastname;       
    string firstname;      
    string patronimic;     
    int tel; 
};

int currentsize = 0; 



class Hashtable { 
private:
    vector<vector<person>> table; 

public:
    Hashtable() { 
        table.resize(currentsize);
    }

    int hashfunc(int phoneNumber) { 
        int sum = 0;
        while (phoneNumber) {
            sum += (phoneNumber % 100);
            phoneNumber /= 100;
        }
        return sum % currentsize;
    }

    void add(person pers) { 
        int index = hashfunc(pers.tel);
        table[index].push_back(pers);
    }

    void del(int te) { 
        int index = hashfunc(te);
        if (table[index].empty()) {
            cout << "Такого человека нет в списке\n";
        }
        else {
            bool t = false;
            for (int i = 0; i < table[index].size(); i++) {
                if (te == table[index][i].tel) {
                    table[index].erase(table[index].begin() + i);
                    t = true;
                    break;
                }
            }
            if (!t) {
                cout << "Такого человека нет в списке\n";
            }
        }
    }

    void search(int te) { 
        int index = hashfunc(te);
        if (table[index].empty()) {
            cout << "Такого человека нет в списке\n";
        }
        else {
            bool t = false;
            for (int i = 0; i < table[index].size(); i++) {
                if (te == table[index][i].tel) {
                    cout << "Ожидайте...\n" << "Элемент находится в ячейке с индексом " << index << " на " << i + 1 << " месте\n";
                    t = true;
                    break;
                }
            }
            if (!t) {
                cout << "Такого человека нет в списке\n";
            }
        }
    }

    void output() { 
        for (int i = 0; i < table.size(); i++) {
            cout << "Ячейка с индексом " << i << '\n';
            if (table[i].empty()) {
                cout << "Пусто\n";
                cout << '\n';
            }
            else {
                for (int j = 0; j < table[i].size(); j++) {
                    cout << "Фамилия: " << table[i][j].lastname << '\n';
                    cout << "Имя: " << table[i][j].firstname << '\n';
                    cout << "Отчество: " << table[i][j].patronimic << '\n';
                    cout << "Телефон: " << table[i][j].tel << '\n';
                    cout << '\n';
                }
            }
        }
    }

};



int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    string b;
    cout << "Введите размер таблицы\n";
    getline(cin, b);
    currentsize = stoi(b);
    Hashtable table;
    for (;;)
    {
        cout << "1 - Вывод хеш-таблицы\n";
        cout << "2 - Добавить элемент\n";
        cout << "3 - Удалить элемент\n";
        cout << "4 - Найти элемент по ключу\n";
        cout << "0 - Выход\n";
        cout << "Ваш выбор:\n";
        getline(cin, b);
        while (b.length() != 1) {
            cout << "Некорректный ввод\n";
            getline(cin, b);
        }
        choice = b[0];
        switch (choice)
        {
        case '0':  exit(0);
        case '1': {
            table.output();
            break;
        }
        case '2': {
            person buf;
            cout << "введите Фамилию\n";
            getline(cin, b);          
            buf.lastname = b;
            cout << "введите имя\n";
            getline(cin, b);     
            buf.firstname = b;
            cout << "введите отчество\n";
            getline(cin, b);           
            buf.patronimic = b;
            cout << "введите номер телефона\n";
            getline(cin, b);
            buf.tel = stoi(b);
            table.add(buf);
            break;
        }
        case '3': {
            cout << "введите номер телефона\n";
            getline(cin, b);
            table.del(stoi(b));
            break;
        }
        case '4': {
            cout << "введите номер телефона\n";
            getline(cin, b);
            auto start = chrono::high_resolution_clock::now();
            table.search(stoi(b));
            auto end = chrono::high_resolution_clock::now();
            auto time = chrono::duration_cast<std::chrono::microseconds>(end - start);
            cout << "Время поиска " << time.count() << "e-6 c\n";
            break;
        }
        default:  cout << "\nВведена неверная команда!\n";
        }
    }
    return 0;
}
