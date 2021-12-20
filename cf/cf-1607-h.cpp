#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

/*
problem url: https://codeforces.com/problemset/problem/1607/H
*/

class BanquetEntry
{
private:
    int disk_a;
    int disk_b;
    int to_eat;

    int total_left;
    int disk_a_min;
    int disk_a_max;

    int eat_disk_a;
    int eat_disk_b;

public:
    BanquetEntry();
    BanquetEntry(int a, int b, int to_eat);
    ~BanquetEntry();

    void reset(int a, int b, int to_eat);
    void print();

    int get_total_grams();
    int get_max_disk_a();
    int get_min_disk_a();

    void set_target_a(int a);
};

void BanquetEntry::set_target_a(int a)
{
    this->eat_disk_a = this->disk_a - a;
    this->eat_disk_b = this->to_eat - this->eat_disk_a;
}

BanquetEntry::BanquetEntry()
{
}

BanquetEntry::BanquetEntry(int a, int b, int to_eat)
{
    this->reset(a, b, to_eat);
}

BanquetEntry::~BanquetEntry()
{
}

void BanquetEntry::reset(int a, int b, int to_eat)
{
    this->disk_a = a;
    this->disk_b = b;
    this->to_eat = to_eat;

    this->total_left = a + b - to_eat;
    this->disk_a_min = max(a - to_eat, 0);
    this->disk_a_max = a + min(b, to_eat) - to_eat;
    this->eat_disk_a = -1;
    this->eat_disk_b = -1;
}

void BanquetEntry::print()
{
    printf("%d %d\n", this->eat_disk_a, this->eat_disk_b);
}

int BanquetEntry::get_total_grams()
{
    return this->total_left;
}

int BanquetEntry::get_min_disk_a()
{
    return this->disk_a_min;
}

int BanquetEntry::get_max_disk_a()
{
    return this->disk_a_max;
}

bool compare_banquet_pointer(BanquetEntry *p1, BanquetEntry *p2)
{
    if(p1->get_total_grams() != p2->get_total_grams())
    {
        return p1->get_total_grams() < p2->get_total_grams();
    }
    else
    {
        if(p1->get_min_disk_a() != p2->get_min_disk_a())
        {
            return p1->get_min_disk_a() < p2->get_min_disk_a();
        }
        else
        {
            return p1->get_max_disk_a() > p2->get_max_disk_a();
        }
    }
}

int main(int argc, char *argv[])
{
    // init test number
    int test_number;
    scanf("%d", &test_number);

    const int max_disk_number = 200000;

    BanquetEntry *banquet_array = new BanquetEntry[max_disk_number];
    BanquetEntry *banquet_parray[max_disk_number];

    int n;
    for (int i = 0; i < test_number; i++)
    {
        // init disk number
        scanf("%d", &n);

        for (int j = 0; j < n; j++)
        {
            int a, b, m;
            scanf("%d %d %d", &a, &b, &m);

            banquet_array[j].reset(a, b, m);
            banquet_parray[j] = banquet_array + j;
        }

        sort(banquet_parray, banquet_parray + n, compare_banquet_pointer);

        int group_number = 1;
        int group_start = 0;

        int min_disk_a = banquet_parray[0]->get_min_disk_a();
        int max_disk_a = banquet_parray[0]->get_max_disk_a();

        for(int j=1; j<n; j++)
        {
            if(banquet_parray[j-1]->get_total_grams() != banquet_parray[j]->get_total_grams() || max_disk_a < banquet_parray[j]->get_min_disk_a())
            {
                // process last group data
                for(int k=group_start; k<j; k++)
                {
                    banquet_parray[k]->set_target_a(min_disk_a);
                }

                // create new group setting
                group_number += 1;
                group_start = j;

                min_disk_a = banquet_parray[j]->get_min_disk_a();
                max_disk_a = banquet_parray[j]->get_max_disk_a();
            }
            else
            {
                min_disk_a = max(min_disk_a, banquet_parray[j]->get_min_disk_a());
                max_disk_a = min(max_disk_a, banquet_parray[j]->get_max_disk_a());
            }
        }

        for(int k=group_start; k<n; k++)
        {
            banquet_parray[k]->set_target_a(min_disk_a);
        }

        printf("%d\n", group_number);

        for(int k=0; k<n; k++)
        {
            banquet_array[k].print();
        }
    }

    delete[] banquet_array;
}
