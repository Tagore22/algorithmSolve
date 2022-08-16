#include <iostream>
#include <vector>

using namespace std; //양방향 그래프, 정점의 번호는 1번부터 N까지

vector<vector<int>> board;
const int MAXNUM = 987654321;
int N, M;

void Floyd()
{
    vector<vector<int>> answer(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j)
                answer[i][j] = j; //이부분이 나름 중요했는데 다른 정점을 들르지 않고 직접 가는것이 최단거리일때
    for (int i = 1; i <= N; ++i)  //answer[i][j]는 바뀌지 않기에 초기값이 필요했다.
        board[i][i] = 0;
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                if (i == j)
                    continue;
                if (board[i][j] > board[i][k] + board[k][j]) //최단거리가 바뀔경우
                {
                    board[i][j] = board[i][k] + board[k][j]; //최단거리를 갱신하고
                    answer[i][j] = answer[i][k];             //중간에 들르게 되는 정점 k를 들르기 위해 가장 처음 들르는
                }                                            //경우로 갱신
            }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (answer[i][j] == 0)
                cout << '-' << ' ';
            else
                cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<int>(N + 1, MAXNUM));
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a][b] = min(board[a][b], c);
        board[b][a] = min(board[b][a], c);
    }
}

int main()
{
    Input();
    Floyd();
    return 0;
}