#include <iostream>

using namespace std;

// Ǯ��.
// ��Ʈ��ŷ �����̴�. �ٸ� �����ؾ��Ұ��� ��� �ִ�.

// 1. �ֻ����� ����� �Ʒ����� ������ ���� �������� ����.
// 2. �ٸ� A��° ���� F��° ��� �´�� �ִµ��� �������� �����Ѵ�.
// 3. �� ��Ģ�� �ǰ��Ͽ� �ߺ��Ǵ� �κ��� ����. ���� dp�� �ǹ̰� ����.

// �� �κи� �� �ľ��ϸ� ���� ��ü�� �׸� ����� �ʴ�.
// �� �Ʒ��� Ȥ�� ������ �־������� ������� ���� �ִ밪�� ����ϸ� �ȴ�.
// ���� ��Ʈ��ŷ�� �̿��Ͽ� Ǯ���µ� �ٸ� ����鵵 ������ �ϴ�.

// �ڼ��� �κ��� �ּ����� �����.

// �迭�� ���ν�Ų��.
// ���ۺκ��� ���� -1��ų �ʿ���� prev����(���� �ֻ����� ������ ���� �ֻ����� �Ʒ�)��
// 0 ~ 6���� �ؼ� ������ �ȴ�.

int board[10000][6];
// ����� �Ʒ����� �������� �迭�� �����Ѵ�.
int map[6] = { 5, 3, 4, 1, 2, 0 };
int N;

// ���� �Ʒ����� �־������� ������� ���� ū ���� ã�Ƴ��� �Լ�.
int FindMax(int idx, int cur)
{
    int ans = 0;
    // 6���� �Ʒ���� ������ ������ ������� �ִ밪�� ��ȯ�Ѵ�.
    for (int i = 0; i < 6; ++i)
        if (i != cur && i != map[cur])
            ans = max(ans, board[idx][i]);

    return ans;
}

// �Ʒ����� �� prev�� �־������� N��° �ֻ������� ��ȸ�ϸ� ���� ū ������ ���ϴ� �Լ�.
int BackTrack(int idx, int prev)
{
    if (idx == N)
        return 0;

    int ans = 0;

    int cur;
    // �Ʒ����� ���� �־������� ���°(A ~ F)������ ã�Ƴ���.
    for (int i = 0; i < 6; ++i)
        if (board[idx][i] == prev)
        {
            cur = i;
            break;
        }

    // �Ʒ���� ������ ������ ������� ���� ū���� ã�Ƴ���.
    int cur_max = FindMax(idx, cur);
    // ���� �ֻ����� �Ѿ��.
    ans = max(ans, BackTrack(idx + 1, board[idx][map[cur]]) + cur_max);

    return ans;
}

void MakeAnswer()
{
    int answer = 0;

    // 6���� ���� ��� �Ʒ������� ������ ���� ū ������� ���� ���س���.
    for (int i = 1; i <= 6; ++i)
        answer = max(answer, BackTrack(0, i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}