#include <string>
#include <fstream>
    using namespace std;
    //#define MAX_PERSONNEL  10

    //int current_personnel = 0;

    //enum jobTitle
    //{
    //    junior = 1, middle, senior
    //};

 
    //struct personnelDepartment
    //{
    //    fullName FIO;   // фио
    //    string education;  // образование
    //    string speciality; // специальность
    //    jobTitle Title;   // должность
    //    int Salary;        // оклад (зарплата)
    //    Date inviteDate;   // дата приглашения на работу 
    //};

    //personnelDepartment listOfPersonnel[MAX_PERSONNEL];

    //void input();
    //void output();
    //void findByJobTitle();
    //void deletePersonnel();


    //int var1n1()
    //{
    //    int choice;
    //    do
    //    {
    //        cout << "\n1. Ввод данных с клавиатуры\n";
    //        cout << "2. Вывод данных\n";
    //        cout << "3. Поиск по должности\n";
    //        cout << "4. удаление по фамилии\n";
    //        cout << "0. Выход из программы\n\n";
    //        cout << "Введите номер операции: ";
    //        cin >> choice;

    //        switch (choice)
    //        {
    //        case 1:           
    //            input();
    //            break;

    //        case 2:
    //            output();
    //            break;

    //        case 3:
    //           findByJobTitle();
    //            break;
    //        case 4:
    //            deletePersonnel();
    //            break;

    //        case 0:
    //            exit(0);
    //            break;

    //        default:
    //            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
    //            break;
    //        }
    //    } while (choice != 0);

    //    return 0;
    //}

    //void input()
    //{
    //    int personnelCount;
    //    cout << "Введите кол-во персонала: ";
    //    cin >> personnelCount;

    //    cin.ignore();

    //    for (int i = 0; i < personnelCount; i++)
    //    {
    //        if (current_personnel < MAX_PERSONNEL)
    //        {
    //            cout << "ФИО: ";
    //            cin >> listOfPersonnel[current_personnel].FIO.surname>> listOfPersonnel[current_personnel].FIO.name >> listOfPersonnel[current_personnel].FIO.partonymic;
    //          
    //            cout << "Образование: ";
    //            cin >>listOfPersonnel[current_personnel].education;
    //           
    //            cout << "Специальность: ";
    //           cin >> listOfPersonnel[current_personnel].speciality;
    //            
    //            cout << "Выберите должность(1-junior, 2- middle, 3 -senior): ";
    //            int Title;
    //            cin >> Title;
    //            listOfPersonnel[current_personnel].Title = static_cast<jobTitle>(Title);

    //            cout << "Зарплата: ";
    //            cin >> listOfPersonnel[current_personnel].Salary;

    //            cout << "Дата вступления: ";
    //            cinIn(int, listOfPersonnel[current_personnel].inviteDate.day);
    //            cinIn(int, listOfPersonnel[current_personnel].inviteDate.month);
    //            cinIn(int, listOfPersonnel[current_personnel].inviteDate.year);

    //            current_personnel++;
    //        }
    //    }

    //}
    //
    //void output()
    //{
    //    for (int i = 0; i < current_personnel; i++)
    //    {
    //        cout << "\nФИО:\t" << listOfPersonnel[i].FIO.surname << ' ' << listOfPersonnel[i].FIO.name << ' ' << listOfPersonnel[i].FIO.partonymic << endl;
    //        cout << "Образование:\t" << listOfPersonnel[i].education << endl;
    //        cout << "Специальность:\t" << listOfPersonnel[i].speciality << endl;
    //        cout << "Должность:\t" << listOfPersonnel[i].Title << endl;
    //        cout << "Зарплата:\t" << listOfPersonnel[i].Salary << endl;
    //        cout << "Дата вступления:\t" << listOfPersonnel[i].inviteDate.day << "." << listOfPersonnel[i].inviteDate.month << "." << listOfPersonnel[i].inviteDate.year << endl;
    //    
    //    }
    //}

    //void findByJobTitle()
    //{
    //    string jTitle;
    //    cout << "Введите должность: ";
    //    cin >> jTitle;

    //    jobTitle jTitleEnum;

    //    if (jTitle == "junior") {
    //        jTitleEnum = junior;
    //    }
    //    else if (jTitle == "middle") {
    //        jTitleEnum = middle;
    //    }
    //    else if (jTitle == "senior") {
    //        jTitleEnum = senior;
    //    }
    //    else {
    //        cout << "Некорректная должность\n";
    //        return;
    //    }

    //    bool found = false;

    //    for (int i = 0; i < current_personnel; i++)
    //    {
    //  
    //        if (jTitleEnum == listOfPersonnel[i].Title)
    //        {
    //            cout << "\nФИО:\t" << listOfPersonnel[i].FIO.surname << ' ' << listOfPersonnel[i].FIO.name << ' ' << listOfPersonnel[i].FIO.partonymic << endl;
    //            cout << "Образование:\t" << listOfPersonnel[i].education << endl;
    //            cout << "Специальность:\t" << listOfPersonnel[i].speciality << endl;
    //            cout << "Должность:\t" << listOfPersonnel[i].Title << endl;
    //            cout << "Зарплата:\t" << listOfPersonnel[i].Salary << endl;
    //            cout << "Дата вступления:\t" << listOfPersonnel[i].inviteDate.day << "." << listOfPersonnel[i].inviteDate.month << "." << listOfPersonnel[i].inviteDate.year << endl;

    //            found = true;
    //        }
    //  
    //    }

    //    if (!found)
    //    {
    //        cout << "Не найдено\n";
    //    }
    //}

    //void deletePersonnel()
    //{
    //   string Surname;
    //    cout << "Введите фамилию для удаления: ";
    //    cin >> Surname;

    //    bool findBySurname = false;

    //    for (int i = 0; i < current_personnel; i++)
    //    {
    //        if (Surname == listOfPersonnel[i].FIO.surname)
    //        {
    //            findBySurname = true;

    //            for (int j = i; j < current_personnel - 1; j++)
    //            {
    //                listOfPersonnel[j] = listOfPersonnel[j + 1];
    //            }
    //            current_personnel--;
    //            cout << "\nЧеловек удален.\n";
    //            break;
    //        }
    //    }

    //    if (!findBySurname)
    //    {
    //        cout << "\nНе найдено \n";
    //    }
    //}

//#define MAX_TEACHERS  10 // максимальное кол-во 
//
//int current_teacher = 0;
//
//struct personnelDepartment
//{
//    fullName FIO;   // фио
//    string examName;  // Название экзамена
//    Date examDate;   // дата экзамена
//};
//
//personnelDepartment listOfTeachers[MAX_TEACHERS];//объявляем структуру
//
////прототипы ф-ций
//void input();
//void output();
//void findBySurname();
//
//
//
//int var1n2()
//{
//    int choice;
//    do
//    {
//        cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
//        cout << "2. Вывод данных из файла\n";
//        cout << "3. Поиск по Фамилии\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            input();
//            break;
//
//        case 2:
//            output();
//            break;
//
//        case 3:
//            findBySurname();
//            break;
//        
//
//        case 0:
//            exit(0);
//            break;
//
//        default:
//            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
////ф-ция ввода
//void input()
//{
//    FILE* f;
//    int teachersCount;
//    cout << "Введите кол-во преподавателей: ";
//    cin >> teachersCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var1n2.txt", "ab+") == 0) // Открываем файл в режиме добавления/чтения в двоичном режиме
//    {
//        for (int i = 0; i < teachersCount; i++)
//        {
//            if (current_teacher < MAX_TEACHERS)
//            {
//                cout << "ФИО: ";
//                cin >> listOfTeachers[current_teacher].FIO.surname >> listOfTeachers[current_teacher].FIO.name >> listOfTeachers[current_teacher].FIO.partonymic;
//             
//                cout << "Название экзамена: ";
//                cin >> listOfTeachers[current_teacher].examName;
//
//                cout << "Дата экзамена: ";
//                cinIn(int, listOfTeachers[current_teacher].examDate.day);
//                cinIn(int, listOfTeachers[current_teacher].examDate.month);
//                cinIn(int, listOfTeachers[current_teacher].examDate.year);
//
//                std::fwrite(&listOfTeachers, sizeof(listOfTeachers), 1, f); //запись в файл
//                current_teacher++;
//            }
//        }
//        if (std::fwrite(&listOfTeachers[current_teacher], sizeof(listOfTeachers[current_teacher]), 1, f) != 1)
//        {
//            cout << "Ошибка записи в файл" << endl;
//        }
//        fclose(f); // закрытие файла
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
////ф-ция вывода
//void output()
//{
//    FILE* f;
//    if (fopen_s(&f, "var1n2.txt", "rb") == 0) //открытие файла для чтения
//    {
//        fread(&listOfTeachers, sizeof(listOfTeachers), 1, f); // читаем содержимое из файла
//        for (int i = 0; i < current_teacher; i++)
//        {
//            cout << endl;
//            cout << "\nФИО:\t" << listOfTeachers[i].FIO.surname << ' ' << listOfTeachers[i].FIO.name << ' ' << listOfTeachers[i].FIO.partonymic << endl;
//            cout << "Название экзамена:\t" << listOfTeachers[i].examName << endl;
//            cout << "Дата экзамена:\t" << listOfTeachers[i].examDate.day << "." << listOfTeachers[i].examDate.month << "." << listOfTeachers[i].examDate.year << endl;
//            cout << endl;
//           fread(&listOfTeachers, sizeof(listOfTeachers), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
////ф-ция поиска
//void findBySurname()
//{
//    FILE* f;
//
//    string Surname;
//    cout << "Введите фамилию: ";
//    cin >> Surname;
//    
//
//    bool found = false;
//    if(fopen_s(&f, "var1n2.txt", "rb") == 0)//открываем файл
//    { 
//        for (int i = 0; i < current_teacher; i++)
//        {
//
//            if (Surname == listOfTeachers[i].FIO.surname)//если нашли, то выводим инфу
//            {
//                cout << "\nФИО:\t" << listOfTeachers[i].FIO.surname << ' ' << listOfTeachers[i].FIO.name << ' ' << listOfTeachers[i].FIO.partonymic << endl;                                           
//                cout << "Название экзамена:\t" << listOfTeachers[i].examName << endl;
//                cout << "Дата экзамена:\t" << listOfTeachers[i].examDate.day << "." << listOfTeachers[i].examDate.month << "." << listOfTeachers[i].examDate.year << endl;
//                cout << endl;
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Не найдено\n";
//    }
//}



//#define MAX_CITIZENS 10
//
//int current_citizens = 0;
//
//enum Gender
//{
//    male = 1, female
//};
//
//
//struct Citizens
//{
//    fullName FIO;   // фио
//    Date BirthdayDate;   // дата рождения
//    string address;  // адресс
//    Gender gender;   // пол
//};
//
//    Citizens listOfCitizens[MAX_CITIZENS];
//
//void input();
//void output();
//void findByBirthdayDate();
//void deleteCitizen();
//
//
//int var2n1()
//{
//    int choice;
//    do
//    {
//        cout << "\n1. Ввод данных с клавиатуры\n";
//        cout << "2. Вывод данных\n";
//        cout << "3. Поиск по дате рождения\n";
//        cout << "4. удаление по фамилии\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            input();
//            break;
//
//        case 2:
//            output();
//            break;
//
//        case 3:
//            findByBirthdayDate();
//            break;
//        case 4:
//            deleteCitizen();
//            break;
//
//        case 0:
//            exit(0);
//            break;
//
//        default:
//            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//void input()
//{
//    int citizensCount;
//    cout << "Введите кол-во персонала: ";
//    cin >> citizensCount;
//
//    cin.ignore();
//
//    for (int i = 0; i < citizensCount; i++)
//    {
//        if (current_citizens < MAX_CITIZENS)
//        {
//            cout << "ФИО: ";
//            cin >> listOfCitizens[current_citizens].FIO.surname >> listOfCitizens[current_citizens].FIO.name >> listOfCitizens[current_citizens].FIO.partonymic;
//
//            cout << "Дата рождения: ";
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.day);
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.month);
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.year);
//           
//            cout << "Адресс: ";
//            cin >> listOfCitizens[current_citizens].address;
//
//            cout << "Выберите пол(1-male, 2- female): ";
//            int gender;
//            cin >> gender;
//            listOfCitizens[current_citizens].gender = static_cast<Gender>(gender);        
//
//            current_citizens++;
//        }
//    }
//
//}
//
//void output()
//{
//    for (int i = 0; i < current_citizens; i++)
//    {
//        cout << "\nФИО:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//        cout << "Дата рождения:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;      
//        cout << "Адресс:\t" << listOfCitizens[i].address << endl;
//        cout << "Пол:\t" << listOfCitizens[i].gender << endl;
//
//    }
//}
//
//void findByBirthdayDate()
//{
//    int day, month, year;
//    cout << "Введите дату рождения: ";
//    cin >> day >> month >> year;
//
//
//    bool found = false;
//
//    for (int i = 0; i < current_citizens; i++)
//    {
//
//        if (day == listOfCitizens[i].BirthdayDate.day && month == listOfCitizens[i].BirthdayDate.month && year == listOfCitizens[i].BirthdayDate.year)
//        {
//            cout << "\nФИО:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//            cout << "Дата рождения:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//            cout << "Адресс:\t" << listOfCitizens[i].address << endl;
//            cout << "Пол:\t" << listOfCitizens[i].gender << endl;
//           
//            found = true;
//        }
//
//    }
//
//    if (!found)
//    {
//        cout << "Не найдено\n";
//    }
//}
//
//void deleteCitizen()
//{
//    string Surname;
//    cout << "Введите фамилию для удаления: ";
//    cin >> Surname;
//
//    bool findBySurname = false;
//
//    for (int i = 0; i < current_citizens; i++)
//    {
//        if (Surname == listOfCitizens[i].FIO.surname)
//        {
//            findBySurname = true;
//
//            for (int j = i; j < current_citizens - 1; j++)
//            {
//                listOfCitizens[j] = listOfCitizens[j + 1];
//            }
//            current_citizens--;
//            cout << "\nЧеловек удален.\n";
//            break;
//        }
//    }
//
//    if (!findBySurname)
//    {
//        cout << "\nНе найдено \n";
//    }
//}
//



//#define MAX_TRAINS  10 // максимальное кол-во 
//
//int current_trains = 0;
//
//struct trains
//{
//    string numberTrain;        // номер поезда
//    string destination;     // пункт назначения
//    Date dayTrain;           // дни следования
//    Time timeArrive;        // время прибытия
//    Time timeDeparture;     // время отправления
//};
//
//trains ListOfTrains[MAX_TRAINS];//объявляем структуру
//
////прототипы ф-ций
//void input();
//void output();
//void findByDestination();
//
//
//
//int var2n2()
//{
//    int choice;
//    do
//    {
//        cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
//        cout << "2. Вывод данных из файла\n";
//        cout << "3. Поиск по пункту назначения\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            input();
//            break;
//
//        case 2:
//            output();
//            break;
//
//        case 3:
//            findByDestination();
//            break;
//
//
//        case 0:
//            exit(0);
//            break;
//
//        default:
//            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
////ф-ция ввода
//void input()
//{
//    FILE* f;
//    int TrainsCount;
//    cout << "Введите кол-во поездов: ";
//    cin >> TrainsCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var2n2.txt", "ab+") == 0) // Открываем файл в режиме добавления/чтения в двоичном режиме
//    {
//        for (int i = 0; i < TrainsCount; i++)
//        {
//            if (current_trains < MAX_TRAINS)
//            {
//                cout << "Номер поезда: ";
//                cin >>ListOfTrains[current_trains].numberTrain;
//               
//                cout << "Пункт назначения: ";
//                cin >> ListOfTrains[current_trains].destination;
//                                                                 
//                cout << "Дни следования: ";
//                cinIn(int, ListOfTrains[current_trains].dayTrain.day);
//                cinIn(int, ListOfTrains[current_trains].dayTrain.month);
//                cinIn(int, ListOfTrains[current_trains].dayTrain.year);
//
//                cout << "Время прибытия: ";
//                cinIn(int, ListOfTrains[current_trains].timeArrive.hours);
//                cinIn(int, ListOfTrains[current_trains].timeArrive.minutes);
//
//                cout << "Время отправления: ";
//                cinIn(int, ListOfTrains[current_trains].timeDeparture.hours);
//                cinIn(int, ListOfTrains[current_trains].timeDeparture.minutes);
//
//                std::fwrite(&ListOfTrains, sizeof(ListOfTrains), 1, f); //запись в файл
//                current_trains++;
//            }
//        }
//        if (std::fwrite(&ListOfTrains[current_trains], sizeof(ListOfTrains[current_trains]), 1, f) != 1)
//        {
//            cout << "Ошибка записи в файл" << endl;
//        }
//        fclose(f); // закрытие файла
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
//
////ф-ция вывода
//void output()
//{
//    FILE* f;
//    if (fopen_s(&f, "var2n2.txt", "rb") == 0) //открытие файла для чтения
//    {
//        fread(&ListOfTrains, sizeof(ListOfTrains), 1, f); // читаем содержимое из файла
//        for (int i = 0; i < current_trains; i++)
//        {
//            cout << endl;
//            cout << "Номер поезда: " << ListOfTrains[i].numberTrain <<endl;
//            cout << "Пункт назначения: " << ListOfTrains[i].destination << endl;
//            cout << "Дни следования:" << ListOfTrains[i].dayTrain.day << "." << ListOfTrains[i].dayTrain.month << "." << ListOfTrains[i].dayTrain.year << endl;
//            cout << "Время прибытия: " << ListOfTrains[i].timeArrive.hours << ":" << ListOfTrains[i].timeArrive.minutes << endl;
//            cout << "Время отправление: " << ListOfTrains[i].timeDeparture.hours << ":" << ListOfTrains[i].timeDeparture.minutes << endl;
//            cout << endl;
//            fread(&ListOfTrains, sizeof(ListOfTrains), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
//
////ф-ция поиска
//void findByDestination()
//{
//    FILE* f;
//
//    string Destination;
//    cout << "Введите пункт назначения: ";
//    cin >> Destination;
//
//
//    bool found = false;
//    if (fopen_s(&f, "var2n2.txt", "rb") == 0)//открываем файл
//    {
//        for (int i = 0; i < current_trains; i++)
//        {
//
//            if (Destination == ListOfTrains[i].destination)//если нашли, то выводим инфу
//            {
//                cout << "Номер поезда: " << ListOfTrains[current_trains].numberTrain;
//                cout << "Пункт назначения: " << ListOfTrains[current_trains].destination;
//                cout << "Дни следования:\t" << ListOfTrains[i].dayTrain.day << "." << ListOfTrains[i].dayTrain.month << "." << ListOfTrains[i].dayTrain.year << endl;
//                cout << "Время прибытия: " << ListOfTrains[i].timeArrive.hours << "." << ListOfTrains[i].timeArrive.minutes << endl;
//                cout << "Время отправление: " << ListOfTrains[i].timeDeparture.hours << "." << ListOfTrains[i].timeDeparture.minutes << endl;
//                cout << endl;
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Не найдено\n";
//    }
//}


//#define MAX_STATES 10
//
//int current_states = 0;
//
//enum formOfGovernment
//{
//    республика = 1, монархия, диктатура, тоталитаризм, демократия
//};
//
//
//struct States
//{
//    string name;   // Название
//    string capital;   // столица
//    int population;   // численность
//    string square;  // площадь
//    formOfGovernment government; // форма правления
//    
//};
//
//States listOfStates[MAX_STATES];
//
//void input();
//void output();
//void findByCapital();
//void deleteState();
//
//
//int var10n1()
//{
//    int choice;
//    do
//    {
//        cout << "\n1. Ввод данных с клавиатуры\n";
//        cout << "2. Вывод данных\n";
//        cout << "3. Поиск по столице\n";
//        cout << "4. удаление по названию города\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            input();
//            break;
//
//        case 2:
//            output();
//            break;
//
//        case 3:
//            findByCapital();
//            break;
//        case 4:
//            deleteState();
//            break;
//
//        case 0:
//            exit(0);
//            break;
//
//        default:
//            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//void input()
//{
//    int statesCount;
//    cout << "Введите кол-во государств: ";
//    cin >> statesCount;
//
//    cin.ignore();
//
//    for (int i = 0; i < statesCount; i++)
//    {
//        if (current_states < MAX_STATES)
//        {
//            cout << "Название: ";
//            cin >> listOfStates[current_states].name;
//
//            cout << "Столица: ";
//            cin >> listOfStates[current_states].capital;
//           
//            cout << "Население: ";
//            cin >> listOfStates[current_states].population;
//
//            cout << "Площадь: ";
//            cin >> listOfStates[current_states].square;
//            
//            cout << "Выберите форму правления(республика - 1, монархия -2 , диктатура - 3, тоталитаризм -4 , демократия -5 ): ";
//            int Government;
//            cin >> Government;
//            listOfStates[current_states].government = static_cast<formOfGovernment>(Government);
//
//            current_states++;
//        }
//    }
//
//}
//
//void output()
//{
//    for (int i = 0; i < current_states; i++)
//    {
//        cout << "\nНазвание: " << listOfStates[i].name << endl;
//        cout << "Столица: " << listOfStates[i].capital << endl;
//        cout << "Население: " << listOfStates[i].population << endl;
//        cout << "Площадь: " << listOfStates[i].square << endl;
//        cout << "Форма правления: " << listOfStates[i].government;
//        cout << endl;
//    }
//}
//
//void findByCapital()
//{
//    string capital;
//    cout << "Введите столицу: ";
//    cin >> capital;
//
//
//    bool found = false;
//
//    for (int i = 0; i < current_states; i++)
//    {
//
//        if (capital == listOfStates[i].capital)
//        {
//            cout << "\nНазвание: " << listOfStates[i].name << endl;
//            cout << "Столица: " << listOfStates[i].capital << endl;
//            cout << "Население: " << listOfStates[i].population << endl;
//            cout << "Площадь: " << listOfStates[i].square << endl;
//            cout << "Форма правления: " << listOfStates[i].government;
//            cout << endl;
//
//            found = true;
//        }
//
//    }
//
//    if (!found)
//    {
//        cout << "Не найдено\n";
//    }
//}
//
//void deleteState()
//{
//    string Name;
//    cout << "Введите название для удаления: ";
//    cin >> Name;
//
//    bool findByState = false;
//
//    for (int i = 0; i < current_states; i++)
//    {
//        if (Name == listOfStates[i].name)
//        {
//            findByState = true;
//
//            for (int j = i; j < current_states - 1; j++)
//            {
//                listOfStates[j] = listOfStates[j + 1];
//            }
//            current_states--;
//            cout << "\nгосударство удалено.\n";
//            break;
//        }
//    }
//
//    if (!findByState)
//    {
//        cout << "\nНе найдено \n";
//    }
//}

//#define MAX_CITIZENS 10
//
//int current_citizens = 0;
//
//enum Gender
//{
//    male = 1, female
//};
//
//struct Citizens
//{
//    fullName FIO;   // фио
//    Date BirthdayDate;   // дата рождения
//    string address;  // адресс
//    Gender gender;   // пол
//};
//
//Citizens listOfCitizens[MAX_CITIZENS];
//
////прототипы ф-ций
//void input();
//void output();
//void findByBirthdayDate();
//
//
//
//
//
//int var10n2()
//{
//    int choice;
//    do
//    {
//        cout << "\n1. Ввод данных с клавиатуры и запись в файл\n";
//        cout << "2. Вывод данных из файла\n";
//        cout << "3. Поиск по дню рождения\n";
//        cout << "0. Выход из программы\n\n";
//        cout << "Введите номер операции: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            input();
//            break;
//
//        case 2:
//            output();
//            break;
//
//        case 3:
//            findByBirthdayDate();
//            break;
//
//
//        case 0:
//            exit(0);
//            break;
//
//        default:
//            cout << "Некорректный ввод. Пожалуйста, выберите допустимую операцию." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//
////ф-ция ввода
//void input()
//{
//    FILE* f;
//    int CitizensCount;
//    cout << "Введите кол-во горожанинов: ";
//    cin >> CitizensCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var10n2.txt", "ab+") == 0) // Открываем файл в режиме добавления/чтения в двоичном режиме
//    {
//        for (int i = 0; i < CitizensCount; i++)
//        {
//            if (current_citizens < MAX_CITIZENS)
//            {
//                cout << "ФИО: ";
//                cin >> listOfCitizens[current_citizens].FIO.surname >> listOfCitizens[current_citizens].FIO.name >> listOfCitizens[current_citizens].FIO.partonymic;
//
//                cout << "Дата рождения: ";
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.day);
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.month);
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.year);
//
//                cout << "Адресс: ";
//                cin >> listOfCitizens[current_citizens].address;
//
//                cout << "Выберите пол(1-male, 2- female): ";
//                int gender;
//                cin >> gender;
//                listOfCitizens[current_citizens].gender = static_cast<Gender>(gender);
//
//                current_citizens++;
//                std::fwrite(&listOfCitizens, sizeof(listOfCitizens), 1, f); //запись в файл
//            }
//        }
//        if (std::fwrite(&listOfCitizens[current_citizens], sizeof(listOfCitizens[current_citizens]), 1, f) != 1)
//        {
//            cout << "Ошибка записи в файл" << endl;
//        }
//        fclose(f); // закрытие файла
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
//
////ф-ция вывода
//void output()
//{
//    FILE* f;
//
//    if (fopen_s(&f, "var10n2.txt", "rb") == 0) //открытие файла для чтения
//    {
//        fread(&listOfCitizens, sizeof(listOfCitizens), 1, f); // читаем содержимое из файла
//        for (int i = 0; i < current_citizens; i++)
//        {
//            cout << "\nФИО:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//            cout << "Дата рождения:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//            cout << "Адресс:\t" << listOfCitizens[i].address << endl;
//            cout << "Пол:\t" << listOfCitizens[i].gender << endl;
//            fread(&listOfCitizens, sizeof(listOfCitizens), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//}
//
//
////ф-ция поиска
//void findByBirthdayDate()
//{
//    FILE* f;
//    int day, month, year;
//    cout << "Введите дату рождения: ";
//    cin >> day >> month >> year;
//
//
//    bool found = false;
//    if (fopen_s(&f, "var10n2.txt", "rb") == 0)//открываем файл
//    { 
//        for (int i = 0; i < current_citizens; i++)
//        {
//
//            if (day == listOfCitizens[i].BirthdayDate.day && month == listOfCitizens[i].BirthdayDate.month && year == listOfCitizens[i].BirthdayDate.year)
//            {
//                cout << "\nФИО:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//                cout << "Дата рождения:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//                cout << "Адресс:\t" << listOfCitizens[i].address << endl;
//                cout << "Пол:\t" << listOfCitizens[i].gender << endl;
//
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "Не найдено\n";
//    }
//    fclose(f);
//}
//
