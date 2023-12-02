#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count1{}, count2{}, count3{};
    int index1{}, index2{}, index3{};
    vector<int> supoza1{ 1,2,3,4,5 };
    vector<int> supoza2{ 2,1,2,3,2,4,2,5 };
    vector<int> supoza3{ 3,3,1,1,2,2,4,4,5,5 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (supoza1[index1] == answers[i])
        {
            count1++;
        }
        if (supoza2[index2] == answers[i])
        {
            count2++;
        }
        if (supoza3[index3] == answers[i])
        {
            count3++;
        }
        index1++;
        index2++;
        index3++;
        if (index1 > 4)
        {
            index1 = 0;
        }
        if (index2 > 7)
        {
            index2 = 0;
        }
        if (index3 > 9)
        {
            index3 = 0;
        }
        
    }
    int maxnum = max(count1, count2); maxnum = max(maxnum, count3);

    if (maxnum == count1)
    {
        answer.push_back(1);
    }
    if (maxnum == count2)
    {
        answer.push_back(2);
    }
    if (maxnum == count3)
    {
        answer.push_back(3);
    }
    return answer;
}