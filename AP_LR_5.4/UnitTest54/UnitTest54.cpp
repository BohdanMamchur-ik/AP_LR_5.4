

#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_LR_5.4/AP_LR_5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
    TEST_CLASS(UnitTest54)
    {
    public:

        TEST_METHOD(TestRecursionAndIterationMatch)
        {
            const int K = 15;
            // отримання еталонного значення ітераційним способом
            double expected = s5(K);

            // перевірка збігу всіх чотирьох рекурсивних способів з ітераційним
            Assert::AreEqual(expected, s1(K, K, 0), 1e-6);
            Assert::AreEqual(expected, s2(K, 1), 1e-6);
            Assert::AreEqual(expected, s3(K, 1, 0), 1e-6);
            Assert::AreEqual(expected, s4(K, K), 1e-6);
        }

        TEST_METHOD(TestBaseCaseK1)
        {
            const int K = 1;
            // очікуване значення для i = 1: (sin(10) + cos(10)) / sqrt(1)
            double expected = sin(10.0) + cos(10.0);

            Assert::AreEqual(expected, s1(K, 1, 0), 1e-6);
            Assert::AreEqual(expected, s2(K, 1), 1e-6);
            Assert::AreEqual(expected, s3(K, 1, 0), 1e-6);
            Assert::AreEqual(expected, s4(K, 1), 1e-6);
            Assert::AreEqual(expected, s5(K), 1e-6);
        }
    };
}