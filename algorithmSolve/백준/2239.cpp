#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 스도쿠 문제이다. 다만 모든칸을 9칸씩 나누어 그 부분의 중복까지도 없애야 하는 조금 까다로운 문제다.
// 이 부분의 원소값을 어떻게 잡아야할지 조금 헤매었다. 결과부터 말하자면 좌표값 y, x가 있을때
// idx = y / 3 * 3 + x / 3이 된다. 이것을 이용하여 모든칸을 9칸씩 나눈 중복배열 square을 사용한다.
// 문제에서 제시되었듯 각 행과 열의 중복 또한 배제해야하기에 이것을 col과 row로 해결한다.
// 여기까지 구현한 이후부터는 백트래킹으로 모든 경우를 해결하면 된다. 사전순으로 가장 작은 경우를 출력해야하기에
// 1 ~ 9까지 수들중 현재 행, 열, square중에서 아직 사용되지 않은 수를 현재 칸에 대입하며 나아가면 된다.

// 다만, 한가지 실수를 했는데 현재값을 대입하고 재귀에서 돌아올때 현재 수를 0으로 바꾸지 않았었다. 
// 이렇게 되면 이전으로 되돌아가 현재로 다시 왔을때 값을 무시하고 넘어가기 때문에 제대로 해결되지 않는다.

// 자세한 설명은 주석으로 남긴다.

// 각각 가로, 세로, 모든칸을 9칸씩 나눈 중복체크용 배열들.
bool row[9][10], col[9][10], square[9][10];
bool isfind = false;
int board[9][9];

// 백트래킹을 이용하여 모든 경우를 순회하는 함수.
void BackTrack(int idx)
{
    // 답을 이미 찾았다면 모두 무시하고 탈출한다.
    if (isfind)
        return;

    // 모든 조건을 만족하고 탈출지점에 도달하였을 경우.
    // board를 출력한후 답을 찾았음을 isfind = true를 이용하여
    // 갱신후 탈출한다.
    if (idx == 81)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cout << board[i][j];
            }
            cout << '\n';
        }
        isfind = true;
        return;
    }

    // 현재 좌표값 y, x 그리고 square의 좌표값 s_idx를 구한다.
    int y = idx / 9;
    int x = idx % 9;
    int s_idx = y / 3 * 3 + x / 3;

    // 현재값이 0일때 조건을 만족하는 수를 찾는다. 그후 값을 대입하고
    // 다음 좌표로 넘어간다.
    if (board[y][x] == 0)
    {
        for (int iter = 1; iter < 10; ++iter)
        {
            if (!col[y][iter] && !row[x][iter] && !square[s_idx][iter])
            {
                col[y][iter] = row[x][iter] = square[s_idx][iter] = true;
                board[y][x] = iter;
                BackTrack(idx + 1);
                col[y][iter] = row[x][iter] = square[s_idx][iter] = false;
                // 여기 이 부분을 놓쳤었다. 0으로 다시 되돌리지 않으면 상술하였듯
                // 이전에서 다시 현재로 왔을시 무시하고 넘어가게 된다.
                board[y][x] = 0;
            }
        }
    }
    // 현재값이 0이 아닐시 무시하고 넘어간다. 상술하였듯 0으로 되돌리지 않으면
    // 이 조건에 의하여 답이 틀리게 된다.
    else
    {
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 중복체크용 배열들의 초기화.
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(square, false, sizeof(square));
    string str;
    for (int i = 0; i < 9; ++i)
    {
        cin >> str;
        for (int j = 0; j < 9; ++j)
        {
            board[i][j] = str[j] - '0';
            // 현재값이 0이 아닐시 각 중복체크용 배열들에 값을 갱신한다.
            if (board[i][j] != 0)
            {
                col[i][board[i][j]] = true;
                row[j][board[i][j]] = true;
                square[i / 3 * 3 + j / 3][board[i][j]] = true;
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}