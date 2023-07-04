#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ����Ѱ��� üũ���� ���� �ѹ��� Ǭ ������.
// ������ �о�� ��Ʈ��ŷ �����ӿ� Ʋ������. �ٸ� dp�� ����ؾ� �ϴ°� �ϸ� �װ� �� �ƴѵ�
// ���� ���� ���� �� ���� ���� ���ϱ� �����̴�. �׷��� ������ ��� ����� ���� ��Ʈ��ŷ���� ���ؼ�
// ���ǿ� �ش��ϴ� ��츦 �ٽ� �߷����� �ȴ�.

// ��Ʈ����ũ�ε� Ǯ���� ������ �̷��� ������ε� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int board[15];
int N, L, R, X, answer;

// ��� ����� ���� ��ȸ�ϴ� ��Ʈ��ŷ �Լ�.
void BackTrack(int idx, int sum, int min_num, int max_num)
{
    // ���� ���ǿ� �����Ѵٸ� ���� 1 ������Ų��.
    if (L <= sum && sum <= R && X <= max_num - min_num)
    {
        // ���� �ּ�ģ �κ��� �߸��Ǿ���. ���� ���ǿ� �����Ͽ� ���� 1 �������� ������ ���Ҹ� ������ �ֱ⿡
        // �׳� Ż���ϸ� �ȵȴ�.
        ++answer;
        //return;
    }

    // �ߺ��� ���ϱ� ���� ���� ���� ���ĺ��� ���������� ��ȸ�ϸ� ���ǿ� �����ϴ�(���̵��� ������ R���� �۰ų� ���ƾ��Ѵ�.)
    // ���Ҹ� ������� ��͸� ȣ���Ѵ�.
    for (int i = idx + 1; i < N; ++i)
    {
        if (sum + board[i] <= R)
        {
            int next_sum = sum + board[i];
            int next_min = min(min_num, board[i]);
            int next_max = max(max_num, board[i]);
            BackTrack(i, next_sum, next_min, next_max);
        }
    }
}

void MakeAnswer()
{
    answer = 0;
    BackTrack(-1, 0, 987654321, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}