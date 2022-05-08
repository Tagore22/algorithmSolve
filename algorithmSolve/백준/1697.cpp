#include <iostream>
#include <queue>

using namespace std;

const int maxNum = 100000;
int n, k;
int check[100001];
bool visit[100001];
int trans[2] = { 1,-1 };

int bfs()
{
    check[n] = 0;
    visit[n] = true;
    queue<int> que;
    que.push(n);
    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        if (here == k)
            return check[here];
        for (int i = 0; i < 3; ++i)
        {
            int there;
            if (i != 2)
                there = here + trans[i];
            else
                there = here * 2;
            if (there < 0 || there > maxNum || visit[there])
                continue;
            check[there] = check[here] + 1;
            que.push(there);
            visit[there] = true;
        }
    }
    return -1;
}

int main()
{
    cin >> n >> k;
    cout << bfs() << '\n';
    return 0;
}