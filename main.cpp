#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int num{};
    
    sort(score.begin(), score.end());

    while (num <= score.size() - 1)
    {
        if (num == 1)
        {
            num += m - 1;
        }
        else
        {
            num += m;
        }
        answer += (score[num] * m);
    }

    return answer;
}