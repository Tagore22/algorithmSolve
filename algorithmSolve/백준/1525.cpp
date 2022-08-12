#include <iostream>
#include <queue>
#include <set>

using namespace std;

string str = "";
string goal = "123456780";
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int BFS()
{
    queue<pair<string, int>> que;
    que.push(make_pair(str, 0));
    set<string> check;
    check.insert(str);
    while (!que.empty())
    {
        string now = que.front().first;
        int nums = que.front().second;
        que.pop();

        if (now == goal)
            return nums;

        int idx = now.find('0');
        int y = idx / 3;
        int x = idx % 3;

        for (int i = 0; i < 4; ++i)
        {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (cy >= 3 || cx >= 3 || cy < 0 || cx < 0)
                continue;

            int newidx = cy * 3 + cx;
            swap(now[idx], now[newidx]);
            if (check.find(now) == check.end())
            {
                que.push(make_pair(now, nums + 1));
                check.insert(now);
            }
            swap(now[idx], now[newidx]);
        }
    }
    return -1;
}

void MakeAnswer()
{
    cout << BFS() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            int a;
            cin >> a;
            str += '0' + a;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}