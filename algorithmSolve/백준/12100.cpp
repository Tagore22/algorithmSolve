#include <iostream>
#include <vector>

using namespace std;

// Ǯ��
// ������ ���õ� �������� �ִ�. 5�� ���������� ����� �ִ� ���� ū ��ϼ��� ����ϸ� �ȴ�.
// ó������ �ִ� 5�� �̵��̶�淡 �� �״�� 5���� �̵��� ���� ū ���� ����ϸ� �Ǵ��� �˾Ҵµ� �ִ� 5���� �̵��߿��� ���� ū���� �ƴϰ�
// �ִ� 5�� �̵��ؼ� ��� ���� ū ��ϼ�����. �̰� ������ ������ �ظ̴�. ���״�� �� Ǯ�� �̰� �ϳ� ������ ������ Ʋ���� �����߰� �־���.
// ���� ������ �̷��� ���� �;���.

// �� ������ �ٽ��� ��ǻ� �̵��� �����ϴ� ���̴�. �������� �¿���� 4���� �̵��� �ݺ��ϵ� �̵��� 5��°�� �Ǹ� board�� ��ȸ�ϸ� ���� ū
// ��ϼ��� �����ϰ� �������� ����ϸ� �Ǳ� �����̴�.

// �׷� �������� ������ �����̴�, �������� �����̴� �͸� ���캸�ڴ�.
// �����ؾ��Ұ��� ������ ����.
// 1. ���� [idx][j]���� ���������� ���� �������� �̵� ���������� ���ɴ�. �ٸ� j��ü�� -- ���Ѽ� �̵���Ű�� ���� ��ȸ�� ���� ���̱� ������
// ���� �ε������� �����ϴ� ���� cur�� �����Ͽ� j������ �ʱ�ȭ���� �����̷� �̵��س�����.
// 2. �������� �̵��� ���纸�� ������ ����ִٸ�(���� 0�̶��) ��� �������� �̵��ϸ� ���簪�� ���ʰ��� �ٲ۴�.
// 3. ���̻� �������� �̵��Ҽ� ������ ���� ���� ��ĥ�� �ִ��� Ȯ���Ѵ�. �̶� ������ ������ ����.
// 3-1. ���簪�� ���ʰ��� ������?
// 3-2. ���ʰ��� �̹� �̵��� ������ ��찡 �ִ°�? �̸� ���� 2���� ���� check�� �ʿ��ϸ� �� �̵��� �ʱ�ȭ���־���Ѵ�.
// 4. ����� ���ǿ� �������� ���� ��� �׳� �����ϰ� �������� �Ѿ��, �����ҽ� ���ʰ��� 2��� �ø���(���簪�� ������) ���簪�� 0�� �Ǹ�,
// ���ʰ��� �������⿡ check���� false�� �����Ѵ�.

// �̷� �̵��� ���� �����¿�� ��Ʈ��ŷ�� ���Ѵ�. �� ���� 5���� �̵��� �Ϸ�Ǹ� �׶� �ִ� ��ϰ��� answer�� �����ذ��� �������� ����Ѵ�.

// P.S �Լ����� BackTrack�̿��� �ϴµ� DFS�� �߸� �������;;



vector<vector<int>> board;
vector<vector<bool>> check;
int N, answer = 0;

void MoveBoard(int idx) // 0 ~ 4 �� �� �� ��
{
    int cur;
    check.clear();
    check.resize(N, vector<bool>(N, true));
    if (idx == 0)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 1; j < N; ++j)
            {
                cur = j;
                while (cur > 0 && board[i][cur - 1] == 0)
                {
                    swap(board[i][cur], board[i][cur - 1]);
                    --cur;
                }

                if (cur > 0 && board[i][cur - 1] == board[i][cur] && check[i][cur - 1])
                {
                    board[i][cur - 1] += board[i][cur];
                    board[i][cur] = 0;
                    check[i][cur - 1] = false;
                }
            }
    }
    else if (idx == 1)
    {
        for (int j = 0; j < N; ++j)
            for (int i = 1; i < N; ++i)
            {
                cur = i;
                while (cur > 0 && board[cur - 1][j] == 0)
                {
                    swap(board[cur][j], board[cur - 1][j]);
                    --cur;
                }

                if (cur > 0 && board[cur - 1][j] == board[cur][j] && check[cur - 1][j])
                {
                    board[cur - 1][j] += board[cur][j];
                    board[cur][j] = 0;
                    check[cur - 1][j] = false;
                }
            }
    }
    else if (idx == 2)
    {
        for (int i = 0; i < N; ++i)
            for (int j = N - 2; j >= 0; --j)
            {
                cur = j;
                while (cur < N - 1 && board[i][cur + 1] == 0)
                {
                    swap(board[i][cur], board[i][cur + 1]);
                    ++cur;
                }

                if (cur < N - 1 && board[i][cur + 1] == board[i][cur] && check[i][cur + 1])
                {
                    board[i][cur + 1] += board[i][cur];
                    board[i][cur] = 0;
                    check[i][cur + 1] = false;
                }
            }
    }
    else
    {
        for (int j = 0; j < N; ++j)
            for (int i = N - 2; i >= 0; --i)
            {
                cur = i;
                while (cur < N - 1 && board[cur + 1][j] == 0)
                {
                    swap(board[cur][j], board[cur + 1][j]);
                    ++cur;
                }

                if (cur < N - 1 && board[cur + 1][j] == board[cur][j] && check[cur + 1][j])
                {
                    board[cur + 1][j] += board[cur][j];
                    board[cur][j] = 0;
                    check[cur + 1][j] = false;
                }
            }
    }
}

void FindMax()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] > answer)
                answer = board[i][j];
}

void DFS(int num, vector<vector<int>> temp)
{
    if (num == 5)
    {
        FindMax();
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        MoveBoard(i);
        DFS(num + 1, board);
        board = temp;
    }
}

void MakeAnswer()
{
    DFS(0, board);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N, 0));
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