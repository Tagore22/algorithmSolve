#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> board;
int N, M;

void Solve()
{
    for (int i = 0; i < M; ++i)
    {
        string str, cur = "";
        cin >> str;

        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] == ',')
            {
                board.erase(cur);
                cur = "";
            }
            else
            {
                cur += str[j];
            }
        }
        board.erase(cur);
        cout << board.size() << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board.insert(str);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}