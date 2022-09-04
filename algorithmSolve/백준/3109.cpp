#include <iostream>
#include <vector>

using namespace std;

//시작점이 맨위부터 시작함으로 마찬가지로 맨위부터 빵집까지 도달할수 있는 파이프를 찾는다.
//도중 겹칠수도 있는데 상술한것처럼 위에서 부터 만들어나가는것이 가장 많이 만들수 있는 방법이기 때문.

vector<vector<bool>> check;
vector<string> board;
int R, C;
int dy[3] = { -1,0,1 };
int dx[3] = { 1,1,1 };
int answer = 0;
bool isfind;

void DFS(int y, int x)
{
    check[y][x] = true;
    if (x == C - 1)
    {
        ++answer;
        isfind = true;
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        int cy = y + dy[i];
        int cx = x + dx[i];

        if (cy < 0 || R <= cy || board[cy][cx] == 'x' || check[cy][cx])
            continue;

        DFS(cy, cx);
        if (isfind)
            return;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
    {
        isfind = false;
        DFS(i, 0);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    check.resize(R, vector<bool>(C, false));
    for (int i = 0; i < R; ++i)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}