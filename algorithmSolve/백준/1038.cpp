#include <iostream>
#include <vector>
#include <queue>

//������ ���� 0~9�� ���Ϳ� �ְ� �� ���� �ڿ� ���� �߰��� ������.
//ex) 1 >>> 10
//�ٸ� �����ϴ� ���̱⿡ �ٷ� ���ڸ����� �� ���������� �߰��Ǿ�� �ϱ⿡
//���� ���� 10���� ������ ���� �ֱ� ���� ���ؼ� �� ������ ���� ����� ä���.
//����, ���� ū �����ϴ� ���� 9876543210���� ���� ���� �Ѿ� ������ Ȥ�� ť�� ����� ������ �� ���� ������ ���Ѵ�.
//ex) 9876543210�� 1022��° ���̱⿡ �׺��� ū 1500���� ���Ҽ��� ���� -1�� ����ؾ���.

using namespace std;

vector<long long> board;
int N;
const int MAXNUM = 1000000;

void CalFirst()
{
    queue<long long> que;
    for (int i = 0; i < 10; ++i)
    {
        board.push_back(i);
        que.push(i);
    }
    while (board.size() <= N && !que.empty())
    {
        long long now = que.front();
        que.pop();
        int div = now % 10;
        for (int i = 0; i < div; ++i)
        {
            long long next = now * 10 + i;
            que.push(next);
            board.push_back(next);
        }
    }
}

void MakeAnswer()
{
    CalFirst();
    if (board.size() - 1 >= N)
        cout << board[N] << '\n';
    else
        cout << -1 << '\n';
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