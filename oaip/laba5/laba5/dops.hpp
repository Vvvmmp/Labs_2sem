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
    //    fullName FIO;   // ���
    //    string education;  // �����������
    //    string speciality; // �������������
    //    jobTitle Title;   // ���������
    //    int Salary;        // ����� (��������)
    //    Date inviteDate;   // ���� ����������� �� ������ 
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
    //        cout << "\n1. ���� ������ � ����������\n";
    //        cout << "2. ����� ������\n";
    //        cout << "3. ����� �� ���������\n";
    //        cout << "4. �������� �� �������\n";
    //        cout << "0. ����� �� ���������\n\n";
    //        cout << "������� ����� ��������: ";
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
    //            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
    //            break;
    //        }
    //    } while (choice != 0);

    //    return 0;
    //}

    //void input()
    //{
    //    int personnelCount;
    //    cout << "������� ���-�� ���������: ";
    //    cin >> personnelCount;

    //    cin.ignore();

    //    for (int i = 0; i < personnelCount; i++)
    //    {
    //        if (current_personnel < MAX_PERSONNEL)
    //        {
    //            cout << "���: ";
    //            cin >> listOfPersonnel[current_personnel].FIO.surname>> listOfPersonnel[current_personnel].FIO.name >> listOfPersonnel[current_personnel].FIO.partonymic;
    //          
    //            cout << "�����������: ";
    //            cin >>listOfPersonnel[current_personnel].education;
    //           
    //            cout << "�������������: ";
    //           cin >> listOfPersonnel[current_personnel].speciality;
    //            
    //            cout << "�������� ���������(1-junior, 2- middle, 3 -senior): ";
    //            int Title;
    //            cin >> Title;
    //            listOfPersonnel[current_personnel].Title = static_cast<jobTitle>(Title);

    //            cout << "��������: ";
    //            cin >> listOfPersonnel[current_personnel].Salary;

    //            cout << "���� ����������: ";
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
    //        cout << "\n���:\t" << listOfPersonnel[i].FIO.surname << ' ' << listOfPersonnel[i].FIO.name << ' ' << listOfPersonnel[i].FIO.partonymic << endl;
    //        cout << "�����������:\t" << listOfPersonnel[i].education << endl;
    //        cout << "�������������:\t" << listOfPersonnel[i].speciality << endl;
    //        cout << "���������:\t" << listOfPersonnel[i].Title << endl;
    //        cout << "��������:\t" << listOfPersonnel[i].Salary << endl;
    //        cout << "���� ����������:\t" << listOfPersonnel[i].inviteDate.day << "." << listOfPersonnel[i].inviteDate.month << "." << listOfPersonnel[i].inviteDate.year << endl;
    //    
    //    }
    //}

    //void findByJobTitle()
    //{
    //    string jTitle;
    //    cout << "������� ���������: ";
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
    //        cout << "������������ ���������\n";
    //        return;
    //    }

    //    bool found = false;

    //    for (int i = 0; i < current_personnel; i++)
    //    {
    //  
    //        if (jTitleEnum == listOfPersonnel[i].Title)
    //        {
    //            cout << "\n���:\t" << listOfPersonnel[i].FIO.surname << ' ' << listOfPersonnel[i].FIO.name << ' ' << listOfPersonnel[i].FIO.partonymic << endl;
    //            cout << "�����������:\t" << listOfPersonnel[i].education << endl;
    //            cout << "�������������:\t" << listOfPersonnel[i].speciality << endl;
    //            cout << "���������:\t" << listOfPersonnel[i].Title << endl;
    //            cout << "��������:\t" << listOfPersonnel[i].Salary << endl;
    //            cout << "���� ����������:\t" << listOfPersonnel[i].inviteDate.day << "." << listOfPersonnel[i].inviteDate.month << "." << listOfPersonnel[i].inviteDate.year << endl;

    //            found = true;
    //        }
    //  
    //    }

    //    if (!found)
    //    {
    //        cout << "�� �������\n";
    //    }
    //}

    //void deletePersonnel()
    //{
    //   string Surname;
    //    cout << "������� ������� ��� ��������: ";
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
    //            cout << "\n������� ������.\n";
    //            break;
    //        }
    //    }

    //    if (!findBySurname)
    //    {
    //        cout << "\n�� ������� \n";
    //    }
    //}

//#define MAX_TEACHERS  10 // ������������ ���-�� 
//
//int current_teacher = 0;
//
//struct personnelDepartment
//{
//    fullName FIO;   // ���
//    string examName;  // �������� ��������
//    Date examDate;   // ���� ��������
//};
//
//personnelDepartment listOfTeachers[MAX_TEACHERS];//��������� ���������
//
////��������� �-���
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
//        cout << "\n1. ���� ������ � ���������� � ������ � ����\n";
//        cout << "2. ����� ������ �� �����\n";
//        cout << "3. ����� �� �������\n";
//        cout << "0. ����� �� ���������\n\n";
//        cout << "������� ����� ��������: ";
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
//            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
////�-��� �����
//void input()
//{
//    FILE* f;
//    int teachersCount;
//    cout << "������� ���-�� ��������������: ";
//    cin >> teachersCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var1n2.txt", "ab+") == 0) // ��������� ���� � ������ ����������/������ � �������� ������
//    {
//        for (int i = 0; i < teachersCount; i++)
//        {
//            if (current_teacher < MAX_TEACHERS)
//            {
//                cout << "���: ";
//                cin >> listOfTeachers[current_teacher].FIO.surname >> listOfTeachers[current_teacher].FIO.name >> listOfTeachers[current_teacher].FIO.partonymic;
//             
//                cout << "�������� ��������: ";
//                cin >> listOfTeachers[current_teacher].examName;
//
//                cout << "���� ��������: ";
//                cinIn(int, listOfTeachers[current_teacher].examDate.day);
//                cinIn(int, listOfTeachers[current_teacher].examDate.month);
//                cinIn(int, listOfTeachers[current_teacher].examDate.year);
//
//                std::fwrite(&listOfTeachers, sizeof(listOfTeachers), 1, f); //������ � ����
//                current_teacher++;
//            }
//        }
//        if (std::fwrite(&listOfTeachers[current_teacher], sizeof(listOfTeachers[current_teacher]), 1, f) != 1)
//        {
//            cout << "������ ������ � ����" << endl;
//        }
//        fclose(f); // �������� �����
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
////�-��� ������
//void output()
//{
//    FILE* f;
//    if (fopen_s(&f, "var1n2.txt", "rb") == 0) //�������� ����� ��� ������
//    {
//        fread(&listOfTeachers, sizeof(listOfTeachers), 1, f); // ������ ���������� �� �����
//        for (int i = 0; i < current_teacher; i++)
//        {
//            cout << endl;
//            cout << "\n���:\t" << listOfTeachers[i].FIO.surname << ' ' << listOfTeachers[i].FIO.name << ' ' << listOfTeachers[i].FIO.partonymic << endl;
//            cout << "�������� ��������:\t" << listOfTeachers[i].examName << endl;
//            cout << "���� ��������:\t" << listOfTeachers[i].examDate.day << "." << listOfTeachers[i].examDate.month << "." << listOfTeachers[i].examDate.year << endl;
//            cout << endl;
//           fread(&listOfTeachers, sizeof(listOfTeachers), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
////�-��� ������
//void findBySurname()
//{
//    FILE* f;
//
//    string Surname;
//    cout << "������� �������: ";
//    cin >> Surname;
//    
//
//    bool found = false;
//    if(fopen_s(&f, "var1n2.txt", "rb") == 0)//��������� ����
//    { 
//        for (int i = 0; i < current_teacher; i++)
//        {
//
//            if (Surname == listOfTeachers[i].FIO.surname)//���� �����, �� ������� ����
//            {
//                cout << "\n���:\t" << listOfTeachers[i].FIO.surname << ' ' << listOfTeachers[i].FIO.name << ' ' << listOfTeachers[i].FIO.partonymic << endl;                                           
//                cout << "�������� ��������:\t" << listOfTeachers[i].examName << endl;
//                cout << "���� ��������:\t" << listOfTeachers[i].examDate.day << "." << listOfTeachers[i].examDate.month << "." << listOfTeachers[i].examDate.year << endl;
//                cout << endl;
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "�� �������\n";
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
//    fullName FIO;   // ���
//    Date BirthdayDate;   // ���� ��������
//    string address;  // ������
//    Gender gender;   // ���
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
//        cout << "\n1. ���� ������ � ����������\n";
//        cout << "2. ����� ������\n";
//        cout << "3. ����� �� ���� ��������\n";
//        cout << "4. �������� �� �������\n";
//        cout << "0. ����� �� ���������\n\n";
//        cout << "������� ����� ��������: ";
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
//            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
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
//    cout << "������� ���-�� ���������: ";
//    cin >> citizensCount;
//
//    cin.ignore();
//
//    for (int i = 0; i < citizensCount; i++)
//    {
//        if (current_citizens < MAX_CITIZENS)
//        {
//            cout << "���: ";
//            cin >> listOfCitizens[current_citizens].FIO.surname >> listOfCitizens[current_citizens].FIO.name >> listOfCitizens[current_citizens].FIO.partonymic;
//
//            cout << "���� ��������: ";
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.day);
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.month);
//            cinIn(int, listOfCitizens[current_citizens].BirthdayDate.year);
//           
//            cout << "������: ";
//            cin >> listOfCitizens[current_citizens].address;
//
//            cout << "�������� ���(1-male, 2- female): ";
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
//        cout << "\n���:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//        cout << "���� ��������:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;      
//        cout << "������:\t" << listOfCitizens[i].address << endl;
//        cout << "���:\t" << listOfCitizens[i].gender << endl;
//
//    }
//}
//
//void findByBirthdayDate()
//{
//    int day, month, year;
//    cout << "������� ���� ��������: ";
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
//            cout << "\n���:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//            cout << "���� ��������:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//            cout << "������:\t" << listOfCitizens[i].address << endl;
//            cout << "���:\t" << listOfCitizens[i].gender << endl;
//           
//            found = true;
//        }
//
//    }
//
//    if (!found)
//    {
//        cout << "�� �������\n";
//    }
//}
//
//void deleteCitizen()
//{
//    string Surname;
//    cout << "������� ������� ��� ��������: ";
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
//            cout << "\n������� ������.\n";
//            break;
//        }
//    }
//
//    if (!findBySurname)
//    {
//        cout << "\n�� ������� \n";
//    }
//}
//



//#define MAX_TRAINS  10 // ������������ ���-�� 
//
//int current_trains = 0;
//
//struct trains
//{
//    string numberTrain;        // ����� ������
//    string destination;     // ����� ����������
//    Date dayTrain;           // ��� ����������
//    Time timeArrive;        // ����� ��������
//    Time timeDeparture;     // ����� �����������
//};
//
//trains ListOfTrains[MAX_TRAINS];//��������� ���������
//
////��������� �-���
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
//        cout << "\n1. ���� ������ � ���������� � ������ � ����\n";
//        cout << "2. ����� ������ �� �����\n";
//        cout << "3. ����� �� ������ ����������\n";
//        cout << "0. ����� �� ���������\n\n";
//        cout << "������� ����� ��������: ";
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
//            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
////�-��� �����
//void input()
//{
//    FILE* f;
//    int TrainsCount;
//    cout << "������� ���-�� �������: ";
//    cin >> TrainsCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var2n2.txt", "ab+") == 0) // ��������� ���� � ������ ����������/������ � �������� ������
//    {
//        for (int i = 0; i < TrainsCount; i++)
//        {
//            if (current_trains < MAX_TRAINS)
//            {
//                cout << "����� ������: ";
//                cin >>ListOfTrains[current_trains].numberTrain;
//               
//                cout << "����� ����������: ";
//                cin >> ListOfTrains[current_trains].destination;
//                                                                 
//                cout << "��� ����������: ";
//                cinIn(int, ListOfTrains[current_trains].dayTrain.day);
//                cinIn(int, ListOfTrains[current_trains].dayTrain.month);
//                cinIn(int, ListOfTrains[current_trains].dayTrain.year);
//
//                cout << "����� ��������: ";
//                cinIn(int, ListOfTrains[current_trains].timeArrive.hours);
//                cinIn(int, ListOfTrains[current_trains].timeArrive.minutes);
//
//                cout << "����� �����������: ";
//                cinIn(int, ListOfTrains[current_trains].timeDeparture.hours);
//                cinIn(int, ListOfTrains[current_trains].timeDeparture.minutes);
//
//                std::fwrite(&ListOfTrains, sizeof(ListOfTrains), 1, f); //������ � ����
//                current_trains++;
//            }
//        }
//        if (std::fwrite(&ListOfTrains[current_trains], sizeof(ListOfTrains[current_trains]), 1, f) != 1)
//        {
//            cout << "������ ������ � ����" << endl;
//        }
//        fclose(f); // �������� �����
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
//
////�-��� ������
//void output()
//{
//    FILE* f;
//    if (fopen_s(&f, "var2n2.txt", "rb") == 0) //�������� ����� ��� ������
//    {
//        fread(&ListOfTrains, sizeof(ListOfTrains), 1, f); // ������ ���������� �� �����
//        for (int i = 0; i < current_trains; i++)
//        {
//            cout << endl;
//            cout << "����� ������: " << ListOfTrains[i].numberTrain <<endl;
//            cout << "����� ����������: " << ListOfTrains[i].destination << endl;
//            cout << "��� ����������:" << ListOfTrains[i].dayTrain.day << "." << ListOfTrains[i].dayTrain.month << "." << ListOfTrains[i].dayTrain.year << endl;
//            cout << "����� ��������: " << ListOfTrains[i].timeArrive.hours << ":" << ListOfTrains[i].timeArrive.minutes << endl;
//            cout << "����� �����������: " << ListOfTrains[i].timeDeparture.hours << ":" << ListOfTrains[i].timeDeparture.minutes << endl;
//            cout << endl;
//            fread(&ListOfTrains, sizeof(ListOfTrains), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
//
////�-��� ������
//void findByDestination()
//{
//    FILE* f;
//
//    string Destination;
//    cout << "������� ����� ����������: ";
//    cin >> Destination;
//
//
//    bool found = false;
//    if (fopen_s(&f, "var2n2.txt", "rb") == 0)//��������� ����
//    {
//        for (int i = 0; i < current_trains; i++)
//        {
//
//            if (Destination == ListOfTrains[i].destination)//���� �����, �� ������� ����
//            {
//                cout << "����� ������: " << ListOfTrains[current_trains].numberTrain;
//                cout << "����� ����������: " << ListOfTrains[current_trains].destination;
//                cout << "��� ����������:\t" << ListOfTrains[i].dayTrain.day << "." << ListOfTrains[i].dayTrain.month << "." << ListOfTrains[i].dayTrain.year << endl;
//                cout << "����� ��������: " << ListOfTrains[i].timeArrive.hours << "." << ListOfTrains[i].timeArrive.minutes << endl;
//                cout << "����� �����������: " << ListOfTrains[i].timeDeparture.hours << "." << ListOfTrains[i].timeDeparture.minutes << endl;
//                cout << endl;
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "�� �������\n";
//    }
//}


//#define MAX_STATES 10
//
//int current_states = 0;
//
//enum formOfGovernment
//{
//    ���������� = 1, ��������, ���������, ������������, ����������
//};
//
//
//struct States
//{
//    string name;   // ��������
//    string capital;   // �������
//    int population;   // �����������
//    string square;  // �������
//    formOfGovernment government; // ����� ���������
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
//        cout << "\n1. ���� ������ � ����������\n";
//        cout << "2. ����� ������\n";
//        cout << "3. ����� �� �������\n";
//        cout << "4. �������� �� �������� ������\n";
//        cout << "0. ����� �� ���������\n\n";
//        cout << "������� ����� ��������: ";
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
//            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
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
//    cout << "������� ���-�� ����������: ";
//    cin >> statesCount;
//
//    cin.ignore();
//
//    for (int i = 0; i < statesCount; i++)
//    {
//        if (current_states < MAX_STATES)
//        {
//            cout << "��������: ";
//            cin >> listOfStates[current_states].name;
//
//            cout << "�������: ";
//            cin >> listOfStates[current_states].capital;
//           
//            cout << "���������: ";
//            cin >> listOfStates[current_states].population;
//
//            cout << "�������: ";
//            cin >> listOfStates[current_states].square;
//            
//            cout << "�������� ����� ���������(���������� - 1, �������� -2 , ��������� - 3, ������������ -4 , ���������� -5 ): ";
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
//        cout << "\n��������: " << listOfStates[i].name << endl;
//        cout << "�������: " << listOfStates[i].capital << endl;
//        cout << "���������: " << listOfStates[i].population << endl;
//        cout << "�������: " << listOfStates[i].square << endl;
//        cout << "����� ���������: " << listOfStates[i].government;
//        cout << endl;
//    }
//}
//
//void findByCapital()
//{
//    string capital;
//    cout << "������� �������: ";
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
//            cout << "\n��������: " << listOfStates[i].name << endl;
//            cout << "�������: " << listOfStates[i].capital << endl;
//            cout << "���������: " << listOfStates[i].population << endl;
//            cout << "�������: " << listOfStates[i].square << endl;
//            cout << "����� ���������: " << listOfStates[i].government;
//            cout << endl;
//
//            found = true;
//        }
//
//    }
//
//    if (!found)
//    {
//        cout << "�� �������\n";
//    }
//}
//
//void deleteState()
//{
//    string Name;
//    cout << "������� �������� ��� ��������: ";
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
//            cout << "\n����������� �������.\n";
//            break;
//        }
//    }
//
//    if (!findByState)
//    {
//        cout << "\n�� ������� \n";
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
//    fullName FIO;   // ���
//    Date BirthdayDate;   // ���� ��������
//    string address;  // ������
//    Gender gender;   // ���
//};
//
//Citizens listOfCitizens[MAX_CITIZENS];
//
////��������� �-���
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
//        cout << "\n1. ���� ������ � ���������� � ������ � ����\n";
//        cout << "2. ����� ������ �� �����\n";
//        cout << "3. ����� �� ��� ��������\n";
//        cout << "0. ����� �� ���������\n\n";
//        cout << "������� ����� ��������: ";
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
//            cout << "������������ ����. ����������, �������� ���������� ��������." << endl;
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//
////�-��� �����
//void input()
//{
//    FILE* f;
//    int CitizensCount;
//    cout << "������� ���-�� �����������: ";
//    cin >> CitizensCount;
//
//    cin.ignore();
//    if (fopen_s(&f, "var10n2.txt", "ab+") == 0) // ��������� ���� � ������ ����������/������ � �������� ������
//    {
//        for (int i = 0; i < CitizensCount; i++)
//        {
//            if (current_citizens < MAX_CITIZENS)
//            {
//                cout << "���: ";
//                cin >> listOfCitizens[current_citizens].FIO.surname >> listOfCitizens[current_citizens].FIO.name >> listOfCitizens[current_citizens].FIO.partonymic;
//
//                cout << "���� ��������: ";
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.day);
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.month);
//                cinIn(int, listOfCitizens[current_citizens].BirthdayDate.year);
//
//                cout << "������: ";
//                cin >> listOfCitizens[current_citizens].address;
//
//                cout << "�������� ���(1-male, 2- female): ";
//                int gender;
//                cin >> gender;
//                listOfCitizens[current_citizens].gender = static_cast<Gender>(gender);
//
//                current_citizens++;
//                std::fwrite(&listOfCitizens, sizeof(listOfCitizens), 1, f); //������ � ����
//            }
//        }
//        if (std::fwrite(&listOfCitizens[current_citizens], sizeof(listOfCitizens[current_citizens]), 1, f) != 1)
//        {
//            cout << "������ ������ � ����" << endl;
//        }
//        fclose(f); // �������� �����
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
//
////�-��� ������
//void output()
//{
//    FILE* f;
//
//    if (fopen_s(&f, "var10n2.txt", "rb") == 0) //�������� ����� ��� ������
//    {
//        fread(&listOfCitizens, sizeof(listOfCitizens), 1, f); // ������ ���������� �� �����
//        for (int i = 0; i < current_citizens; i++)
//        {
//            cout << "\n���:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//            cout << "���� ��������:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//            cout << "������:\t" << listOfCitizens[i].address << endl;
//            cout << "���:\t" << listOfCitizens[i].gender << endl;
//            fread(&listOfCitizens, sizeof(listOfCitizens), 1, f);
//        }
//        fclose(f);
//    }
//    else
//    {
//        cout << "������ �������� �����";
//        return;
//    }
//}
//
//
////�-��� ������
//void findByBirthdayDate()
//{
//    FILE* f;
//    int day, month, year;
//    cout << "������� ���� ��������: ";
//    cin >> day >> month >> year;
//
//
//    bool found = false;
//    if (fopen_s(&f, "var10n2.txt", "rb") == 0)//��������� ����
//    { 
//        for (int i = 0; i < current_citizens; i++)
//        {
//
//            if (day == listOfCitizens[i].BirthdayDate.day && month == listOfCitizens[i].BirthdayDate.month && year == listOfCitizens[i].BirthdayDate.year)
//            {
//                cout << "\n���:\t" << listOfCitizens[i].FIO.surname << ' ' << listOfCitizens[i].FIO.name << ' ' << listOfCitizens[i].FIO.partonymic << endl;
//                cout << "���� ��������:\t" << listOfCitizens[i].BirthdayDate.day << "." << listOfCitizens[i].BirthdayDate.month << "." << listOfCitizens[i].BirthdayDate.year << endl;
//                cout << "������:\t" << listOfCitizens[i].address << endl;
//                cout << "���:\t" << listOfCitizens[i].gender << endl;
//
//                found = true;
//            }
//        }
//    }
//
//    if (!found)
//    {
//        cout << "�� �������\n";
//    }
//    fclose(f);
//}
//
