#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ūƲ�� ������ ����.

// 1. � ī�� 2���� ��� �� ī���� ������ ���Ѵ�.
// 2. ���� ���� �� ī�� 2���� ���ο� ���� �ȴ�.
// 3. �̰��� M�� �ݺ����� ��� ī����� ���� �������� �ּҰ��� ����Ѵ�.

// �׸��������� �Ź� 2���� ī�带 ���� �� ���� ���� ���� ���� ��� ���ϸ� �ȴ�.
// ó������ �Ź� �����Ͽ� ���Ͽ����� �ʹ� �����ɷȴ�.
// �켱����ť�� set, map���� ����ص� �ǳ� ���� ���� �����̳ʸ� ����� �ʿ䰡 �������Ƿ�
// �켱����ť�� ����Ͽ� �����Ͽ���. ����, ī���� ���� �ִ� 100���̱⿡ ������ ���ҽ�
// int���� ������� �־� long longŸ���� ������ ����ؾ� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

priority_queue<long long> que;
int N, M;

void MakeAnswer()
{
    long long first, second, sum;
    // �տ��� 2��(���� ���� 2��)�� ������ ������ �ٽ� 2�� ť�� �����Ѵ�.
    // �̰��� M�� �ݺ��Ѵ�.
    for (int i = 0; i < M; ++i)
    {
        first = -que.top();
        que.pop();
        second = -que.top();
        que.pop();
        sum = first + second;
        que.push(-sum);
        que.push(-sum);
    }

    // ��� ������ ���� ����Ѵ�.
    long long answer = 0;
    while (!que.empty())
    {
        answer += -que.top();
        que.pop();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        que.push(-num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}