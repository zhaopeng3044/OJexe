#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <bitset>
#include <numeric>
#include <functional>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iterator>
#include <limits>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>

#define DEBUG

const int MAX_ELEMENT_NUM = 200000;

struct Node
{
    int x, y, index;
    int category_index;
};

Node nodes[MAX_ELEMENT_NUM];
int nodex_index_map[MAX_ELEMENT_NUM];
int tmp_path_array[MAX_ELEMENT_NUM];
int X_INDEX_MAP[MAX_ELEMENT_NUM + 1];
int Y_INDEX_MAP[MAX_ELEMENT_NUM + 1];

bool compareNodes(const Node &a, const Node &b)
{
    if (a.x == b.x)
    {
        return a.y < b.y;
    }
    return a.x < b.x;
}

void sortNodes(Node nodes[], int n)
{
    std::sort(nodes, nodes + n, compareNodes);
}

void printOriginArrayInfo(Node nodes[], int node_index_map[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d %d\n", nodes[node_index_map[i]].index, nodes[node_index_map[i]].x, nodes[node_index_map[i]].y, nodes[node_index_map[i]].category_index);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    memset(nodes, 0, sizeof(nodes));
    memset(nodex_index_map, 0, sizeof(nodex_index_map));
    memset(tmp_path_array, 0, sizeof(tmp_path_array));
    memset(X_INDEX_MAP, 0, sizeof(X_INDEX_MAP));
    memset(Y_INDEX_MAP, 0, sizeof(Y_INDEX_MAP));

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &nodes[i].x, &nodes[i].y);

        nodes[i].index = i;
        nodes[i].category_index = -1;
        X_INDEX_MAP[nodes[i].x] = i;
        Y_INDEX_MAP[nodes[i].y] = i;
    }

    sortNodes(nodes, n);

    // init sorted nodes map
    for (int i = 0; i < n; i++)
    {
        nodex_index_map[nodes[i].index] = i;
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        printf("index: %d; x: %d; y: %d; category: %d\n", nodes[i].index, nodes[i].x, nodes[i].y, nodes[i].category_index);
    }

    printOriginArrayInfo(nodes, nodex_index_map, n);

    printf("y=7 info: %d %d %d\n", nodes[nodex_index_map[Y_INDEX_MAP[7]]].index, nodes[nodex_index_map[Y_INDEX_MAP[7]]].x, nodes[nodex_index_map[Y_INDEX_MAP[7]]].y);
    printf("x=3 info: %d %d %d\n", nodes[nodex_index_map[X_INDEX_MAP[3]]].index, nodes[nodex_index_map[X_INDEX_MAP[3]]].x, nodes[nodex_index_map[X_INDEX_MAP[3]]].y);
#endif

    int max_category_index = 0;
    for (int i = 0; i < n; i++)
    {
        int current_category_index = max_category_index;
        if (-1 != nodes[i].category_index)
        {
            current_category_index = nodes[i].category_index;
        }
        else
        {
            nodes[i].category_index = current_category_index;
        }

        tmp_path_array[0] = i;
        int tmp_path_array_index = 1;

        for (int j = nodes[i].y + 1; j <= n; j++)
        {
            Node *tmp_node = &nodes[nodex_index_map[Y_INDEX_MAP[j]]];
            if (tmp_node->x > nodes[i].x)
            {
                if (-1 == tmp_node->category_index)
                {
                    tmp_node->category_index = current_category_index;
                    tmp_path_array[tmp_path_array_index++] = nodex_index_map[Y_INDEX_MAP[j]];
                }
                else
                {
                    current_category_index = tmp_node->category_index;
                    for (int k = 0; k < tmp_path_array_index; k++)
                    {
                        nodes[tmp_path_array[k]].category_index = current_category_index;
                    }
                }
            }
        }

        if (max_category_index == current_category_index)
        {
            max_category_index++;
        }
    }

#ifdef DEBUG
    printOriginArrayInfo(nodes, nodex_index_map, n);
#endif

    return 0;
}