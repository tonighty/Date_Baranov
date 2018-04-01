#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string>

class Date
{
  private:
	int day;
	int month;
	int year;
	static std::string dateFormat;
	bool IsLeapYear(int);
	bool IsCorrectDate(int, int, int);

  public:
	Date(int, int, int);
	Date(std::string);
	int GetYear();
	int GetMonth();
	int GetDay();
	void SetDate(int, int, int);
	void SetDate(std::string);
	std::string ToString();
	bool IsLeapYear();
	int DateToJDN();
	int GetDateDiff(Date *d2);
	int DateToJDNOfWeek();
	operator std::string();
	static void SetDateFormat(std::string str);
	friend std::ostream &operator<<(std::ostream &, Date &);
	friend std::istream &operator>>(std::istream &, Date &);
	static Date JDNToDate(int);
	friend const Date operator+(Date &, int);
	friend const Date operator-(Date &, int);
	Date &operator+=(int);
	Date &operator=(const Date &);
};

#endif // DATE_H_INCLUDED
