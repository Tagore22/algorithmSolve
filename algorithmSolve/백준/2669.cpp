#include <iostream>

using namespace std;

// Ǯ��.
// ���ͺ��� �����а� ������ ���� ������ �����δ� ���� ���þ��� Ǯ�� �ִ�.
// �� Ǯ�̰� �Ʒ� Ǯ�̴�. ������ ������ �ʰ� �׳� �簢���� ��ǥ�� �Է¹޾�
// �� �������� board�� �����صθ� �ȴ�. �������� board�� ��ȸ�ϸ� ����Ǿ��ִ�
// �������� ��� ���� ����ϸ� �ȴ�. �Ƹ��� ������ ���������� �����Ϸ��ٰ�
// �ѱ�� ������ �׷��� �̹��� Ǯ� �����̴�.

int main()
{
    bool board[101][101] = { false, };
    int x1, y1, x2, y2;
    for (int iter = 0; iter < 4; ++iter)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = y1; i < y2; ++i)
            for (int j = x1; j < x2; ++j)
                board[i][j] = true;
    }
    int answer = 0;
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            if (board[i][j])
                ++answer;
    cout << answer << '\n';
    return 0;
}