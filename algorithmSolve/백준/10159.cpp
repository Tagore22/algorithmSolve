#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// Ǯ��.
// 10159���� ���� �������� Ǯ���̴�.
// �׷��� Ž������ Ǯ���µ� �ߺ����� ��͵Ǵ� ���� ���⿡
// ǥ���� ���� ��� Ǭ�Ͱ���.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> heavy, light, dp;
bool visit[101];
int N, M;

// �ߺ��Ǵ� ���� ������ ǥ����ü�� ����.
int CalAnswer(int idx, int isheavy)
{
    visit[idx] = true;

    int ans = 0;

    if (isheavy == 1)
    {
        for (int iter = 0; iter < heavy[idx].size(); ++iter)
        {
            int there = heavy[idx][iter];
            if (!visit[there])
                ans += CalAnswer(there, isheavy) + 1;
        }
    }

    else
    {
        for (int iter = 0; iter < light[idx].size(); ++iter)
        {
            int there = light[idx][iter];
            if (!visit[there])
                ans += CalAnswer(there, isheavy) + 1;
        }
    }

    return ans;
}

void MakeAnswer()
{
    int answer;
    for (int iter = 1; iter <= N; ++iter)
    {
        // �Ź� �湮 ���θ� �������־�� ������ ����.
        answer = 1;
        memset(visit, false, sizeof(visit));
        answer += CalAnswer(iter, 1);
        memset(visit, false, sizeof(visit));
        answer += CalAnswer(iter, 0);

        cout << N - answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    heavy.resize(N + 1, vector<int>());
    light.resize(N + 1, vector<int>());
    dp.resize(N + 1, vector<int>(2, -1));
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        light[from].push_back(to);
        heavy[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}