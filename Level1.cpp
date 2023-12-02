#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// ���Ϳ� �Ųٷ� �ֱ�
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

// �ݶ��� ����. ? : ����ϱ�
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

// p���ڿ����� ���� t�� �κй��ڿ� ����
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

// ���� ǥ����

#include <regex> // GCC������ <bits/stdc++.h>
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


// ���� ã�� - ����
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

// ���� ��ġ�� char ���ϱ�
bool cmp(string a, string b, int num)
{
    if (a[num] == b[num])
    {
        return a < b;
    }
    else if (a[num] > b[num])
    {
        return false;
    }
    else if (a[num] < b[num])
    {
        return true;
    }
    return true;
}

vector<string> solution(vector<string> strings, int n) {
    int num = n;
    sort(strings.begin(), strings.end(), [num](const string& a, const string& b)->bool
        {
            return cmp(a, b, num);
        });

    vector<string> answer = strings;

    return answer;
}

// ��Ʈ�������� ����ȭ ����
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr1_sub;
    vector<int> arr2_sub;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1_sub.push_back(arr1[i] % 2);
            arr2_sub.push_back(arr2[i] % 2);
            arr1[i] /= 2;
            arr2[i] /= 2;
        }
    }



    for (int i = 0; i < n; i++)
    {
        ostringstream oss;
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr1_sub[i * n + j] == 1 || arr2_sub[i * n + j] == 1)
            {
                oss << '#';
            }
            else
            {
                oss << ' ';
            }
        }
        answer.push_back(oss.str());
    }


    return answer;
}

// ���� �Լ� �ȿ��� pair�� second�� �ε����� ������������, �⺻�� first�� �������� ������������
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> aproc(N);
    vector<pair<float, int>> fail(N);

    for (int i = 0; i < N; i++)
    {
        fail[i].second = i + 1;
    }

    for (int i = 0; i < stages.size(); i++)
    {
        if (stages[i] == N + 1)
        {
            for (int j = 0; j < N; j++)
            {
                aproc[j]++;
            }
        }
        else {
            for (int j = 0; j < stages[i]; j++)
            {
                aproc[j]++;
                if (j == (stages[i] - 1))
                {
                    fail[j].first += 1.0;
                }
            }
        }
    }

    for (int k = 0; k < N; k++)
    {

        fail[k].first = fail[k].first / aproc[k];

        if (aproc[k] == 0)
        {
            fail[k].first = 0.0;
        }
    }

    sort(fail.begin(), fail.end(), [](const auto& a, const auto& b) {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
            return a.first > b.first;
        });

    for (int k = 0; k < N; k++)
    {
        answer.push_back(fail[k].second);
    }

    return answer;
}