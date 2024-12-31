#include "stdafx.h"

using namespace std;

void findHoliday(int dayNumber, int monthNumber) {
    const char* holidayToday[] = { "My Birthday", "Defender of the Fatherland Day", "World Women's Day", "Valentine's Day", "Victory Day", "Independence day of the RB", "New Year" };

    if (dayNumber == 22 && monthNumber == 9)
        cout << holidayToday[0];
    else if (dayNumber == 23 && monthNumber == 2)
        cout << "\nToday is " << holidayToday[1];
    else if (dayNumber == 8 && monthNumber == 3)
        cout << "\nToday is " << holidayToday[2];
    else if (dayNumber == 14 && monthNumber == 2)
        cout << "\nToday is " << holidayToday[3];
    else if (dayNumber == 9 && monthNumber == 5)
        cout << "\nToday is " << holidayToday[4];
    else if (dayNumber == 3 && monthNumber == 7)
        cout << "\nToday is " << holidayToday[5];
    else if (dayNumber == 31 && monthNumber == 12)
        cout << "\nToday is " << holidayToday[6];
    else
        cout << "\nI was too lazy to write more holidays";
}