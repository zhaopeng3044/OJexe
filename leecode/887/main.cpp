#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
protected:
    static const int MAX_FLOOR = 10001;
    static const int MAX_EGG = 101;
    int result[MAX_FLOOR][MAX_EGG];

protected:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }

public:
    virtual int superEggDrop(int egg, int floor) = 0;
};

class Solution1 : public Solution
{
public:
    Solution1()
    {
        // 二分查找需要的鸡蛋数量，大于该数量的鸡蛋没有意义。
        int minimalResult[MAX_FLOOR] = {0, 1, 2, 2};

        for (int i = 4; i < MAX_FLOOR; i++)
        {
            int mid_index = (i + 1) / 2;

            minimalResult[i] = minimalResult[i - mid_index] + 1;
        }

        // 手动计算简单情况的最优解
        for (int i = 0; i < MAX_FLOOR; i++)
        {
            result[i][0] = 0;
            result[i][1] = i;
        }

        for (int i = 1; i < MAX_EGG; i++)
        {
            result[0][i] = 0;
            result[1][i] = 1;
            result[2][i] = 2;
        }

        // 填表
        for (int egg = 2; egg < MAX_EGG; egg++)
        {
            int last_floor = 2;

            for (int floor = 3; floor < MAX_FLOOR; floor++)
            {
                if (egg >= minimalResult[floor])
                {
                    result[floor][egg] = minimalResult[floor];
                }
                else
                {
                    int tmpResult = floor;
                    for (int f = last_floor; f <= (floor + 1) / 2; f++)
                    {
                        int tmp = max(result[f - 1][egg - 1], result[floor - f][egg]) + 1;
                        if (tmp <= tmpResult)
                        {
                            tmpResult = tmp;
                            last_floor = f;
                        }
                        else
                        {
                            break;
                        }
                    }

                    result[floor][egg] = tmpResult;
                }
            }
        }
    }

    int superEggDrop(int k, int n)
    {
        return result[n][k];
    }
};

class Solution2 : public Solution
{
public:
    Solution2()
    {
        // 填充-1标记位
        memset(result, -1, sizeof(int) * MAX_FLOOR * MAX_EGG);

        int minimalResult[MAX_FLOOR] = {0, 1, 2, 2};

        // 二分查找需要的鸡蛋数量，大于该数量的鸡蛋没有意义。
        for (int i = 4; i < MAX_FLOOR; i++)
        {
            int mid_index = (i + 1) / 2;

            minimalResult[i] = minimalResult[i - mid_index] + 1;

            for (int e = minimalResult[i]; e < MAX_EGG; e++)
            {
                result[i][e] = minimalResult[i];
            }
        }

        // 手动计算简单情况的最优解
        for (int i = 0; i < MAX_FLOOR; i++)
        {
            result[i][0] = 0;
            result[i][1] = i;
        }

        for (int i = 1; i < MAX_EGG; i++)
        {
            result[0][i] = 0;
            result[1][i] = 1;
            result[2][i] = 2;
        }
    }

    int superEggDrop(int k, int n)
    {
        if (result[n][k] != -1)
        {
            return result[n][k];
        }
        else
        {
            int r = n;
            for (int f = 2; f <= (n + 1) / 2; f++)
            {
                int tmp = max(superEggDrop(k - 1, f - 1), superEggDrop(k, n - f)) + 1;

                if (tmp <= r)
                {
                    r = tmp;
                }
                else
                {
                    break;
                }
            }
            result[n][k] = r;
            return r;
        }
    }
};

int main(int argc, char *argv[])
{
    int eggs, floor;

    Solution *s1 = new Solution1();
    Solution *s2 = new Solution2();

    cin >> eggs >> floor;

    cout << s1->superEggDrop(eggs, floor) << endl;
    cout << s2->superEggDrop(eggs, floor) << endl;

    delete s1;
    delete s2;
    return 0;
}
