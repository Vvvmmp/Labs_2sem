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
    string name; // Фамилия студента
    int numExams; // Количество экзаменов
    int marks[MAX_EXAMS]; // Оценки за экзамены
};

Student listOfStudents[MAX_STUDENTS];

int dop1()
{
    do
    {
        cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
        cout << "2 - Вывод элементов структуры в консольное окно" << endl;
        cout << "3 - Проверка на успешность" << endl;
        cout << "4 - Характеристика успеваемости" << endl;
        cout << "5 - Выход из программы" << endl;
        cin >> choice; // Считываем выбор пользователя

        switch (choice)
        {
        case 1:
            inputStudents(); // Вызываем функцию для ввода данных о студентах
            break;
        case 2:
            outputStudents(); // Вызываем функцию для вывода данных о студентах
            break;
        case 3:
            checkSuccess(); // Вызываем функцию для проверки успешности студента
            break;
        case 4:
            calculateSuccessRate(); // Вызываем функцию для расчета процента успешных студентов
            break;
        }
    } while (choice != 5); // Повторяем цикл, пока пользователь не выберет выход

    return 0;
}

void inputStudents()
{
    int numStudents;
    cout << "Введите количество студентов: ";
    cin >> numStudents; // Считываем количество студентов

    for (int i = 0; i < numStudents; i++)
    {
        if (currentStudent < MAX_STUDENTS)
        {
            cin.ignore();
            cout << endl << "Фамилия студента: ";
            getline(cin, listOfStudents[currentStudent].name); // Считываем фамилию студента
            cout << "Количество экзаменов: ";
            cin >> listOfStudents[currentStudent].numExams; // Считываем количество экзаменов
            cout << "Оценки: " << endl;
            for (int j = 0; j < listOfStudents[currentStudent].numExams; j++)
            {
                cout << "Введите оценку за " << j + 1 << " экзамен: ";
                cin >> listOfStudents[currentStudent].marks[j]; // Считываем оценку за каждый экзамен
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
        cout << endl << "Фамилия студента: " << listOfStudents[i].name << endl; // Выводим фамилию студента
        cout << "Количество экзаменов: " << listOfStudents[i].numExams << endl; // Выводим количество экзаменов
        cout << "Оценки: " << endl;
        for (int j = 0; j < listOfStudents[i].numExams; j++)
        {
            cout << "Оценка за " << j + 1 << " экзамен: " << listOfStudents[i].marks[j] << endl; // Выводим оценку за каждый экзамен
        }
    }
}

void checkSuccess()
{
    int count = 0;
    bool found = false;
    string surname;
    cout << "Введите фамилию студента: ";
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
                cout << endl << "Студент сдал все экзамены на 4 или выше." << endl;
            }
            else
            {
                cout << endl << "Студент не сдал все экзамены на 4 или выше." << endl;
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Студента с такой фамилией не найдено!" << endl;
    }
}

void calculateSuccessRate()
{
    int successfulStudents = 0;
    string surname;
    cout << "Введите фамилию студента: ";
    cin.ignore();
    getline(cin, surname); // Считываем фамилию студента

    for (int i = 0; i < currentStudent; i++)
    {
        if (listOfStudents[i].name == surname) // Проверяем, есть ли студент с введенной фамилией
        {
            int count = 0;
            for (int j = 0; j < listOfStudents[i].numExams; j++)
            {
                if (listOfStudents[i].marks[j] >= 4) // Проверяем оценку за каждый экзамен
                {
                    count++;
                }
            }
            if (count == listOfStudents[i].numExams) // Проверяем, все ли оценки выше 4
            {
                successfulStudents++;
            }
        }
    }

    cout << "Количество успешных студентов: " << successfulStudents << endl;
}


#define MAX_TRAINS 10



struct Train
{
    string destination; // пункт назначения
    int number; // номер поезда
    int departureTime; // время отправления
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
        cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
        cout << "2 - Вывод элементов структуры в консольное окно" << endl;
        cout << "3 - Проверка на время" << endl;
        cout << "0 - Выход из программы" << endl;
        cin >> choice; // Считываем выбор пользователя

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
    cout << "Введите количество поездов: ";
    cin >> numTrains; // Считываем количество поездов

    cin.ignore(); // Игнорируем символ новой строки после ввода числа

    for (int i = 0; i < numTrains; i++)
    {
        if (currentTrains < MAX_TRAINS)
        {
            cout << endl << "Пункт назначения: ";
            getline(cin, listOfTrains[currentTrains].destination);

            cout << "Номер поезда: ";
            cin >> listOfTrains[currentTrains].number;

            cout << "Время отправления: ";
            cin >> listOfTrains[currentTrains].departureTime;

            cout << endl;

            cin.ignore(); // Игнорируем символ новой строки после ввода времени

            currentTrains++;
        }
    }
}

void outputTrain()
{
    for (int i = 0; i < currentTrains; i++)
    {
        cout << endl << "Пункт назначения: " << listOfTrains[i].destination << endl;
        cout << "Номер поезда: " << listOfTrains[i].number << endl;
        cout << "Время отправления: " << listOfTrains[i].departureTime << "ч." << endl;
    }
}

void checkTrain()
{
    int departureTime;
    cout << "\nВведите текущее время: ";
    cin >> departureTime;

    bool foundTrain = false;

    for (int i = 0; i < currentTrains; i++)
    {
        if (departureTime <= listOfTrains[i].departureTime)
        {
            foundTrain = true;
            cout << endl << "Пункт назначения: " << listOfTrains[i].destination << endl;
            cout << "Номер поезда: " << listOfTrains[i].number << endl;
            cout << "Время отправления: " << listOfTrains[i].departureTime << "ч." << endl;
        }
    }

    if (!foundTrain)
    {
        cout << "\nНет подходящих поездов.";
    }
}



#define MAX_SANATORIUMS 10

struct Sanatorium
{
    string name;
    string location;
    string direction; //направление
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
        cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
        cout << "2 - Вывод элементов структуры в консольное окно" << endl;
        cout << "3 - Поиск по названию" << endl;
        cout << "0 - Выход из программы" << endl;
        cin >> choice; // Считываем выбор пользователя

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
    cout << "Введите количество санаториев: ";
    cin >> numSanatorium; // Считываем количество санаториев

    cin.ignore(); // Игнорируем символ новой строки после ввода числа

    for (int i = 0; i < numSanatorium; i++)
    {
        if (currentSanatorium < MAX_SANATORIUMS)
        {
            cout << "\nНазвание санатория: ";
            getline(cin, listOfSanatorium[currentSanatorium].name);

            cout << "\nМесто расположения: ";
            getline(cin, listOfSanatorium[currentSanatorium].location);

            cout << "\nЛечебный профиль: ";
            getline(cin, listOfSanatorium[currentSanatorium].direction);

            cout << "\nКол-во путёвок: ";
            cin >> listOfSanatorium[currentSanatorium].amountPermit;

            cout << endl;

            cin.ignore(); // Игнорируем символ новой строки после ввода времени

            currentSanatorium++;
        }
    }
}

void outputSanatorium()
{
    int choice;
    for (int i = 0; i < currentSanatorium; i++)
    {
        cout << "\nНазвание санатория: " << listOfSanatorium[i].name;
        cout << "\nМесто расположения: " << listOfSanatorium[i].location;
        cout << "\nЛечебный профиль: " << listOfSanatorium[i].direction;
        cout << "\nКол-во путёвок: " << listOfSanatorium[i].amountPermit;

        cout << endl;

    }
        cin.ignore();
}

void foundSanatorium()
{
    string name;
    cout << "\nВведите название санатория: ";
    cin >> name;

    bool foundSanatorium = false;

    for (int i = 0; i < currentSanatorium; i++)
    {
        if (listOfSanatorium[i].name == name)
        {
            foundSanatorium = true;
            cout << "\nНазвание санатория: " << listOfSanatorium[i].name;
            cout << "\nМесто расположения: " << listOfSanatorium[i].location;
            cout << "\nЛечебный профиль: " << listOfSanatorium[i].direction;
            cout << "\nКол-во путёвок: " << listOfSanatorium[i].amountPermit;
            cout << endl;
        }
    }

    if (!foundSanatorium)
    {
        cout << "\nНет санаториев с указанным названием." << endl;
    }
}