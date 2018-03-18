#include "Date.h"

int main()
{
	try {
		// Setting Date Format
		Date::SetDateFormat("NATA HUI: %d-%m-%y");

		// Default constructor
		Date* d = new Date(25,11,2020);

		// Create date from string acording to date format
		Date* dateFromString = new Date("NATA HUI: 15-11-1998");

		std::cout << "Convert date to string:" << std::endl;
		std::cout << d << std::endl;
		std::cout << dateFromString << std::endl;

		std::cout << "Check if year is leap:" << std::endl;
		std::cout << d->IsLeapYear() << std::endl;

		std::cout << "Calc date diff in days:" << std::endl;
		Date* d1 = new Date(12, 10, 2010);
		Date* d2 = new Date(2, 4, 2005);
		std::cout << d1->GetDateDiff(d2) << std::endl;

		std::cout << "Calc day number of week:" << std::endl;
		std::cout << d->GetDayNumberOfWeek() << std::endl;

		std::cout << "Add days" << std::endl;
		Date* d3 = new Date(17, 03, 2018);
		std::cout << *d3 + 3 << std::endl;
		int a;
		std::cin >> a;
	}
	catch (char const* str)
	{
		std::cout << str << std::endl;
		int a;
		std::cin >> a;
	}
    return 0;
}