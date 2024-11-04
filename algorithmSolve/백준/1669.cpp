#include <iostream>

using namespace std;

// Ǯ��.
// �� 4 ~ 5���� �̷� ������ ���Ҵ�. ���� �˷��� �˰��� ����� �ƴ� ������ ������ �ʿ��� �����鸻�̴�.
// ������ �����ڸ� ������ ���Ҹ����� �𸣰ڴ�. �̰� �� ������ Ȯ���Ѱ͵� �ƴϰ� ã�Ⱑ �ָŸ�ȣ�ϴ�.
// ��...

int x, y;

void MakeAnswer()
{
    if (x == y)
    {
        cout << 0 << '\n';
    }
    else
    {
        long long cost = 0;
        int dist = y - x;

        while (cost * cost < dist)
            ++cost;

        if (cost * cost - cost < dist)
            cout << cost * 2 - 1 << '\n';
        else
            cout << cost * 2 - 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    MakeAnswer();
    return 0;
}