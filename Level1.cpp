#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// 벡터에 거꾸로 넣기
vector<int> solution(long long n) {
    vector<int> answer;
    int x{};
    while (n > 10) {
        x = n % 10;
        answer.push_back(x);
        n /= 10;
    }
    answer.push_back(n);
    return answer;
}

// 콜라츠 추측. ? : 기억하기
int solution(int num) {
    int answer = 0;
    long long n{ num };
    while (n != 1)
    {
        n % 2 == 0 ? n /= 2 : n = 3 * n + 1;
        answer++;

        if (answer == 500) { answer = -1; break; }

    }
    return answer;
}

// p문자열보다 작은 t의 부분문자열 개수
int solution(string t, string p) {
    int answer = 0;
    string temp;
    int Psize = p.size();
    bool checking;
    vector<string> Tvec;

    for (int i = 0; i <= t.size() - p.size(); i++)
    {
        temp = t.substr(i, p.size());
        checking = true;
        for (int j = 0; j < Psize; j++)
        {
            if (temp[j] == p[j])
            {
            }
            else if (temp[j] < p[j])
            {
                break;
            }
            else if (temp[j] > p[j])
            {
                checking = false;
                break;
            }
        }
        if (checking)
        {
            answer++;
        }
    }


    return answer;
}

// 정규 표현식

#include <regex> // GCC에서는 <bits/stdc++.h>
#include <map>
using namespace std;

int solution(string s) {
    map<string, string> nums = { {"zero","0"},{"one","1"},{"two","2"},{"three","3"},
                          {"four","4"},{"five","5"},{"six","6"},{"seven","7"},
                          {"eight","8"},{"nine","9"} };

    for (auto it : nums)
        s = regex_replace(s, regex(it.first), it.second);

    return stoi(s);
}


// 글자 찾기 - 기출
vector<int> solution1(string s) {
    vector<int> answer(s.size());
    unordered_map<char, int> container;
    for (int i = 0; i < s.size(); i++)
    {
        if (!container.count(s[i]))
        {
            container[s[i]] = i;
            answer[i] = -1;
        }
        else
        {
            answer[i] = i - container[s[i]];
            container[s[i]] = i;
        }
    }

    return answer;
}