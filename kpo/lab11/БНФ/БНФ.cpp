#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool checkEightNumber(string& input)
{
	regex pattern("[0-7]+$");
	return regex_match(input, pattern);
}

int main() 
{
	setlocale(0, "");

	//  <целое_число> : = <цифра_восьмеричная> | <цифра_восьмеричная> <цифра_восьмеричная>*
	//	<цифра_восьмеричная> : = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7

	string firstInput = "1206732";	
	string secondInput = "511824";
	string thirdInput = "125549";

	cout << boolalpha; 

	cout << checkEightNumber(firstInput) << '\n';
	cout << checkEightNumber(secondInput) << '\n';
	cout << checkEightNumber(thirdInput) << '\n';


	//	<выражение> :: = <терм> | <выражение> <оператор> <терм>
	//	<терм> :: = <идентификатор> | <константа> | (<выражение>)
	//	< идентификатор > :: = <буква> <символ_идентификатор>*
	//	<константа> :: = <число> | <строка> | <логическая_константа>
	//	<оператор> :: = +| -| *| / | = | < | > | <= | >= | == | !=
	//	<буква> :: = a | b | c | ... | x | y | z | A | B | C | ... | X | Y | Z | _
	//	<символ_идентификатор> :: = <буква> | <цифра>
	//	<число> :: = <целое_число> | <вещественное_число>
	//	<строка> :: = "<любой_текст>"
	//	< логическая_константа > :: = true | false
	//	<цифра> :: = 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9

	return 0;
}