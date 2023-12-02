#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> aproc(N);
    vector<pair<float, int>> fail(N);

    for (int i = 0; i < N; i++)
    {
        fail[i].second = i+1;
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

int main()
{
    solution(5, vector<int>{2, 1, 2, 6, 2, 4, 3, 3});
}