#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//ó������ �ʹ� �����ϰ� y��, x��� �����ϴ� ���簢���� �����ߴ�.

//Ǯ��
//�� 4���� ���� �Է¹����� ������ �Ͽ� �� ���� ��ġ�� ��´�. (0��°�� ���� �Ʒ�, 1��°�� ������ �Ʒ� ���)
//�� ���� ���̸� ������, �밢���� ���� ���� ���Ͽ� ���� ���̰� �������� ����, �밢���� ���̰� �� ���� ������ ������ ���� ������
//Ȯ���Ͽ� 0 �Ǵ� 1�� ����Ѵ�.
//���������� �־����� �Է°��� ���밪�� 10�������� ���̸� ���ϴµ� �־� �������� ����ϱ⿡ �ܼ� int�� �ƴ� long long�� ����Ͽ�
//�����÷ο쿡 �����Ѵ�.

pair<long long, long long> board[4];
int T;

long long CalLen(pair<long long, long long> x, pair<long long, long long> y)
{
    return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

bool IsAnswer()
{
    long long zero_one = CalLen(board[0], board[1]);
    long long zero_two = CalLen(board[0], board[2]);
    long long two_three = CalLen(board[2], board[3]);
    long long one_three = CalLen(board[1], board[3]);

    long long zero_three = CalLen(board[0], board[3]);
    long long one_two = CalLen(board[1], board[2]);

    if (zero_one == zero_two && zero_one == two_three && zero_one == one_three &&
        zero_three == zero_one + one_three && one_two == zero_one + zero_two)
        return true;
    else
        return false;
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        for (int idx = 0; idx < 4; ++idx)
            cin >> board[idx].first >> board[idx].second;

        sort(board, board + 4);

        if (IsAnswer())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}