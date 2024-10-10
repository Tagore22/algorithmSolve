#include <iostream>

using namespace std;

// Ǯ��.
// �Ӹ��� �ȵ��ư���. ���� �ھ߰ڴ�. DP�������� �Ϲ����� DP�ʹ� ���� �ٸ���.
// �������� �ּҰ��̳� �ִ밪�� ���ؼ� DP���� ��ȯ������ �̹��� DP�� �ش� ������ ����Ǿ������� ���θ� ������.
// ����, ���� DP�� ����ϳ� �ǹ��̾���. DP�� �ߺ��� �����ϱ� �����ε� �ߺ������� �Ǵ� ��Ȳ�� �������� �ʾұ� �����̴�.
// ������ �� �����غ��� �ݵ�� �����ߴµ� ���� ��� AAAABBBBCCCC�� �̿��Ҷ� ��� ���� �� �������� B, C ���°� �Ǵ�
// ������ ������ ���� ���̴�. �� ��� �������� �ߺ��� �ȴ�. �� �� 2���� �����ϰ� ���꿡 ������ �ʱ� �����̴�.
// �׷��� ������ �ݵ�� DP�� ��߸� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

int board[3];
bool dp[51][51][51][3][3] = { false, };
char ans[51];
string str;

// DFS �Լ�. �� a, b, c�� ���� ����� �������� ��, ���� ��.
bool DFS(int a, int b, int c, int pp, int p)
{
    // ��� ���Ǿ��ٸ� ������ ��ȯ�Ѵ�.
    if (a == board[0] && b == board[1] && c == board[2])
        return true;

    // ó�� ����ÿ� cur�� false�����̸� ���� ���۽� true�� �ȴ�. �� ���� �ߺ��� �ȴٸ�
    // �����ϱ� ���� false�� ��ȯ�ϰ� Ż���Ѵ�.
    bool& cur = dp[a][b][c][pp][p];
    if (cur)
        return false;
    cur = true;

    if (a + 1 <= board[0] && DFS(a + 1, b, c, p, 0))
    {
        ans[a + b + c] = 'A';
        return true;
    }
    // B���ʹ� ������ ���� ���ĺ����� Ȯ���ؾ� �Ѵ�.
    if (b + 1 <= board[1] && p != 1 && DFS(a, b + 1, c, p, 1))
    {
        ans[a + b + c] = 'B';
        return true;
    }
    if (c + 1 <= board[2] && pp != 2 && p != 2 && DFS(a, b, c + 1, p, 2))
    {
        ans[a + b + c] = 'C';
        return true;
    }
    return false;
}

void MakeAnswer()
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'A')
            ++board[0];
        else if (str[i] == 'B')
            ++board[1];
        else
            ++board[2];
    }
    if (DFS(0, 0, 0, -1, -1))
    {
        for (int i = 0; i < str.size(); ++i)
            cout << ans[i];
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}