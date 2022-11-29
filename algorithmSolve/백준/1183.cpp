#include <iostream>
#include <algorithm>

using namespace std;

int board[50];
int N;

//Ǯ��
//y = |x| + |x-3| + |x-6| + |x-9|�� �׷������� y���� ������ x������ 0, 3, 6 ,9�� �������� �����Ͽ� �� �߾Ӱ��� 3���� 6���� �Լ� �׷����� ���� �˼� �ִ�.
//���� n�� Ȧ���� n���Ŀ����� �� �߾Ӱ��� �� �Ѱ����̱⿡ �ּҰ� ���� �Ѱ���.

void MakeAnswer()
{
    sort(board, board + N);
    if (N % 2 == 1)
        cout << 1 << '\n';
    else
        cout << (board[N / 2] - board[N / 2 - 1] + 1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[i] = a - b;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}