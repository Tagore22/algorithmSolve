#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������ �ι��ؾ��ϴ� ��������. ù��°�δ� �� ������ �������� �����ؾ��߰�, �� ���Ŀ���
// ������ ��ȣ�� �������� �����ؾ��ߴ�.

int main()
{
    pair<int, int> board[8];
    for (int i = 0; i < 8; ++i)
    {
        cin >> board[i].first;
        board[i].second = i + 1;
    }
    sort(board, board + 8, greater<pair<int, int>>());
    int answer = 0;
    int point[5];
    for (int i = 0; i < 5; ++i)
    {
        answer += board[i].first;
        point[i] = board[i].second;
    }
    cout << answer << '\n';
    sort(point, point + 5);
    for (int i = 0; i < 5; ++i)
        cout << point[i] << ' ';
    cout << '\n';
    return 0;
}