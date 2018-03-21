/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
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

static class TestDescription_suite_DateTest_testCorrectDate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DateTest_testCorrectDate() : CxxTest::RealTestDescription( Tests_DateTest, suiteDescription_DateTest, 26, "testCorrectDate" ) {}
 void runTest() { suite_DateTest.testCorrectDate(); }
} testDescription_suite_DateTest_testCorrectDate;

static class TestDescription_suite_DateTest_testStringConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DateTest_testStringConstructor() : CxxTest::RealTestDescription( Tests_DateTest, suiteDescription_DateTest, 39, "testStringConstructor" ) {}
 void runTest() { suite_DateTest.testStringConstructor(); }
} testDescription_suite_DateTest_testStringConstructor;

static class TestDescription_suite_DateTest_testDateToJDN : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_DateTest_testDateToJDN() : CxxTest::RealTestDescription( Tests_DateTest, suiteDescription_DateTest, 57, "testDateToJDN" ) {}
 void runTest() { suite_DateTest.testDateToJDN(); }
} testDescription_suite_DateTest_testDateToJDN;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
