#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 다시 생각도 하기 싫은 끔찍한 문제다.
// 2차원 벡터와 1차원 벡터의 매핑부터 온갖 꼬아놓은 것들 뿐인 문제다.
// 문제 자체는 어렵지 않다. 말그대로 물고기 이동 원리가 있고 상어의 이동 원리가 있다.
// 각각 상어가 움직일수 있는 모든 곳을 갔을때 먹을수 있는 물고기번호의 총합중 가장 큰것을 출력하면 된다.
// 다만 구현이 쉽지 않았는데 어떻게 이게 60퍼를 넘는 정답률인지를 모르겠다.

struct fish
{
    int num;
    int dir;
    int y;
    int x;
    bool islive;
};

vector<vector<int>> board;
vector<fish> fishes;
int rot[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} }; // 위부터 반시계 방향.
fish shark;
int answer = 0;

// 물고기는 0번부터 이동한다. 그렇기에 정렬이 필요한다.
bool CompareFish(const fish& lhs, const fish& rhs)
{
    return lhs.num < rhs.num;
}

// 물고기들의 이동을 담당하는 함수.
void FishMove(vector<vector<int>>& cur_board, vector<fish>& cur_fishes, fish& cur_shark)
{
    for (int iter = 0; iter < cur_fishes.size(); ++iter)
    {
        if (!cur_fishes[iter].islive)
            continue;

        // 현재 좌표값 및 방향.
        int cy = cur_fishes[iter].y;
        int cx = cur_fishes[iter].x;
        int cur_dir = cur_fishes[iter].dir - 1;

        // 최대 7번을 45도씩 반시계 방향으로 회전해보며 이동할수 있는 곳을 찾는다.
        // 또한 그 후 방향이 바뀌는 것에 주의.
        int dy, dx;
        for (int i = 0; i < 8; ++i)
        {
            dy = cy + rot[cur_dir][0];
            dx = cx + rot[cur_dir][1];

            if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4 || (dy == cur_shark.y && dx == cur_shark.x))
            {
                cur_dir = (cur_dir + 1) % 8;
                continue;
            }

            // 바뀌는 것은 fishes안에 있는 좌표값과 물고기의 생존 여부이며 현재 움직인 물고기가 방향이 바뀌었다면 그것마저
            // 갱신해야 한다.
            swap(cur_fishes[iter].y, cur_fishes[cur_board[dy][dx] - 1].y);
            swap(cur_fishes[iter].x, cur_fishes[cur_board[dy][dx] - 1].x);
            swap(cur_board[cy][cx], cur_board[dy][dx]);
            swap(cur_fishes[iter].islive, cur_fishes[cur_board[dy][dx] - 1].islive);
            cur_fishes[iter].dir = cur_dir + 1;
            break;
        }
    }
}

// 백트래킹이자 상어의 움직임을 담당하는 함수. 위 함수와는 달리 참조자를 이용하여 변수끼리 매핑시키면 안된다.
void SharkEat(vector<vector<int>> cur_board, vector<fish> cur_fishes, fish cur_shark, int sum)
{
    FishMove(cur_board, cur_fishes, cur_shark);
    vector<vector<int>> new_board;
    vector<fish> new_fishes;
    fish new_shark;
    int idx = 0;

    while (true)
    {
        // 백트래킹 이후 다시 복귀하였을때 값이 바뀌어있으면 안되기에 매번 복사해야한다.
        ++idx;
        new_board = cur_board;
        new_fishes = cur_fishes;
        new_shark = cur_shark;

        new_shark.y = new_shark.y + rot[new_shark.dir - 1][0] * idx;
        new_shark.x = new_shark.x + rot[new_shark.dir - 1][1] * idx;

        // 좌표값을 벗어난다면 더이상 움직일수 없다.
        if (new_shark.y < 0 || new_shark.y >= 4 || new_shark.x < 0 || new_shark.x >= 4)
            break;

        // 이미 먹을 물고기라면 먹을수 없다. 하지만 다음 물고기로 넘어갈수는 있다.
        if (!new_fishes[new_board[new_shark.y][new_shark.x] - 1].islive)
            continue;

        new_fishes[new_board[new_shark.y][new_shark.x] - 1].islive = false;
        new_shark = new_fishes[new_board[new_shark.y][new_shark.x] - 1];

        SharkEat(new_board, new_fishes, new_shark, sum + new_shark.num);
    }
    answer = max(answer, sum);
}

void MakeAnswer()
{
    SharkEat(board, fishes, shark, shark.num);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    board.resize(4, vector<int>(4, 0));

    int cur_num, cur_dir;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            cin >> cur_num >> cur_dir;
            fishes.push_back(fish{ cur_num, cur_dir, i, j, true });
        }
    shark = fishes[0];
    fishes[0].islive = false;
    sort(fishes.begin(), fishes.end(), CompareFish);
    for (int i = 0; i < fishes.size(); ++i)
        board[fishes[i].y][fishes[i].x] = fishes[i].num;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}