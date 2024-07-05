#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 풀이.
// 골드 1이다. 삼성이다. 오래걸렸다. 거의 역대급 같은데... 7시 반이다. 후..
// 늘 그렇듯 어렵진 않으나 여러가지가 복잡하게 얽혀져 있는 문제다. 여러가지 실수를 했는데 각 주석에서 처리하고자 한다.

// 자세한 설명은 주석으로 남긴다.

// P.S 문제가 개...친절하지 않은 문제였다. 특히나 상어가 이동할때의 설명이 매우 부족했는데 출발이전에 같은 칸에
// 물고기가 존재할수도 있기 때문이다. 이 경우에 먹고 출발하는지 그렇지 않은지에 대한 설명이 아예 없었다.
// 따라서 직접 해보면서 맞고 틀리고로 알아야 하는데 애시당초 그런 경우가 존재하는 예시 자체가 엄청 복잡한 경우라서
// 직접해보기도 어려웠으며 만약 그런 예시 자체가 없었다면 더 골때리는 상황이 존재했을 것이다.

struct fish
{
    int y;
    int x;
    int d;
};

vector<fish> fishs, prev_fish;
int fish_rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int shark_rot[5][2] = { {0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int M, S;
pair<int, int> shark;
pair<string, int> shark_max;
int fish_board[5][5] = { 0, };
int smell_board[5][5] = { 0, };
// 5번에서 물고기들을 순회하며 위치가 냄새가 아닌 물고기들만 추가 한다.
// 냄새가 있는곳에 다시 냄새가 생기면 그냥 덮어씌운다.

// 5번에 해당하는 함수. 물고기들을 복제한다.
void ReproFish()
{
    // 1번에 존재했던 모든 물고기들을 복제한다. 상어가 있는 칸이든 냄새가 있는 칸이든 무시한다.
    for (auto& a : prev_fish)
        ++fish_board[a.y][a.x];
    // 여기에서 엄청 헤맸다. 어떤 물고기가 복제되면서 냄새가 있는 칸에 복제되었는데 8방향이 모두 막혀서
    // 나아갈수 없었다면 이번 이동에 그 물고기는 냄새가 있는 칸에 그대로 머물게 된다. 따라서 주석처리 된 부분처럼
    // 냄새가 0인 위치의 물고기들만 추가하면 안된다. 냄새가 2인곳은 이번에 무조건 물고기들이 잡혀서 물고기들이 아예 없지만
    // 1인 곳은 상술한대로 냄새가 있던 곳에 복제되어 살아남은 물고기들이 존재하기 때문이다.
    for (auto& a : fishs)
    {
        // if(smell_board[a.y][a.x] == 0)
        //     prev_fish.push_back(a); 
        if (smell_board[a.y][a.x] != 2)
            prev_fish.push_back(a);
    }
    // 다시 fishs에 모든 물고기들의 정보를 넘긴다.
    fishs = prev_fish;
}

// 냄새가 지워지는 4번 함수.
void EraseSmell()
{
    // 모든 칸들의 냄새를 1씩 지운다. 다만 이때 음수가 되어선 안된다.
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            if (smell_board[i][j] > 0)
                --smell_board[i][j];
}

// 상어의 모든 이동들을 계산해보는 함수.
void CalMoveShark(int y, int x, string str, int sum)
{
    // 3번을 모두 이동하였을때 잡아먹은 물고기들의 수가 역대급이라면 이동방향들과
    // 물고기들의 수를 갱신하고 탈출한다.
    if (str.size() == 3)
    {
        if (sum > shark_max.second)
            shark_max = make_pair(str, sum);
        return;
    }

    // 4방향을 모두 순회해본다.
    for (int i = 1; i <= 4; ++i)
    {
        int ny = y + shark_rot[i][0];
        int nx = x + shark_rot[i][1];

        // 배열값을 벗어나면 무시한다.
        if (ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
            continue;

        // 이곳에서도 실수했는데 잡아먹은 칸의 물고기들을 일시적으로 0으로 처리하지 않으면
        // 이미 물고기들이 없음에도 다시 재방문하게 된다.
        int next_fish = fish_board[ny][nx];
        fish_board[ny][nx] = 0;
        CalMoveShark(ny, nx, str + to_string(i), sum + next_fish);
        fish_board[ny][nx] += next_fish;
    }
}

// 실제로 상어가 이동하는 함수.
void MoveShark(int d)
{
    // 주어진 방향대로 이동한다.
    shark.first += shark_rot[d][0];
    shark.second += shark_rot[d][1];

    // 이동한곳에 물고기들이 존재한다면 0으로 수정하고 냄새를 3으로 한다.
    // 왜 2가 아니라 3이냐면 이동전 4번에서 한번 지우기 때문이다.
    if (fish_board[shark.first][shark.second] > 0)
    {
        smell_board[shark.first][shark.second] = 3;
        fish_board[shark.first][shark.second] = 0;
    }
}

// 물고기들이 움직이는 2번 함수.
void MoveFish()
{
    // 모든 물고기들으 순회한다.
    for (auto& a : fishs)
    {
        int y = a.y;
        int x = a.x;
        int d = a.d - 1;

        // 8방향을 순회한다.
        for (int i = 0; i < 8; ++i)
        {
            int ny = y + fish_rot[d][0];
            int nx = x + fish_rot[d][1];

            // 배열값을 벗어나지 않고 상어가 존재하지 않으며 냄새가 없는 칸이라면 이동한다.
            if (ny > 0 && ny <= 4 && nx > 0 && nx <= 4 && smell_board[ny][nx] == 0 &&
                make_pair(ny, nx) != shark)
            {
                --fish_board[y][x];
                ++fish_board[ny][nx];
                a.y = ny;
                a.x = nx;
                a.d = d + 1;
                break;
            }
            d = (d + 7) % 8;
        }
    }
}

// 상어가 이동전에 같은 칸에 물고기가 있다면 그것인 제외인가 아닌가
void MakeAnswer()
{
    for (int iter = 0; iter < S; ++iter)
    {
        // 여기서도 실수했었는데 최대값을 구하는 shark_max값을 매번 초기화해주어야만 한다.
        shark_max = make_pair("", -1);
        // 1번. 따로 clear()를 하지 않았다. 나중에 문제되나 확인.
        prev_fish = fishs;
        // 2번.
        MoveFish();
        // 3번.
        CalMoveShark(shark.first, shark.second, "", 0);
        for (int i = 0; i < 3; ++i)
            MoveShark(shark_max.first[i] - 48);
        // 4번.
        EraseSmell();
        // 5번.
        ReproFish();
    }
    int answer = 0;
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= 4; ++j)
            answer += fish_board[i][j];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> S;
    fish cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur.y >> cur.x >> cur.d;
        fishs.push_back(cur);
        ++fish_board[cur.y][cur.x];
    }
    cin >> shark.first >> shark.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}