#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = -1;
    char prev{};
    int sizeS=s.size(), index{};
    bool checking = true;
    vector<bool> stringS(s.size(), true);

    while (checking && sizeS > 1) {
        checking = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (prev == s[i])
            {
                stringS[i] = stringS[i - 1] = false;
                checking = true;
                index = i;
                sizeS -= 2;
                while (index > 1)
                {
                    index -= 2;
                    if (stringS[index])
                    {
                        prev = s[index];
                    }
                    else
                    {
                        prev = {};
                    }
                }
            }
            if (stringS[i])
            {
                prev = s[i];
            }
        }
    }

    if (sizeS > 0)
    {
        answer++;
    }
    else
    {
        answer += 2;
    }
    return answer;
}