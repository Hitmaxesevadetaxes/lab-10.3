#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 10.3\lab 10.3\source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int maxRecords = 5;
            PhoneRecord records[maxRecords];
            int recordCount = 0;

            // Add a new record
            records[recordCount].phoneNumber = 12;
            records[recordCount].roomNumber = 101;
            records[recordCount].employeeCount = 2;
            records[recordCount].employees[0] = "Alice";
            records[recordCount].employees[1] = "Bob";
            recordCount++;

            // Verify the added record
            Assert::AreEqual(12, records[0].phoneNumber);
            Assert::AreEqual(101, records[0].roomNumber);
            Assert::AreEqual(2, records[0].employeeCount);
            Assert::AreEqual(string("Alice"), records[0].employees[0]);
            Assert::AreEqual(string("Bob"), records[0].employees[1]);
        
		}
	};
}
