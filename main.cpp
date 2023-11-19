#include <string>
#include <vector>
#include <algorithm>


using namespace std;

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