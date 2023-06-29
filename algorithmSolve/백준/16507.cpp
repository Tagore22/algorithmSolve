#include <iostream>

using namespace std;

// Ǯ��.
// �־��� �� ������ �������� ������ ����� ����ϴ� ������.
// �־����� �迭�� ���� 1000 * 1000�̰�, �׽�Ʈ ���̽� Q�� 10000�ε� 1000���� �߸�����
// ó������ 10���̴ϱ� �ǰ��� �ϰ�� �������̷� Ǯ������ �翬�� �ð��ʰ��� ���Դ�.
// ������ �������� �̿��ϴ°��̾��µ� ������ �����Ͽ��� �ô� �������� �̿��ϴ� ���̾���.
// ������ �� ���簢���̱� ������ �׸��� �׷����� Ǯ�� �����ϱⰡ ����. �������� ���ϴ°� ������ ����.

// 1. ���� ���ؾ� �ϴ� �� x, y�� ������ �迭 sum�� �ִٰ� �Ѵ�.
// 2. x - 1�� 0���� Ŭ��(�־��� ��ǥ�� ������ 1, 1������) sum[x - 1][y]���� ���Ѵ�.
// 3. y - 1�� 0���� Ŭ�� sum[x][y - 1]�� ���Ѵ�.
// 4. sum[x - 1][y - 1]�� �ι� ���ŵǾ��� ������ �ٽ� sum[x - 1][y - 1]�� �����ش�.
// 5. ���������� board[x][y]���� �����ش�.

// �̰��� �ٷ� ��ǥ x, y�� ���簢�� �������� ���ϴ� ����̴�.
// ��ó���� ��� ��ǥ���� �������� �������� ��ġ�� �ʴ� �κе��� ���ְ� �ռ� ����������
// �ι� ���ŵȰ����� �ٽ� �����༭ ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[1001][1001], sum[1001][1001];
int R, C, Q;
pair<int, int> from, to;

// ����� �� ��ǥ�� ���簢�� ��� �������� ���ϴ� �Լ�.
void CalSum()
{
    int ans;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
        {
            ans = 0;
            if (i - 1 > 0)
                ans += sum[i - 1][j];
            if (j - 1 > 0)
                ans += sum[i][j - 1];
            if (i - 1 > 0 && j - 1 > 0)
                ans -= sum[i - 1][j - 1];
            ans += board[i][j];
            sum[i][j] = ans;
        }
}

// �� �������� �̸� ��������, ���۰��� ������ �޾� �� ����� ����Ѵ�.
void MakeAnswer()
{
    CalSum();
    int answer;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> from.first >> from.second >> to.first >> to.second;

        // �������� �����Ѵ�.
        answer = sum[to.first][to.second];
        // ������� ���Ե��� �ʴ� ������ �����Ѵ�. �ٸ� ���ǹ��� �ɾ� �迭������ �����°��� �����ؾ��Ѵ�.
        if (from.first - 1 > 0)
            answer -= sum[from.first - 1][to.second];
        // ���� ����.
        if (from.second - 1 > 0)
            answer -= sum[to.first][from.second - 1];
        // �������� ���Ҷ��� ����, �ι� ���ŵ� �κе��� �����ϹǷ� �ٽ� ä���־��־�� �Ѵ�.
        if (from.first - 1 > 0 && from.second - 1 > 0)
            answer += sum[from.first - 1][from.second - 1];
        // ��ǥ���� ������ ������ ����Ѵ�.
        answer /= (to.first - from.first + 1) * (to.second - from.second + 1);
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> Q;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}