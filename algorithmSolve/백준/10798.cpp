#include <iostream>

using namespace std;

// Ǯ��.
// ����� ��ȸ ���� �����̴�.
// �ٸ� �Ѱ��� �Ǽ������� �ִµ� MakeAnswer()���� 2��° for���� �ִ� ���ǹ��̴�.
// size()�� ���ϱ� ������ ��ĭ ���� ���ؾ��ϴµ� �� �κ��� �����ߴ�.
// ����� �Ϳ��� ��������.

// �ڼ��� ������ �ּ����� �����.

string board[5];
int max_size = 0;

void MakeAnswer()
{
    for (int iter = 0; iter < max_size; ++iter)
        for (int i = 0; i < 5; ++i)
        {
            // ����Ͽ��� �� �κп��� �Ǽ��� �־���. size()�� ���ϱ� ������ iter�� ���ٸ� ����Ҽ� ����.
            if (board[i].size() <= iter)
                continue;
            cout << board[i][iter];
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        cin >> board[i];
        int cur_size = board[i].size();
        max_size = max(max_size, cur_size);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}