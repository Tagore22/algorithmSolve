#include <iostream>

using namespace std;

//Ǯ��
//���� ������ �Ǻ���ġ�� ���� ���ؾ��Ұ�ó�� ���̳�, �����δ� ��Ģ�� �ִ�. �־����� n�� �����鼭 ¦����� ��������� �Ǻ���ġ�� ���ϱ� -1�� �ϸ�
//�ǰ� �� �̿ܶ�� ���� �ǵ帱 �ʿ���� ���� ��ġ�ϱ� �����̴�. ���� �־����� n�� �˻��Ͽ� -1, 0, 1 �� �ϳ��� ����ϰ� n������ �Ǻ���ġ��
//����ѵ� ���밪�� ����϶�� �߱⿡ �׳� �Ǻ���ġ���� �״�� ����ϸ� �ȴ�.

int board[1000001];
int n;
const int DIV_NUM = 1000000000;

void MakeAnswer()
{
    if (n == 0)
        cout << 0 << '\n';
    else if (n < 0 && n % 2 == 0)
        cout << -1 << '\n';
    else
        cout << 1 << '\n';

    board[0] = 0;
    board[1] = 1;

    n = n >= 0 ? n : n * -1;

    for (int i = 2; i <= n; ++i)
        board[i] = (board[i - 2] + board[i - 1]) % DIV_NUM;

    cout << board[n] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}