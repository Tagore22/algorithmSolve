#include <iostream>

using namespace std;

// Ǯ��.
// ����� ��Ʈ��ŷ �����̴�. ����ϴ� ŰƮ�� ������ ���� ���� �޶����Ƿ� ��� ����� ���� �������� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[8];
bool check[8] = { false, };
int N, K, answer = 0;

// ��� ����� ���� ��ȸ�ϴ� �Լ�.
void BackTrack(int cur, int num)
{
    // ���� ���� �߷��� 500�� �ȵȴٸ� �� ����� �����Ѵ�.
    if (cur < 500)
        return;

    // 500�� �����ϸ� N���� ��� ����� ��� ������ answer�� 1 ������Ű�� Ż���Ѵ�.
    if (num == N)
    {
        ++answer;
        return;
    }

    // ��� ŰƮ�� ��ȸ�ϸ�, ��� ������ ŰƮ�� ����ϰ� ���ȣ���Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            BackTrack(cur + board[i] - K, num + 1); // ���⼭ K�� �ƴ� ���ÿ� �־��� K�� 4�� �־� �ѹ� Ʋ�ȴ�.. T^T
            check[i] = false;
        }
    }
}

void MakeAnswer()
{
    BackTrack(500, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}