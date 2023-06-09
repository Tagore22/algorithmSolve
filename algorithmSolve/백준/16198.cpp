#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� Ž�� ��������, dp�ʹ� �ٸ� ��Ʈ��ŷ �����̴�.
// ��� ��ȸ�� �������� �������� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int board[10];
int N, answer = 0;
bool check[10];

// �������� ���� ���� ����� ������ ���Ұ��� ��ȯ�ϴ� �Լ�.
int FindFront(int idx)
{
    while (true)
    {
        --idx;
        if (!check[idx])
            return idx;
    }
}

// �������� ���� ���� ����� ������ ���Ұ��� ��ȯ�ϴ� �Լ�.
int FindBack(int idx)
{
    while (true)
    {
        ++idx;
        if (!check[idx])
            return idx;
    }
}

// ��Ʈ��ŷ �Լ�. 1������ N - 2������ ���� ������� ����(�������� ����) ��ȣ�� �ϳ���
// ��󰡸� �������� ���� ������Ų��. ���� 2���� ���Ҵٸ�(�� ó���� �� �������� ���� ���⿡) ���� ����
// �������� ���Ѵ�.
void BackTrack(int num, int sum)
{
    if (num == 2)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 1; i < N - 1; ++i)
    {
        if (!check[i])
        {
            check[i] = true;
            int front = FindFront(i);
            int back = FindBack(i);
            BackTrack(num - 1, sum + board[front] * board[back]);
            check[i] = false;
        }
    }
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(N, 0);

    cout << answer << '\n';
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