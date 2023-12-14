#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <set>
#include <iostream>

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

// ���� ���� �κ� �� (��������)
int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int sizeV = elements.size();
    int count{}, end{};

    for (int start = 0; start < sizeV; ++start)
    {
        int sum = elements[start];
        s.insert(sum);
        count = 1;
        end = start;
        while (count < sizeV)
        {
            count++; end++;
            sum += elements[end % sizeV];
            s.insert(sum);
        }
    }
    answer = s.size();
    return answer;
}

// 1���� �迭 ä��� -> 2���� �迭 ä���
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++)
    {
        if (i / n >= i % n)
        {
            answer.push_back(i / n + 1);
        }
        else
        {
            answer.push_back(i % n + 1);
        }
    }

    return answer;
}