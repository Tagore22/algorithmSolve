#include <iostream>
#include <vector>

using namespace std;

vector<int> board;
vector<bool> CanGo;
int N, answer, erase;

void DFS(int now)
{
    bool isleaf = true;
    for (int i = 0; i < N; ++i)
        if (board[i] == now && CanGo[i])
        {
            isleaf = false;
            DFS(i);
        }
    if (isleaf && now != -1)
        ++answer;
}

void EraseDFS(int erase)
{
    CanGo[erase] = false;
    for (int i = 0; i < N; ++i)
        if (board[i] == erase)
            EraseDFS(i);
}

void MakeAnswer()
{
    EraseDFS(erase);
    answer = 0;
    DFS(-1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.assign(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> erase;
    CanGo.assign(N, true);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}