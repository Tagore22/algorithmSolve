#include <iostream>

using namespace std;

// Ǯ��.
// ī�̻縣 ��ȣ���� �ٽ� ������� �ǵ������� ���ĺ��� ������ 3���� ���� �ȴ�.
// �ٸ� �̷� ��� C���� ������ �Ǵµ� �� ��� A���� ���� ��ŭ Z���� �ٽ� ���� �ȴ�.
// �̶� ������ �������� 3�� �ƴ� 2�� �����ִ� �͵� �����ؾ� �Ѵ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string board, answer = "";
    cin >> board;
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i] - 3 >= 'A')
            answer += board[i] - 3;
        else
            answer += 'Z' - ('A' - board[i] + 2);
    }
    cout << answer << '\n';
    return 0;
}