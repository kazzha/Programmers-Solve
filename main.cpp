#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, bool> member;
    for (int i = 0; i < participant.size(); ++i)
    {
        member[participant[i]] = true;
    }

    for (int i = 0; i < completion.size(); ++i)
    {
        auto found = member.find(completion[i]);

        if (found != member.end())
        {
            if (member[completion[i]])
            {
                member[completion[i]] = false;
            }
            else
            {
                answer = completion[i];
                break;
            }
        }
        else
        {
            answer = completion[i];
            break;
        }
    }


    return answer;
}

int main()
{
    solution({ "leo", "kiki", "eden" }, { "eden", "kiki" });
}