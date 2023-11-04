#include <string>
#include <vector>

using namespace std;

// ���Ϳ� �Ųٷ� �ֱ�
vector<int> solution(long long n) {
    vector<int> answer;
    int x{};
    while (n > 10) {
        x = n % 10;
        answer.push_back(x);
        n /= 10;
    }
    answer.push_back(n);
    return answer;
}

// �ݶ��� ����. ? : ����ϱ�
int solution(int num) {
    int answer = 0;
    long long n{ num };
    while (n != 1)
    {
        n % 2 == 0 ? n /= 2 : n = 3 * n + 1;
        answer++;

        if (answer == 500) { answer = -1; break; }

    }
    return answer;
}

// p���ڿ����� ���� t�� �κй��ڿ� ����
int solution(string t, string p) {
    int answer = 0;
    string temp;
    int Psize = p.size();
    bool checking;
    vector<string> Tvec;

    for (int i = 0; i <= t.size() - p.size(); i++)
    {
        temp = t.substr(i, p.size());
        checking = true;
        for (int j = 0; j < Psize; j++)
        {
            if (temp[j] == p[j])
            {
            }
            else if (temp[j] < p[j])
            {
                break;
            }
            else if (temp[j] > p[j])
            {
                checking = false;
                break;
            }
        }
        if (checking)
        {
            answer++;
        }
    }


    return answer;
}