#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ������... �� Ǯ���µ� �Ǽ��� �ߴޱ�.. ����.. ������ �ٽ��� �ִ� 600���� ������ ���� �ٸ� 4����
// ��� 2���� ���� �� ���� ���̰� �ּҰ��� ��츦 ����ϴ� ���̴�. ������ ��� ��츦 �ѷ����⿡��
// 600�� 4�����̱⿡ ����� �Ұ����ߴ�. ���� �̸� 2���� ���� ������ ������� �� ���鿡�� ������
// �����ϴ� ���� �ٽ� 2���� ã��� �ߴ�. �̸� 2���� ���� ���� 600�� 2�����̹Ƿ� 36���ۿ� ���� �ʴ´�.
// �� ���� �ռ� ����� �ִ� 36������ ���Ҹ� ��ȸ�ϸ� ������ ���Ұ� ���� �ٸ� �����̸� ����� ��� �� ���̰���
// �ּҰ��� ���Ѵ�. ���ĵ� �����̱⿡ ������ ������ ���̰� ���� �۱� �����̴�. ���� �����̾����� �ϼ���
// �Ѱ��� ũ��ū �Ǽ��� ���� �ѽð��� ��ǰ� ����. �׷��� �������� 30�ۿ� �����ϰ� �� ������ Ǯ���⿡ ������.

// �ڼ��� ������ �ּ����� �����.

struct snow
{
    int first;
    int second;
    int sum;
};

vector<snow> sums;
int board[600];
int N;

// �� �����̸� ���Ͽ� �����ϱ� ���� �Լ�. ���̰��� �������� ��.
bool SortFunc(const snow& l, const snow& r)
{
    if (l.sum != r.sum)
        return l.sum < r.sum;
    else if (l.first != r.first)
        return l.first < r.first;
    else
        return l.second < r.second;
}

void MakeAnswer()
{
    // ��� ���ҵ��� ��ȸ�ϸ� 2���� ��� �̸� ����Ѵ�.
    // �������� �����̰� �Ʒ����̺��� �۾ƾ� �ϴ� ������ �־�����,
    // �����غ��� �ʿ����. �ƹ��ų� ū���� �Ʒ��� �ְ� �������� ���� ������ �Ǳ� ������
    // �ߺ��� ��길 �ƴ϶�� �ʿ䰡 ����.
    for (int i = 0; i < N - 1; ++i)
        for (int j = i + 1; j < N; ++j)
            sums.push_back(snow{ i, j, cur });

    sort(sums.begin(), sums.end(), SortFunc);
    // answer�� ���� 987654321�̾���. ���� �������� ���� 987654321�� �ʱ�ȭ�ߴµ� �̰� �ٷ�
    // ����� ġ������ �Ǽ���. �־��� ���� �ִ밪�� 10������ �� ���Ұ��� ���� 20���� ��찡 �ִ�.
    // �׸��� �ٸ� ���� 10�� ��쵵 ���� ���̴�. �̶� �� ���� ���̴� 19���� �پ�Ѵµ� �̷� ���
    // answer�� �� �۴ٺ��� ������ ���� �ʴ� ���̴�. �ٷ� �� �κ��� ��������.
    int answer = 2000000001;
    // ��� 2���� ������� ������ ��ȸ�Ѵ�.
    for (int i = 0; i < sums.size() - 1; ++i)
    {
        // ������ ���� ���� �ٸ� 2���� �����̸� �� ���¶�� ������ ����̹Ƿ� �ּҰ� answer�� �����Ѵ�.
        if (sums[i].first == sums[i + 1].first || sums[i].first == sums[i + 1].second ||
            sums[i].second == sums[i + 1].first || sums[i].second == sums[i + 1].second)
            continue;
        answer = min(answer, sums[i + 1].sum - sums[i].sum);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

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