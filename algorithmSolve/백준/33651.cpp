#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string answer = "UAPC";
    for (int i = 0; i < str.size(); ++i)
        answer.erase(find(answer.begin(), answer.end(), str[i]));
    cout << answer << '\n';
    return 0;
}