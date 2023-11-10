#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int i{};
    i = distance(seoul.begin(), find(seoul.begin(), seoul.end(), "Kim"));
    answer = "김서방은 " + to_string(i) + "에 있다";
    return answer;
}

int main()
{
    vector<string> seoul{ "se","Kim" };
    cout << solution(seoul);
}