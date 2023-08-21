#include <iostream>

using namespace std;

// 2526���� ���� ����ȭ�� Ǯ��.
// board�迭�� boolŸ���� �ƴ� intŸ������ �ٲٸ� ���� ���λӸ� �ƴ϶� ���� ��������
// �ѹ��� �˾Ƴ��� �ִ�. 

// �ڼ��� ������ �ּ����� �����.

// ���� bool �迭���� int �迭�� ����Ǿ���. �� ����Ѵ�� ���� ���λӸ� �ƴ϶� ���� ��������
// �ѹ��� �����Ҽ� �ִ�.
int board[97] = { 0 };
int N, P;

void MakeAnswer()
{
    // �� ���� ������ �����ϴ� count ����. 
    int count = 1;
    board[N] = count;
    int cur = N;
    while (true)
    {
        cur = cur * N % P;
        // �̹� ������ ���� �ٽ� ������ ���, ��� ���� Ƚ�� - ���� ���� ���� ���� + 1�� ���� ���Ѵ�.
        if (board[cur] != 0)
        {
            cout << count - board[cur] + 1 << '\n';
            return;
        }
        board[cur] = ++count;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}