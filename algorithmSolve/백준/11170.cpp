#include <iostream>

using namespace std;

// Ǯ��.
// �� ��� Ǯ����ұ� �ϴٰ� ���������� Ǯ��� �ߴ�. �ִ� 100������ ���� �ִ� 6���� ������ �ϱ⿡
// �ִ� ���귮�� 600���� �ȵǾ���. �׷��� ������ �̸� 0 ~ 100������ 0�� ������ ���س���
// [to] - [from - 1]�� ���Ͽ� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

// 0 ~ 100���� ��ƾ��ϱ⿡ 100�� 1����.
int board[1000001];
int T;

// ��� �� num�� 0�� ������ ���ϴ� �Լ�.
int CalZero(int num)
{
    int ans = 0;
    while (num > 0)
    {
        if (num % 10 == 0)
            ++ans;
        num /= 10;
    }
    return ans;
}

// 0 ~ 100�������� 0�� ������ �̸� ���ϴ� �Լ�.
void Init()
{
    int ans = 1;

    for (int i = 0; i <= 1000000; ++i)
    {
        ans += CalZero(i);
        board[i] = ans;
    }
}

void MakeAnswer()
{
    Init();
    int from, to;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> from >> to;
        cout << board[to] - board[from - 1] << '\n';
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