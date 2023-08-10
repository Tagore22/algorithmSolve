#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ���� ó�� �Ӹ��� ���ö����� ��Ʈ��ŷ�̾���.
// ������ ���� �׷��ʿ䰡 ������. 1000�̶�� �ﰢ���� 44��°�ۿ� ���� �ʾҰ�, 3���� ���� ���̶�� �̸� �����־�����
// �ܿ� 3������. ���� �Ʒ� Ǯ��ó�� 45�� �������� 9��5õ���� �ȵǴ� �������� Ǯ�� �־���.
// �ʹ� ��ư� �����ϴ°� ����. ����ͺ��� ��������.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int T, K;

// ��� �ﰢ�� 3���� �̷���� ������ ���ϴ� �Լ�.
void Init()
{
    int num = 1;
    while (num * (num + 1) / 2 <= 1000)
    {
        board.push_back(num * (num + 1) / 2);
        ++num;
    }
}

// �ִ� 45�� �������� ��ȸ�Ͽ� ������� �ﰢ�� 3���� �̷������ �ִ��� Ȯ���ϴ� �Լ�.
int Check(int num)
{
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board.size(); ++j)
            for (int u = 0; u < board.size(); ++u)
                if (board[i] + board[j] + board[u] == K)
                    return 1;
    return 0;
}

void MakeAnswer()
{
    Init();
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> K;
        cout << Check(K) << '\n';
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