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

