#include <string>
using namespace std;

int variant6number1()
{
    int N, K;
    int counter = 0;
    char buffer[255];

    ifstream inputFile("FILE1.txt");
    if (!inputFile.is_open()) {
        cout << "�� ������� ������� ���� A.txt" << endl;
        return 0;
    }
    cout << "������� N: "<< endl;
    cin >> N;
    cout << "������� k: "<< endl;
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
    
    cout << "����� ���������: " << counter;
    return 0;
}

int variant6number2()
{
    // ���� ������ � ����������
    cout << "������� ������ ��������, ��������� �� ����� ���� � �����: ";
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

    // ������ ������ �� ����� � ����� ����� � ������ ����������� ��������
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� ���� ��� ������." << endl;
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