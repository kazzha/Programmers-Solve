#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

// 2진수 변환 반복하기
vector<int> solution(string s) {
    vector<int> answer(2);
    int count{}, zero{};

    while (s != "1")
    {
        answer[0]++;
        string tmp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                tmp += '1';
            }
        }
        zero += s.size() - tmp.size();
        bitset<sizeof(int) * 8> binaryNum(tmp.size());
        string binaryString = binaryNum.to_string();

        s = binaryString.substr(binaryString.find_first_not_of('0'));
    }
    answer[1] = zero;
    return answer;

}

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