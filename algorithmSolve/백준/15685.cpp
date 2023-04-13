#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 풀이.
// 드래곤 커브는 다음의 2가지 원리에 의해 그려진다.
// 1. 처음 그릴시(0세대)에는 방향대로 1번 움직인다.
// 2. 처음이 아닐시 기존에 방향들을 뒤에서부터 꺼내서 그 방향을 1씩 증가시킨 방향으로 움직인다.

// 그렇기 때문에 벡터에 기존 움직임들을 저장해놓고 뒤에서부터 꺼내서 1씩 증가시킨후 현재 위치를
// 옮긴후 그 방향을 다시 벡터에 집어넣는것을 반복하면 된다.

// 결국 최종 풀이는 모든 드래곤 커브를 드려서 움직인 좌표를 bool 배열 check에 저장해놓고
// 모든 좌표들을 순회하며 현재 위치 {y, x}를 비롯하여 {y + 1, x}, {y, x + 1}, {y + 1, x + 1}이
// true인지 확인하고 맞다면 최종답 answer를 1씩 증가시켜나가 마지막에 answer를 출력하면 된다.

// P.S 
// x값과 y값을 거꾸로 주는 조금 꼬인 문제였다. 워낙 많이 당해봐서 어렵진 않았다.
// 혹여나 커브를 그리는데 배열을 벗어나는 경우가 있을지 몰라서 조건문을 넣어놨으나 
// 조건문이 없어도 맞는걸보니 나가는 경우가 없나보다.

struct curve
{
    int from_y;
    int from_x;
    int dir;
    int gen;
};

vector<int> board;
int rot[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
bool check[101][101];
curve curves[20];
int N;

// 커브를 그리는 함수. 
void DrawCurve(int y, int x, int dir, int gen)
{
    if (gen == -1)
        return;

    if (board.empty())
    {
        check[y][x] = true;
        board.push_back(dir);
        y = y + rot[dir][0];
        x = x + rot[dir][1];

        if (y < 0 || y > 100 || x < 0 || x > 100)
            return;

        check[y][x] = true;
    }
    else
    {
        int iter = board.size() - 1;
        int new_dir;
        for (int i = iter; i >= 0; --i)
        {
            new_dir = (board[i] + 1) % 4;
            y = y + rot[new_dir][0];
            x = x + rot[new_dir][1];

            if (y < 0 || y > 100 || x < 0 || x > 100)
                return;

            check[y][x] = true;
            board.push_back(new_dir);
        }
    }
    DrawCurve(y, x, dir, gen - 1);
}

// 모든 커브를 그리는 함수.
void DrawAllCurves()
{
    for (int i = 0; i < N; ++i)
    {
        board.clear();
        DrawCurve(curves[i].from_y, curves[i].from_x, curves[i].dir, curves[i].gen);
    }
}

// 4방향이 모두 커브에 포함되어있는지 확인하는 함수.
bool CheckPos(int y, int x)
{
    return (check[y][x] && check[y + 1][x] && check[y][x + 1] && check[y + 1][x + 1]);
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    DrawAllCurves();

    int answer = 0;
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            if (CheckPos(i, j))
                ++answer;

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> curves[i].from_x >> curves[i].from_y >> curves[i].dir >> curves[i].gen;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}