#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size());
    answer[0] = -1;
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (s[i] == s[j])
            {

            }
        }
    }

    return answer;
}