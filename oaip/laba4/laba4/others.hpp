#include <iostream>
#include <string>
#include <Windows.h>
#define MAX_STUDENTS 30
#define MAX_EXAMS 6

using namespace std;

void inputStudents();
void outputStudents();
void checkSuccess();
void calculateSuccessRate();

int choice = 0;
int currentStudent = 0;

struct Student
{
    string name; // ������� ��������
    int numExams; // ���������� ���������
    int marks[MAX_EXAMS]; // ������ �� ��������
};

Student listOfStudents[MAX_STUDENTS];

int dop1()
{
    do
    {
        cout << "1 - ���� ��������� ��������� � ����������" << endl;
        cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
        cout << "3 - �������� �� ����������" << endl;
        cout << "4 - �������������� ������������" << endl;
        cout << "5 - ����� �� ���������" << endl;
        cin >> choice; // ��������� ����� ������������

        switch (choice)
        {
        case 1:
            inputStudents(); // �������� ������� ��� ����� ������ � ���������
            break;
        case 2:
            outputStudents(); // �������� ������� ��� ������ ������ � ���������
            break;
        case 3:
            checkSuccess(); // �������� ������� ��� �������� ���������� ��������
            break;
        case 4:
            calculateSuccessRate(); // �������� ������� ��� ������� �������� �������� ���������
            break;
        }
    } while (choice != 5); // ��������� ����, ���� ������������ �� ������� �����

    return 0;
}

void inputStudents()
{
    int numStudents;
    cout << "������� ���������� ���������: ";
    cin >> numStudents; // ��������� ���������� ���������

    for (int i = 0; i < numStudents; i++)
    {
        if (currentStudent < MAX_STUDENTS)
        {
            cin.ignore();
            cout << endl << "������� ��������: ";
            getline(cin, listOfStudents[currentStudent].name); // ��������� ������� ��������
            cout << "���������� ���������: ";
            cin >> listOfStudents[currentStudent].numExams; // ��������� ���������� ���������
            cout << "������: " << endl;
            for (int j = 0; j < listOfStudents[currentStudent].numExams; j++)
            {
                cout << "������� ������ �� " << j + 1 << " �������: ";
                cin >> listOfStudents[currentStudent].marks[j]; // ��������� ������ �� ������ �������
                cout << endl;
            }
            currentStudent++;
        }
    }
}

void outputStudents()
{
    for (int i = 0; i < currentStudent; i++)
    {
        cout << endl << "������� ��������: " << listOfStudents[i].name << endl; // ������� ������� ��������
        cout << "���������� ���������: " << listOfStudents[i].numExams << endl; // ������� ���������� ���������
        cout << "������: " << endl;
        for (int j = 0; j < listOfStudents[i].numExams; j++)
        {
            cout << "������ �� " << j + 1 << " �������: " << listOfStudents[i].marks[j] << endl; // ������� ������ �� ������ �������
        }
    }
}

void checkSuccess()
{
    int count = 0;
    bool found = false;
    string surname;
    cout << "������� ������� ��������: ";
    cin.ignore();
    getline(cin, surname);

    for (int i = 0; i < currentStudent; i++)
    {
        if (listOfStudents[i].name == surname)
        {
            for (int j = 0; j < listOfStudents[i].numExams; j++)
            {
                if (listOfStudents[i].marks[j] >= 4)
                {
                    count++;
                }
            }

            if (count == listOfStudents[i].numExams)
            {
                cout << endl << "������� ���� ��� �������� �� 4 ��� ����." << endl;
            }
            else
            {
                cout << endl << "������� �� ���� ��� �������� �� 4 ��� ����." << endl;
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "�������� � ����� �������� �� �������!" << endl;
    }
}

void calculateSuccessRate()
{
    int successfulStudents = 0;
    string surname;
    cout << "������� ������� ��������: ";
    cin.ignore();
    getline(cin, surname); // ��������� ������� ��������

    for (int i = 0; i < currentStudent; i++)
    {
        if (listOfStudents[i].name == surname) // ���������, ���� �� ������� � ��������� ��������
        {
            int count = 0;
            for (int j = 0; j < listOfStudents[i].numExams; j++)
            {
                if (listOfStudents[i].marks[j] >= 4) // ��������� ������ �� ������ �������
                {
                    count++;
                }
            }
            if (count == listOfStudents[i].numExams) // ���������, ��� �� ������ ���� 4
            {
                successfulStudents++;
            }
        }
    }

    cout << "���������� �������� ���������: " << successfulStudents << endl;
}


#define MAX_TRAINS 10



struct Train
{
    string destination; // ����� ����������
    int number; // ����� ������
    int departureTime; // ����� �����������
};

Train listOfTrains[MAX_TRAINS];

void inputTrain();
void outputTrain();
void checkTrain();

int currentTrains = 0;

int dop2()
{
    do
    {
        cout << "1 - ���� ��������� ��������� � ����������" << endl;
        cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
        cout << "3 - �������� �� �����" << endl;
        cout << "0 - ����� �� ���������" << endl;
        cin >> choice; // ��������� ����� ������������

        switch (choice)
        {
        case 1:
            inputTrain();
            break;
        case 2:
            outputStudents();
            break;
        case 3:
            checkTrain();
            break;

        }
    } while (choice != 0);



    return 0;
}

void inputTrain()
{
    int numTrains;
    cout << "������� ���������� �������: ";
    cin >> numTrains; // ��������� ���������� �������

    cin.ignore(); // ���������� ������ ����� ������ ����� ����� �����

    for (int i = 0; i < numTrains; i++)
    {
        if (currentTrains < MAX_TRAINS)
        {
            cout << endl << "����� ����������: ";
            getline(cin, listOfTrains[currentTrains].destination);

            cout << "����� ������: ";
            cin >> listOfTrains[currentTrains].number;

            cout << "����� �����������: ";
            cin >> listOfTrains[currentTrains].departureTime;

            cout << endl;

            cin.ignore(); // ���������� ������ ����� ������ ����� ����� �������

            currentTrains++;
        }
    }
}

void outputTrain()
{
    for (int i = 0; i < currentTrains; i++)
    {
        cout << endl << "����� ����������: " << listOfTrains[i].destination << endl;
        cout << "����� ������: " << listOfTrains[i].number << endl;
        cout << "����� �����������: " << listOfTrains[i].departureTime << "�." << endl;
    }
}

void checkTrain()
{
    int departureTime;
    cout << "\n������� ������� �����: ";
    cin >> departureTime;

    bool foundTrain = false;

    for (int i = 0; i < currentTrains; i++)
    {
        if (departureTime <= listOfTrains[i].departureTime)
        {
            foundTrain = true;
            cout << endl << "����� ����������: " << listOfTrains[i].destination << endl;
            cout << "����� ������: " << listOfTrains[i].number << endl;
            cout << "����� �����������: " << listOfTrains[i].departureTime << "�." << endl;
        }
    }

    if (!foundTrain)
    {
        cout << "\n��� ���������� �������.";
    }
}



#define MAX_SANATORIUMS 10

struct Sanatorium
{
    string name;
    string location;
    string direction; //�����������
    string amountPermit;
};

Sanatorium listOfSanatorium[MAX_SANATORIUMS];

void inputSanatorium();
void outputSanatorium();
void foundSanatorium();

int currentSanatorium = 0;

int dop3()
{
    do
    {
        cout << "1 - ���� ��������� ��������� � ����������" << endl;
        cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
        cout << "3 - ����� �� ��������" << endl;
        cout << "0 - ����� �� ���������" << endl;
        cin >> choice; // ��������� ����� ������������

        switch (choice)
        {
        case 1:
            inputSanatorium();
            break;
        case 2:
            outputSanatorium();
            break;
        case 3:
            foundSanatorium();
            break;

        }
    } while (choice != 0);



    return 0;
}

void inputSanatorium()
{
    int numSanatorium;
    cout << "������� ���������� ����������: ";
    cin >> numSanatorium; // ��������� ���������� ����������

    cin.ignore(); // ���������� ������ ����� ������ ����� ����� �����

    for (int i = 0; i < numSanatorium; i++)
    {
        if (currentSanatorium < MAX_SANATORIUMS)
        {
            cout << "\n�������� ���������: ";
            getline(cin, listOfSanatorium[currentSanatorium].name);

            cout << "\n����� ������������: ";
            getline(cin, listOfSanatorium[currentSanatorium].location);

            cout << "\n�������� �������: ";
            getline(cin, listOfSanatorium[currentSanatorium].direction);

            cout << "\n���-�� ������: ";
            cin >> listOfSanatorium[currentSanatorium].amountPermit;

            cout << endl;

            cin.ignore(); // ���������� ������ ����� ������ ����� ����� �������

            currentSanatorium++;
        }
    }
}

void outputSanatorium()
{
    int choice;
    for (int i = 0; i < currentSanatorium; i++)
    {
        cout << "\n�������� ���������: " << listOfSanatorium[i].name;
        cout << "\n����� ������������: " << listOfSanatorium[i].location;
        cout << "\n�������� �������: " << listOfSanatorium[i].direction;
        cout << "\n���-�� ������: " << listOfSanatorium[i].amountPermit;

        cout << endl;

    }
        cin.ignore();
}

void foundSanatorium()
{
    string name;
    cout << "\n������� �������� ���������: ";
    cin >> name;

    bool foundSanatorium = false;

    for (int i = 0; i < currentSanatorium; i++)
    {
        if (listOfSanatorium[i].name == name)
        {
            foundSanatorium = true;
            cout << "\n�������� ���������: " << listOfSanatorium[i].name;
            cout << "\n����� ������������: " << listOfSanatorium[i].location;
            cout << "\n�������� �������: " << listOfSanatorium[i].direction;
            cout << "\n���-�� ������: " << listOfSanatorium[i].amountPermit;
            cout << endl;
        }
    }

    if (!foundSanatorium)
    {
        cout << "\n��� ���������� � ��������� ���������." << endl;
    }
}