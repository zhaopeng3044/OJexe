// cf url: https://codeforces.com/contest/1029/problem/F
// 数论
// 质因数分解

#include <iostream>
#include <math.h>
#include <vector>
#include <tuple>

using namespace std;

unsigned long long f(unsigned long long a, unsigned long long b)
{
    unsigned long long area = a + b;
    vector<unsigned long long> v;

    for (unsigned long long x = sqrt(a); x > 0; x--)
    {
        if (0 == (a % x))
        {
            unsigned long long y = a / x;
            unsigned long long h = x > y ? x : y;
            unsigned long long w = x > y ? y : x;
            v.push_back(h);
            v.push_back(w);
        }
    }

    for (unsigned long long x = sqrt(b); x > 0; x--)
    {
        if (0 == (b % x))
        {
            unsigned long long y = b / x;
            unsigned long long h = x > y ? x : y;
            unsigned long long w = x > y ? y : x;

            v.push_back(h);
            v.push_back(w);
        }
    }

    for (unsigned long long x = sqrt(area); x > 0; x--)
    {
        if (0 == (area % x))
        {
            unsigned long long y = area / x;

            unsigned long long h = x > y ? x : y;
            unsigned long long w = x > y ? y : x;

            for (int i = 0; i < v.size(); i += 2)
            {
                unsigned long long minh = v[i];
                unsigned long long minw = v[i + 1];

                if (h >= minh && w >= minw)
                {
                    return (h + w) * 2;
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    unsigned long long a, b;
    while (cin >> a >> b)
    {
        cout << f(a, b) << endl;
    }
}