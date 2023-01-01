#include <iostream>

using namespace std;

//���� �򰥷ȴ� ����. �ٸ� �� ĭ�� ox, xo, xx�θ� �Ѽ� �ֱ⿡ �ǿܷ� ���� ��������.

//Ǯ��
//�� ����Ͽ��� �� ĭ�� ox, xo, xx�� ó���Ҽ� �ִ�. �ٸ� ���η� �پ� ������ �ȵǱ⿡ �װ��� �� ó���ؼ�
//N����� ��ȸ�Ͽ� ��� ����� ���� ���� ����ϸ� �ȴ�.

int board[100001][3];
int N;
const int DIV_NUM = 9901;

void MakeAnswer()
{
    board[1][0] = 1;
    board[1][1] = 1;
    board[1][2] = 1;

    for (int i = 2; i <= N; ++i)
    {
        board[i][0] = (board[i - 1][1] + board[i - 1][2]) % DIV_NUM;
        board[i][1] = (board[i - 1][0] + board[i - 1][2]) % DIV_NUM;
        board[i][2] = (board[i - 1][0] + board[i - 1][1] + board[i - 1][2]) % DIV_NUM;
    }

    cout << (board[N][0] + board[N][1] + board[N][2]) % DIV_NUM << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}