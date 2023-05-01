#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���״�� �迭�� �� ���ҵ��� �ð� �ݴ� �������� �ٲٴ� ������.
// �� ������, �������� �ϴ� ��ġ ��� ����ؾ��Ұ� ���Ƽ� �����ߴ� ��������
// �ϳ��ϳ� �ٽ������� �����س����� ����� �ʴ�.

// �Ǽ��ߴ� ���� �ϳ� �ִµ� ȸ���� R�� ����ġ�� �Ҽ� ������ �˾Ҵ�.
// �� N, M�� �־����� ȸ������ (N - 1) * 2 + (M - 1) * 2�̱� ������
// �� ���� R�� ���� �������θ� ȸ���ϸ� ���� �˾Ҵ�.
// ������ N = 5, M = 4 ���� ��츦 ���� �����غ��� ���� �ٱ� ȸ���� �ѹ�����
// 14���� �� �ٷ� ���� ȸ���� 6���� �� ������ Ʋ�� ��찡 �Ǿ���.

// �ڼ��� ������ �ּ����� �����.

int board[300][300];
int N, M, R;

// ȸ���� ����ϴ� �Լ�.
void MoveFunc()
{
    // ����, ���η��� ȸ���� ��.
    int row = N - 1;
    int col = M - 1;

    // ���� ��ġ �� ������ ������ ��.
    int cur_y = 0, cur_x = 0, cur_num;

    // �� ����, ���� ȸ���� �������� ���� 2�� �پ���.
    while (row > 0 && col > 0)
    {
        // ȸ���� �����ϴ� ����� �������� �����غ�������, �̰��� ���� �´�.
        // ���� ��ġ�� ���� Ȥ�� ���η� 1�� �������� �� �κ��� ���� ���� ��(���� ��)�� �����ϸ� �ȴ�.
        cur_num = board[cur_y][cur_x];
        for (int i = 0; i < row; ++i)
        {
            ++cur_y;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < col; ++i)
        {
            ++cur_x;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < row; ++i)
        {
            --cur_y;
            swap(cur_num, board[cur_y][cur_x]);
        }
        for (int i = 0; i < col; ++i)
        {
            --cur_x;
            swap(cur_num, board[cur_y][cur_x]);
        }

        // 1���� ȸ��(�ѹ���)�� ������ ���� ���� ȸ���� ���� ���� - 2, ���� - 2�� �پ���.
        // ����, �� ��ġ�� �� ���� �»�ܿ��� ���߸� ���� ������ �����ϴٸ� ���� ��ġ����
        // ����, ���η� 1�� ���ϴ����� �̵��Ѱ����� ���۵ȴ�.
        row -= 2;
        col -= 2;
        ++cur_y;
        ++cur_x;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        MoveFunc();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
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