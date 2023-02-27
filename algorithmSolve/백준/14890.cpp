#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 가로 및 세로의 끝까지 어느 한쪽에서 시작해서 반대쪽으로 나아갈수 있는 경우를 길을 나아간다 라고 할때
// 길이 나아갈수 있는 경우는 다음과 같다.

// 1. 처음부터 끝까지 값이 같을 경우.
// 2. 다음 값과 현재 값이 1차이 날때 경사로를 두어 처음부터 끝까지 지나갈때.

// 다만 경사로는 한칸에 오직 하나밖에 둘수 없고, 차이가 1일때에만 둘수 있다.
// 늘 그렇듯이 작게 나누어 하나씩 풀어보자.

// 1. [idx][0]에서 시작하여 [idx][N - 1]까지 가로로 갈수 있는지 확인하는 함수.
// 2. [0][idx]에서 시작하여 [N - 1][idx]까지 세로로 갈수 있는지 확인하는 함수.
// 3. 총 결과를 반환하는 함수.

// 1번 함수의 로직은 다음과 같다.
// 1. 현재값과 다음값의 차이 dis를 구한다.
// 2. dis가 2보다 크다면 경사로를 사용하여도 지나갈수 없으므로 0을 반환한다.
// 3. dis가 1이라면 경사로를 두고 넘어갈수 있다. 하지만 먼저 경사로를 둘 L개의 칸이 확보되어있는지 확인해야한다.
// 3-1. 현재값과 다음값을 비교하여 어느쪽에 경사로를 두어야하는지 확인한다.
// 3-1-1. 경사로를 두는 L개의 칸이 있는지 확인하고 존재하지 않는다면 0을 반환한다.
// 3-1-2. 존재한다면 L개의 칸이 모두 같은 값을 가지고 있는지, 이전에 경사로를 두었었는지를 모두 확인하되, 하나라도 조건에 부합하지 않는다면
// 0을 반환하고 모두 부합한다면 경사로를 둔것을 vector<vector<bool>> check 벡터에 갱신한후, 다음으로 넘어간다.
// 4. 0을 반환하지 않고 모든 순회가 끝났다면(이번 길을 나아갈수 있다면) 1을 반환한다.

// 2번 함수의 로직은 1번과 같되, 가로와 세로의 차이만이 존재한다. 

// 3번 함수는 0부터 N-1만큼 순회하며 idx번째 가로 혹은 세로가 길을 나아갈수 있는지 1번 함수와 2번 함수를 호출하여 확인한다.다만 2번 함수를 호출하기전 
// 경사로를 두었는지 확인하는 check를 다시 갱신해 주어야한다. 1번 함수로 순회를 돌때와 2번 함수로 순회를 돌때 같은 좌표값을 지나게 되어 1번 함수에서
// 어떤 좌표값에 경사로를 두었는지의 대한 여부가 2번 함수에서 영향을 끼치면 안되기 때문이다. 최종 출력값 answer을 0으로 두고, 1번 혹은 2번 함수를 호출
// 할때마다 그 여부로 인해 answer값은 증가하고 모든 순회가 끝났을때 answer를 출력한다.

vector<vector<int>> board;
vector<vector<bool>> check;
int N, L, answer = 0;

int CangoCol(int idx)
{
    int dis;
    for (int i = 0; i < N - 1; ++i)
    {
        dis = abs(board[i][idx] - board[i + 1][idx]);
        if (dis >= 2)
        {
            return 0;
        }
        else if (dis == 1)
        {
            if (board[i][idx] > board[i + 1][idx])
            {
                if (i + L >= N)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[i + 1][idx] != board[i + 1 + j][idx] || check[i + 1 + j][idx])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[i + 1 + j][idx] = true;
                }
            }

            else
            {
                if (i + 1 - L < 0)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[i][idx] != board[i - j][idx] || check[i - j][idx])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[i - j][idx] = true;
                }
            }
        }
    }

    return 1;
}

int CangoRow(int idx) // 가로로 나아간다.
{
    int dis;
    for (int i = 0; i < N - 1; ++i)
    {
        dis = abs(board[idx][i] - board[idx][i + 1]);
        if (dis >= 2)
        {
            return 0;
        }
        else if (dis == 1)
        {
            if (board[idx][i] > board[idx][i + 1])
            {
                if (i + L >= N)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[idx][i + 1] != board[idx][i + 1 + j] || check[idx][i + 1 + j])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[idx][i + 1 + j] = true;
                }
            }

            else
            {
                if (i + 1 - L < 0)
                {
                    return 0;
                }
                else
                {
                    for (int j = 0; j < L; ++j)
                        if (board[idx][i] != board[idx][i - j] || check[idx][i - j])
                            return 0;

                    for (int j = 0; j < L; ++j)
                        check[idx][i - j] = true;
                }
            }
        }
    }

    return 1;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        answer += CangoRow(i);

    check.clear();
    check.resize(N, vector<bool>(N, false));

    for (int i = 0; i < N; ++i)
        answer += CangoCol(i);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    board.resize(N, vector<int>());
    check.resize(N, vector<bool>(N, false));
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            board[i].push_back(cur);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}