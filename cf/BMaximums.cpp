// cf url: http://codeforces.com/problemset/problem/1326/B
// 模拟题

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int array_a[200000];
    int array_b[200000];

    int array_len;
    while (cin >> array_len)
    {
        for (int i = 0; i < array_len; i++)
        {
            cin >> array_b[i];
        }

        int max_value = 0;
        array_a[0] = array_b[0];

        for (int j = 1; j < array_len; j++)
        {
            if (array_a[j - 1] > max_value)
            {
                max_value = array_a[j - 1];
            }
            array_a[j] = array_b[j] + max_value;
        }

        for (int k = 0; k < array_len; k++)
        {
            cout << array_a[k] << " ";
        }

        cout << "\n";
    }
}