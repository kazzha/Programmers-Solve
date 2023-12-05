#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    int index{};
    string prev;
    bool fail = true;
    vector<string> str{ "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); i++)
    {
        fail = true;

        while (fail && index < babbling[i].size())
        {
            fail = false;
            for (auto e : str)
            {
                auto found = babbling[i].find(e, index);
                if (found != std::string::npos)
                {
                    if ((int)found == index  && prev != e){
                    prev = e;
                    fail = true;
                    
                    index += e.size();
                    if (index >= babbling[i].size())
                    {
                        answer++;
                        break;
                    }
                }
                else { 
                }
                }
                
            }
            
        }
        index = 0;
        prev = "";
    }

    return answer;
}

int main()
{
    solution({ "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" });
}