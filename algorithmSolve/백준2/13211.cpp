#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    unordered_set<string> board;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board.insert(str);
    }
    int M, answer = 0;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (board.find(str) != board.end())
            ++answer;
    }
    cout << answer << '\n';
    return 0;
}