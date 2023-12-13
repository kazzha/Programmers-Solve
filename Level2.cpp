#include <string>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

// 2���� ��ȯ �ݺ��ϱ�
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

// �׸��� �˰���
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int idx = 0;
    while (people.size() > idx)
    {
        int back = people.back(); people.pop_back();
        // ū ������ �ְ�, ���� ���� ���� kg�� �������� limit�� ���� ������ ���� ��Ʈ�� �¿�
        if (people[idx] + back <= limit) { answer++; idx++; }
        else answer++;
    }

    return answer;
}