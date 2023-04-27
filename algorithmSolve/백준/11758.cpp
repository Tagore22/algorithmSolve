#include <iostream>

using namespace std;

// Ǯ��.
// CCW��� ���� �˰����� ��������. (Counter Clock Wise)
// ó�� �� �˰����̶� ���� ��̴�.

// �⺻���� ������ �׸� ����� ������
// a, b, c�� ���� ������ �� c - a�� b - a�� ���͸� �������

// bx - ax , by - ay
// cx - ax , cy - ay
// �� ����ϸ� �ȴ�. ��갪��

// (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)�� �Ǵµ� �̰��� 
// 1. ������� �ð����.
// 2. 0�̶�� ����.
// 3. ������ �ݽð������ �ȴ�.



pair<int, int> board[3];

void MakeAnswer()
{
    int answer = (board[1].first - board[0].first) * (board[2].second - board[0].second) -
        (board[1].second - board[0].second) * (board[2].first - board[0].first);

    if (answer > 0)
        cout << 1 << '\n';
    else if (answer == 0)
        cout << 0 << '\n';
    else
        cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}