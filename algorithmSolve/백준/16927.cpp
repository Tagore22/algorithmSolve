#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 문제를 잘못 이해해서 한참 헤맸던 문제다. 배열을 회전시키는데 각 칸을 시계 반대방향으로 회전시킨다.
// 배열을 회전시키는게 아닌 각 값을 회전시키는 것이다. 상술한대로 한가지 큰 실수를 했는데 최대 회전값은
// 1억에 달한다. 그런데 잘 생각해보면 몇번의 회전끝에 다시 되돌아올때가 있다. 이것을 이용하여 회전값 R을
// 현재 배열값으로 나누어 최소화시킬수 있다. 이때 나는 배열의 가장 바깥쪽 값으로 구했는데 이게 실수였다.
// 예를 들어 4, 4 짜리 배열이 존재한다면 가장 바깥쪽은 4, 4로 구하는 것이 맞다. 그러나 그 내부쪽은
// 4, 4가 아닌 3, 3으로 구해야 올바른 회전값을 알아낼수 있다. 이게 실수였다.
// 나머지는 자잘하지만 복잡한 구현들뿐이다. 그래도 스스로의 힘으로 풀어내서 다행이다.

// 자세한 설명은 주석으로 남긴다.

int board[300][300];
int N, M, R;

// 배열의 각 부분을 회전시키는 함수.
void RotateArray(int num)
{
    // 현재 배열 부분의 세로값, 가로값을 이용하여 회전시켜야 하는 횟수를 알아낸다.
    int cur_n = N - (num * 2);
    int cur_m = M - (num * 2);
    int div = cur_m + (cur_n - 1) + (cur_m - 1) + (cur_n - 2);
    int rot = R % div;

    // 횟수만큼 회전시킨다.
    for (int iter = 0; iter < rot; ++iter)
    {
        int y = num;
        int x = num;
        int temp = board[y][x];

        for (int i = 0; i < cur_m - 1; ++i)
            board[y][x++] = board[y][x + 1];
        for (int i = 0; i < cur_n - 1; ++i)
            board[y++][x] = board[y + 1][x];
        for (int i = 0; i < cur_m - 1; ++i)
            board[y][x--] = board[y][x - 1];
        // 이부분이 조금 중요한데 cur_n - 2를 잘살펴야 한다. 마지막 1, 0은 0, 0의 값을 전달받아야 하는데
        // 현재 board[0][0]의 값은 기존 board[0][1]값이므로 이것을 받지 않고 미리 저장해두었던 temp를
        // 받아야 한다. 따라서 for문에서 제외하고 따로 값을 전달한다.
        for (int i = 0; i < cur_n - 2; ++i)
            board[y--][x] = board[y - 1][x];
        board[y--][x] = temp;
    }
}

void MakeAnswer()
{
    // 각 부분을 회전시킨다.
    int piv = min(N, M) / 2;
    for (int i = 0; i < piv; ++i)
        RotateArray(i);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
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