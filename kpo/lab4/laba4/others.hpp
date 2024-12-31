#include <string>

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
	day dd;
	month mm;
	year yyyy;
};


//bool operator<(const Date& lhs, const Date& rhs)
//{
//	return (lhs.yyyy < rhs.yyyy) || (lhs.yyyy == rhs.yyyy && lhs.mm < rhs.mm) || (lhs.yyyy == rhs.yyyy && lhs.mm == rhs.mm && lhs.dd < rhs.dd);
//}
//
//bool operator>(const Date& lhs, const Date& rhs)
//{
//	return rhs < lhs;
//}
//
//bool operator==(const Date& lhs, const Date& rhs)
//{
//	return lhs.dd == rhs.dd && lhs.mm == rhs.mm && lhs.yyyy == rhs.yyyy;
//}
//



//void number1()
//{
//	Date date1 = { 7,1,1980 };
//	Date date2 = { 7,2,1993 };
//	Date date3 = { 7,1,1980 };
//
//	if (date1 < date2)
//	{
//		std::cout << "True\n";
//	}
//	else
//	{
//		std::cout << "False\n";
//	}
//
//	if (date1 > date2)
//	{
//		std::cout << "True\n";
//	}
//	else
//	{
//		std::cout << "False\n";
//	}
//
//	if (date1 == date2)
//	{
//		std::cout << "True\n";
//	}
//	else
//	{
//		std::cout << "False\n";
//	}
//
//	if (date1 == date3)
//	{
//		std::cout << "True\n";
//	}
//	else
//	{
//		std::cout << "False\n";
//	}
//}

typedef unsigned int age;
typedef float GradePointAverage;


struct FullNameStudent
{
	std::string name;
	std::string surname;
	std::string phonetic;
};



struct Student
{
	FullNameStudent FullNameStudent;
	age nnn;
	std::string gender;
	GradePointAverage bb;
};


bool correctStudent(const Student& student)
{
	if (student.nnn > 110 || student.nnn <= 0)
	{
		std::cout << "Incorrect age!";
		return false;
	}
	if (student.gender != "male" && student.gender != "female")
	{
		std::cout << "Incorrect gender!";
		return false;
	}
	if (student.bb > 10.0 || student.bb < 2.0)
	{
		std::cout << "Incorrect GPA!";
		return false;
	}
	return true;
}


void number6()
{
	Student student;
	student.FullNameStudent.name = "Vladislav";
	student.FullNameStudent.surname = "Luzhetski";
	student.FullNameStudent.phonetic = "Konstantinovich";
	student.nnn = 18;
	student.gender = "male";
	student.bb = 8.2;

	Student student1;
	student1.FullNameStudent.name = "Danila";
	student1.FullNameStudent.surname = "Mironov";
	student1.FullNameStudent.phonetic = "Aleksandrovich";
	student1.nnn = 19;
	student1.gender = "male";
	student1.bb = 9.3;

	if (!correctStudent(student))
		return;
	if (!correctStudent(student1))
		return;

	std::cout << "Student`s full name:  " << student.FullNameStudent.surname << ' ' << student.FullNameStudent.name << ' ' << student.FullNameStudent.phonetic << '\n';
	std::cout << "Full years:           " << student.nnn << '\n';
	std::cout << "Student`s gender:     " << student.gender << '\n';
	std::cout << "Student`s GPA:        " << student.bb << '\n';

	std::cout << std::endl;

	std::cout << "Student`s full name:  " << student1.FullNameStudent.surname << ' ' << student1.FullNameStudent.name << ' ' << student1.FullNameStudent.phonetic << '\n';
	std::cout << "Full years:           " << student1.nnn << '\n';
	std::cout << "Student`s gender:     " << student1.gender << '\n';
	std::cout << "Student`s GPA:        " << student1.bb << '\n';



	if (student.nnn > student1.nnn)
		std::cout << "\nStudent " << student.FullNameStudent.name << " is older than student " << student1.FullNameStudent.name;
	else if(student.nnn < student1.nnn)
		std::cout << "\nStudent " << student.FullNameStudent.name << " is younger than student " << student1.FullNameStudent.name;
	else
		std::cout << "\nStudent" << student.FullNameStudent.name << " and " << student1.FullNameStudent.name << "have the same age";

	if (student.gender == student1.gender)
		std::cout << "\nSame sex students";
	else
		std::cout << "\nStudents of different genders";
}