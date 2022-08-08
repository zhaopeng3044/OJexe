// https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <chrono>
#include <algorithm>
using namespace std;

unsigned int string_to_int(const char *str);

void process_func(const int MAX_VALUE, int k);

void loop_find_solution(unsigned int n, unsigned int k);

int main(int argc, char *argv[])
{
    const unsigned int SIZE = string_to_int(argv[1]);
    const unsigned int k = string_to_int(argv[2]);

    // unsigned int SIZE = 957747794;
    // unsigned int k = 366107483;
    // process_func(SIZE, k);

    loop_find_solution(SIZE, k);

    return 0;
}

// current_value should be unsigned long long. when current_value * 10, int value may overflow
int mini_k_solution(unsigned long long current_value, unsigned int current_index, const unsigned int max_value, const unsigned int target_index)
{
    bool find = false;

    while (!find)
    {
        if (current_index == target_index)
        {
            break;
        }

        // first go deeper, unsigned int may be overflow, so current_value must be unsigned long long type
        if (current_value * 10 <= max_value)
        {
            current_value = current_value * 10;
            current_index++;
        }
        else
        {
            int max_index_step = (target_index - current_index);
            int last_value_step = 9 - (current_value % 10);
            int max_value_step = (max_value - current_value);

            int step = min(min(max_index_step, last_value_step), max_value_step);

            current_value += step;
            current_index += step;

            if (current_index == target_index)
            {
                find = true;
                break;
            }

            // go upper
            while (9 == (current_value % 10) || current_value + 1 > max_value)
            {
                current_value /= 10;
            }

            current_value++;
            current_index++;
        }
    }

    return (int)current_value;
}

void loop_find_solution(unsigned int n, unsigned int k)
{
    auto start = std::chrono::steady_clock::now();

    int result = mini_k_solution(1, 1, n, k);

    auto end = std::chrono::steady_clock::now();

    printf("%d; time consume %.3fs\n", result, (std::chrono::duration<double, std::milli>(end - start).count()) / 1000.0);
}

int str_compare(const void *p1, const void *p2)
{
    return strcmp((const char *)p1, (const char *)p2);
}

unsigned int string_to_int(const char *str)
{
    unsigned int sum = 0;
    int i = 0;

    while (str[i])
    {
        sum = (sum * 10) + (str[i] - '0');
        i++;
    }

    return sum;
}

int int_len(int value)
{
    int tmp = value;
    int len = 0;
    while (tmp)
    {
        len += 1;
        tmp /= 10;
    }

    return len;
}

void process_func(const int MAX_VALUE, int k)
{
    auto start = std::chrono::steady_clock::now();

    const int SIZE = MAX_VALUE;
    const int MAX_NUM_LEN = 11;

    char *p = new char[(unsigned int)(SIZE * MAX_NUM_LEN * sizeof(char))]();
    char(*parray)[MAX_NUM_LEN] = (char(*)[MAX_NUM_LEN])p;

    for (int i = 0; i < SIZE; i++)
    {
        int string_len = int_len(i + 1);

        for (int j = 0; j < string_len; j++)
        {
            parray[i][string_len - j - 1] = '0' + (((i + 1) / int(pow(10, j))) % 10);
        }

        parray[i][string_len] = 0;
    }

    qsort((void *)parray, SIZE, MAX_NUM_LEN * sizeof(char), str_compare);

    auto end = std::chrono::steady_clock::now();

    printf("%s; time consume %.3fs\n", parray[k - 1], (std::chrono::duration<double, std::milli>(end - start).count()) / 1000.0);
}