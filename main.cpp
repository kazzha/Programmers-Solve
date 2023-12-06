#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    int num{};
    int index{};
    int one{};
    bool flag = false;
   
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 49)
        {
            index = i;
            answer[1] += i;
            break;
        }
    }

    long long sll = stoll(s.substr(index));

    while (sll != 1)
    {
        if (sll % 10 == 0)
        {
            answer[1]++;
        }
        else
        {
            one++;
        }
        sll /= 10;
    }
    answer[0]++;
    one++;


   while (one != 1)
    {
        bitset<sizeof(one) * 8> binaryNum(one);

        one = 0;

        for (int i = 0; i < binaryNum.size(); i++)
        {
            if (binaryNum[i])
            {
                flag = true;
            }
            if (flag && binaryNum[i] == 0)
            {
                answer[1]++;
            }
            else if(flag && binaryNum[i] == 1)
            {
                one++;
            }
        }
        flag = false;
        answer[0]++;
    }
    
 
    return answer;
}

int main()
{
    solution("01110");
}