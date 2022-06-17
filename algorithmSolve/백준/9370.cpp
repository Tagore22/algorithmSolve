#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; //����� �׷���, ������ ��ȣ�� 1������ n������, �� ������ ������ �ʿ�� ����.

vector<vector<pair<int, int>>> board;
vector<int> To;
int n, m, t, s, g, h;//s�� ������̸� g���� h Ȥ�� h���� g�� �ݵ�� ���İ����Ѵ�. g�� h�� ���������� �� �ִٸ� �ش� ������ �������� �ƴ�
const int MAXNUM = 987654321;

int DK(int from, int to)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, from - 1));
    vector<int> Dist(n, MAXNUM);
    Dist[from - 1] = 0;
    while (!que.empty())
    {
        int cost = que.top().first;
        int here = que.top().second;;
        que.pop();

        if (cost > Dist[here])
            continue;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;
            if (Dist[there] > Dist[here] + len)
            {
                Dist[there] = Dist[here] + len;
                que.push(make_pair(Dist[there], there));
            }
        }
    }
    return Dist[to - 1];
}

void ShowAnswer()
{
    int FirstG = DK(s, g);
    int FirstH = DK(s, h);
    int from = FirstG < FirstH ? g : h;
    int to = FirstG < FirstH ? h : g;
    int FirstWay = FirstG < FirstH ? FirstG : FirstH;
    sort(To.begin(), To.end());
    for (int i = 0; i < To.size(); ++i)
    {
        int road = FirstWay + DK(from, to) + DK(to, To[i]);
        if (road <= DK(s, To[i]))
            cout << To[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> n >> m >> t >> s >> g >> h;
        board.assign(n, vector<pair<int, int>>());
        for (int j = 0; j < m; ++j)
        {
            int a, b, d;
            cin >> a >> b >> d;
            board[a - 1].push_back(make_pair(b - 1, d));
            board[b - 1].push_back(make_pair(a - 1, d));
        }
        To.clear();
        for (int j = 0; j < t; ++j)
        {
            int x;
            cin >> x;
            To.push_back(x);
        }
        ShowAnswer();
    }
    return 0;
}