#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> unit;
vector<bool> check;
vector<string> board;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
int answer = 0;

//일반적인 BFS나 DFS로는 +와 같은 형태를 탐색할수 없었다. 그래서 25개중 7개의 조합을 구해
//그 형태가 모두 인접해 있는지를 확인한다.

bool BFS()
{
    int trans = 1;
    queue<pair<int, int>> que;
    que.push(make_pair(unit[0] / 5, unit[0] % 5));
    vector<bool> visit = check;
    visit[unit[0]] = false;
    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int cy = y + dy[i];
            int cx = x + dx[i];

            if (cy >= 5 || cx >= 5 || cy < 0 || cx < 0 || !check[cy * 5 + cx] || !visit[cy * 5 + cx])
                continue;

            visit[cy * 5 + cx] = false;
            que.push(make_pair(cy, cx));
            ++trans;
        }
    }
    return trans == 7 ? true : false;
}

void Comb(int idx, int s_num)
{
    if (unit.size() == 7)
    {
        if (s_num >= 4 && BFS())
            ++answer;
        return;
    }
    for (int i = idx + 1; i < 25; ++i)
    {
        int plus_s = board[i / 5][i % 5] == 'S' ? 1 : 0;
        unit.push_back(i);
        check[i] = true;
        Comb(i, s_num + plus_s);
        check[i] = false;
        unit.pop_back();
    }
}

void MakeAnswer()
{
    Comb(-1, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    check.resize(25, false);

    for (int i = 0; i < 5; ++i)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}