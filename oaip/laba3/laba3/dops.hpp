
using namespace std;
#include <string>
#include <sstream>
using namespace std;

// ������� ��� �������� ������� � �����
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

// ������� ��� ����������� ������ ����� � ���������� ����������� �������
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
            maxVowelWordIndex = currentIndex + 1; // � ������ 1-����������
        }
        currentIndex++;
    }
    return maxVowelWordIndex;
}

int variant13number1() {
    ifstream inputFile("FILE1.txt");
    ofstream outputFile("FILE2.txt");
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "�� ������� ������� �����." << endl;
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
            outputFile << line << " (����� � ���������� ����������� ������� - " << maxVowelWordIndex << ")\n";
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

#include <unordered_map>

int variant13number2() {
    setlocale(LC_ALL, "rus");
    // ���� ������ � ����������
    cout << "������� ������ ��������, ��������� �� ���� � ������: ";
    string inputString;
    getline(cin, inputString);

    // ������ ������ � ����
    ofstream outputFile("input.txt");
    if (!outputFile.is_open()) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
        return 1;
    }
    outputFile << inputString;
    outputFile.close();

    // ������ ������ �� ����� � ������� ���������� ��������� ������
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
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

    // ����� ���������� ������ ���������� ����
    cout << "���������� ��������� ������:\n";
    for (const auto& pair : bracketCounts) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }

    return 0;
}


// ������� ��� ��������, �������� �� ������ ������� ������
bool isVowel(char* symb) {
    char s = *symb;
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
        return true;
    else
        return false;
}

// ������� ��� ���������� ����� �� ������ �����, ������ �� � ������ ���� � �������� ���������� ������� ����
int variant3number1() {
    ifstream file1("FILE1.txt"); // �������� ����� ��� ������
    ofstream file2("FILE2.txt"); // �������� ����� ��� ������
    int k;
    char str[1000];

    cout << "������� k �� 1 �� 6: ";
    cin >> k;

    if (k > 6) {
        cout << "�� ����� ������������ ��������! ";
        return 1;
    }

    int k2 = k + 3;
    int count = 1;

    while (file1.getline(str, 1000)) { // ������ ����� �� ����� file1
        if (count >= k && count <= k2) { // ��������, ��������� �� ������� ������ � �������� ��������� k-k2
            file2 << str << "\n"; // ������ ������ � ���� file2
        }
        count++;
    }

    file1.close(); // �������� ����� file1
    file2.close(); // �������� ����� file2

    ifstream file3("FILE2.txt"); // �������� ����� ��� ������

    count = 0;

    while (file3.getline(str, 1000)) { // ������ ����� �� ����� file3
        for (int i = 0; str[i] != '\0'; i++) { // ������� �������� � ������
            if (isVowel(&str[i])) { // ��������, �������� �� ������� ������ ������� ������
                count++; // ���������� �������� ������� ����
            }
        }
    }

    file3.close(); // �������� ����� file3

    cout << "���������� �������: " << count;

    return 0;
}

int variant3number2()
{
    setlocale(LC_ALL, "ru");
    ofstream file1("FILE1.txt");
    ofstream file2("FILE2.txt");
    cout << "������� ������: ";
    char str[1000];
    gets_s(str);
    if (file1.is_open())
    {
        file1 << str;
        file1.close();
    }
    else
    {
        cout << "�� ������� ������� ���� ��� ������.";
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
    cout << "���������� ��������: " << count;
    file3.close();
    return 0;
}



int variant11number2() {
    setlocale(LC_ALL, "rus");

    char str1[500], str2[500];
    cout << "������� ������ ������: ";
    gets_s(str1); // ���� ������ ������

    cout << endl << "������� ������ ������: ";
    gets_s(str2); // ���� ������ ������

    ofstream file1("FILE1.txt");

    if (file1.is_open()) {
        file1 << str1 << '\n' << str2; // ���������� ������ � ����
        file1.close();
    }
    else {
        cout << "�� ������� ������� ���� ��� ������.";
        return 1;
    }

    ifstream file2("FILE1.txt");
    char str[1000];

    file2.getline(str, 500); // ������ ������ ������ �� �����

    int size = strlen(str);
    char word[100];
    int minlen = INT_MAX, buflen = 0, k = 0;

    // ����� ����������� ����� � ������ ������
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
    cout << "���������� ����� � ������ ������: " << word << endl;

    file2.getline(str, 1000); // ������ ������ ������ �� �����

    k = 0, buflen = 0;
    int maxlen = INT_MIN;

    // ����� ����������� ����� �� ������ ������
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
    cout << "���������� ����� �� ������ ������: " << word << endl;

    file2.close();
    return 0;
}