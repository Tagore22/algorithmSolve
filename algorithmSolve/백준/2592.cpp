#include <iostream>

using namespace std;

// �־����� 10���� ���� ��հ��� ���� ���� �����ϴ� �ֺ��� ���ϴ� ����.

int board[100] = { 0, };
int sum = 0;

int main()
{
    for (int iter = 0; iter < 10; ++iter)
    {
        int num;
        cin >> num;
        sum += num;
        ++board[num / 10];
    }
    pair<int, int> answer = make_pair(0, -1);
    for (int iter = 1; iter < 100; ++iter)
        if (board[iter] > answer.second)
            answer = make_pair(iter * 10, board[iter]);
    cout << sum / 10 << '\n';
    cout << answer.first << '\n';
    return 0;
}