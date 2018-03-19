#include "Date.h"
#include <sstream>

std::string Date::dateFormat = "%d.%m.%y";

bool Date::IsLeapYear(int year)
{
	bool res = false;
	if (year % 4 == 0) res = true;
	if (year % 100 == 0) res = false;
	if (year % 400 == 0) res = true;
	return res;
}
bool Date::IsCorrectDate(int newDay, int newMonth, int newYear)
{
	if (newDay < 1 || newDay > 31)
	{
		throw "Incorrect day";
	}

	if (newMonth < 1 || newMonth > 12)
	{
		throw "Incorrect month";
	}

	if (newMonth == 2 && newDay > 29 - IsLeapYear(newYear))
	{
		throw "Incorrect february day";
	}

	if (newDay > 30 + (newMonth <= 7 ? newMonth % 2 : (newMonth + 1) % 2))
	{
		throw "Incorrect day";
	}
}
Date::Date(int newDay, int newMonth, int newYear)
{
	if (IsCorrectDate(newDay, newMonth, newYear))
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
}
Date::Date(std::string str)
{
	int flag = 0;
	int newDay;
	int newMonth;
	int newYear;
	for (unsigned int i = 0, j = 0; i < dateFormat.length(); i++, j++)
	{
		if (dateFormat[i] != '%') continue;
		i++;
		if (dateFormat[i] == 'd')
		{
			newDay = std::stoi(str.substr(j++, 2));
		}
		else if (dateFormat[i] == 'm')
		{
			newMonth = std::stoi(str.substr(j++, 2));
		}
		else if (dateFormat[i] == 'y')
		{
			newYear = std::stoi(str.substr(j, 4));
			j += 3;
		}
		else throw "String doesn't match Date Format";
	}
	if (IsCorrectDate(newDay, newMonth, newYear))
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
}
int Date::GetYear()
{
	return year;
}
int Date::GetMonth()
{
	return month;
}
int Date::GetDay()
{
	return day;
}
void Date::SetDate(int newDay, int newMonth, int newYear)
{
	if (Date::IsCorrectDate(newDay, newMonth, newYear))
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
}
std::string Date::ToString()
{
	std::stringstream str;
	int flag = 0;
	char c;
	for (unsigned int i = 0; i < dateFormat.length(); i++)
	{
		c = dateFormat[i];
		if (flag)
		{
			switch (c)
			{
				case 'd': str << day; break;
				case 'm': str << month; break;
				case 'y': str << year; break;
				default: throw "Incorrect Date Format";
			}
			flag = 0;
			continue;
		}
		if (c != '%')
		{
			str << c;
		}
		else
		{
			flag = 1;
		}
	}
	return str.str();
}
bool Date::IsLeapYear()
{
	return IsLeapYear(year);
}
int Date::GetDayNumber()
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
int Date::GetDateDiff(Date* d2)
{
	return this->GetDayNumber() - d2->GetDayNumber();
}
int Date::GetDayNumberOfWeek()
{
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}
Date::operator std::string()
{
	return Date::ToString();
}
void Date::SetDateFormat(std::string str)
{
	dateFormat = str;
}
std::ostream& operator <<(std::ostream& os, Date* d)
{
	return os << d->ToString();
}
Date* Date::JDNToDate(int days)
{
	int JDN = this->GetDayNumber() + days;
	int a = JDN + 32044;
	int b = (4 * a + 3) / 146097;
	int c = a - 146097 * b / 4;
	int d = (4 * c + 3) / 1461;
	int e = c - 1461 * d / 4;
	int m = (5 * e + 2) / 153;

	this->day = e - (153 * m + 2) / 5 + 1;
	this->month = m + 3 - 12 * (m / 10);
	this->year = 100 * b + d - 4800 + m / 10;

	return this;
}
Date* Date::Add(int days)
{
	return Date::JDNToDate(days);
}
Date* Date::Sub(int days)
{
	return Date::JDNToDate(-days);
}
Date* Date::operator+ (int days)
{
	return Add(days);
}
Date* Date::operator- (int days)
{
	return Date::Sub(days);
}
