#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    char c;
    cin >> c;
    string str = "ILOVEYONSEI";
    int answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        answer += abs(c - str[i]);
        c = str[i];
    }
    cout << answer << '\n';
    return 0;
}