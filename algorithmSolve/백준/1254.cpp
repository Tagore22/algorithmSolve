#include <iostream>
#include <algorithm>

//풀이
//어떤 문자열의 최대 길이의 팰린드롬은 그 문자열을 뒤집어서 붙였을때이다. 즉, abc의 최대 길이 팰린드롬은 abc + cba = abccba다.
//이렇게 뒤집어서 맨뒤자리부터 부분문자열을 붙여가며 최초로 팰린드롬을 발견했을때가 바로 최소 길이의 팰린드롬이다.

using namespace std;

string str;

bool IsPal(const string& str)
{
    int len = str.size() - 1;
    for (int i = 0; i < str.size() / 2; ++i)
        if (str[i] != str[len - i])
            return false;
    return true;
}

void MakeAnswer()
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    int answer = str.size();

    if (IsPal(str))
    {
        cout << answer << '\n';
        return;
    }

    for (int i = rev.size() - 1; i >= 0; --i)
    {
        ++answer;
        if (IsPal(str + rev.substr(i)))
        {
            cout << answer << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}