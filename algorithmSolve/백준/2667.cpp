#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[26][26];
int check[26][26];
int trans[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
vector<int> house;
int houseNum = -1;

void dfs(int y, int x)
{
    ++house[houseNum];
    check[y][x] = 1;
    for (int i = 0; i < 4; ++i)
    {
        int cy = y + trans[i][0];
        int cx = x + trans[i][1];
        if (cy >= n || cy < 0 || cx >= n || cx < 0 || board[cy][cx] == 0 || check[cy][cx] == 1)
            continue;
        dfs(cy, cx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; ++j)
            board[i][j] = str[j] - '0';
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == 1 && check[i][j] == 0)
            {
                ++houseNum;
                house.push_back(0);
                dfs(i, j);
            }
    cout << houseNum + 1 << '\n';
    sort(house.begin(), house.end());
    for (int i = 0; i <= houseNum; ++i)
        cout << house[i] << '\n';
    return 0;
}