#include <iostream>
#include <string.h>
#include <string>

using namespace std;

class Solution
{
private:
    int charIndexMap[26][101];
    char charList[101];
    int printIndexList[100];

private:
    void initStatus()
    {
        memset(charIndexMap, 0, sizeof(int) * 26 * 101);
        memset(charList, 0, sizeof(char) * 100);
    }

    void uniqueString(string s)
    {
        charList[0] = s[0];
        int index = 0;

        int charIndex = s[0] - 'a';
        charIndexMap[charIndex][1] = 0;
        charIndexMap[charIndex][0] = 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != charList[index])
            {
                charList[++index] = s[i];

                charIndex = s[i] - 'a';
                charIndexMap[charIndex][charIndexMap[charIndex][0] + 1] = index;
                charIndexMap[charIndex][0] += 1;
            }
        }
    }

public:
    int strangePrinter(string s)
    {
        initStatus();
        uniqueString(s);

        int uniqueStringLen = strlen(charList);

        if (uniqueStringLen < 3)
        {
            return uniqueStringLen;
        }

        printIndexList[0] = 1;
        printIndexList[1] = 2;

        for (int i = 2; i < uniqueStringLen; i++)
        {
            
        }
        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    s.strangePrinter("aaabbcccabcddefgghhijjaa");

    return 0;
}