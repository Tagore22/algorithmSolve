#include <iostream>

using namespace std;

//������ ���� �˼� �ִ� ������ �뷫 4�����ε�
//1. N�� 1���϶� = ������
//2. N�� 2���϶�
//2-1. board[0]�� board[1]�� ���ٸ� �����ε� ��� ���⿡ board[0]�� ���
//2-2. board[0]�� board[1]�� �ٸ��ٸ� ������
//3. �� �̿ܿ��� ���� ���� ���غ����Ѵ�.

//a�� board[2] - board[1] / board[1] - board[0]���� �˼� �ִµ� �̰� ���� ����غ����Ѵ�.
//N�� 3�϶� ù��° ���� x��� �θ� �ι�° ���� ax + b ���װ� ����°���� a(ax + b) + b�� �ȴ�.
//�̰� board[2] - board[1] / board[1] - board[0]�ϸ� ���ڴ� a((a-1)x + b)�� �ǰ�
//�и�� (a-1)x + b�� �Ǿ� ������ a�� ���´�.

//b�� �ռ� ���� a�� �̿��� board[1] - board[0] * a�� ���ϸ� �ȴ�.

//���� �־��� �迭�� ��ȸ�ϸ� �̹� ���� a�� b�� �̿��Ͽ� ���� ���ҿ� ���Ѵ�.
//�ٸ� �ѹ��̶� ���� Ʋ����� ���� ���Ҽ� ���� ����̹Ƿ� B�� ����ϰ�
//������ ���ұ��� �ٴٸ� ��� board[N-1] * a + b�� ����Ѵ�.

int board[50];
int N;

void MakeAnswer()
{
    if (N == 1)
    {
        cout << 'A' << '\n';
        return;
    }
    else if (N == 2)
    {
        if (board[0] == board[1])
            cout << board[0] << '\n';
        else
            cout << 'A' << '\n';
        return;
    }
    else
    {
        int a = 0;
        if (board[0] != board[1])
            a = (board[2] - board[1]) / (board[1] - board[0]);
        int b = board[1] - board[0] * a;

        for (int i = 1; i < N; ++i)
            if (board[i] != board[i - 1] * a + b)
            {
                cout << 'B' << '\n';
                return;
            }
        cout << board[N - 1] * a + b << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}