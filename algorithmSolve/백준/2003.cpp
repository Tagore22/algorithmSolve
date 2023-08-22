#include <iostream>

using namespace std;

// Ǯ��.
// i��° ���Һ��� �����ؼ� ���ӵ� ������ ���� M�� ����� ���� ����ϴ� ������.
// ������ ������ �ִ� 10000���� 2�� for���� �ᵵ 1��ۿ� ���� �ʾƼ�
// ����� Ǯ���� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[10000];
int N, M;

void MakeAnswer()
{
    int answer = 0;
    int cur;
    // ��� ����(���� ��ġ)�� ��ȸ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        cur = 0;
        // ���� ��ġ���� ��� ���Ҹ� ��ȸ�ϸ� �� ���ҵ��� ���� M�̰ų� �� Ŭ������ ��ȸ�Ѵ�.
        for (int j = i; j < N; ++j)
        {
            cur += board[j];
            // �� ũ�ų� ������ �ι�° for���� Ż���Ѵ�. �ٸ� m�� ���������� ������ answer�� 1 �����ش�.
            if (cur >= M)
            {
                answer = cur == M ? answer + 1 : answer;
                break;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}