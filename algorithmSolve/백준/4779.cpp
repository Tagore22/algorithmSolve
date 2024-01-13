#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// ���� ������ ��͸� �̿��� ������. ���ڿ��� 3����Ͽ� ��� �κ��� �������� �ٲٰ� ������ �κκ��� �ٽ�
// ��� �Լ��� ���Ͽ� �ٽ� �����⸦ �ݺ��Ѵ�. ���� ���ڿ��� ���̰� 1�̶� ���̻� 3����� �Ҽ� ���ٸ�
// - �� ����ϰ� Ż���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int N;

// �ݺ��Ǵ� ��� �Լ�.
void MakeStr(int from, int to)
{
    // from == to��� ���� ���̴� 1�̹Ƿ� ���̻� 3���� ����������.
    // ���� - �� ����ϰ� Ż���Ѵ�.
    if (from == to)
    {
        cout << '-';
        return;
    }
    // ���� ���̸� 3����Ͽ� �պκ��� ����Լ��� ȣ���Ѵ�.
    int size = (to - from + 1) / 3;
    MakeStr(from, from + size - 1);
    // ��� �κ��� �������� �ٲ۴�.
    for (int i = 0; i < size; ++i)
        cout << ' ';
    // �޺κ��� ȣ���Ѵ�.
    MakeStr(to - size + 1, to);
}

void MakeAnswer()
{
    while (cin >> N)
    {
        MakeStr(0, pow(3, N) - 1);
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}