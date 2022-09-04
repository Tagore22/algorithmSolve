#include <iostream>

using namespace std;

string str1, str2;

void MakeAnswer()
{
    long long answer = 0;
    for (int i = 0; i < str1.size(); ++i)
        for (int j = 0; j < str2.size(); ++j)
        {
            int first = str1[i] - '0';
            int second = str2[j] - '0';
            answer += first * second;
        }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}