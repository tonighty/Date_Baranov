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
    std::string ToString();
    bool IsLeapYear();
    int GetDayNumber();
    int GetDateDiff(Date* d2);
    int GetDayNumberOfWeek();
    operator std::string();
    static void SetDateFormat(std::string str);
    friend std::ostream& operator<< (std::ostream&, Date*);
    Date* JDNToDate(int);
    Date* Add(int);
    Date* Sub(int);
    Date* operator+ (int);
    Date* operator- (int);
};

#endif // DATE_H_INCLUDED
