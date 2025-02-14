#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// Ǯ��.
// ���̵��� �� �ְ� �������� ������� ����� ��������. ���İ� �켱���� ť�� �̿��� ����������
// �� ���� ����� �� �������� �ʾҴ�. ���۸��� �ߴµ� �׳� N * C����ŭ ��ȸ�ϸ� ã�� ���̾���.
// ó������ ���귮�� 4���� �Ѿ�⿡ �䰡�ΰ� ������ if���� ���� ����ġ�Ⱑ �ְ�,
// �� ������ �������� �ʱ⿡ �����ѵ� �ʹ�. ����, �켱����ť�� ������ ť�� �ִ� �� �������
// ���귮�� ũ�� ���̳��µ� �켱����ť�� ���� ������� �ٷ� ť�� �־ ������, ���ڴ�
// ������ �ϱ� ���� ���� ������ �ص��Ŀ� �ٽ� ��ȸ�ϸ� ť�� �ֱ⿡ �ξ� ���ȴ�.

// ����, ���� ����� ������ �����ͺ��� ä�������� �ϴµ� ���� �������� ������ ���� ������
// Ž���� �ؾ� �ִ��� ���� �Ҹ� ���� �ִ�.

// �ڼ��� ������ �ּ����� �����.

// �켱���� ť�� ����� ���� ���� �Լ�.
struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

int C, N;
int chi[20000];
bool visit[20000] = { false, };
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;

void MakeAnswer()
{
    sort(chi, chi + C);
    int answer = 0;
    while (!que.empty())
    {
        int from = que.top().first, to = que.top().second;
        que.pop();
        // ��� �ߵ��� ��ȸ�ϸ� ���ǿ� �´� ũ�Ⱑ ���� ���� ù��° ���� ����.
        for (int i = 0; i < C; ++i)
        {
            if (from <= chi[i] && chi[i] <= to && !visit[i])
            {
                ++answer;
                visit[i] = true;
                break;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> C >> N;
    for (int i = 0; i < C; ++i)
        cin >> chi[i];
    for (int i = 0; i < N; ++i)
    {
        int num1, num2;
        cin >> num1 >> num2;
        que.push(make_pair(num1, num2));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}