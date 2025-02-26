#include <iostream>

using namespace std;

// Ǯ��.
// �־��� ���� ���� �׷��� ���� K�� �� �������� ��������. ���ؾ��ϴ� ���� ������ ������� ���� ���¿���
// K�� �׷����� ���� �������� �ּҰ��� �ִ밪�̾����Ƿ� �Ű� ���� Ž���� �̺� Ž������ ���Ҽ� �־���.
// 0�� ��� �������� ���� + 1�� �������� ������ ���ݾ� �ٿ�������. �߰������� K���� �׷��� ���Ѽ� �ִٸ�
// ������ ū������ �ű�� �׷��� ���ϴٸ� ���������� �ٿ������� �ȴ�.

int N, K, Sum = 0;
int Board[100000];

// ���ݰ� Mid�� �־����� K���� �׷��� ���Ҽ� �ִ��� Ȯ���ϴ� �Լ�.
bool CheckNum(int Mid)
{
    int Cur = 0, Num = 0;
    for (int i = 0; i < N; ++i)
    {
        Cur += Board[i];
        // ���� ������ Mid���� ũ�ٸ� �ϳ��� �׷��� ����� ������ 0���� �ʱ�ȭ�Ѵ�.
        if (Cur >= Mid)
        {
            ++Num;
            Cur = 0;
        }
    }
    return Num >= K;
}

void MakeAnswer()
{
    int From = 0, To = Sum + 1;
    while (From <= To)
    {
        int Mid = (From + To) / 2;
        if (CheckNum(Mid))
            From = Mid + 1;
        else
            To = Mid - 1;
    }
    // From == To�� ������ ������ �����Ѵٸ� From�� 1�� �����ѻ����̱� ������ -1�� ������ϰ�
    // �����Ѵٸ� From�� ��ȭ�� ������ �� ������ ������ ���̱� ������ ���� -1�� ������Ѵ�.
    cout << From - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> Board[i];
        Sum += Board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}