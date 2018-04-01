#include "Date.h"
#include <sstream>

std::string Date::dateFormat = "%d.%m.%y";

bool Date::IsLeapYear(int year)
{
	bool res = false;
	if (year % 4 == 0)
		res = true;
	if (year % 100 == 0)
		res = false;
	if (year % 400 == 0)
		res = true;
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

	if (newMonth == 2 && newDay > 28 + IsLeapYear(newYear))
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
		if (dateFormat[i] != '%')
		{
			if (dateFormat[i] != str[j])
				throw "String doesn't match date format";
			continue;
		}
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
		else
			throw "String doesn't match Date Format";
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
	if (IsCorrectDate(newDay, newMonth, newYear))
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
}
void Date::SetDate(std::string str)
{
	int flag = 0;
	int newDay;
	int newMonth;
	int newYear;
	for (unsigned int i = 0, j = 0; i < dateFormat.length(); i++, j++)
	{
		if (dateFormat[i] != '%')
		{
			if (dateFormat[i] != str[j])
				throw "String doesn't match date format";
			continue;
		}
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
		else
			throw "String doesn't match Date Format";
	}
	if (IsCorrectDate(newDay, newMonth, newYear))
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
			case 'd':
				str << (day < 10 ? "0" : "") << day;
				break;
			case 'm':
				str << (month < 10 ? "0" : "") << month;
				break;
			case 'y':
				str << (year < 10 ? "000" : year < 100 ? "00" : year < 1000 ? "0" : "") << year;
				break;
			default:
				throw "Incorrect Date Format";
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
int Date::DateToJDN()
{
	int a = (14 - month) / 12;
	int y = year + 4800 - a;
	int m = month + 12 * a - 3;
	return day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}
int Date::GetDateDiff(Date *d2)
{
	return this->DateToJDN() - d2->DateToJDN();
}
int Date::DateToJDNOfWeek()
{
	return DateToJDN() % 7;
}
Date::operator std::string()
{
	return ToString();
}
void Date::SetDateFormat(std::string str)
{
	dateFormat = str;
}
std::ostream &operator<<(std::ostream &os, Date &d)
{
	return os << d.ToString();
}
std::istream &operator>>(std::istream &is, Date &d)
{
	std::string str;
	is >> str;
	d.SetDate(str);
	return is;
}
Date Date::JDNToDate(int days)
{
	int JDN = days;
	int a = JDN + 32044;
	int b = (4 * a + 3) / 146097;
	int c = a - 146097 * b / 4;
	int d = (4 * c + 3) / 1461;
	int e = c - 1461 * d / 4;
	int m = (5 * e + 2) / 153;

	int day = e - (153 * m + 2) / 5 + 1;
	int month = m + 3 - 12 * (m / 10);
	int year = 100 * b + d - 4800 + m / 10;

	return Date(day, month, year);
}
const Date operator+(Date &d, int days)
{
	return Date::JDNToDate(d.DateToJDN() + days);
}
const Date operator-(Date &d, int days)
{
	return Date::JDNToDate(d.DateToJDN() - days);
}
Date &Date::operator+=(int days)
{
	return *this = *this + days;
}
Date &Date::operator=(const Date &d)
{
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;

	return *this;
}