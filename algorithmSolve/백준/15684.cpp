#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 생각할게 많은 어려운 문제였다. 문제에도 약간의 함정이 숨겨져 있어서 문제 또한 자세히 봐야했다.
// 결과적으로 말하자면 추가할수 있는 모든 가로줄을 하나씩 추가해가며 j번 사다리의 끝이 j로 끝날때의 최소한의 추가된 가로줄을
// 출력하는 것이다.

// 구현된 배열은 다음의 원리를 따른다. 

// 1. 현재 위치에서(i, j) 왼쪽 혹은 오른쪽과 연결된 가로줄이 없다면 0을 지닌다.
// 2. 왼쪽으로 가로줄이라면 -1을 지닌다.
// 3. 오른족으로 가로줄이라면 1을 지닌다.

// 구현된 함수는 다음과 같다.

// 1. 모든 배열을 순회하며 i번 사다라의 끝이 i로 끝나는지 확인하는 함수.
// 2. 가로줄을 추가 혹은 제거 하는 함수.
// 3. 추가할수 있는 모든 줄을 추가해가는 백트래킹 함수.

// 1번 함수는 별로 어렵지 않다. 현재 가로값 cur을 지니고 시작하되 초기값은 시작 가로값 j이다. 
// 가로줄을 순회하되 그안에서 다시 세로줄을 순회하며 만난 값을 cur에 더해준다. 이것이 왼쪽 혹은 오른쪽의
// 가로줄이 존재할시 사다리의 위치를 옮기는 것과 같다. 세로줄의 순회 끝에서 cur값이 j값과 다르다면
// 실패하여 false를 반환하고 모든 가로줄을 순회 성공하였다면 모든 j번째 사다리에서 시작하여 j에서 끝난것이므로
// true를 반환한다.

// 2번 함수 역시 어렵지 않다. 주어지는 좌표 (y, x)와 그 오른쪽값인 (y, x + 1)을 변경하는 것인데,
// 상술한 배열의 원리에 의해 (y, x)는 1 혹은 0으로 (y, x + 1)은 -1 혹은 0으로 변경한다.

// 3번 함수는 백트래킹의 위치값을 잡는것이 조금 복잡했다. 우선 3개 초과일시는 무시한다고 문제에서 제시되어 있기에
// 4개 혹은 현재 최종값 answer보다 현재값 num이 크다면 무시한다. 그 이후 1번 함수는 호출하여 참을 반환한다면
// 최종값 answer을 sum으로 갱신한다. 
// 마지막으로 다음 좌표값으로 백트래킹을 할것인데 기존 1차원 백트래킹이었던것과 다르게 이번은 2차원 백트래킹이기에
// 단순히 y값과 x값을 1씩 더해서 다음으로 넘어가면 안됀다. 그렇기에 2차원을 옆으로 길게 늘린 1차원으로 치환하여
// 0 ~ (N - 1) * H까지 바꾸어 한개씩 늘려나간다. 

int board[31][11];
const int MAX_NUM = 4;
int N, M, H, answer = MAX_NUM;

// 모든 사다리가 시작과 끝이 동일한지 확인하는 함수.
bool IsEnd()
{
    int cur;
    for (int j = 1; j <= N; ++j)
    {
        cur = j;
        for (int i = 1; i <= H; ++i)
            cur += board[i][cur];
        if (cur != j)
            return false;
    }
    return true;
}

// 가로줄을 삽입 또는 제거하는 함수.
void DrawLine(int y, int x, int num)
{
    board[y][x] = num;
    board[y][x + 1] = -num;
}

// 백트래킹 순회하는 함수.
void BackTrack(int idx, int num)
{
    // 가지치기.
    if (num >= answer)
        return;

    // 배열이 완성되었다면 현재까지 추가한 가로줄의 수와 최종값 answer을 비교하여 갱신한다.
    if (IsEnd())
    {
        answer = min(answer, num);
        return;
    }

    // 백트래킹 순회. 2차원으로는 풀수 없기에 옆으로 늘린 1차원으로 치환하여 가로줄을 한개씩 늘려나간다.
    int i, j;
    for (int iter = idx + 1; iter < (N - 1) * H; ++iter)
    {
        i = iter % H + 1;
        j = iter / H + 1;
        if (board[i][j] == 0 && board[i][j + 1] == 0)
        {
            DrawLine(i, j, 1);
            BackTrack(iter, num + 1);
            DrawLine(i, j, 0);
        }
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);

    cout << (answer != MAX_NUM ? answer : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, 0, sizeof(board));

    cin >> N >> M >> H;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = 1;
        board[from][to + 1] = -1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}