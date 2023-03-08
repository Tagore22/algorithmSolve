#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ��ɴ�� �ֻ����� �������� �迭�ȿ� �����Ѵٸ� �ֻ����� ȸ������ ĭ�� ������ ����, Ȥ�� �������� �ʴ� �����̴�.

// ������ �Լ��� ������ ����.

// 1. �ֻ����� ȸ����Ű�� �Լ�.
// 2. �־��� ��ɿ� ���� �ֻ����� �̵� �� ȸ����Ų�� ����ϴ� �Լ�.

// ���� ���ΰ��� Y, ���ΰ��� X�� ��Ƽ� �־��� �Է°��� �ݴ�� ����ߴµ� ������ X�� ���θ� Y�� ���θ� ����Ű�� �־���.
// ������ �ݴ�� �ص� �־��� ������ �ٸ¾Ҿ���. �̰� ����... ������ �ߺ���.

int board[20][20];
int rot[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} }; // ��, ��, ��, ��
int moves[1000];
int dice[6] = {}; // ���ʿ��� ������ ��, ��, ��, �� �׸��� ���� �Ʒ� ����.
int N, M, X, Y, K;

// �ֻ����� ȸ����Ű�� �Լ�.
void MoveDice(int num)
{
    int temp = dice[5];
    if (num == 1)
    {
        dice[5] = dice[0];
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = temp;
    }
    else if (num == 2)
    {
        dice[5] = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[0];
        dice[0] = temp;
    }
    else if (num == 3)
    {
        dice[5] = dice[2];
        dice[2] = dice[4];
        dice[4] = dice[3];
        dice[3] = temp;
    }
    else
    {
        dice[5] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[2];
        dice[2] = temp;
    }
}

// �������� ó���ϴ� �Լ�.
void MakeAnswer()
{
    int check_y;
    int check_x;
    
    // �־��� ��ɿ� ���� �ֻ����� �̵����Ѻ��� �迭���̶�� �������� ���̶�� �����Ѵ�.
    for (int i = 0; i < K; ++i)
    {
        check_y = Y + rot[moves[i] - 1][0];
        check_x = X + rot[moves[i] - 1][1];

        if (check_x < 0 || check_x >= M || check_y < 0 || check_y >= N)
            continue;

        // ������ �ֻ����� �̵� �� ȸ����Ų��.
        Y = check_y;
        X = check_x;
        MoveDice(moves[i]);

        // �̵��� ĭ�� ���� 0�̶�� �ֻ����� �Ʒ����� �����Ű��, �׷��� �ʴٸ� �ֻ����� �Ʒ����� ĭ�� ������ ������ ��
        // ĭ�� ���� 0���� �����Ų��.
        if (board[Y][X] == 0)
        {
            board[Y][X] = dice[5];
        }
        else
        {
            dice[5] = board[Y][X];
            board[Y][X] = 0;
        }

        // �ֻ����� ���� ���.
        cout << dice[4] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> Y >> X >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    for (int i = 0; i < K; ++i)
        cin >> moves[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}