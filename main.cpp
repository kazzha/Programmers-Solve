#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 그리디 알고리즘
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    while (people.size() > idx)
    {
        int back = people.back(); people.pop_back();
        // 큰 수부터 넣고, 만약 가장 작은 kg과 합했을때 limit를 넘지 않으면 같이 보트에 태움
        if (people[idx] + back <= limit) { answer++; idx++; }
        else answer++;
    }
    
    return answer;
}