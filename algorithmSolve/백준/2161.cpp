#include <iostream>
#include <deque>

using namespace std;

// Ǯ��.
// �������ſ� ���Ҹ� �ǵڷ� �Űܾ��ߴµ� Ư���� �������Ÿ� ����ϰ� �Ҽ� �ִ� �����̳ʴ� ���� ������.
// ���߿��� Queue�� �����ߴµ� �Ǿ��� ���Ҹ� �����ؾ������Ƿ� Deque�� ��ȯ�ߴ�.
// �Ǿ��� ���Ҹ� �����ϰ� �ι�° ���Ҹ� �Ǹ��������� �ű�� ���� ������ ������ 1���� ���������� �ݺ��ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

deque<int> deq;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 1 ~ N������ ���ҷ� �ʱ�ȭ.
    for (int i = 1; i <= N; ++i)
        deq.push_back(i);
    // Deque�� ���Ұ� �Ѱ����� ���ٸ� �ݺ��Ѵ�.
    while (deq.size() > 1)
    {
        // �Ǿ��� ���Ҹ� �����ϸ� ����Ѵ�.
        cout << deq[0] << ' ';
        deq.pop_front();
        // �ι�° ���Ҹ� �����ϸ� �ǵڿ� �߰��Ѵ�.
        deq.push_back(deq[0]);
        deq.pop_front();
    }
    // ���� ������ ���Ҹ� ����Ѵ�.
    cout << deq[0] << '\n';
    return 0;
}