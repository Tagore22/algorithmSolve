#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �Ź� �ΰ��� ������ ���ļ� ��������� �ϳ��� ������ ����� �����ε� ��ĥ������ �� ������ ũ�⸸ŭ�� ����� ���.
// ���� ���� ���� 2���� ������ �Ź� ���ļ� �� ����� �ּ�ȭ�ؾ��Ѵ�. ��������� �켱���� ť�� �̿��Ͽ�
// ���� ���� 2���� ã�Ƴ����ߴ�. �ٸ� �Ź� ������ �ϴٺ��� �ð��� ��û���� ��ƸԾ���. ����, ���ʷ� �־����� �����
// �ִ� 10000�̱� ������ ��ġ�ٺ��� int���� ������� �־� long long Ÿ������ �����ؾ� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

priority_queue<long long, vector<long long>, greater<>> que;
int T, K;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // �켱���� ť���� clear()�� ����.
        // ���� ť�� �� �������� ������ pop()�� ȣ���ؾ� �Ѵ�.
        while (!que.empty())
            que.pop();
        cin >> K;
        int num;
        for (int i = 0; i < K; ++i)
        {
            cin >> num;
            // ��� ���ϵ��� ť�� ������ �����Ѵ�.
            que.push(num);
        }
        long long answer = 0;
        // ť�� ���������� ������ ���� �ϳ��� ���������� �ݺ��Ѵ�.
        while (que.size() > 1)
        {
            // ���� ���� 2���� ã�Ƴ��� ���ϰ� �ٽ� �� ���� ť�� �ִ´�.
            // ����, ������ answer���� �����ش�.
            long long first = que.top();
            que.pop();
            long long second = que.top();
            que.pop();
            answer += first + second;
            que.push(first + second);
        }
        // ������ ���.
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}