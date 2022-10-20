#include <iostream>
#include <vector>

using namespace std;

//한번에 수많은 정점 x,y의 최단거리 혹은 도달가능성을 파악하는 플로이드 워셜 문제이다. 특별히 생각해야하는점은 없기에 어렵지 않으나,
//다만 보통 플로이드 워셜은 i에서 i는 이동하지 않는 그대로이기에 도달가능함을 미리 전처리하지만, 이번 문제는 i에서 i가 도달가능하지
//않는다(입력의 [i][i]가 0일 경우)라고 주어지는 경우도 있기에 오히려 그 전처리가 답을 못맞추게 방해할수도 있었다.

vector<vector<int>> board;
int N;

void MakeAnswer()
{
    /*for (int i = 0; i < N; ++i) <<< 움직이지 않아도 주어지는 해당 원소값이 0이라면 도달할수 없다고 해야함.
        board[i][i] = 0;*/

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] |= board[i][k] & board[k][j];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}