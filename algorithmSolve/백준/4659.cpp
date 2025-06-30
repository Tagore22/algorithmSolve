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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    while (true)
    {
        cin >> str;
        if (str == "end")
            break;
        int ssize = str.size();
        bool cananswer = true, hasvow = false;
        int vow = 0, con = 0;
        for (int i = 0; i < ssize; ++i)
        {
            if (IsVowel(str[i]))
            {
                hasvow = true;
                ++vow;
                con = 0;
            }
            else
            {
                ++con;
                vow = 0;
            }
            if ((con >= 3 || vow >= 3) || (i != ssize - 1 && str[i] != 'e' && str[i] != 'o' && str[i] == str[i + 1]))
            {
                cananswer = false;
                break;
            }
        }
        if (cananswer && hasvow)
            cout << '<' << str << "> is acceptable." << '\n';
        else
            cout << '<' << str << "> is not acceptable." << '\n';
    }
    return 0;
}