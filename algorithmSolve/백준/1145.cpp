#include <iostream>

using namespace std;

//�־����� ���� �ִ밪�� 100�̹Ƿ� ��� ����� ũ��� �ִ� 100 * 100 * 100�� 100������ �Ʒ��̹Ƿ�
//1���� ���ʴ�� ��� 3���� ���� ������ �ִ� ���� �ɶ����� 1�� �����ϸ� ã�ƺ��� �ð����� ã���� �ִ�.

int board[5];

void MakeAnswer()
{
    int now = 1;
    while (true)
    {
        int div = 0;
        for (int i = 0; i < 5; ++i)
            div = now % board[i] == 0 ? div + 1 : div;
        if (div >= 3)
        {
            cout << now << '\n';
            return;
        }
        ++now;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}