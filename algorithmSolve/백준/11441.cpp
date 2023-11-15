#include <iostream>

using namespace std;

// Ǯ��.
// from��° ���Һ��� to��° ���ұ����� ���� ����ϴ� ������ ������.
// to������ ������ - from - 1������ �������� �� ��ȭ���̴�.
// �������� ������ �����ϰ� �ִٸ� ����� ���� ��������.

// �ڼ��� ������ �ּ����� �����.

// �������� �����صδ� int �迭.
int board[100001];
int N, M;

void MakeAnswer()
{
    int from, to;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> from >> to;

        // to������ ������ - from - 1������ �������� ���� ����Ѵ�.
        cout << board[to] - board[from - 1] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num, cur = 0;
    // 1������ N�� ���ұ����� �������� �̸� ���س��´�.
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        cur += num;
        board[i] = cur;
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}