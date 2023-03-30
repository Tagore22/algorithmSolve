#include <iostream>
#include <queue>
#include <cstring>

// �־����� ��ȣ�� 12�� ������� �����Ͽ� �ð� �����̴�.
// �ð� �������� �������� �ǵڸ� �Ǿ����� �ű��,
// �ݽð� ������ �Ǿ��� �ǵڷ� �ű��.

using namespace std;

// Ǯ��.
// �����ϴ� ������ �Ｚ ������. ���ó� �Ｚ ��������.
// �� ������ ������ ���� ũ�� 2���� �����ϸ� �ȴ�.

// 1. ������ ������ �Լ�.
// 2. ���ݵ��� ��ȣ�� ��ȸ�ϸ� �����ϸ鼭 ���� ���� �ִ��� Ȯ���ϴ� �Լ�.

// �ٸ� ������ ������ ���ŷӰų� ������ �ִ�.
// ����, 2�� ���ǿ��� ���� ���� ������ ����� ���� ��� ���� ��հ� ���ϴµ�
// �̶� �Ҽ����� ������ �ʰ� �״�� ������ �ִµ� ������ �����ؾ� �Ѵ�.
// ó������ �ƿ� ���Ҹ� double�� �޾Ƽ��� �غôµ� ���� ������ �ִٺ���
// ���� ������ �������� �Ұ����ߴ�. int�� ���� ������ ������ ������ ������ �Ҷ�����
// double�� ��ȯ�ϴ� ���� �����̴�.

// �ڼ��� ���� �ּ��� �����.

struct rota
{
    int x;
    int d;
    int k;
};

deque<int> board[51];
bool check[51][51];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��
rota r[50];
int N, M, T;

// ������ ȸ���ϴ� �Լ�. �����ε� �ð��� �߸� ������.
void MoveClock(int idx)
{
    int div = r[idx].x;
    int dir = r[idx].d;
    int num = r[idx].k;

    // div�� ����� ���ݸ� ȸ����Ű�� ������ �������� 0�� �ƴ� 1�� ��Ҵ�.
    for (int i = 1; i <= N; ++i)
        if (i % div == 0)
        {
            // ���� �ð� ����� �ݽð� �����϶�. ȸ���� deque�� �����Ͽ� ����� �ʾҴ�.
            if (dir == 0)
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].back();
                    board[i].pop_back();
                    board[i].push_front(cur);
                }
            else
                for (int iter = 0; iter < num; ++iter)
                {
                    int cur = board[i].front();
                    board[i].pop_front();
                    board[i].push_back(cur);
                }
        }
}

// ����� 2�� ������ �Լ�. 
void EraseNum()
{
    // ���� ���� �ٲپ������ ���� ��ȸ�� ����� ���� �񱳵Ǿ� ��Ȯ�� ���� ���Ҽ� ����.
    // �׷��⿡ �ܼ��� üũ�ϴ� bool Ÿ���� �迭�� ������ �س��� �� �������� ���� �����ؾ��Ѵ�.
    memset(check, false, sizeof(check));

    // �����ϸ鼭 ���� ���� ã�Ҵ����� Ȯ���ϴ� ����.
    bool isfind = false;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            // ���� 0, �� ������ ��ȣ��� �����Ѵ�.
            if (board[i][j] == 0)
                continue;

            for (int iter = 0; iter < 4; ++iter)
            {
                int dy = i + rot[iter][0];
                int dx = j + rot[iter][1];

                // ����Ͽ��� ��������� 0���� �ƴ� 1������ �����߱⿡ y�� 0�� �Ǹ� �ȵȴ�.
                if (dy <= 0 || dy > N)
                    continue;

                // x���� ȸ���Ǳ⿡ ������ ������� ����� �Ѵ�.
                if (dx == M)
                    dx = 0;
                else if (dx == -1)
                    dx = M - 1;

                if (board[i][j] == board[dy][dx])
                {
                    isfind = true;
                    check[i][j] = true;
                    check[dy][dx] = true;
                }
            }
        }

    // �����ϸ鼭 ���� ���� ã�Ҵٸ� �ش� ������ ��� 0���� �ٲپ������.
    if (isfind)
    {
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (check[i][j])
                    board[i][j] = 0;
    }

    // ã�� ���ߴٸ� ��� ���� ����� ���Ͽ� ��պ��� ũ�ٸ� -1��,
    // �۴ٸ� +1�� ���ش�. �ٸ� �����ÿ��� �ƹ��� ��ġ�� ������ ������
    // �Ҽ����� ������ �ʱ⿡ double���� ��ȯ�� ����ؾ� �Ѵ�.
    // �ƿ� ���Ұ��� double�� �ص� �ȵǸ� �� ������ ����Ͽ���.
    else
    {
        int num = 0;
        int sum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    ++num;
                    sum += board[i][j];
                }

        // �Ҽ����� ������ �ʱ⿡ double���� ��ȯ�� ����ؾ� �Ѵ�. + ������ �°�.
        double div = static_cast<double>(sum) / num;

        // ��� ������ �����Ѵ�.
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] != 0)
                {
                    if (board[i][j] > div)
                        --board[i][j];
                    else if (board[i][j] < div)
                        ++board[i][j];
                }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        MoveClock(i);
        EraseNum();
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            answer += board[i][j];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> T;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int cur;
            cin >> cur;
            board[i].push_back(cur);
        }

    for (int i = 0; i < T; ++i)
        cin >> r[i].x >> r[i].d >> r[i].k;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}