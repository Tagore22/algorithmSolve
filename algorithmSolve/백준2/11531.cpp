#include <iostream>
#include <cstring>

using namespace std;

int n;
int endtime[26], board[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(endtime, -1, sizeof(endtime));

    while (true)
    {
        int m;
        cin >> m;
        if (m == -1)
            break;
        char name;
        string result;
        cin >> name >> result;
        int idx = name - 'A';

        if (result == "wrong")
            ++board[idx];
        else
            endtime[idx] = m;
    }
    pair<int, int> answer = { 0, 0 };
    for (int i = 0; i < 26; ++i)
    {
        if (endtime[i] != -1)
        {
            ++answer.first;
            answer.second += 20 * board[i] + endtime[i];
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}