#include <iostream>

using namespace std;

// Ǯ��.
// �������� �Ķ����� ���������� ��ġ�Բ� �ű涧 ���� �ּ����� Ƚ���� ����ϸ� �ȴ�.
// ó������ ����Ž���� ���������� �ִ� ���̰� 50���̶� �Ұ����ߴ�. ���� �ǿܷ� �����ߴµ�
// ����� ���� ����, Ȥ�� ���������� �̵����������� Ƚ���� ���غ��� �ȴ�.

// 1. �Ķ����� ��������
// 2. �Ķ����� ����������
// 3. �������� ��������
// 4. �������� ����������

// �� 4���� �񱳳��� ���� ª�� Ƚ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

string str;
int N, answer = 987654321;

// 4���� ������ �̹� ���������� �����ִ��� ���ϴ� �Լ�.
bool CheckArray()
{
    int num = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        if (str[i] != str[i + 1])
            ++num;
    }

    return num <= 1;
}

// �� ���� �������� �̵���Ű�� �Լ�.
void MoveBall(char first, char second, bool isFirst)
{
    int ans = 0, idx;
    // ó������ �����̶�� ���ʺ��� Ž���Ѵ�.
    if (isFirst)
    {
        // ���ʺ��� first�� ã�´�. �� ������ ������ �������� �̵���ų�� �ִ�.
        for (int i = 0; i < N; ++i)
        {
            if (str[i] == first)
            {
                idx = i;
                break;
            }
        }
        // first ���ĺ��� �̵������� ������ ���� ���Ѵ�.
        for (int i = idx + 1; i < N; ++i)
        {
            if (str[i] == second)
                ++ans;
        }
    }
    // ó������ ������ �ƴϱ⿡ �����ʺ��� Ž���Ѵ�.
    else
    {
        // �����ʺ��� first�� ã�´�. �� ������ ������ ���������� �̵���ų�� �ִ�.
        for (int i = N - 1; i >= 0; --i)
        {
            if (str[i] == first)
            {
                idx = i;
                break;
            }
        }
        // first ���ĺ��� �̵������� ������ ���� ���Ѵ�.
        for (int i = idx - 1; i >= 0; --i)
        {
            if (str[i] == second)
                ++ans;
        }
    }
    // ���� �ּҰ��� ã�´�.
    answer = min(answer, ans);
}

void MakeAnswer()
{
    cin >> str;

    if (CheckArray())
    {
        cout << 0 << '\n';
        return;
    }

    // ��� �������� �������� �ű涧.
    MoveBall('B', 'R', true);
    // ��� �������� ���������� �ű涧.
    MoveBall('B', 'R', false);
    // ��� �Ķ����� �������� �ű涧.
    MoveBall('R', 'B', true);
    // ��� �Ķ����� ���������� �ű涧.
    MoveBall('R', 'B', false);

    cout << answer << '\n';
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