#include <iostream>
#include <queue>

using namespace std;

// 2003�� �� ����Ǯ��.
// ���� for���� �ƴ� �ϳ��� for������ �̿��Ͽ� Ǭ Ǯ�̴�.
// ������ �������Ϳ� ����ѵ�, 0��° ���Һ��� �� ���ϴٰ� �� ���� M�̰ų� �� Ŀ���ٸ�
// ���۾��������� �� �տ��Һ��� �����Ѵ�. �� ���߿� ���� M�̸� ������ answer�� 1 �����ְ�
// �ٽ� N��° ���ұ��� ��ȸ�� �ݺ��Ѵ�. ����ϴ� �޸𸮴� ���ݴ� �þ��µ� �Ϲ� �迭�� �ƴ�
// deque�� ����ؼ� �׷��� ����.

// �ڼ��� ������ �ּ����� �����.

deque<int> deq;
int N, M;

void MakeAnswer()
{
    int answer = 0;
    int ans = 0;
    int cur;
    // 0��°���� N - 1��° ���ұ��� ��ȸ�� �Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        // ���� ���� �Է¹޾� ���ҵ��� �� ans�� ������ deq�� �߰��Ѵ�.
        cin >> cur;
        ans += cur;
        deq.push_back(cur);
        // �� ans�� M���� �۾��������� ���� ó���� �߰��� ���Ҹ� �����س�����.
        while (ans >= M)
        {
            // �� ���߿� ans�� M�� �ȴٸ� ������ answer�� 1 �߰��Ѵ�.
            answer = ans == M ? answer + 1 : answer;
            int erase = deq.front();
            ans -= erase;
            deq.pop_front();
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}