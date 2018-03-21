#include <cxxtest/TestSuite.h>
#include "Date.h"

class DateTest : public CxxTest::TestSuite
{
  public:
	void testLeapYear(void)
	{
		TS_TRACE("Starting leap year test");
		Date *date = new Date(10, 10, 2000);
		for (int i = 0; i < 100; i += 4)
		{
			TS_ASSERT_EQUALS(date->IsLeapYear(), 1);
			date->SetDate(10, 10, 2000 + i);
		}
		for (int i = 0; i < 100; i += 4)
		{
			date->SetDate(10, 10, 2001 + i);
			TS_ASSERT_EQUALS(date->IsLeapYear(), 0);
		}
		date->SetDate(10, 10, 2010);
		TS_ASSERT_EQUALS(date->IsLeapYear(), 0);
		delete date;
		TS_TRACE("Finishing leap year test");
	}
	void testCorrectDate(void)
	{
		TS_TRACE("Starting correct date test");
		Date *date = new Date(1, 1, 1);
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(20, 13, 2010));
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(32, 1, 2010));
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(29, 2, 2010));
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(10, 20, 2010));
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(0, 0, 0));
		TS_ASSERT_THROWS_ANYTHING(date->SetDate(31, 4, 2010));
		delete date;
		TS_TRACE("Finishing correct date test");
	}
	void testStringConstructor(void)
	{
		TS_TRACE("Starting date string constructor test");
		Date::SetDateFormat("%d-%m-%y");
		TS_ASSERT_THROWS_ANYTHING(Date d("1-1-1990"));
		TS_ASSERT_THROWS_ANYTHING(Date d("12-13-1990"));
		TS_ASSERT_THROWS_ANYTHING(Date d("01-1990"));
		TS_ASSERT_THROWS_ANYTHING(Date d("1432-1-1990"));
		TS_ASSERT_THROWS_ANYTHING(Date d("90-90-90"));
		TS_ASSERT_THROWS_ANYTHING(Date d("11.11.2001"));
		TS_ASSERT_THROWS_ANYTHING(Date d(""));
		TS_ASSERT_THROWS_ANYTHING(Date d("bla bla bla"));
		Date::SetDateFormat("Month: %m Day: %d Year: %y");
		TS_ASSERT_THROWS_NOTHING(Date d("Month: 10 Day: 10 Year: 0101"));
		TS_ASSERT_THROWS_NOTHING(Date d("Month: 05 Day: 20 Year: 2050"));
		TS_ASSERT_THROWS_NOTHING(Date d("Month: 01 Day: 30 Year: 0001"));
		TS_TRACE("Finishing date string constructor test");
	}
	void testDateToJDN(void)
	{
		TS_TRACE("Starting get day number test");
		Date d(19, 03, 2018);
		for (int i = 1; i < 100; i++)
		{
			d += 1;
			TS_ASSERT_EQUALS(d.DateToJDN(), 2458197 + i);
		}
		TS_TRACE("Finishing get day number test");
	}
};
