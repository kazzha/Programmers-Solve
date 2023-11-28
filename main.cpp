#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    map<int, bool> cont;
    for (int i = 0; i < numbers.size()-1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            cont.insert(make_pair(numbers[i] + numbers[j], true));
        }
    }
    
    for (const auto& pair : cont)
    {
        answer.push_back(pair.first);
    }
    return answer;
}
