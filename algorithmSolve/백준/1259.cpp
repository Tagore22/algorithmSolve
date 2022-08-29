#include <iostream>

using namespace std; //str.size() 전까지 앞뒤가 같다면

bool CalculPal(const string& str)
{
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != str[str.size() - 1 - i])
            return false;
    return true;
}

void MakeAnswer()
{
    while (true)
    {
        string str;
        cin >> str;
        if (str == "0")
            break;
        cout << (CalculPal(str) ? "yes" : "no") << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}