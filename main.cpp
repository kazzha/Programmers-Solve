#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index{};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            answer.push_back(s[i]);
            index = 0;
        }
        else if (index % 2 == 0)
        {
            answer.push_back(s[i] - 32);
            index++;
        }
        else if (index % 2 == 1)
        {
            answer.push_back(s[i]);
            index++;
        }

    }
    return answer;
}

int main()
{
    string cec{ "aaa " };

    cout << solution(cec);
}