#include <iostream>

using namespace std;

// Ǯ��.
// ������ ���� �������Ҵ�. �����δ� ������ �ָ��ؼ� ���� ����������� ������ Ǯ��� �˾Ҵ�.
// ��������δ� �� �ð����� �����Ǿ� �ִ� Ʈ���� ���� �����ذ��� ���� �� �ð����� �����Ǿ� �ִ� Ʈ���� �� *
// ������ ��� ���Ͽ� ����ϸ� �ȴ�. �ٸ� �Ʒ� Ǯ�̿����� 0 ~ 100�� ��� ��ȸ���� �ʰ� ����ġ�⸦ ����ϱ� ����
// ������ ���� ���� �ð��� ���� ���� �ð��� ���Ͽ� ���� ���� �ð� ~ ���� ���� �ð� - 1������ ��ȸ�Ͽ���.

int main()
{
    int cost[4] = { 0, };
    for (int i = 1; i <= 3; ++i)
        cin >> cost[i];
    int from = 101, to = -1, left, right;
    int board[101] = { 0, };
    for (int i = 0; i < 3; ++i)
    {
        cin >> left >> right;
        from = min(from, left);
        to = max(to, right);
        for (int j = left; j < right; ++j)
            ++board[j];
    }
    int answer = 0;
    for (int i = from; i < to; ++i)
        answer += cost[board[i]] * board[i];
    cout << answer << '\n';
    return 0;
}