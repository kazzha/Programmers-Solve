#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int sum{};
    for (int i = 0; i < number.size() - 2; i++)
    {
        sum += i;
        for (int j = i + 1; j < number.size() - 1; j++)
        {
            sum += j;
            for (int k = j + 1; k < number.size(); k++)
            {
                sum += k;
                if (sum == 0)
                {
                    answer++;
                }
                sum = 0;
            }
        }
    }
    return answer;
}