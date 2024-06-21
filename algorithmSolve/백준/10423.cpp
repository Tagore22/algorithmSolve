#include <iostream>

using namespace std;

// Ǯ��.
// �ּ� ���д� Ʈ���̴�. �ٸ� ũ�罺Į�� �ͼ����� �ʾƼ� �������� Ǯ����. �ϳ� ������ ȭ�� ����.
// ��Ǯ���µ� ���� ����Ѱ����� �ϳ� �߲������̴�. �� ��ð� ��ǰ� ����. �׷��� ūƲ�� Ʋ���� �ʾҴٴ°�
// �ټ� ������ ������, �귯 ���� �ð��� ������ ���� �� ���̾���.

// ��·�� Ǯ�̸� ���ڸ� �⺻���� �������� �޶���. �⺻���� ������ �ּ� ���д� Ʈ�� ��ü�� ��� �����ϵ�
// ������� ���� ������ 0��° �������� �����ϸ� ������ �� ��쿡�� �������� ���� �����ߴ�. �װͿ� �����ؾ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int N, M, K, sum = 0, answer = 0;
bool connect[1001] = { false, };
int path[1001][1001], len[1001];

void MakeAnswer()
{
    // �������� ���� �����ϱ⿡ ���ؾ� �Ѵ�. ���ʿ� ������κ��� ����Ǿ� �ִ� �������� ã���鼭
    // ������ ���̸� �����س�����.
    
    // ��� �ּ� ���̴� �ִ밪���� �ʱ�ȭ�Ѵ�.
    for (int i = 1; i <= N; ++i)
        len[i] = 10001;
    // ��� �������� ��ȸ�ϸ鼭 �����ҿ� ����� ������ �����Ҷ� �׿� ����� �������� �ּ� ���̸�
    // �����س�����.
    for (int i = 1; i <= N; ++i)
    {
        if (connect[i])
        {
            for (int j = 1; j <= N; ++j)
                len[j] = min(len[j], path[i][j]);
        }
    }
    while (sum < N)
    {
        int dis = 10001, next;
        for (int i = 1; i <= N; ++i)
        {
            // ���� ���� ���� �������� �ּұ��̰� ���� ª�� ������ �����Ѵ�. ���⼭ ����� �Ǽ��� �߻��ߴ�.
            if (!connect[i] && len[i] < dis)
            {
                next = i;
                dis = len[i]; // �ٷ� �̺κ��ε� dis�� �������� �ʾƼ� ���� ª�� ������ ���õǴ� ���� �ƴ϶�
                              // dis���� �ּұ��̰� ª�� �������� ���� �� �� ������ �������. T^T
            }
        }
        // ������ ��������� �����ϰ� answer�� sum���� �߰��Ѵ�.
        connect[next] = true;
        answer += len[next];
        ++sum;
        // ���� ����� ���� next�� ��ȸ�ϸ� ����� �������� �ּұ��̸� �ٽ� �����Ѵ�.
        for (int i = 1; i <= N; ++i)
        {
            if (!connect[i] && len[i] > path[next][i])
                len[i] = path[next][i];
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            path[i][j] = 10001;
    int pos;
    for (int i = 0; i < K; ++i)
    {
        cin >> pos;
        connect[pos] = true;
    }
    sum = K;
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        path[from][to] = cost;
        path[to][from] = cost;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}