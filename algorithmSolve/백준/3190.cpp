#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이
// 주어진대로 구현하라는 거의 시뮬레이션식 문제이다. 제시된 뱀의 움직임을 다시 한번 살펴보고 어떻게 구현하면 될지 보자

// 1. 뱀은 머리를 주어진 방향으로 한칸 더 내민다.(나아간다).
// 2. 만약 나아간곳이 사과라면 사과는 사라지고 꼬리는 사라지지 않는다. 즉, 몸이 1칸 늘어난다.
// 3. 사과가 아니라면 꼬리는 한칸 당겨져 온다.
// 4. 나아간 곳이 뱀의 일부거나 벽이라면 그 즉시 게임은 종료된다.

// 처음에는 뱀의 이동을 어떻게 구현해야할지가 애매했다. board[][]에 2나 3을 두어 따로 뱀의 위치를 표시할까도 생각했으나,
// 꼬리의 위치 변경이나, 방향 전환시 뱀의 위치들의 변환등이 애매했다. 그래서 생각해낸 것은 그냥 컨테이너 안에 다 집어넣고
// 머리와 꼬리만 위치를 변경하는 것이었다. deque로 구현하여 나아간 머리의 위치를 새로 추가하고, 나아간 곳이 사과라면
// 사과만 없애고 사과가 아니라면 맨 마지막 꼬리부분만 삭제하면 된다. 추가와 삭제는 앞뒤에서만 일어나기에 deque로 구현하기에
// 안성맞춤이었다. 

int board[101][101];
int rot[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 북 동 남 서, 0 ~ 3
deque<pair<int, char>> moving;
deque<pair<int, int>> snake; // 앞쪽이 머리다.
int N, K, L;

void MakeAnswer()
{

    // 각각 시간과 방향의 초기화값. 시작은 오른쪽방향임이 이미 문제에 주어져있다.
    int answer = 0, dir = 1;

    // 나아간 위치값을 나타내는 변수.
    pair<int, int> next;
    while (true)
    {
        // 현재 시간에서 방향을 전환해야하는지 확인후, 그러하다면 방향을 전환한다.
        if (!moving.empty() && answer == moving.front().first)
        {
            if (moving.front().second == 'D')
                dir = dir + 1 <= 3 ? dir + 1 : 0;
            else
                dir = dir - 1 >= 0 ? dir - 1 : 3;
            moving.pop_front();
        }

        ++answer;

        next = make_pair(snake.front().first + rot[dir][0], snake.front().second + rot[dir][1]);


        // 나아간 곳이 벽이거나, 뱀의 일부라면 즉시 종료한다.
        if (next.first <= 0 || next.first > N || next.second <= 0 || next.second > N ||
            find(snake.begin(), snake.end(), next) != snake.end())
            break;

        snake.push_front(next);

        // 나아간 곳이 사과라면 사과를 없애고, 사과가 아니라면 꼬리를 없앤다.
        if (board[next.first][next.second] == 1)
            board[next.first][next.second] = 0;
        else
            snake.pop_back();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int y, x;
    for (int i = 0; i < K; ++i)
    {
        cin >> y >> x;
        board[y][x] = 1;
    }
    cin >> L;
    int time;
    char dir;
    for (int i = 0; i < L; ++i)
    {
        cin >> time >> dir;
        moving.push_back(make_pair(time, dir));
    }
    snake.push_back(make_pair(1, 1));
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}