#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ����� ������ ������ �������� ���� ���� ������ ������ �����̴�.
// �̷� ������ Ǯ�� ������ ���� 1�������ε� �ּ��� �̿��� �޸� �̿��ϴ� ���̴�.
// ����Ͽ��� ������ ���� ������ ��ĩ �ѹ� ���������� ���� ��������.
// �̹�ó�� �����ؼ� �ѹ��� Ǯ�������.

// ������ ū Ʋ�� ������ ����.
// 1. ��ƼĿ�� �Է� �޴´�.
// 2. ��Ʈ���� ��ȸ�ϸ� ���� ��ƼĿ�� ���ϼ� �ֳ� Ȯ���Ѵ�.
// 2-1. ���ϼ� �ִٸ� ���� ��ƼĿ�� �Ѿ��.
// 2-2. ���ϼ� ���ٸ� ��ƼĿ�� �ð� �������� 90�� ȸ���Ͽ� �ִ� 3�� Ȯ���Ѵ�. �� ���Ŀ��� ���ϼ� ���ٸ� �����ϰ� �Ѿ��.
// 1 ~ 2�� �ִ� K�� Ȯ���� ���� ��Ʈ�Ͽ� �پ� �ִ� ��ƼĿ���� ĭ�� ����ϸ� �ȴ�.

// ��ƼĿ�� ȸ����Ű�� �κп��� �ǿܷ� �ָ� �Ծ���. ó������ ��� ��ƼĿ�� ȸ����Ű�� ��ȭ���� �������� �ʴ��پ˰� 
// �°� ������ �ߴµ� ���� ������ Ǯ��� ���� �����ߴ�. �۵����� �Ӹ��θ� Ǫ�� ������ ������.

// �ڼ��� ������ �ּ����� �����.

// ��Ʈ�ϰ� ���� ��ƼĿ�� ��Ÿ���� 2���� bool �迭��.
bool board[40][40], sticker[10][10];
int N, M, K, row, col; // ����, ���μ���

// ���� ��ƼĿ�� ȸ����Ű�� �Լ�. plus�� ���� ������ ũ�� -1�� �����ϸ� ���η� 1ĭ �ü��� 2�� �����Ѵ�.
// ���� ���θ� ������ �� x�� plus�� ���ϸ� �ȴ�. ����, ���� ���� ũ�⸦ �����ϴ� �͵� ������ �ȉ´�.
void RotateSticker()
{
    bool temp[10][10];
    memset(temp, false, sizeof(temp));

    int plus = row - 1;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            if (sticker[i][j])
                temp[j][i + plus] = true;
        plus -= 2;
    }

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            sticker[i][j] = temp[i][j];
    swap(row, col);
}

// ��ƼĿ�� ��Ʈ�Ͽ� ���̴� �Լ�. ���� ��ƼĿ�� �پ� �ִ� ���(true�϶�) ��Ʈ�ϵ� true�� �ȴ�.
void AddSticker(int y, int x)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (sticker[i][j])
                board[i + y][j + x] = true;
}

// ���� ĭ���� ��ƼĿ�� ���ϼ� �ִ��� Ȯ���ϴ� �Լ�. ������ y, x���� ��ƼĿ�� ����, ���θ�ŭ ��ȸ�ϸ�
// ��ƼĿ�� true�϶� ��Ʈ�ϵ� true��� ����� ���ϼ� ����.
bool CheckSticker(int y, int x)
{
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (i + y >= N || j + x >= M || (board[i + y][j + x] && sticker[i][j]))
                return false;
    return true;
}

// ���ĭ�� ��ȸ�ϸ� �� ĭ���� ��ƼĿ�� ���ϼ� �ִ��� Ȯ���ϴ� �Լ�.
// ���ϼ� �ִٸ� ������ true�� ��ȯ�ϰ� ���ϼ� ���ٸ�
// false�� ��ȯ�Ѵ�.
bool CheckAll()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (CheckSticker(i, j))
            {
                AddSticker(i, j);
                return true;
            }
    return false;
}

// �� ����� ū Ʋ�� �����ϴ� �Լ�.
void MakeAnswer()
{
    memset(board, false, sizeof(board));
    for (int iter = 0; iter < K; ++iter)
    {
        cin >> row >> col;
        memset(sticker, false, sizeof(sticker));
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                cin >> sticker[i][j];

        for (int i = 0; i < 4; ++i)
        {
            // �����غ���. 
            if (CheckAll())
                break;
            // ���⼭ ȸ���Ѵ�.
            RotateSticker();
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j])
                ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}