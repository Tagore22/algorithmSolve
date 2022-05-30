#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXNUM = 10000;
int from, to;
vector<pair<int, char>> parent;
vector<int> t;


void Trans(int now)
{
    t.assign(4, 0);
    if (now == 0)
        return;
    int idx = 3;
    while (now > 0)
    {
        t[idx] = now % 10;
        now /= 10;
        --idx;
    }
}

int TransL(int now)
{
    Trans(now);
    int l = 0;
    for (int i = 1; i < t.size(); ++i)
        l = l * 10 + t[i];
    l = l * 10 + t[0];
    return l;
}

int TransR(int now)
{
    Trans(now);
    int l = t[t.size() - 1];
    for (int i = 0; i < t.size() - 1; ++i)
        l = l * 10 + t[i];
    return l;
}

void BFS()
{
    parent.assign(MAXNUM, make_pair(-1, ' '));
    parent[from] = make_pair(-10, ' ');
    queue<int> que;
    que.push(from);
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        if (here == to)
            return;

        int there = here * 2 > 9999 ? here * 2 % 10000 : here * 2; // D
        if (parent[there].first == -1)
        {
            parent[there] = make_pair(here, 'D');
            que.push(there);
        }
        there = here == 0 ? 9999 : here - 1; // S
        if (parent[there].first == -1)
        {
            parent[there] = make_pair(here, 'S');
            que.push(there);
        }
        there = TransL(here); // L
        if (parent[there].first == -1)
        {
            parent[there] = make_pair(here, 'L');
            que.push(there);
        }
        there = TransR(here); // R
        if (parent[there].first == -1)
        {
            parent[there] = make_pair(here, 'R');
            que.push(there);
        }
    }
}

void FindAnswer()
{
    string str = "";
    while (parent[to].first != -10)
    {
        str += parent[to].second;
        to = parent[to].first;
    }
    for (int i = str.size() - 1; i >= 0; --i)
        cout << str[i];
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> from >> to;
        BFS();
        FindAnswer();
    }
    return 0;
}