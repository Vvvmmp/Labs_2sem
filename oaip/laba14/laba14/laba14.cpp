#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct KeyValuePair {
    int key;
    // Дополнительные данные, связанные с ключом
};

class HashTable {
private:
    std::vector<std::vector<KeyValuePair>> table;
    int size;

public:
    HashTable(int size) : size(size) {
        table.resize(size);
    }

    // Хеш-функция для вычисления индекса
    int hash(int key) {
        return key % size;
    }

    // Вставка элемента в хеш-таблицу
    void insert(int key) {
        int index = hash(key);
        for (auto& entry : table[index]) {
            if (entry.key == key) {
                // Ключ уже существует, выполните необходимые действия
                return;
            }
        }
        table[index].push_back({ key });
    }

    // Поиск элемента в хеш-таблице
    // Поиск элемента в хеш-таблице
    int search(int key) {
        int comparisons = 0;
        for (const auto& bucket : table) {
            for (const auto& entry : bucket) {
                comparisons++;
                if (entry.key == key) {
                    // Ключ найден, выполните необходимые действия
                    return comparisons; // Возвращаем количество сравнений
                }
            }
        }
        return comparisons; // Ключ не найден
    }
};

int main() {
    setlocale(0, "");
    std::ifstream file("file.txt");
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    // Создание хеш-таблицы
    HashTable hashtable(100); // Укажите желаемый размер таблицы

    // Чтение чисел из файла и добавление их в хеш-таблицу
    int num;
    while (file >> num) {
        hashtable.insert(num);
    }

    // Поиск числа в хеш-таблице
    int searchNum;
    std::cout << "Введите целое число для поиска: ";
    std::cin >> searchNum;

    int comparisons = hashtable.search(searchNum);
    if (comparisons != 0) {
        std::cout << "Число найдено." << std::endl;
        std::cout << "Количество сравнений: " << comparisons << std::endl;
    }
    else {
        std::cout << "Число не найдено." << std::endl;
    }

    file.close();
    return 0;
}

