#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 어렵진 않으나 생각할게 많은 삼성 문제다. 하지만 생각보단 어렵지 않아 정답율이 50퍼센트에 육박한다.
// 아니면 그냥 많은 사람들이 답지보고 푼건가. 어쨌든 주어진 행동들을 취하면 되지만
// 설명할게 많으니 주석으로 남긴다.

// 자세한 설명은 주석으로 남긴다.

struct horse
{
    int y;
    int x;
    int d;
    bool ismove;
};

int board[13][13], rot[5][2] = { {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
vector<int> pos[13][13];
horse h[10];
int N, K, answer;

// 1. 각 말의 순서대로 이동한다.
// 2. 어떤 말이 다른 말 위에 놓여져 있을 경우에는 무시한다.
// 3. 말이 4개 이상 쌓였을때 게임은 끝난다. 그 턴이 1000을 넘거나 아예 끝나지 않을 경우
// -1을 반환한다.
// 4. 이동하는 칸이 0일때 다른 말이 이미 존재한다면 그 순서 그대로 기존 말위에 올라간다.
// 5. 이동하는 칸이 1일때 현재 말들의 순서를 뒤집고 기존 말위에 올라간다.
// 6. 이동하는 칸이 2일때 이동방향을 반대로 하고 이동한다. 만약 이동방향이 반대인곳 역시
// 2라면 방향을 바꾼채 이동은 하지 않는다.
// 7. 배열값을 벗어나는 경우도 칸이 2일때와 같다.
// 8. 입력시 한칸에 말이 2개 이상인 경우는 존재하지 않는다.

// 벡터의 2중 배열로 각 칸을 만들어 칸마다 존재하는 말들의 번호를 순서대로 가진다.
// 각 말을 순회하되 맨 아래 말이라면 이동한다.

// 말들을 움직이는 함수.
void MoveHorse(int idx)
{
    int y = h[idx].y;
    int x = h[idx].x;
    int d = h[idx].d;

    int ny = y + rot[d][0];
    int nx = x + rot[d][1];

    // 이동시 기존의 맨 아래가 맨 아래가 아니게 되어 변경될 경우 생각.

    // 이동하는 칸이 파란색이거나 배열값을 벗어났을때에는 이동방향을 반대로 한채
    // 다시 이동한다. 다만 반대방향 역시 배열값을 벗어났거나 파란색이라면 방향만 반대로 한채
    // 탈출한다.
    if (board[ny][nx] == 2 || ny <= 0 || ny > N || nx <= 0 || nx > N)
    {
        // 방향을 반대로 한다. 수의 정렬이 별로인 상태라 점화식이 떠오르질 않았다.
        if (d == 1)
            d = 2;
        else if (d == 2)
            d = 1;
        else if (d == 3)
            d = 4;
        else
            d = 3;

        // 반대방향으로 이동했을 경우의 좌표.
        ny = y + rot[d][0];
        nx = x + rot[d][1];
        h[idx].d = d;

        // 상술한대로 반대방향 역시 배열값을 벗어났거나 파란색이라면 무시하고 그렇지 않다면
        // 다시 한번 이동한다.
        if (board[ny][nx] != 2 && ny > 0 && ny <= N && nx > 0 && nx <= N)
            MoveHorse(idx);
    }
    // 위치를 안바꾸었다.
    
    // 하얀색일 경우 아무런 변화없이 그냥 이동한다.
    else if (board[ny][nx] == 0)
    {
        // 이동하는 칸에 이미 말들이 존재한다면 현재 말은 더이상 주도적으로 이동이 불가능하다.
        if (pos[ny][nx].size() != 0)
            h[idx].ismove = false;
        // 현재 칸의 말들을 정방향으로 이동시킨다.
        for (auto& a : pos[y][x])
        {
            pos[ny][nx].push_back(a);
            h[a].y = ny;
            h[a].x = nx;
        }
        // 현재 칸의 말들을 지운다.
        pos[y][x].clear();
    }
    // 빨간색일 경우 말들의 순서를 뒤집어서 이동한다.
    else if (board[ny][nx] == 1)
    {
        // 현재 말은 이동 불가능하다.
        h[idx].ismove = false;
        if (pos[ny][nx].size() == 0)
            h[pos[y][x][pos[y][x].size() - 1]].ismove = true;
        int vsize = pos[y][x].size() - 1;
        // 역방향으로 뒤집어서 이동한다.
        for (int i = vsize; i >= 0; --i)
        {
            pos[ny][nx].push_back(pos[y][x][i]);
            h[pos[y][x][i]].y = ny;
            h[pos[y][x][i]].x = nx;
        }
        // 현재 칸의 말들을 지운다.
        pos[y][x].clear();
    }
    // 이동한 칸의 말이 4개 이상일 경우 답을 출력하고 탈출한다.
    // 여기서 한가지 실수를 했는데 vector<int>의 2중배열을 사용하였다. 배열값을 벗어난 경우
    // 알수 없는 값들을 가지게 되어 답이 틀리게 된다. 따라서 범위값의 검사를 해주어야만 한다.
    // 혹은 3중 벡터를 사용해야 한다.
    if (pos[ny][nx].size() >= 4 && ny > 0 && ny <= N && nx > 0 && nx <= N)
    {
        cout << answer << '\n';
        exit(0);
    }
}

void MakeAnswer()
{
    for (answer = 1; answer <= 1000; ++answer)
    {
        // 모든 말들을 순회하여 맨 아래 말일 경우 이동한다.
        for (int i = 0; i < K; ++i)
        {
            if (h[i].ismove)
                MoveHorse(i);
        }
    }
    // 1000번의 말들의 이동 이후에도 4개 이상의 말이 겹치는 상황이 존재하지 않는다면
    // -1을 출력한다.
    cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < K; ++i)
    {
        cin >> h[i].y >> h[i].x >> h[i].d;
        h[i].ismove = true;
        pos[h[i].y][h[i].x].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}