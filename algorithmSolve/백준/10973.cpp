#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���������� ������������ �� �������� ���鶧 ���� �־����� ������ ���� ������ ���ϴ� ������.
// �����ϰ� ������ �������ʿ� ���� STL�� prev_permutation()�� �̿��ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N;

void MakeAnswer()
{
    // permutation �迭�� �Լ��� ��� bool�� ��ȯ�Ѵ�. ���� ������ �����ϸ� true��, �������� �ʴ´ٸ� false�� ��ȯ�Ѵ�.
    // �� ���������� ���� ������ �����ϴ����� ��ȯ�Ѵ�.
    bool isFind = prev_permutation(board, board + N);

    // ���� ������ �����ϸ� ����Ѵ�.
    if (isFind)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << board[i] << ' ';
        }
    }
    // �������� �ʴ´ٸ� -1�� ����Ѵ�.
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
    {
        cin >> board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}