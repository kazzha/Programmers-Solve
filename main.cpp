#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b)->bool
        {if (a[n] < b[n]) { return true; }
        else if (a[n] > b[n]) { return false; }
        else if (a[n] == b[n])
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] > b[i])
            {
                return false;
            }
        }
        return true;
    }
    return true;
        });

        vector<string> answer = strings;

        return answer;
}