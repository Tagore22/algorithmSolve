#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// �� ���������� �Ｚ ������� ������ ������.
// ó���� ���� �������� �������鼭 ��� �����س����� Ǯ����.
// ó�� �����ߴ� ���� ��� ����������. �׷��ٰ� �������� ��Ʈ����ũ����.
// N�� �ִ� 10���̴� int �ϳ��� ����� ��� ��Ȳ�� �׷����� �־���.
// ���Ŀ��� �������� �� Ǯ�ȴµ� ��Ʈ����ũ�� �̹� idx���� 1��(1)���� 2��(0)���� Ȯ�θ� �ϸ� �Ǿ��� �����̴�.
// ��·�� Ǯ������ �����̴�. ���� �� ����.

// �ڼ��� ������ �ּ����� �����.
// P.S �˰��� �з��� ���� �˼� �ֵ��� ���ù����� �����ΰ� ������ �̻��ϸ���ġ �������� ����.
// �Ｚ ������ ���� ������� �����ߴ� �����ΰ�����.

// �� ��ȣ�� �α���.
int board[10];
// �� ��ȣ���� ����� ��ȣ���� �����ϴ� ����.
vector<vector<int>> way;
int N, first_num, second_num, mask;

// ���� ��Ȳ(mask�� ����)�� �־������� �� ���ű����� ����Ǿ��ִ��� Ȯ���ϴ� BFS.
int BFS(int idx, bool check)
{
    vector<bool> visit(N, false);
    visit[idx] = true;
    queue<int> que;
    que.push(idx);
    int ans = 1;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < way[here].size(); ++i)
        {
            int there = way[here][i];
            // there��° ������ �̹� �����߰ų�, ���������� ���� ���ű��� �ƴ϶�� �����Ѵ�.
            if (!visit[there] && (((mask & (1 << there)) > 0) == check))
            {
                que.push(there);
                visit[there] = true;
                ++ans;
            }
        }
    }
    return ans;
}

// �� ���ű��� �� �ο��� ���̸� ����ϴ� �Լ�.
int CalPeople()
{
    int first = 0;
    int second = 0;
    // ��� ������ ��ȸ�ϸ� �� ���ű����� �� �ο����� ���� �� ���̸� ��ȯ�Ѵ�.
    for (int i = 0; i < N; ++i)
    {
        if (mask & (1 << i))
            first += board[i];
        else
            second += board[i];
    }
    return abs(first - second);
}

void MakeAnswer()
{
    // 1. ����ũ(���ű� ����)�� ��ȸ�Ѵ�.
    // 2. �ΰ��� ���ű��� ���� ���Ѵ�.(1�� ���ű��� a��, 2�� ���ű��� b��).
    // 3. �ΰ��� ���ű��� �ƹ��ų� �ϳ�(���� ���ǰ�)���� BFS�� ���� ���ű��� �ִ���� ���Ѵ�.
    // 4. 3������ ���� ���ű��� 2������ ���� ���ű��� ���ٸ� �� ���ű����� �α����� ���� ���̰���
    // ������ �����Ѵ�.
    int answer = 987654321;
    // 1��.
    for (mask = 1; mask < ((1 << N) - 1); ++mask)
    {
        first_num = second_num = 0;
        int first_from, second_from;
        // 2��.
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
            {
                ++first_num;
                first_from = i;
            }
            else
            {
                ++second_num;
                second_from = i;
            }
        }
        // 3��.
        int cur_first = BFS(first_from, true);
        int cur_second = BFS(second_from, false);

        // 4��.
        if (first_num == cur_first && second_num == cur_second)
            // ���⼭ �α����� ���̸� ���Ѵ�.
            answer = min(answer, CalPeople());
    }
    cout << (answer == 987654321 ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    way.resize(N, vector<int>());
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j)
        {
            int next;
            cin >> next;
            way[i].push_back(next - 1);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}