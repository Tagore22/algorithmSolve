#include <iostream>

using namespace std;

//2167���� �������� �̿��ؼ� Ǭ Ǯ��. 2���� �迭�� 1������ ���ٹ��� �ణ �޶� �򰥷Ⱦ���. �� �����صѰ�

//Ǯ��
//2���� ���������� Ǯ�� ���ؼ��� 2������ �����Ա⸦ �����Ű�� �ȴ�. �� ��ȭ���� cashe[i][j] = cashe[i-1][j] + cashe[i][j-1] + board[i][j] -
//cashe[i][j]�ε�, �ε������� ������ �ϰ� �ֱ⿡ [0][i]�� [i][0]�� ���Ҽ��� ��� �� ��� ���� 1ĭ�� �÷��� ������ 0���� ä���� �Ѵ�.
//�� �� ����� ��ȭ���� �̿��Ͽ� ������ Ǭ��.

//P.S ���� ���ش� �ϰ� ������, �׸����� �������ڴ� �ʹ� ��ƴ�. Ȥ���� ���߿� ����� �ȳ��� �ٽ� �̱��� ���ٸ� 2���� �������� �˻��Ұ�.

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