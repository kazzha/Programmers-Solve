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