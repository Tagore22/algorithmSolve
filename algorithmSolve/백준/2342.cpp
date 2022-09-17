#include <iostream>
#include <vector>
#include <cstring>

//처음엔 그리디로 해결하려 했으나, 그리디로는 https://www.acmicpc.net/board/view/87451
//의 반례같은 경우를 풀수가 없어서 완전탐색을 이용해야했다.
//왼발을 움직이느냐 오른발을 움직이느냐 인데 2의 100000제곱이 되므로 다 풀수 없어
//DP를 사용해야만 한다.
//다른 방식으로 왔으나 현위치와 다름위치가 같은 경우가 있기에 DP로 해결해야하면 됨.

using namespace std;

vector<int> board;
int cashe[100001][5][5];
int cost[5][5]; //[현위치][다음위치];
const int MAXNUM = 987654321;

void SetCost()
{
    for (int i = 1; i <= 4; ++i)
    {
        cost[0][i] = 2;
        cost[i][i] = 1;
    }
    cost[1][2] = cost[1][4] = cost[2][1] = cost[2][3] = cost[3][2] = cost[3][4] = 3;
    cost[4][1] = cost[4][3] = 3;
    cost[1][3] = cost[2][4] = cost[3][1] = cost[4][2] = 4;
    cost[0][0] = 1;
}

int DP(int idx, int l, int r)
{
    if (idx == board.size() - 1)
        return 0;
    if ((l != 0 && r != 0) && l == r)
        return MAXNUM;
    int& ans = cashe[idx + 1][l][r];
    if (ans != -1)
        return ans;
    ans = min(DP(idx + 1, board[idx + 1], r) + cost[l][board[idx + 1]],
        DP(idx + 1, l, board[idx + 1]) + cost[r][board[idx + 1]]);
    return ans;
}

void MakeAnswer()
{
    SetCost();
    cout << DP(-1, 0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    int now;
    while (true)
    {
        cin >> now;
        if (now == 0)
            break;
        board.push_back(now);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}