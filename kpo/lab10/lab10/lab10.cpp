#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	setlocale(0, "");
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	int target1 = 3;
	int num_items1 = count(v.begin(), v.end(), target1);

	cout << "Число: " << target1 << " количество: " << num_items1 << '\n';

	int num_items3 = count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "Количество элементов, кратных 3: " << num_items3 << '\n';
	cout << endl << "Лямбда, захват переменных" << endl;

	for (auto i : v)[i]()
	{
		if (i % 3 == 0)
		{
			cout << i << ' ';
		}
	}();

	cout << endl << "Лямбда с параметрами" << endl;

	for (auto i : v)[](auto i)
	{
		if (i % 3 == 0)
		{
			cout << i << ' ';
		}
	}(i);

	cout << endl << "Лямбда без параметров" << endl;

	for (auto i : v)[i]
	{
		if (i % 3 == 0)
		{
			cout << i << ' ';
		}
	}();



	//Дополнительное задание №3
	string a = "\nSweety";
	string b = " juice";
	cout << endl << "Лямбда-конкатенация" << endl;
	cout << [](auto firstWord, auto secondWord) ->string {
		return firstWord + secondWord;
		} (a, b) << '\n';
}