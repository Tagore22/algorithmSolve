#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 가지치기가 중요했던 문제이다.
// 10X10 배열에 색종이를 최소한으로 붙여 모든 배열을 0으로 만드는 문제인데, 그리디로는 풀수가 없었다.
// 그래서 백트래킹을 통한 완전탐색을 생각했는데 마침 배열도 10X10으로 아주 작은수로 고정되어 있었다.
// 배열을 순회하며 1인 값을 발견하였을때 5종류중 사용할수 있는 모든 색종이를 사용하여 다음 순회로 넘어가며
// (9,9)까지 도달하였을때 사용한 최소한의 색종이 수를 출력하면 된다.

vector<vector<int>> board;
vector<int> paper;
const int MAX_NUM = 987654321;
int answer = MAX_NUM;

// 사용할수 있는 색종이의 최대 크기를 구하는 함수.
int CalRange(int y, int x, vector<vector<int>>& cur_board)
{
    // 현재 0 ~ 9값을 벗어나는 것을 방지하기 위해 먼저 최대한의 크기를 구한다.
    int dis_y = 10 - y;
    int dis_x = 10 - x;
    int total_dis = min(dis_y, dis_x);

    bool isfind;
    // 좌표상으로 구한 최대값부터 최소한인 1까지 순회하며 가능한 최대 크기의 색종이를 구한다.
    for (int range = total_dis >= 5 ? 5 : total_dis; range > 0; --range)
    {
        isfind = true;
        for (int i = y; i < y + range; ++i)
        {
            for (int j = x; j < x + range; ++j)
                if (cur_board[i][j] != 1)
                {
                    isfind = false;
                    break;
                }
            if (!isfind)
                break;
        }
        if (isfind)
            return range;
    }
}

// 색종이를 붙여 좌표값을 0으로 변경한다.
vector<vector<int>> OneToZero(int y, int x, int range, vector<vector<int>> cur_board)
{
    for (int i = y; i < y + range; ++i)
        for (int j = x; j < x + range; ++j)
            cur_board[i][j] = 0;

    return cur_board;
}

// 배열을 순회하는 백트래킹 함수. 이미 구한 최소값보다 현재 sum값이 더 크다면 무시하고,
// 배열을 순회하며 1을 발견할시 대입할수 있는 가장 큰 색종이부터 하나씩 대입해가며 다음 순회로 넘어간다.
// 다만 모든 색종이는 5개씩 있으며, 5개 이상을 사용할수 없기에 색종이의 수를 비교해가며 조건문을 구현한다.
// 마지막 좌표(9,9)까지 도달하여 더이상의 1값이 없다면 현재 사용한 색종이수와 answer을 비교하여 최종값
// answer을 갱신한다.
void BackTrack(vector<vector<int>> cur_board, vector<int> paper, int y, int x, int sum)
{
    if (sum >= answer) // 가지치기.
        return;

    int range;
    vector<vector<int>> temp = cur_board;
    for (int i = y; i < 10; ++i)
        for (int j = x; j < 10; ++j)
        {
            if (cur_board[i][j] == 1)
            {
                range = CalRange(i, j, cur_board);
                for (int k = range; k >= 1; --k)
                {
                    if (paper[k - 1] == 0)
                        continue;
                    --paper[k - 1];
                    temp = OneToZero(i, j, k, cur_board);
                    BackTrack(temp, paper, y, x, sum + 1);
                    ++paper[k - 1];
                }
                return;
            }
        }
    answer = min(answer, sum);
}

void MakeAnswer()
{
    BackTrack(board, paper, 0, 0, 0);

    cout << (answer == MAX_NUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    board.resize(10, vector<int>(10, 0));
    paper.resize(5, 5);
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}