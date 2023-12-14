#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n{}, x{}, answer{};
    cin >> n;
    vector<int> count(n);
    for (int i = 0; i < n; i++)
    {
        cin >> count[i];
    }
    cin >> x;

    int start{}, end{1};

    sort(count.begin(), count.end());

    while (start < n-1)
    {
        end = start + 1;
        while (end < n) {
            if (count[start] + count[end] < x)
                end++;
            else if (count[start] + count[end] == x)
            {
                answer++;
                break;
            }
            else { break; }
        }
        start++;
    }

    cout << answer;
}