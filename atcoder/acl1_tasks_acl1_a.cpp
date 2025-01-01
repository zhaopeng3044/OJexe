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

        std::cout << nodes[node_index_map[i]].index << " " << nodes[node_index_map[i]].x << " " << nodes[node_index_map[i]].y << std::endl;
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

#ifdef DEBUG
    for (int i = 0; i < n; i++)
    {
        std::cout << "index: " << nodes[i].index << "; x: " << nodes[i].x << "; y: " << nodes[i].y << std::endl;
    }

    printOriginArrayInfo(nodes, nodex_index_map, n);
#endif

    // init sorted nodes map
    for (int i = 0; i < n; i++)
    {
        nodex_index_map[nodes[i].index] = i;
    }

    int category_index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp_category_index = -1;
        if (nodes[i].category_index == -1)
        {
            nodes[i].category_index = category_index;
            tmp_category_index = category_index;
        }
        else
        {
            tmp_category_index = nodes[i].category_index;
        }

        int k = 0;

       
    }
    return 0;
}