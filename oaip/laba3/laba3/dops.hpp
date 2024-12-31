
using namespace std;
#include <string>
#include <sstream>
using namespace std;

// Функция для подсчета гласных в слове
int countVowels(const string& word) {
    int count = 0;
    string vowels = "aeiouAEIOU";
    for (char c : word) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

// Функция для определения номера слова с наибольшим количеством гласных
int findMaxVowelWord(const string& line) {
    istringstream iss(line);
    string word;
    int maxVowelCount = 0;
    int maxVowelWordIndex = -1;
    int currentIndex = 0;
    while (iss >> word) {
        int vowelCount = countVowels(word);
        if (vowelCount > maxVowelCount) {
            maxVowelCount = vowelCount;
            maxVowelWordIndex = currentIndex + 1; // С учетом 1-индексации
        }
        currentIndex++;
    }
    return maxVowelWordIndex;
}

int variant13number1() {
    ifstream inputFile("FILE1.txt");
    ofstream outputFile("FILE2.txt");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Не удалось открыть файлы." << endl;
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        int wordCount = 0;
        while (iss >> word) {
            wordCount++;
        }
        if (wordCount > 2) {
            int maxVowelWordIndex = findMaxVowelWord(line);
            outputFile << line << " (Слово с наибольшим количеством гласных - " << maxVowelWordIndex << ")\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

#include <unordered_map>

int variant13number2() {
    setlocale(LC_ALL, "rus");
    // Ввод строки с клавиатуры
    cout << "Введите строку символов, состоящую из цифр и скобок: ";
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

    // Чтение данных из файла и подсчет количества различных скобок
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл для чтения." << endl;
        return 1;
    }

    unordered_map<char, int> bracketCounts;
    char c;
    while (inputFile.get(c)) {
        if (c == '('  ||c == ')'  ||c == '['  ||c == ']' || c == '{' || c == '}') {
            bracketCounts[c]++;
        }
    }

    inputFile.close();

    // Вывод количества скобок различного вида
    cout << "Количество различных скобок:\n";
    for (const auto& pair : bracketCounts) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }

    return 0;
}


// Функция для проверки, является ли символ гласной буквой
bool isVowel(char* symb) {
    char s = *symb;
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        return true;
    else
        return false;
}

// Функция для извлечения строк из одного файла, записи их в другой файл и подсчета количества гласных букв
int variant3number1() {
    ifstream file1("FILE1.txt"); // Открытие файла для чтения
    ofstream file2("FILE2.txt"); // Открытие файла для записи
    int k;
    char str[1000];

    cout << "Введите k от 1 до 6: ";
    cin >> k;

    if (k > 6) {
        cout << "Вы ввели неправильное значение! ";
        return 1;
    }

    int k2 = k + 3;
    int count = 1;

    while (file1.getline(str, 1000)) { // Чтение строк из файла file1
        if (count >= k && count <= k2) { // Проверка, находится ли текущая строка в заданном диапазоне k-k2
            file2 << str << "\n"; // Запись строки в файл file2
        }
        count++;
    }

    file1.close(); // Закрытие файла file1
    file2.close(); // Закрытие файла file2

    ifstream file3("FILE2.txt"); // Открытие файла для чтения

    count = 0;

    while (file3.getline(str, 1000)) { // Чтение строк из файла file3
        for (int i = 0; str[i] != '\0'; i++) { // Перебор символов в строке
            if (isVowel(&str[i])) { // Проверка, является ли текущий символ гласной буквой
                count++; // Увеличение счетчика гласных букв
            }
        }
    }

    file3.close(); // Закрытие файла file3

    cout << "Количество гласных: " << count;

    return 0;
}

int variant3number2()
{
    setlocale(LC_ALL, "ru");
    ofstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    cout << "Введите строку: ";
    char str[1000];
    gets_s(str);
    if (file1.is_open())
    {
        file1 << str;
        file1.close();
    }
    else
    {
        cout << "Не удалось открыть файл для записи.";
        return 1;
    }
    ifstream file3("FILE1.txt");
    char word[100];
    while (file3 >> word)
    {
        int i = 0;
        if (!(word[i] >= '0' && word[i] <= '9'))
        {
            file2 << word << '\n';
            cout << word << " ";
        }
    }


    file2.close();
    file3.close();
    return 0;
}

int variant11number1()
{
    ifstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    char str[1000];
    while (file1.getline(str, 1000))
    {
        int count = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == ' ')
            {
                count++;
            }
        }
        if (count == 0)
        {
            file2 << str << '\n';
        }
    }
    file1.close();
    file2.close();
    ifstream file3("FILE2.txt");
    int count = 0;
    while (file3.getline(str, 1000))
    {
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] != '\0')
            {
                count++;
            }
        }
    }
    cout << "Количество символов: " << count;
    file3.close();
    return 0;
}



int variant11number2() {
    setlocale(LC_ALL, "rus");

    char str1[500], str2[500];
    cout << "Введите первую строку: ";
    gets_s(str1); // Ввод первой строки

    cout << endl << "Введите вторую строку: ";
    gets_s(str2); // Ввод второй строки

    ofstream file1("FILE1.txt");

    if (file1.is_open()) {
        file1 << str1 << '\n' << str2; // Записываем строки в файл
        file1.close();
    }
    else {
        cout << "Не удалось открыть файл для записи.";
        return 1;
    }

    ifstream file2("FILE1.txt");
    char str[1000];

    file2.getline(str, 500); // Читаем первую строку из файла

    int size = strlen(str);
    char word[100];
    int minlen = INT_MAX, buflen = 0, k = 0;

    // Поиск наименьшего слова в первой строке
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            if (buflen < minlen) {
                minlen = buflen;
                for (int j = 0; j < buflen; j++) {
                    word[j] = str[k + j];
                }
                word[buflen] = '\0';
            }
            buflen = 0;
            k = i + 1;
        }
        else {
            buflen++;
        }
    }
    cout << "Наименьшее слово в первой строке: " << word << endl;

    file2.getline(str, 1000); // Читаем вторую строку из файла

    k = 0, buflen = 0;
    int maxlen = INT_MIN;

    // Поиск наибольшего слова во второй строке
    for (int i = 0; i < size; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            if (buflen > maxlen) {
                maxlen = buflen;
                for (int j = 0; j < buflen; j++) {
                    word[j] = str[k + j];
                }
                word[buflen] = '\0';
            }
            buflen = 0;
            k = i + 1;
        }
        else {
            buflen++;
        }
    }
    cout << "Наибольшее слово во второй строке: " << word << endl;

    file2.close();
    return 0;
}