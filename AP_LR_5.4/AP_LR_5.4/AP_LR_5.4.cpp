// Алгоритмізація та програмування
// Лабораторна робота № 5.4
// Мамчур Богдан Тарасович ІК-12
// Варіант 9

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double s1(const int K, int i, double t); // обчислення на рекурсивному спуску, параметр спадає
double s2(const int K, int i);           // обчислення на рекурсивному підйомі, параметр зростає
double s3(const int K, int i, double t); // обчислення на рекурсивному спуску, параметр зростає
double s4(const int K, int i);           // обчислення на рекурсивному підйомі, параметр спадає
double s5(const int K);                  // обчислення ітераційним способом

int main()
{
    const int K = 15; 

    cout << fixed << setprecision(5);
    
    // обчислення на рекурсивному спуску, параметр спадає
    cout << "Sposib 1:             " << s1(K, K, 0) << endl; 
    // обчислення на рекурсивному підйомі, параметр зростає
    cout << "Sposib 2:             " << s2(K, 1) << endl; 
    // обчислення на рекурсивному спуску, параметр зростає
    cout << "Sposib 3:             " << s3(K, 1, 0) << endl;
    // обчислення на рекурсивному підйомі, параметр спадає
    cout << "Sposib 4:             " << s4(K, K) << endl;
    // обчислення ітераційним способом
    cout << "Sposib 5 (iteration): " << s5(K) << endl;

    return 0;
}

// обчислення на рекурсивному спуску, параметр спадає 
double s1(const int K, int i, double t)
{
    t += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
    if (i <= 1)
        return t;
    else
        return s1(K, i - 1, t);
}

// обчислення на рекурсивному підйомі, параметр зростає
double s2(const int K, int i)
{
    if (i > K)
        return 0;
    else
        return (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i) + s2(K, i + 1);
}

// обчислення на рекурсивному спуску, параметр зростає
double s3(const int K, int i, double t)
{
    t += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
    if (i >= K)
        return t;
    else
        return s3(K, i + 1, t);
}

// обчислення на рекурсивному підйомі, параметр спадає
double s4(const int K, int i)
{
    if (i < 1)
        return 0;
    else
        return (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i) + s4(K, i - 1);
}

// 5. ітераційний спосіб (звичайний цикл від 1 до K)
double s5(const int K)
{
    double sum = 0;
    for (int i = 1; i <= K; i++)
    {
        sum += (sin(10.0 * i) + cos(10.0 / i)) / sqrt(i);
    }
    return sum;
}