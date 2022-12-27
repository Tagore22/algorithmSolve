#include <iostream>
#include <set>
#include <string>

using namespace std;

//풀이
//모든 칸을 순회하며 만들수 있는 모든 6자리 수를 구한다. 다만 중복은 피해야하기에 set에 수를 입력하여 현재 만든 6자리수가 이미 존재하는지 확인
//하며 갱신한다. 이후 순회가 끝나면 set안에 존재하는 서로 다른 수들 즉, size를 출력한다. 

set<string> check;
int board[5][5];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

void DFS(int y, int x, string str)
{
    if (str.size() == 6) //만드는 수는 6자리
    {
        if (check.find(str) == check.end())
            check.insert(str);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || cy >= 5 || cx < 0 || cx >= 5)
            continue;

        DFS(cy, cx, str + to_string(board[cy][cx]));
    }
}

void MakeAnswer()
{
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            DFS(i, j, to_string(board[i][j]));

    cout << check.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}