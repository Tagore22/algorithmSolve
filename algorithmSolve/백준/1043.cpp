#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
set<int> known;
int N, M;

void CalculKnown()
{
    for (int num = 0; num < M; ++num)
        for (int i = 0; i < M; ++i)
            for (auto iter = known.begin(); iter != known.end(); ++iter)
                if (find(board[i].begin(), board[i].end(), *iter) != board[i].end())
                    for (int j = 0; j < board[i].size(); ++j)
                        known.insert(board[i][j]);
}

void CalculAnswer()
{
    int answer = M;
    for (int i = 0; i < M; ++i)
        for (auto iter = known.begin(); iter != known.end(); ++iter)
            if (find(board[i].begin(), board[i].end(), *iter) != board[i].end())
            {
                --answer;
                break;
            }
    cout << answer << '\n';
}

void MakeAnswer()
{
    if (known.empty())
    {
        cout << M << '\n';
        return;
    }
    CalculKnown();
    CalculAnswer();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(M);
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        int a;
        cin >> a;
        known.insert(a);
    }
    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; ++j)
        {
            int b;
            cin >> b;
            board[i].push_back(b);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}