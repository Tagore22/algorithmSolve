#include <iostream>

using namespace std;

// Ǯ��.
// ������ Ǯ���� ���� ���� ������ ���� ��������.
// �� �� �� ���� ���� ��̴µ� �����ϴ°� �ٽ� Ǯ� ���Ҵ�.
// �ٸ� ������ ��ǥ���� �ִ� 100�� �ΰ� ������ �ѹ� Ʋ�ȴ�.
// �ִ� 100���̱⿡ ��갪�� int���� ����� �־� long long�� ����ߴ�.
// ������ �� ����.

// �ڼ��� ������ �ּ����� �����.

pair<long long, long long> pos[4];

// ����, ������, �߾�(���� ���а� ������)�� �ִ����� Ȯ���ϴ� CCW�Լ�.
// �ٸ� ����Ͽ��� ��ǥ���� �ִ� ���밪 100���� �ѱ⿡ int�� �ƴ� long longŸ������ �ؾ��Ѵ�.
int CCW(const pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c)
{
    long long ans = ((b.first - a.first) * (c.second - b.second)) - ((c.first - b.first) * (b.second - a.second));
    if (ans < 0)
        return -1;
    else if (ans == 0)
        return 0;
    else
        return 1;
}

void MakeAnswer()
{
    int first = CCW(pos[0], pos[1], pos[2]) * CCW(pos[0], pos[1], pos[3]);
    int second = CCW(pos[2], pos[3], pos[0]) * CCW(pos[2], pos[3], pos[1]);

    // �� ������ �������� �����Ҷ�.
    if (first == 0 && second == 0)
    {
        if (pos[0] > pos[1])
            swap(pos[0], pos[1]);
        if (pos[2] > pos[3])
            swap(pos[2], pos[3]);
        // �� ������ �������� �����ϳ� ������������ ������.
        if (pos[1] < pos[2] || pos[3] < pos[0])
            cout << 0 << '\n';
        // ������������.
        else
            cout << 1 << '\n';
    }
    else
    {
        // �� �� first�� second�� ���� �ϳ��� 1�̸� �������� �ʴ´�.
        // 1 �̶�� ���� � ���п��� �ٸ� ������ �� ���� ���ʿ� �����ִٴ� ���� ���ϱ� �����̴�.
        if (first <= 0 && second <= 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> pos[i].first >> pos[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}