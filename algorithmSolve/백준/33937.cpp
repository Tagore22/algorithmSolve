#include <iostream>

using namespace std;

bool IsVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    string answer = "";
    bool isfind = false;
    for (int i = 0; i < str1.size(); ++i)
    {
        if (IsVowel(str1[i]))
        {
            if (!isfind)
                isfind = true;
        }
        else
        {
            if (isfind)
            {
                answer += str1.substr(0, i);
                break;
            }
        }
    }
    if (answer == "")
    {
        cout << "no such exercise" << '\n';
        return 0;
    }
    string check = answer;
    isfind = false;
    for (int i = 0; i < str2.size(); ++i)
    {
        if (IsVowel(str2[i]))
        {
            if (!isfind)
                isfind = true;
        }
        else
        {
            if (isfind)
            {
                answer += str2.substr(0, i);
                cout << answer << '\n';
                break;
            }
        }
    }
    if (answer == check)
        cout << "no such exercise" << '\n';
    return 0;
}