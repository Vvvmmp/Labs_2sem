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
    unsigned int day : 5;   // 5 бит для представления дня (значения от 1 до 31)
    unsigned int month : 4; // 4 бита для представления месяца (значения от 1 до 12)
    unsigned int year : 12; // 12 бит для представления года (значения от 0 до 4095)
};

struct Time
{
    unsigned int hours : 4;    // 1 - 12
    unsigned int minutes : 6;  // 1 - 60
};

#define cinIn(type, target) { type value; cin >> value; target = value; } // Макрос для удобного ввода значения из потока ввода




//#define MAX_CARS 10
//
//void inputCars(); // Ввод информации о машинах
//void outputCars(); // Вывод информации о машинах
//void checkCarsByNumber(); // Поиск машины по номеру
//void deleteCars(); // Удаление машины
//
//int currentCars = 0; // Текущее количество машин в списке
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
//    brand brands; // Марка автомобиля
//    string color; // Цвет машины
//    int number;   // Номер автомобиля
//    string bodyType; // Тип кузова
//    string owner; // Имя владельца
//    Date date; // Дата выпуска
//    Date lastInspection; // Дата последнего технического осмотра
//};
//
//Car listOfCars[MAX_CARS]; // Массив структур Car для хранения информации о машинах
//
//int var6n1()
//{
//    int choice;
//    do
//    {
//        cout << "1 - Ввод элементов структуры с клавиатуры" << endl;
//        cout << "2 - Вывод элементов структуры в консольное окно" << endl;
//        cout << "3 - Выбор транспортных средств по номеру" << endl;
//        cout << "4 - Удаление машины из списка" << endl;
//        cout << "0 - Выход из программы" << endl;
//        cin >> choice; // Считываем выбор пользователя
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
//            cout << "Некорректный ввод!";
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
//    cout << "Введите количество машин: ";
//    cin >> numCars; // Считываем количество поездов
//
//    cin.ignore(); // Игнорируем символ новой строки после ввода числа
//
//    for (int i = 0; i < numCars; i++)
//    {
//        if (currentCars < MAX_CARS)
//        {
//            cout << endl << "Цвет машины: ";
//            getline(cin, listOfCars[currentCars].color);
//
//            cout << "Номер автомобиля: ";
//            cin >> listOfCars[currentCars].number;
//
//            cout << "Введите марку автомобиля(1 - Mercedes, 2 - BMW, 3 - Porsche и т.д.): ";
//            int BrandValue;
//            cin >> BrandValue;
//            listOfCars[currentCars].brands = static_cast<brand>(BrandValue);
//
//            cout << "Дата выпуска: ";
//            cinIn(int, listOfCars[currentCars].date.day);
//          
//            cinIn(int, listOfCars[currentCars].date.month);           
//            cinIn(int, listOfCars[currentCars].date.year);
//
//            cout << "Дата последнего тех.осмотра: ";
//            cinIn(int, listOfCars[currentCars].lastInspection.day);
//            cinIn(int, listOfCars[currentCars].lastInspection.month);
//            cinIn(int, listOfCars[currentCars].lastInspection.year);
//
//            cin.ignore(); // Игнорируем символ новой строки после ввода времени
//             
//            cout << "Введите имя владельца: ";
//            getline(cin,listOfCars[currentCars].owner);
//
//            cout << "Тип кузова: ";
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
//        cout << "\nЦвет машины: " << listOfCars[i].color << endl;
//        cout << "Номер автомобиля: " << listOfCars[i].number << endl;
//        cout << "Марка автомобиля: " << listOfCars[i].brands << endl;
//        cout << "Дата выпуска: " << listOfCars[i].date.day << "." << listOfCars[i].date.month << "."  << listOfCars[i].date.year << endl;
//        cout << "Дата последнего тех.осмотра: " << listOfCars[i].lastInspection.day << "." << listOfCars[i].lastInspection.month << "."  << listOfCars[i].lastInspection.year << endl;
//        cout << "Имя владельца: " << listOfCars[i].owner << endl;
//        cout << "Тип кузова: " << listOfCars[i].bodyType << endl;
//    }
//}
//
//void checkCarsByNumber()
//{
//    int number;
//    cout << "Введите номер машины: ";
//    cin >> number;
//
//    bool findCarWithThatNumber = false;
//    for (int i = 0; i < currentCars; i++)
//    {
//        if (number == listOfCars[i].number)
//        {
//            findCarWithThatNumber = true;
//            cout << "\nНайденный автомобиль:";
//            cout << "\nЦвет машины: " << listOfCars[i].color << endl;
//            cout << "Номер автомобиля: " << listOfCars[i].number << endl;
//            cout << "Марка автомобиля: " << listOfCars[i].brands << endl;
//            cout << "Дата выпуска: " << listOfCars[i].date.day << "." << listOfCars[i].date.month << "." << listOfCars[i].date.year << endl;
//            cout << "Дата последнего тех.осмотра: " << listOfCars[i].lastInspection.day << "." << listOfCars[i].lastInspection.month << "." << listOfCars[i].lastInspection.year << endl;
//            cout << "Имя владельца: " << listOfCars[i].owner << endl;
//            cout << "Тип кузова: " << listOfCars[i].bodyType << endl;
//        }
//    }
//
//    if (!findCarWithThatNumber)
//    {
//        cout << "\nНе найдено машин с таким номером.";
//    }
//}
//
//void deleteCars()
//{
//    int number;
//    cout << "Введите номер машины для удаления: ";
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
//            cout << "\nАвтомобиль удален.\n";
//            break;
//        }
//    }
//
//    if (!findCarWithThatNumber)
//    {
//        cout << "\nНе найдено машин с таким номером.\n";
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
    fullName FIO;   // фио
    string education;  // образование
    string speciality; // специальность
    string jobTitle;   // должность
    int Salary;        // оклад (зарплата)
    Date inviteDate;   // дата приглашения на работу - assuming it's a custom Date structure
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
            fullName FIO;   // П.I.Б. (по-белорусски)
            string education;  // адукацыя
            string speciality; // спецыяльнасць
            string jobTitle;   // пасада
            int Salary;        // аклад (зарплата)
            Date inviteDate;   // дата запрашэння на працу - прадпалягаем, што гэта карыстальніцкая структура Date
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
                cout << "\n1. Увод дадзеных з клавіятуры і запіс у файл\n";
                cout << "2. Вывод дадзеных з файла\n";
                cout << "3. Пошук па пасадзе\n";
                cout << "0. Выхад з праграмы\n\n";
                cout << "Увядзіце нумар аперацыі: ";
                cin >> choice;

                switch (choice)
                {
                case 1:
                    cout << "Увядзіце колькасць работнікаў: ";
                    cin >> number;
                    cin.ignore();
                    input(number);
                    break;

                case 2:
                    output();
                    break;

                case 3:

                    cout << "Увядзіце пасаду: ";
                    getline(cin, Title);
                    findByJobTitle(Title);
                    break;

                case 0:
                    exit(0);
                    break;

                default:
                    cout << "Некарэктны ўвод. Калі ласка, выберыце дапушчальную аперацыю." << endl;
                    break;
                }
            } while (choice != 0);

            return 0;
        }

        void input(int size)
        {
            FILE* f;
            personnelDepartment buf;

            if (fopen_s(&f, "base.txt", "ab+") == 0) // Адкрыўаем файл у рэжыме дадавання/чытання ў двайным рэжыме
            {
                for (int p = 0; p < size; p++)
                {
                    cout << "П.І.Б.: ";
                    getline(cin, buf.FIO.name);
                    getline(cin, buf.FIO.surname);
                    getline(cin, buf.FIO.partonymic);

                    cout << "Адукацыя: ";
                    getline(cin, buf.education);
                    cout << "Спецыяльнасць: ";
                    getline(cin, buf.speciality);
                    cout << "Пасада: ";
                    getline(cin, buf.jobTitle);
                    cout << "Аклада: ";
                    cin >> buf.Salary;
                    cout << "Дата запрашэння:";
                    cinIn(int, buf.inviteDate.day);
                    cinIn(int, buf.inviteDate.month);
                    cinIn(int, buf.inviteDate.year);

                    fwrite(&buf, sizeof(buf), 1, f); // Запісваем структуру ў файл
                }

                fclose(f);
            }
            else
            {
                cout << "Памылка адкрыцця файла";
                return;
            }
        }

        void output()
        {
            FILE* f;
            personnelDepartment buf;

            if (fopen_s(&f, "base.txt", "rb") == 0) // Адкрыўаем файл у рэжыме чытання ў двайным рэжыме
            {
                cout << "\nП.І.Б.\t\tАдукацыя\tСпецыяльнасць\tПасада\tАклада\tДата запрашэння\n";
                fread(&buf, sizeof(buf), 1, f); // Чытаем структуру з файла

                while (!feof(f))
                {
                    cout << buf.FIO.name << ' ' << buf.FIO.surname << ' ' << buf.FIO.partonymic << "  " << buf.education << "  " << buf.speciality << "  " << buf.jobTitle << "  " << buf.Salary << "  " << buf.inviteDate.day << '.' << buf.inviteDate.month << '.' << buf.inviteDate.year << endl;
                    fread(&buf, sizeof(buf), 1, f); // Чытаем наступную структуру з файла
                }

                cout << endl;
                fclose(f);
            }
            else
            {
                cout << "Памылка адкрыцця файла";
                return;
            }
        }

        void findByJobTitle(string Title)
        {
            FILE* f;
            personnelDepartment buf;
            bool found = false;

            if (fopen_s(&f, "base.txt", "rb") == 0) // Адкрыўаем файл у рэжыме чытання ў двайным рэжыме
            {
                while (fread(&buf, sizeof(buf), 1, f) == 1)
                {
                    if (buf.jobTitle == Title)
                    {
                        cout << "\nП.І.Б.\t\tАдукацыя\tСпецыяльнасць\tПасада\tАклада\tДата запрашэння\n";
                        cout << buf.FIO.name << ' ' << buf.FIO.surname << ' ' << buf.FIO.partonymic << "  " << buf.education << "  " << buf.speciality << "  " << buf.jobTitle << "  " << buf.Salary << "  " << buf.inviteDate.day << '.' << buf.inviteDate.month << '.' << buf.inviteDate.year << endl;
                        found = true;
                    }
                }

                fclose(f);

                if (!found)
                    cout << "Не знойдзена\n";
            }
            else
            {
                cout << "Памылка адкрыцця файла";
                return;
            }
        }