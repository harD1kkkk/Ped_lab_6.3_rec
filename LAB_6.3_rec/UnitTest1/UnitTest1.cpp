#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_6.3_rec/lab_6.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_CountEvenElements)
        {
            const int n = 6;
            int a[n] = { 1, 2, 3, 4, 5, 6 };

            int result1 = CountEvenElements(a, n, 0);
            Assert::AreEqual(3, result1); 

            int result2 = CountEvenElements<int>(a, n, 0);
            Assert::AreEqual(3, result2); 
        }
    };
}
