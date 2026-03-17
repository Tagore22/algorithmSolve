#include <iostream>
#include <string>

using namespace std;

int N;
int board[53];
string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        ++board[num];
    }
    cin.ignore();
    getline(cin, str);
    int idx;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == ' ')
            idx = 0;
        else if ('a' <= str[i] && str[i] <= 'z')
            idx = str[i] - 'a' + 27;
        else
            idx = str[i] - 'A' + 1;
        --board[idx];
    }
    for (int i = 0; i < 53; ++i)
    {
        if (board[i] != 0)
        {
            cout << 'n' << '\n';
            return 0;
        }
    }
    cout << 'y' << '\n';
    return 0;
}