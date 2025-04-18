#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 전체적으로 어려울 것 없었으나 단축키를 찾지 못했을때 그냥 출력해야하는걸 놓쳤다.

int N;

void Solve()
{
    cin.ignore();
    bool IsSet[26] = { false, };
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        getline(cin, str);
        int idx = 0;
        bool IsFind = false, IsFirst = true;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
                IsFirst = true;
                continue;
            }
            else if (IsFirst)
            {
                IsFirst = false;
                idx = 'A' <= str[i] && str[i] <= 'Z' ? str[i] - 'A' : str[i] - 'a';
                if (!IsSet[idx])
                {
                    IsSet[idx] = true;
                    string nstr = str.substr(0, i);
                    nstr += '[';
                    nstr += str[i];
                    nstr += ']';
                    nstr += str.substr(i + 1);
                    cout << nstr << '\n';
                    IsFind = true;
                    break;
                }
            }
        }
        if (IsFind)
            continue;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != ' ')
            {
                idx = 'A' <= str[i] && str[i] <= 'Z' ? str[i] - 'A' : str[i] - 'a';
                if (!IsSet[idx])
                {
                    IsSet[idx] = true;
                    string nstr = str.substr(0, i);
                    nstr += '[';
                    nstr += str[i];
                    nstr += ']';
                    nstr += str.substr(i + 1);
                    cout << nstr << '\n';
                    IsFind = true;
                    break;
                }
            }
        }
        if (IsFind)
            continue;
        cout << str << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}