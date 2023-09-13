#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ �����̴�. �ٸ� ���ĭ�� 9ĭ�� ������ �� �κ��� �ߺ������� ���־� �ϴ� ���� ��ٷο� ������.
// �� �κ��� ���Ұ��� ��� ��ƾ����� ���� ��ž���. ������� �����ڸ� ��ǥ�� y, x�� ������
// idx = y / 3 * 3 + x / 3�� �ȴ�. �̰��� �̿��Ͽ� ���ĭ�� 9ĭ�� ���� �ߺ��迭 square�� ����Ѵ�.
// �������� ���õǾ��� �� ��� ���� �ߺ� ���� �����ؾ��ϱ⿡ �̰��� col�� row�� �ذ��Ѵ�.
// ������� ������ ���ĺ��ʹ� ��Ʈ��ŷ���� ��� ��츦 �ذ��ϸ� �ȴ�. ���������� ���� ���� ��츦 ����ؾ��ϱ⿡
// 1 ~ 9���� ������ ���� ��, ��, square�߿��� ���� ������ ���� ���� ���� ĭ�� �����ϸ� ���ư��� �ȴ�.

// �ٸ�, �Ѱ��� �Ǽ��� �ߴµ� ���簪�� �����ϰ� ��Ϳ��� ���ƿö� ���� ���� 0���� �ٲ��� �ʾҾ���. 
// �̷��� �Ǹ� �������� �ǵ��ư� ����� �ٽ� ������ ���� �����ϰ� �Ѿ�� ������ ����� �ذ���� �ʴ´�.

// �ڼ��� ������ �ּ����� �����.

// ���� ����, ����, ���ĭ�� 9ĭ�� ���� �ߺ�üũ�� �迭��.
bool row[9][10], col[9][10], square[9][10];
bool isfind = false;
int board[9][9];

// ��Ʈ��ŷ�� �̿��Ͽ� ��� ��츦 ��ȸ�ϴ� �Լ�.
void BackTrack(int idx)
{
    // ���� �̹� ã�Ҵٸ� ��� �����ϰ� Ż���Ѵ�.
    if (isfind)
        return;

    // ��� ������ �����ϰ� Ż�������� �����Ͽ��� ���.
    // board�� ������� ���� ã������ isfind = true�� �̿��Ͽ�
    // ������ Ż���Ѵ�.
    if (idx == 81)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j];
            }
            cout << '\n';
        }
        isfind = true;
        return;
    }

    // ���� ��ǥ�� y, x �׸��� square�� ��ǥ�� s_idx�� ���Ѵ�.
    int y = idx / 9;
    int x = idx % 9;
    int s_idx = y / 3 * 3 + x / 3;

    // ���簪�� 0�϶� ������ �����ϴ� ���� ã�´�. ���� ���� �����ϰ�
    // ���� ��ǥ�� �Ѿ��.
    if (board[y][x] == 0)
    {
        for (int iter = 1; iter < 10; ++iter)
        {
            if (!col[y][iter] && !row[x][iter] && !square[s_idx][iter])
            {
                col[y][iter] = row[x][iter] = square[s_idx][iter] = true;
                board[y][x] = iter;
                BackTrack(idx + 1);
                col[y][iter] = row[x][iter] = square[s_idx][iter] = false;
                // ���� �� �κ��� ���ƾ���. 0���� �ٽ� �ǵ����� ������ ����Ͽ���
                // �������� �ٽ� ����� ������ �����ϰ� �Ѿ�� �ȴ�.
                board[y][x] = 0;
            }
        }
    }
    // ���簪�� 0�� �ƴҽ� �����ϰ� �Ѿ��. ����Ͽ��� 0���� �ǵ����� ������
    // �� ���ǿ� ���Ͽ� ���� Ʋ���� �ȴ�.
    else
    {
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // �ߺ�üũ�� �迭���� �ʱ�ȭ.
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(square, false, sizeof(square));
    string str;
    for (int i = 0; i < 9; ++i)
    {
        cin >> str;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = str[j] - '0';
            // ���簪�� 0�� �ƴҽ� �� �ߺ�üũ�� �迭�鿡 ���� �����Ѵ�.
            if (board[i][j] != 0)
            {
                col[i][board[i][j]] = true;
                row[j][board[i][j]] = true;
                square[i / 3 * 3 + j / 3][board[i][j]] = true;
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}