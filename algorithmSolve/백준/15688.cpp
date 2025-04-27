#include <iostream>

using namespace std;

// Ǯ��.
// �׳� ���� �Է¹޾� sort()�� �����Ͽ� ����ص� ������ �̷��� for���� �ι� ����Ͽ�
// �տ������� ������ Ƚ����ŭ ������־ �ȴ�. �ٸ� sort()�� ����ȭ�� �ſ� �����ϰ� �Ǿ��ֱ⿡
// N�� Ư�⳪�� ū ��찡 �ƴϸ� �����ؾ��ϴ� �޸𸮿� ���� �ӵ��� �־ ���ǹ��� ���̴� ���� �ʾҴ�.

const int MAXNUM = 2000001;
int board[MAXNUM];
int N;

void Solve()
{
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        cin >> num;
        ++board[num + 1000000];
    }

    for (int i = 0; i < MAXNUM; ++i)
    {
        while (board[i])
        {
            cout << i - 1000000 << '\n';
            --board[i];
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    Solve();
    return 0;
}