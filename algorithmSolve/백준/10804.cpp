#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// reverse()�� �̿��ϸ� ��ó�� ª�� ������ �ڵ带 �����Ҽ� �ִ�. ���� ���͸� ������� �ʰ�
// int �迭�� ����ص� �ȴ�.

vector<int> board;
int from, to;

int main()
{
    for (int i = 1; i <= 20; ++i)
        board.push_back(i);
    for (int i = 0; i < 10; ++i)
    {
        cin >> from >> to;
        reverse(board.begin() + (from - 1), board.begin() + to);
    }
    for (auto n : board)
        cout << n << ' ';
    cout << '\n';
    return 0;
}