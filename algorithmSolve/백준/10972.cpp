#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��ü�� ������ �ƴϴ�. �� �״�� ���� ������ ã�� ����ϵ�,
// �̹��� ������ �����̶�� -1�� ����ϸ� �ȴ�. ������ STL�� ���� ������ ã���ִ� 
// next_permutation()�� �����Ѵ�. �� �Լ��� ���� ������ �����Ұ�� ���� �迭�� ���� ������
// �������ϰ�, �̹��� ������ ������ ��� ���� �ٲ��, false�� ����Ѵ�.

// bool next_permutation(~.begin(), ~.end())
// ���� ������ �迭�� ��������. �̹� ������ ������ ������ ���(������������ ���� �������� ���)����
// false�� ��ȯ�Ѵ�. �ð����⵵�� ���ƾ� ��� ������ �� / 2�̴�.

// �̰͸� �˸� ��� ������ ���� ������. ������ �̰��� �𸣸� ���� �������� �� ����.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N;

void MakeAnswer()
{
    // ���� ������ ������������ ������ ��ȯ�ϴ°�.
    bool isEnd = next_permutation(board, board + N);

    // true��� ���� ������ ���������� �����ĵ� �迭�� �����.
    if (isEnd)
    {
        for (int i = 0; i < N; ++i)
            cout << board[i] << ' ';
    }
    // false��� �̹� ������ ������ �����̾����Ƿ� -1�� �����.
    else
    {
        cout << -1;
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}