/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_DateTest_init = false;
#include "C:\Users\132\Desktop\baranov_labs\1.1\DateTest.h"

static DateTest suite_DateTest;

static CxxTest::List Tests_DateTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_DateTest( "DateTest.h", 4, "DateTest", suite_DateTest, Tests_DateTest );

static class TestDescription_suite_DateTest_testLeapYear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DateTest_testLeapYear() : CxxTest::RealTestDescription( Tests_DateTest, suiteDescription_DateTest, 7, "testLeapYear" ) {}
 void runTest() { suite_DateTest.testLeapYear(); }
} testDescription_suite_DateTest_testLeapYear;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
