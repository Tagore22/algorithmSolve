#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// �־����� �� N�� ���ӵ��� ���� ���¿��� 1, 2, 3�� ������ ǥ���ϴ� ����� ���� ����ϸ� �ȴ�.
// ����Ž���� DP�� �̿��Ͽ� �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

const int DIV = 1000000009;
int board[100001][4];
int T;

// ��� ����Ž���� �����ϴ� �Լ�.
int DFS(int num, int prev)
{
    // ���� �� num�� 2���� ������ �������� ���簪�� ���ٸ� 0��, �ٸ��ٸ� 1�� ��ȯ�Ѵ�.
    if (num <= 2)
        return prev == num ? 0 : 1;

    int& ans = board[num][prev];
    if (ans != -1)
        return ans;
    ans = 0;

    // 1, 2, 3 ��� ��츦 �����غ���.
    for (int i = 1; i <= 3; ++i)
    {
        // �������� ���簪�� ���ų� num���� ���簪�� ������ 0���� �۴ٸ� �����Ѵ�.
        if (i == prev || num - i < 0)
            continue;

        ans += DFS(num - i, i);
        ans %= DIV;
    }
    return ans;
}

void MakeAnswer()
{
    int num;
    memset(board, -1, sizeof(board));
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;

        int answer = DFS(num, 0);
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}