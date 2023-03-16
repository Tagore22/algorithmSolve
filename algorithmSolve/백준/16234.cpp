#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 원리 자체를 생각해내는건 어렵지 않았다. 다만 이상한곳에서 헤맸는데 
// 인구 이동은 하루동안 진행된다는 걸 간과했다. 기존에는 (1, 1)과 (1, 2)의 차이가 R보다 커서 인구 이동이 없었으나,
// (1, 1)이 (2, 1)과의 인구 이동으로 커졌다고 치자. 그럼 (1, 2)와의 인구 이동이 가능해지는가?
// 정답은 그렇지 않다. (1, 1)이 (1, 2)와의 인구 이동이 가능한건 사실이다. 다만 그 시점이 다르다.
// (1, 1)이 (1, 2)와 인구 이동을 한 순간 이미 하루가 지나기 때문에 그날 당일에 (1, 2)와의 인구 이동은 불가능하고
// 그렇기에 순회를 돌때 (1, 2) 차례에서 (1, 1)로의 DFS는 불가능하다. 다른 말로 check를 통해 이미 방문된
// 좌표들은 값의 차이가 L에서 R이라 할지라도 DFS가 불가능하다. 이러 간단한 걸 간과하고 있었다. ㅠㅠ

int board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
vector<vector<bool>> check;
int N, L, R, sum;
vector<pair<int, int>> country;

void DFS(int y, int x)
{
    check[y][x] = true;
    sum += board[y][x];
    country.push_back(make_pair(y, x));
    int dy, dx;

    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[i][0];
        dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || check[dy][dx] ||
            abs(board[y][x] - board[dy][dx]) < L || abs(board[y][x] - board[dy][dx]) > R)
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    int answer = 0, csize, new_people;
    bool ismove;
    while (true)
    {
        ismove = false;
        check.assign(N, vector<bool>(N, false));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (!check[i][j])
                {
                    sum = 0;
                    country.clear();
                    DFS(i, j);

                    csize = country.size();
                    if (csize >= 2)
                    {
                        ismove = true;
                        new_people = sum / csize;
                        for (int i = 0; i < csize; ++i)
                            board[country[i].first][country[i].second] = new_people;
                    }
                }
        if (ismove)
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}