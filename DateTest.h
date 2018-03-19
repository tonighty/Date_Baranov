#include <cxxtest/TestSuite.h>
#include "Date.h"

class DateTest : public CxxTest::TestSuite
{
public:
    void testLeapYear(void)
    {
		TS_TRACE("Starting leap year test");
        TS_ASSERT_EQUALS((Date d1(20,10,2010)).IsLeapYear(), 1);
		TS_ASSERT_EQUALS((Date d2(20,10,1010)).IsLeapYear(), 1);
    }
};
