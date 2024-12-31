#include <string>
using namespace std;

int variant6number1()
{
    int N, K;
    int counter = 0;
    char buffer[255];

    ifstream inputFile("FILE1.txt");
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл A.txt" << endl;
        return 0;
    }
    cout << "Введите N: "<< endl;
    cin >> N;
    cout << "Введите k: "<< endl;
    cin >> K;

    int i=0;
    
    ofstream outputFile("FILE2.txt");
    while (inputFile.getline(buffer, 255))
    {
        if (i >= N && i <= K)
        {
            outputFile << buffer << "\n";
            for (int j = 0; j < strlen(buffer); j++)
            {
                if (buffer[j] != 'a' && buffer[j] != ' ' && buffer[j] != 'A' && buffer[j] != 'e' && buffer[j] != 'E' && buffer[j] != 'i' && buffer[j] != 'I' && buffer[j] != 'o' && buffer[j] != 'O' && buffer[j] != 'u' && buffer[j] != 'U')
                {
                    counter++;
                }
            }
        }
        i++;
    }
    inputFile.close();
    outputFile.close();
    
    cout << "Всего согласных: " << counter;
    return 0;
}

int variant6number2()
{
    // Ввод строки с клавиатуры
    cout << "Введите строку символов, состоящую из групп цифр и нулей: ";
    string inputString;
    getline(cin, inputString);

    // Запись строки в файл
    ofstream outputFile("input.txt");
    if (!outputFile.is_open()) {
        cerr << "Не удалось открыть файл для записи." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // Чтение данных из файла и вывод групп с четным количеством символов
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return 1;
    }

    string line;
    while (inputFile >> line) {
        if (line.size() % 2 == 0) {
            cout << line << endl;
        }
    }

    inputFile.close();

    return 0; 
}