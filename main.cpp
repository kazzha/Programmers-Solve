#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
                if (temp[j] <= p[j])
                {
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

int main()
{
    cout << solution("3141592", "271");
}