#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool prev = true;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isspace(s[i]))
        {
            prev = true;
        }
        else
        {
            if (prev && !isupper(s[i]))
            {
                s[i] = toupper(s[i]);
                prev = false;
            }
            else if (!prev && !islower(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }

    answer = s;
    
    return answer;
}

int main()
{
    solution("  sldfk 3d");
}