#include <iostream>
#include <vector>

using namespace std;

//그래서에서 한번에 여러 좌표들의 거리르 알아야하는 플로이드 와셜 문제이다. 단순하게 a와 b의 최단거리가 아닌
//1에서 2,3,4,5의 거리, 2에서 1,3,4,5의 거리 등 여러가지 최단거리를 모두 알아야하기 때문이다.

vector<vector<int>> board;
int N, M;

//i에서 i는 0으로 한다. 이 알고리즘은 a에서 b의 최단거리 + b에서 c의 최단거리를 더해 a에서 c의 최단거리를 구하기 때문에
//i에서 i는 사실상 움직이지 않는 최단거리에 포함되지 않는 부분이여야하기에 0이 적합하다.

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        board[i][i] = 0;
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);

    pair<int, int> answer = make_pair(-1, 987654321);
    for (int i = 0; i < N; ++i)
    {
        int check = 0;
        for (int j = 0; j < N; ++j)
            check += board[i][j];

        answer = check < answer.second ? make_pair(i, check) : answer;
    }
    cout << answer.first + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(N, 150));
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a - 1][b - 1] = 1;
        board[b - 1][a - 1] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}