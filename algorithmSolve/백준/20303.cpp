#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ��û���� ����� ��������. ������ �������� 30�۰� �ȵȴ�. �ʹݿ��� �밭 Ʋ�� ��Ҿ���.
// �и� DP�� �̿��� ������������. �׷��� idx��° ���̸� ���������� �� ������ ģ������ ã�°���
// ��������. ó������ bool �迭 visit������ �̿��ؼ� idx��°�� ģ������ ��� ã���� visit = true;��
// �������� ���߿� ���� Ȥ���� �ߺ��� ���Բ� �߾���. �Ұ����ߴ�. ��������δ� ���Ͽ� ���ε带 �̿��Ͽ�
// ���� ��Ʈ�� �ִ� ������ ��� 30000���� ������ ���°� �ƴ� �� ��Ʈ�鸸 ��ȸ�Ͽ� ���°��� �����̾���.
// ����, ������ ���ȣ�� ����ϰ� �Լ��� �����ߴµ� �� �κп����� �ð��ʰ��� ����. ������ ������ �����ΰ� ����.
// �ֽô��� ����, DP, �׷���, ���Ͽ� ���ε���� �����ִ� �ſ� �������� �����ε�, �ƹ����� �����ڰ� �׳� �� ����������ϴ�.

// �ڼ��� ������ �ּ����� �����.

int N, M, K;
int c[30001], dp[30001][3001], p[30001], all[30001];
vector<int> f[30001], board;

// ���Ͽ� ���ε��� Find() �Լ�. Ư���Ұ� ����.
int Find(int num)
{
    if (p[num] == num)
        return num;

    // �� �κ��� ����ȭ�� �κ��ε� ���ȣ��� ���ÿ� ���� �����ϱ� �����̴�.
    return p[num] = Find(p[num]);
}

// ���Ͽ� ���ε��� Merge() �Լ�. ������ rank[]�� �̿��Ͽ�
// Ž���� ����ȭ���Ѿ� ������ �뷮�� �ָ��Ͽ� �׳� �����ȴ�.
void Merge(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    p[b] = a;
}

void MakeAnswer()
{
    // ���� ��Ʈ�鸸�� ������ �ܰ�. ���� ģ������ ������ �ľ��Ѵ�.
    for (int i = 1; i <= N; ++i)
    {
        int h = Find(i);
        f[h].push_back(i);
        board.push_back(h);
    }
    // �� �κп��� ���� ���� ������ ����. �ֳ��ϸ� ���� ��� 1, 2, 3�� ģ���ε�
    // ���� ��Ʈ�� 1�̶�� N���� ��ȸ�ϸ鼭 1, 2, 3�� ��Ʈ�� 1�� 3�� ���� �����̴�.
    // ���� �Ʒ� �κп��� �ߺ��� ���� �����ϱ� ���� ������ ������ ������ ���ٸ� ��� �����ϴ�
    // unique �Լ��� ����Ѵ�.
    sort(board.begin(), board.end());
    board.erase(unique(board.begin(), board.end()), board.end());
    // �� ��Ʈ���� ��� ������ ���� ���Ѵ�.
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < f[board[i]].size(); ++j)
            all[i] += c[f[board[i]][j]];
    int answer = 0;
    // ���ȣ���� �ƴ� �ܼ� for���� �̿��� DP Ǯ��.
    // �ߺ�����.
    for (int i = 0; i < board.size(); ++i)
    {
        int cur = board[i];
        int num = f[cur].size();
        int candy = all[i];
        for (int j = K - 1; j >= 0; --j)
        {
            if (j >= num)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - num] + candy);
            else
                dp[i + 1][j] = dp[i][j];
            answer = max(answer, dp[i + 1][j]);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        p[i] = i;
    for (int i = 1; i <= N; ++i)
        cin >> c[i];
    int a, b;
    // ó���� ���Ͽ� ���ε带 ��� �����ؾ� �ұ� �ߴµ� �̰ſ���.
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        Merge(a, b);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}