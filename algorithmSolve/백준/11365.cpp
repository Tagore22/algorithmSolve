#include <iostream>

using namespace std;

string str;

void MakeAnswer()
{
    while (true)
    {
        getline(cin, str);
        if (str == "END")
            break;
        for (int i = str.size() - 1; i >= 0; --i)
            cout << str[i];
        cout << '\n';
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