#include <iostream>
#include <vector>
#include <algorithm>

// 풀이.
// 삼성 문제답게 생각할 것도 많고 조건도 많은 문제였다.

// 큰 틀은 다음과 같다.
// 1. 매번 말들이 번호순서대로, 가지고 있는 방향에 따라 움직인다.
// 2. 만약 어느 좌표에서 말이 4개 이상 쌓이는 순간 그 턴을 출력한다.

// 그럼 더 단순하게 말들의 움직이는 원리를 보자.
// 1. 기본적으로 지니고 있는 방향대로 1칸씩 움직인다.
// 2. 만약 현재 말위에 다른말이 놓여져 있다면 그 말들도 함께 움직인다.
// 3. 새로운 좌표가 하얀색(0)이라면 그냥 움직인다.
// 4. 새로운 좌표가 빨간색(1)이라면 현재 움직인 말들의 순서가 뒤집힌다.
// 5-1. 새로운 좌표가 파란색이거나, 배열값을 벗어날때 방향이 반전되어 새로운 방향대로 1칸을 움직인다.
// 5-2. 새로운 방향대로 움직인 곳마저 파란색이거나 배열값을 벗어났다면 움직이지 않는다.

// 이것을 구현해주면 되는데 주의해야 할점이 한가지 있다.
// 1. 현재 좌표가 빨간색(1)이고 방향대로 움직였을때 파란색이며, 반전된 방향대로 움직여도 파란색일 경우
// 결국은 움직이지 않기에 말들의 순서가 뒤집히면 안된다.

// 이것을 주의하며 나머지를 구현하면 된다.

using namespace std;

// 장기말들을 구현하는 구조체.
struct chess
{
    int y;
    int x;
    int dir;
};

// 각 좌표에 장기말들의 인덱스값들을 가지고 있는다.
vector<vector<vector<int>>> cur_board;
int board[13][13];
chess c[10];
int rot[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
int N, K;
bool isfind = false;

// 주어진 값들의 새로운 좌표값을 반환하는 함수.
chess MoveChess(int y, int x, int dir)
{
    int dy = y + rot[dir - 1][0];
    int dx = x + rot[dir - 1][1];

    // 새로운 좌표가 파란색이거나 배열값을 벗어나는 경우.
    if (dy <= 0 || dy > N || dx <= 0 || dx > N || board[dy][dx] == 2)
    {
        // 방향을 반전시키고 두번째 새로운 좌표값을 찾는다.
        dir = dir % 2 == 0 ? dir - 1 : dir + 1;
        dy = y + rot[dir - 1][0];
        dx = x + rot[dir - 1][1];
        
        // 두번째 새로운 좌표값 역시 배열값을 벗어나거나 파란색이라면 움직이지 않는다. 다만 반전된 방향은 그대로이다.
        if (dy <= 0 || dy > N || dx <= 0 || dx > N || board[dy][dx] == 2)
        {
            dy = y;
            dx = x;
        }
    }

    return chess{ dy, dx, dir };
}

void MoveAllChess(int idx)
{
    int y = c[idx].y;
    int x = c[idx].x;
    int dir = c[idx].dir;

    // 여기서 새로운 위치와 방향을 찾는다.
    chess new_pos = MoveChess(y, x, dir);

    int new_y = new_pos.y;
    int new_x = new_pos.x;
    int new_dir = new_pos.dir;

    // 이 이후부터 방향값은 건드리지 않는다. 하지만 방향값이 반전되어 있을수도 있기에 여기서 새로 갱신한다.
    c[idx].dir = new_dir;

    // 여기서부터 현재 idx번째 말부터 맨위까지 새로운 위치로 옮긴다.

    // 1. 흰색일때 -> 그냥 옮김.
    // 2. 빨간색일때 -> 위치는 옮기나 쌓인 순서가 반전.
    // 3. 파란색일때 -> 
    vector<int>& cur = cur_board[y][x];
    vector<int> temp;
    int Csize = cur.size() - 1;
    for (int i = Csize; i >= 0; --i)
    {
        temp.push_back(cur[i]); // 순서가 거꾸로 들어가는것을 잊지말자.
        cur.pop_back();

        if (temp.back() == idx)
            break;
    }

    // 여기서 두번째 조건문이 중요하다. 상술하였듯 현재값이 빨간색(1)인데 결국에 움직이지 않을때 쌓인 장기말들의 순서는 변함이 없어야한다.
    if (board[new_y][new_x] != 1 || (y == new_y && x == new_x))
        reverse(temp.begin(), temp.end());

    // 장기말들의 인덱스값을 옮기며 좌표 또한 갱신해준다.
    vector<int>& next = cur_board[new_y][new_x];
    for (int i = 0; i < temp.size(); ++i)
    {
        next.push_back(temp[i]);
        c[temp[i]].y = new_y;
        c[temp[i]].x = new_x;
    }

    if (next.size() >= 4)
        isfind = true;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
    {
        int y = c[i].y;
        int x = c[i].x;

        cur_board[y][x].push_back(i);
    }

    int answer = 0;
    while (true)
    {
        ++answer;
        for (int i = 0; i < K; ++i)
            MoveAllChess(i);

        if (isfind)
        {
            cout << answer << '\n';
            return;
        }

        if (answer > 1000)
        {
            cout << -1 << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cur_board.resize(N + 1, vector<vector<int>>(N + 1, vector<int>()));
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];

    for (int i = 0; i < K; ++i)
        cin >> c[i].y >> c[i].x >> c[i].dir;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}