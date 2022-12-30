#include <iostream>

using namespace std;

//2167번을 누적합을 이용해서 푼 풀이. 2차원 배열은 1차원과 접근법이 약간 달라서 헷갈렸었다. 잘 이해해둘것

//풀이
//2차원 누적합으로 풀기 위해서는 2차원의 땅따먹기를 연상시키면 된다. 그 점화식은 cashe[i][j] = cashe[i-1][j] + cashe[i][j-1] + board[i][j] -
//cashe[i][j]인데, 인덱스값의 뺄셈을 하고 있기에 [0][i]나 [i][0]은 구할수가 없어서 각 행과 열을 1칸씩 늘려서 시작을 0으로 채워야 한다.
//그 후 상술한 점화식을 이용하여 문제를 푼다.

//P.S 내가 이해는 하고 있으나, 그림없이 설명하자니 너무 어렵다. 혹여나 나중에 기억이 안나서 다시 이글을 본다면 2차원 누적합을 검색할것.

int board[301][301], cashe[301][301];
int N, M, K;

void Init()
{
    for (int i = 0; i < N; ++i)
        cashe[0][i] = 0;
    for (int i = 0; i < M; ++i)
        cashe[i][0] = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cashe[i][j] = cashe[i - 1][j] + cashe[i][j - 1] + board[i][j] - cashe[i - 1][j - 1];
}

void MakeAnswer()
{
    Init();

    int from_y, from_x, to_y, to_x;
    for (int i = 0; i < K; ++i)
    {
        cin >> from_y >> from_x >> to_y >> to_x;
        cout << cashe[to_y][to_x] - cashe[from_y - 1][to_x] - cashe[to_y][from_x - 1] + cashe[from_y - 1][from_x - 1] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        board[0][i] = 0;
    for (int i = 0; i < M; ++i)
        board[i][0] = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}