#include <iostream>

using namespace std;

// Ǯ��.
// ��Ʈ��ŷ �����̴�. 1 ~ N�������� ������ ���� true Ȥ�� false�� ���Խ�Ų�� �� ����
// �������� ��� true�� �Ǵ����� Ȯ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

bool board[21];
int clause[200];
int N, M;
bool isfind = false;

// �� ���� ���� ��� true���� Ȯ���ϴ� �Լ�.
bool Check()
{
    for (int i = 0; i < M; i += 2)
    {
        // �� ���� ù��° ������ �ι�° ����.
        bool first = board[abs(clause[i])];
        bool second = board[abs(clause[i + 1])];

        // �� ���� ������ - ���¶��.
        if (clause[i] < 0)
            first = !first;
        if (clause[i + 1] < 0)
            second = !second;

        // ���� �ϳ��� true�� �ƴ϶�� ���� ���·δ� ���� ã���� ����.
        if (!first && !second)
            return false;
    }
    return true;
}

void BackTrack(int idx)
{
    if (isfind)
        return;

    if (idx == N + 1)
    {
        // ���⼭ ���� true�� ����� �ֳ� Ȯ���Ѵ�.
        // ����� �ִٸ� isfind�� true�� �����ϰ� Ż���Ѵ�.
        if (Check())
            isfind = true;
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        board[idx] = i;
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    // ���⼭ ��Ʈ��ŷ
    BackTrack(1);

    cout << (isfind ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    M *= 2;
    for (int i = 0; i < M; ++i)
        cin >> clause[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}