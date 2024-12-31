#include <string>
#include <fstream>

using namespace std;

struct fullName
{
    string name;
    string surname;
    string partonymic;
};
struct Date
{
    unsigned int day : 5;   // 5 ��� ��� ������������� ��� (�������� �� 1 �� 31)
    unsigned int month : 4; // 4 ���� ��� ������������� ������ (�������� �� 1 �� 12)
    unsigned int year : 12; // 12 ��� ��� ������������� ���� (�������� �� 0 �� 4095)
};

struct Time
{
    unsigned int hours : 4;    // 1 - 12
    unsigned int minutes : 6;  // 1 - 60
};

#define cinIn(type, target) { type value; cin >> value; target = value; } // ������ ��� �������� ����� �������� �� ������ �����




//#define MAX_CARS 10
//
//void inputCars(); // ���� ���������� � �������
//void outputCars(); // ����� ���������� � �������
//void checkCarsByNumber(); // ����� ������ �� ������
//void deleteCars(); // �������� ������
//
//int currentCars = 0; // ������� ���������� ����� � ������
//
//
//enum brand
//{
//    Mercedes = 1, BMW, Porshe, Lotus, Koenigsegg, Lada, Lamborgini, McLaren, Ferrari, Ford, Wolkswagen, Opel, Nissan
//};
//
//
//struct Car
//{
//    brand brands; // ����� ����������
//    string color; // ���� ������
//    int number;   // ����� ����������
//    string bodyType; // ��� ������
//    string owner; // ��� ���������
//    Date date; // ���� �������
//    Date lastInspection; // ���� ���������� ������������ �������
//};
//
//Car listOfCars[MAX_CARS]; // ������ �������� Car ��� �������� ���������� � �������
//
//int var6n1()
//{
//    int choice;
//    do
//    {
//        cout << "1 - ���� ��������� ��������� � ����������" << endl;
//        cout << "2 - ����� ��������� ��������� � ���������� ����" << endl;
//        cout << "3 - ����� ������������ ������� �� ������" << endl;
//        cout << "4 - �������� ������ �� ������" << endl;
//        cout << "0 - ����� �� ���������" << endl;
//        cin >> choice; // ��������� ����� ������������
//
//        switch (choice)
//        {
//        case 1:
//            inputCars();
//            break;
//        case 2:
//            outputCars();
//            break;
//        case 3:
//            checkCarsByNumber();
//            break;
//        case 4:
//            deleteCars();
//            break;
//        case 0:
//            exit(0);
//            break;
//        default:
//            cout << "������������ ����!";
//            break;
//        }
//    } while (choice != 0);
//
//    return 0;
//}
//
//
//void inputCars()
//{
//    int numCars;
//    cout << "������� ���������� �����: ";
//    cin >> numCars; // ��������� ���������� �������
//
//    cin.ignore(); // ���������� ������ ����� ������ ����� ����� �����
//
//    for (int i = 0; i < numCars; i++)
//    {
//        if (currentCars < MAX_CARS)
//        {
//            cout << endl << "���� ������: ";
//            getline(cin, listOfCars[currentCars].color);
//
//            cout << "����� ����������: ";
//            cin >> listOfCars[currentCars].number;
//
//            cout << "������� ����� ����������(1 - Mercedes, 2 - BMW, 3 - Porsche � �.�.): ";
//            int BrandValue;
//            cin >> BrandValue;
//            listOfCars[currentCars].brands = static_cast<brand>(BrandValue);
//
//            cout << "���� �������: ";
//            cinIn(int, listOfCars[currentCars].date.day);
//          
//            cinIn(int, listOfCars[currentCars].date.month);           
//            cinIn(int, listOfCars[currentCars].date.year);
//
//            cout << "���� ���������� ���.�������: ";
//            cinIn(int, listOfCars[currentCars].lastInspection.day);
//            cinIn(int, listOfCars[currentCars].lastInspection.month);
//            cinIn(int, listOfCars[currentCars].lastInspection.year);
//
//            cin.ignore(); // ���������� ������ ����� ������ ����� ����� �������
//             
//            cout << "������� ��� ���������: ";
//            getline(cin,listOfCars[currentCars].owner);
//
//            cout << "��� ������: ";
//            getline(cin,listOfCars[currentCars].bodyType);
//            cout << endl;
//
//
//            currentCars++;
//        }
//    }
//}
//
//void outputCars()
//{
//    for (int i = 0; i < currentCars; i++)
//    {
//        cout << "\n���� ������: " << listOfCars[i].color << endl;
//        cout << "����� ����������: " << listOfCars[i].number << endl;
//        cout << "����� ����������: " << listOfCars[i].brands << endl;
//        cout << "���� �������: " << listOfCars[i].date.day << "." << listOfCars[i].date.month << "."  << listOfCars[i].date.year << endl;
//        cout << "���� ���������� ���.�������: " << listOfCars[i].lastInspection.day << "." << listOfCars[i].lastInspection.month << "."  << listOfCars[i].lastInspection.year << endl;
//        cout << "��� ���������: " << listOfCars[i].owner << endl;
//        cout << "��� ������: " << listOfCars[i].bodyType << endl;
//    }
//}
//
//void checkCarsByNumber()
//{
//    int number;
//    cout << "������� ����� ������: ";
//    cin >> number;
//
//    bool findCarWithThatNumber = false;
//    for (int i = 0; i < currentCars; i++)
//    {
//        if (number == listOfCars[i].number)
//        {
//            findCarWithThatNumber = true;
//            cout << "\n��������� ����������:";
//            cout << "\n���� ������: " << listOfCars[i].color << endl;
//            cout << "����� ����������: " << listOfCars[i].number << endl;
//            cout << "����� ����������: " << listOfCars[i].brands << endl;
//            cout << "���� �������: " << listOfCars[i].date.day << "." << listOfCars[i].date.month << "." << listOfCars[i].date.year << endl;
//            cout << "���� ���������� ���.�������: " << listOfCars[i].lastInspection.day << "." << listOfCars[i].lastInspection.month << "." << listOfCars[i].lastInspection.year << endl;
//            cout << "��� ���������: " << listOfCars[i].owner << endl;
//            cout << "��� ������: " << listOfCars[i].bodyType << endl;
//        }
//    }
//
//    if (!findCarWithThatNumber)
//    {
//        cout << "\n�� ������� ����� � ����� �������.";
//    }
//}
//
//void deleteCars()
//{
//    int number;
//    cout << "������� ����� ������ ��� ��������: ";
//    cin >> number;
//
//    bool findCarWithThatNumber = false;
//    for (int i = 0; i < currentCars; i++)
//    {
//        if (number == listOfCars[i].number)
//        {
//            findCarWithThatNumber = true;
//           
//            for (int j = i; j < currentCars - 1; j++)
//            {
//                listOfCars[j] = listOfCars[j + 1];
//            }
//            currentCars--;
//            cout << "\n���������� ������.\n";
//            break;
//        }
//    }
//
//    if (!findCarWithThatNumber)
//    {
//        cout << "\n�� ������� ����� � ����� �������.\n";
//    }
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
struct personnelDepartment
{
    fullName FIO;   // ���
    string education;  // �����������
    string speciality; // �������������
    string jobTitle;   // ���������
    int Salary;        // ����� (��������)
    Date inviteDate;   // ���� ����������� �� ������ - assuming it's a custom Date structure
};

void input(int size);
void output();
void findByJobTitle(string Title);

int var6n2()
{
    int choice, number;
    string Title;
    do
    {
        struct personnelDepartment
        {
            fullName FIO;   // �.I.�. (��-����������)
            string education;  // ��������
            string speciality; // �������������
            string jobTitle;   // ������
            int Salary;        // ����� (��������)
            Date inviteDate;   // ���� ���������� �� ����� - ������������, ��� ���� �������������� ��������� Date
        };

        void input(int size);
        void output();
        void findByJobTitle(string Title);

        int var6n2()
        {
            int choice, number;
            string Title;
            do
            {
                cout << "\n1. ���� �������� � ��������� � ���� � ����\n";
                cout << "2. ����� �������� � �����\n";
                cout << "3. ����� �� �������\n";
                cout << "0. ����� � ��������\n\n";
                cout << "������� ����� ��������: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "������� ��������� ��������: ";
                    cin >> number;
                    cin.ignore();
                    input(number);
                    break;

                case 2:
                    output();
                    break;

                case 3:

                    cout << "������� ������: ";
                    getline(cin, Title);
                    findByJobTitle(Title);
                    break;

                case 0:
                    exit(0);
                    break;

                default:
                    cout << "���������� ����. ��� �����, �������� ������������ ��������." << endl;
                    break;
                }
            } while (choice != 0);

            return 0;
        }

        void input(int size)
        {
            FILE* f;
            personnelDepartment buf;

            if (fopen_s(&f, "base.txt", "ab+") == 0) // ��������� ���� � ������ ���������/������� � ������� ������
            {
                for (int p = 0; p < size; p++)
                {
                    cout << "�.�.�.: ";
                    getline(cin, buf.FIO.name);
                    getline(cin, buf.FIO.surname);
                    getline(cin, buf.FIO.partonymic);

                    cout << "��������: ";
                    getline(cin, buf.education);
                    cout << "�������������: ";
                    getline(cin, buf.speciality);
                    cout << "������: ";
                    getline(cin, buf.jobTitle);
                    cout << "������: ";
                    cin >> buf.Salary;
                    cout << "���� ����������:";
                    cinIn(int, buf.inviteDate.day);
                    cinIn(int, buf.inviteDate.month);
                    cinIn(int, buf.inviteDate.year);

                    fwrite(&buf, sizeof(buf), 1, f); // �������� ��������� � ����
                }

                fclose(f);
            }
            else
            {
                cout << "������� �������� �����";
                return;
            }
        }

        void output()
        {
            FILE* f;
            personnelDepartment buf;

            if (fopen_s(&f, "base.txt", "rb") == 0) // ��������� ���� � ������ ������� � ������� ������
            {
                cout << "\n�.�.�.\t\t��������\t�������������\t������\t������\t���� ����������\n";
                fread(&buf, sizeof(buf), 1, f); // ������ ��������� � �����

                while (!feof(f))
                {
                    cout << buf.FIO.name << ' ' << buf.FIO.surname << ' ' << buf.FIO.partonymic << "  " << buf.education << "  " << buf.speciality << "  " << buf.jobTitle << "  " << buf.Salary << "  " << buf.inviteDate.day << '.' << buf.inviteDate.month << '.' << buf.inviteDate.year << endl;
                    fread(&buf, sizeof(buf), 1, f); // ������ ��������� ��������� � �����
                }

                cout << endl;
                fclose(f);
            }
            else
            {
                cout << "������� �������� �����";
                return;
            }
        }

        void findByJobTitle(string Title)
        {
            FILE* f;
            personnelDepartment buf;
            bool found = false;

            if (fopen_s(&f, "base.txt", "rb") == 0) // ��������� ���� � ������ ������� � ������� ������
            {
                while (fread(&buf, sizeof(buf), 1, f) == 1)
                {
                    if (buf.jobTitle == Title)
                    {
                        cout << "\n�.�.�.\t\t��������\t�������������\t������\t������\t���� ����������\n";
                        cout << buf.FIO.name << ' ' << buf.FIO.surname << ' ' << buf.FIO.partonymic << "  " << buf.education << "  " << buf.speciality << "  " << buf.jobTitle << "  " << buf.Salary << "  " << buf.inviteDate.day << '.' << buf.inviteDate.month << '.' << buf.inviteDate.year << endl;
                        found = true;
                    }
                }

                fclose(f);

                if (!found)
                    cout << "�� ���������\n";
            }
            else
            {
                cout << "������� �������� �����";
                return;
            }
        }