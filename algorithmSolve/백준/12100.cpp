#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 문제에 제시된 움직임이 있다. 5번 움직였을때 만들수 있는 가장 큰 블록수를 출력하면 된다.
// 처음에는 최대 5번 이동이라길래 말 그대로 5번의 이동중 가장 큰 수를 출력하면 되는줄 알았는데 최대 5번의 이동중에서 가장 큰수가 아니고
// 최대 5번 이동해서 얻는 가장 큰 블록수였다. 이것 때문에 한참을 해맸다. 말그대로 다 풀고 이거 하나 때문에 로직이 틀려서 못맞추고 있었다.
// 무슨 지문을 이렇게 내지 싶었다.

// 이 문제의 핵심은 사실상 이동을 구현하는 것이다. 나머지는 좌우상하 4번의 이동을 반복하되 이동의 5번째가 되면 board를 순회하며 가장 큰
// 블록수를 갱신하고 마지막에 출력하면 되기 때문이다.

// 그럼 나머지는 방향의 차이이니, 왼쪽으로 움직이는 것만 살펴보겠다.
// 주의해야할것은 다음과 같다.
// 1. 현재 [idx][j]에서 시작했을시 점점 왼쪽으로 이동 가능하지를 살핀다. 다만 j자체를 -- 시켜서 이동시키면 다음 순회때 값이 꼬이기 때문에
// 현재 인덱스값을 유지하는 변수 cur을 생성하여 j값으로 초기화한후 왼쪽이로 이동해나간다.
// 2. 왼쪽으로 이동시 현재보다 왼쪽이 비어있다면(값이 0이라면) 계속 왼쪽으로 이동하며 현재값과 왼쪽값을 바꾼다.
// 3. 더이상 왼쪽으로 이동할수 없을시 왼쪽 값과 합칠수 있는지 확인한다. 이때 조건은 다음과 같다.
// 3-1. 현재값과 왼쪽값이 같은가?
// 3-2. 왼쪽값이 이번 이동중 합쳐진 경우가 있는가? 이를 위해 2차원 벡터 check가 필요하며 매 이동시 초기화해주어야한다.
// 4. 상술한 조건에 부합하지 않을 경우 그냥 무시하고 다음으로 넘어가며, 부합할시 왼쪽값을 2배로 늘리고(현재값과 합쳐짐) 현재값은 0이 되며,
// 왼쪽값은 합쳐졌기에 check값을 false로 갱신한다.

// 이런 이동을 각각 상하좌우로 백트래킹을 행한다. 이 이후 5번의 이동이 완료되면 그때 최대 블록값을 answer에 갱신해가며 마지막에 출력한다.

// P.S 함수명이 BackTrack이여야 하는데 DFS로 잘못 만들었다;;



vector<vector<int>> board;
vector<vector<bool>> check;
int N, answer = 0;

void MoveBoard(int idx) // 0 ~ 4 좌 상 우 하
{
    int cur;
    check.clear();
    check.resize(N, vector<bool>(N, true));
    if (idx == 0)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 1; j < N; ++j)
            {
                cur = j;
                while (cur > 0 && board[i][cur - 1] == 0)
                {
                    swap(board[i][cur], board[i][cur - 1]);
                    --cur;
                }

                if (cur > 0 && board[i][cur - 1] == board[i][cur] && check[i][cur - 1])
                {
                    board[i][cur - 1] += board[i][cur];
                    board[i][cur] = 0;
                    check[i][cur - 1] = false;
                }
            }
    }
    else if (idx == 1)
    {
        for (int j = 0; j < N; ++j)
            for (int i = 1; i < N; ++i)
            {
                cur = i;
                while (cur > 0 && board[cur - 1][j] == 0)
                {
                    swap(board[cur][j], board[cur - 1][j]);
                    --cur;
                }

                if (cur > 0 && board[cur - 1][j] == board[cur][j] && check[cur - 1][j])
                {
                    board[cur - 1][j] += board[cur][j];
                    board[cur][j] = 0;
                    check[cur - 1][j] = false;
                }
            }
    }
    else if (idx == 2)
    {
        for (int i = 0; i < N; ++i)
            for (int j = N - 2; j >= 0; --j)
            {
                cur = j;
                while (cur < N - 1 && board[i][cur + 1] == 0)
                {
                    swap(board[i][cur], board[i][cur + 1]);
                    ++cur;
                }

                if (cur < N - 1 && board[i][cur + 1] == board[i][cur] && check[i][cur + 1])
                {
                    board[i][cur + 1] += board[i][cur];
                    board[i][cur] = 0;
                    check[i][cur + 1] = false;
                }
            }
    }
    else
    {
        for (int j = 0; j < N; ++j)
            for (int i = N - 2; i >= 0; --i)
            {
                cur = i;
                while (cur < N - 1 && board[cur + 1][j] == 0)
                {
                    swap(board[cur][j], board[cur + 1][j]);
                    ++cur;
                }

                if (cur < N - 1 && board[cur + 1][j] == board[cur][j] && check[cur + 1][j])
                {
                    board[cur + 1][j] += board[cur][j];
                    board[cur][j] = 0;
                    check[cur + 1][j] = false;
                }
            }
    }
}

void FindMax()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] > answer)
                answer = board[i][j];
}

void DFS(int num, vector<vector<int>> temp)
{
    if (num == 5)
    {
        FindMax();
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        MoveBoard(i);
        DFS(num + 1, board);
        board = temp;
    }
}

void MakeAnswer()
{
    DFS(0, board);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}