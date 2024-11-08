#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Ǯ��.
// ���ù����� ��������. ��1�� �������� 20�۵� �ȵǴ� �������µ� �˰��� ����� ��ô�ȸ ��������.
// ��� ���� ������ ���ͽ�Ʈ�� �˰��� ������, ���뿡�� ����������. �ӵ��� 2��� �����Ҽ���
// �����Ҽ��� �ֱ� �����̴�. Ư���� �����Ҷ� ������ ����ġ�� Ȧ����� ���� �̻������� ������
// ��� ����ġ�� 2��� ���Ͽ� �����ߴ�. ����� ����Ѵ�� ����� ���ͽ�Ʈ��� Ǯ�� ������
// ����� �ӵ��� ������ �ֱ� ������ 2���� �迭�� ����ؾ��Ѵ�. i��° ������ Ȧ����°�� ������������
// ¦����°�� �������� ��찡 �ٸ��� �����̴�. ����, �켱����ť���� -�� �̿��Ͽ� ������ �ø��°� �����ߴµ�
// �翬�ϰԵ� �ð��ʰ��� ����. �����̶�� �������� ������ ��� �˻��ϱ� �����̴�. ��������.

// �ڼ��� ������ �ּ����� �����.

const int MAXNUM = 2100000000;
int N, M;
vector<pair<int, int>> board[4001];
// ���� ����� ������ �� ���������� �ִܰŸ�.
vector<int> FoxDist, WolfDist;

// ������ �� �������� �ִܰŸ��� ���ϴ� �Լ�.
// ����� ���ͽ�Ʈ��� �ٸ��� ����.
void DKFox()
{
    for (int i = 0; i <= N; ++i)
        FoxDist.push_back(MAXNUM);
    FoxDist[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (cost > FoxDist[here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int next = cost + p.second;
            if (next < FoxDist[there])
            {
                FoxDist[there] = next;
                que.push(make_pair(-next, there));
            }
        }
    }
}

// ������ �� �������� �ִܰŸ��� ���ϴ� �Լ�.
void DKWolf()
{
    // Ȧ����°�� �����Ҷ��� ¦����°�� �����Ҷ��� �ٸ��� ������
    // 2���� �迭�� ����Ѵ�.
    int odd[2][4001];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j <= N; ++j)
            odd[i][j] = MAXNUM;
    // �̺κ��� �ſ� �߿��ѵ� ó������ ������ ���� odd[0][1] = odd[1][1] = 0�� �߾���.
    // ������ �׷��� �ȵǴ°� int ���� isodd�� �������� ����ϴ� Ȧ�� Ȥ�� ¦���̰�
    // (isodd + 1) % 2�� ������������ ���� ��Ÿ���� �����̴�. ���ʿ� isodd�� 1�� �����ϱ⿡ 
    // 0���� �����ϴ� ���� 0���� 0�̹Ƿ� 0������, 1���� ��򰡷��� ����ġ�� ����� 0�� �ɼ� ���� �����̴�.
    odd[0][1] = 0;
    priority_queue<pair<pair<int, int>, int>> que;
    que.push(make_pair(make_pair(0, 1), 1));

    while (!que.empty())
    {
        // ����Ѵ�� �켱����ť�� ����Ҷ� ���� -�� �����ϴ°��� ��������.
        int cost = -que.top().first.first;
        int here = que.top().first.second;
        int isodd = que.top().second;
        que.pop();

        if (cost > odd[(isodd + 1) % 2][here])
            continue;

        for (auto& p : board[here])
        {
            int there = p.first;
            int dis = isodd == 1 ? p.second / 2 : p.second * 2;
            int next = cost + dis;
            if (next < odd[isodd][there])
            {
                odd[isodd][there] = next;
                que.push(make_pair(make_pair(-next, there), (isodd + 1) % 2));
            }
        }
    }
    WolfDist.push_back(0);
    // Ȧ����°�� ¦����°������ ���Ͽ� �ּҰ��� ���Ϳ� �ִ´�.
    for (int i = 1; i <= N; ++i)
    {
        int low = min(odd[0][i], odd[1][i]);
        WolfDist.push_back(low);
    }
}

void MakeAnswer()
{
    DKFox();
    DKWolf();
    int answer = 0;
    // ����� ������ ���� ���Ͽ� ���찡 �� ª���� ������ answer�� 1 �����Ѵ�.
    for (int i = 1; i <= N; ++i)
        if (FoxDist[i] < WolfDist[i])
            ++answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, cost * 2));
        board[to].push_back(make_pair(from, cost * 2));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}