#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ �߸� �����ؼ� ���� ��̴� ������. �迭�� ȸ����Ű�µ� �� ĭ�� �ð� �ݴ�������� ȸ����Ų��.
// �迭�� ȸ����Ű�°� �ƴ� �� ���� ȸ����Ű�� ���̴�. ����Ѵ�� �Ѱ��� ū �Ǽ��� �ߴµ� �ִ� ȸ������
// 1�￡ ���Ѵ�. �׷��� �� �����غ��� ����� ȸ������ �ٽ� �ǵ��ƿö��� �ִ�. �̰��� �̿��Ͽ� ȸ���� R��
// ���� �迭������ ������ �ּ�ȭ��ų�� �ִ�. �̶� ���� �迭�� ���� �ٱ��� ������ ���ߴµ� �̰� �Ǽ�����.
// ���� ��� 4, 4 ¥�� �迭�� �����Ѵٸ� ���� �ٱ����� 4, 4�� ���ϴ� ���� �´�. �׷��� �� ��������
// 4, 4�� �ƴ� 3, 3���� ���ؾ� �ùٸ� ȸ������ �˾Ƴ��� �ִ�. �̰� �Ǽ�����.
// �������� ���������� ������ ��������̴�. �׷��� �������� ������ Ǯ��� �����̴�.

// �ڼ��� ������ �ּ����� �����.

int board[300][300];
int N, M, R;

// �迭�� �� �κ��� ȸ����Ű�� �Լ�.
void RotateArray(int num)
{
    // ���� �迭 �κ��� ���ΰ�, ���ΰ��� �̿��Ͽ� ȸ�����Ѿ� �ϴ� Ƚ���� �˾Ƴ���.
    int cur_n = N - (num * 2);
    int cur_m = M - (num * 2);
    int div = cur_m + (cur_n - 1) + (cur_m - 1) + (cur_n - 2);
    int rot = R % div;

    // Ƚ����ŭ ȸ����Ų��.
    for (int iter = 0; iter < rot; ++iter)
    {
        int y = num;
        int x = num;
        int temp = board[y][x];

        for (int i = 0; i < cur_m - 1; ++i)
            board[y][x++] = board[y][x + 1];
        for (int i = 0; i < cur_n - 1; ++i)
            board[y++][x] = board[y + 1][x];
        for (int i = 0; i < cur_m - 1; ++i)
            board[y][x--] = board[y][x - 1];
        // �̺κ��� ���� �߿��ѵ� cur_n - 2�� �߻���� �Ѵ�. ������ 1, 0�� 0, 0�� ���� ���޹޾ƾ� �ϴµ�
        // ���� board[0][0]�� ���� ���� board[0][1]���̹Ƿ� �̰��� ���� �ʰ� �̸� �����صξ��� temp��
        // �޾ƾ� �Ѵ�. ���� for������ �����ϰ� ���� ���� �����Ѵ�.
        for (int i = 0; i < cur_n - 2; ++i)
            board[y--][x] = board[y - 1][x];
        board[y--][x] = temp;
    }
}

void MakeAnswer()
{
    // �� �κ��� ȸ����Ų��.
    int piv = min(N, M) / 2;
    for (int i = 0; i < piv; ++i)
        RotateArray(i);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}