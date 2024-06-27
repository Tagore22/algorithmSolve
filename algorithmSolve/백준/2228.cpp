#include <iostream>

using namespace std;

// Ǯ��.
// ���� �������. ����. �������� 30�ۼ�Ʈ�� �ȵǴ� �����̴� �翬�Ѱǰ�.
// ������ DP�� �̿��� Ǯ���̴�. ���� idx��° ���ҿ� �����Ͽ����� ������ �ൿ�� 2������ �����Ѵ�.

// 1. ���� ���Ҹ� ���ο� �������� �����.
// 2. ���� ���Ҹ� �ǳʶڴ�.

// �� 2������ �����ϸ� �ȴ�. �������� ����� �ʾҴµ� ��.. ���� �ʹ� ��ư� �����Ѱ� ���⵵ �ϰ� �ƴϸ�
// ������ ���� �˾Ƽ� ����� �ʰ� �����ϴ°� ���⵵ �ϰ�. ��·�� ���ϵ� ��������.

// �ڼ��� ������ �ּ����� �����.

int N, M;
int board[100];
int dp[100][51];

// ��� ����� ���� ��ȸ�ϴ� �Լ�.
int BackTrack(int idx, int num)
{
    // M���� ��� ����ٸ� 0�� ��ȯ�Ͽ� ��ȸ�� �����.
    if (num == M)
        return 0;
    // �ǳ� �� ����� �迭�� ����ٸ� �ſ� ū ���� ��ȯ�Ͽ� �����Ѵ�.
    if (idx >= N)
        return -987654321;

    int& ans = dp[idx][num];
    if (ans != -1)
        return ans;

    // 1. idx��° ���Ҹ� �ǳ� �� ���.
    ans = BackTrack(idx + 1, num);
    int sum = 0;
    // 2. idx��° ���Һ��� i���� ���Ҹ� �������� ����� ���.
    // �̶� �ִ� N������ �Ͽ� �������� �Ѿ�� ���� ������ʿ��� �ɷ����� ������
    // ��� ��츦 �� �غ���.
    for (int i = idx; i < N; ++i)
    {
        sum += board[i];
        // ������ �����ϸ� �ȵǱ⿡ �̹� ���� + 2��° ���ҷ� �̵��Ѵ�.
        ans = max(ans, BackTrack(i + 2, num + 1) + sum);
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= M; ++j)
            dp[i][j] = -1;
    cout << BackTrack(0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}