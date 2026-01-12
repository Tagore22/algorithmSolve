#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> board;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board.insert(str);
    }
    int M;
    cin >> M;
    int ans = 0, to = N % 2 == 0 ? N / 2 : N / 2 + 1, answer = 0;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (board.find(str) != board.end())
        {
            ++ans;
            answer = ans == to ? i + 1 : answer;
            board.erase(str);
        }
    }
    cout << answer << '\n';
    return 0;
}