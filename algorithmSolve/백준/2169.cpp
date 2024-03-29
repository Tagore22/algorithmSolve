#include <iostream>
#include <cstring>

using namespace std;

bool check[1000][1000];
int cashe[1000][1000][3];
int board[1000][1000];
int N, M;
int dy[3] = { 0,1,0 };
int dx[3] = { -1,0,1 };
const int MINNUM = -987654321;

//坦製拭澗 しししし 採歳拭辞 号庚食採研 呪舛背爽檎 瓜戚 蝶縮聖 [][][]猿走 照背亀 吃暗虞壱 持唖梅生蟹,
//陥獣 持唖背左檎 DP研 宜凶 嬢彊廃 疎妊 y,x拭辞税 蝶獣葵精 乞砧 旭精 葵聖 走観陥.
//益依戚 図楕, 神献楕, 是楕拭辞 羨悦拝走虞亀 源戚陥. 買蟹 戚 葵精 乞砧 含虞醤馬澗汽 
//訊劃馬檎 森研 級嬢 神献楕拭辞 羨悦梅聖凶拭澗 神献楕戚 焼観 焼掘楕, 図楕生稽 戚疑廃 葵戚 赤嬢醤馬澗汽
//図楕拭辞 羨悦背亀 図楕, 焼掘楕掻 笛葵聖 走艦奄拭 轄軒旋生稽 源戚 照鞠奄 凶庚戚陥.

int DP(int y, int x, int dir)
{
    if (y == N - 1 && x == M - 1)
        return board[y][x];
    int& ans = cashe[y][x][dir];
    if (ans != MINNUM)
        return ans;
    for (int i = 0; i < 3; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy >= N || cx >= M || cy < 0 || cx < 0 || check[cy][cx])
            continue;

        check[cy][cx] = true; //しししししししししししし
        ans = max(ans, DP(cy, cx, i) + board[y][x]);
        check[cy][cx] = false;
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cashe[i][j][0] = MINNUM;
            cashe[i][j][1] = MINNUM;
            cashe[i][j][2] = MINNUM;
        }
    check[0][0] = true;
    cout << DP(0, 0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, 0, sizeof(check));

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}