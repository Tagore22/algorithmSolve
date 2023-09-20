#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 어려워 보일수 있으나 생각보다 단순한 문제다.
// 각 색종이들을 배열하였을때 눈으로 보이는 면적들을 출력하는 문제다.
// 단순히 0 ~ N - 1번째의 색종이들을 나열해 나가되 각 칸에 현재 몇번째 색종이로 덮혀있는지를
// 체크해나간다. 그 이후 모든 칸을 순회하며 덮혀있는 색종이들의 크기를 모두 더해 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1001][1001], answer[100];
int N;

void MakeAnswer()
{
    // 만약 색종이가 보이지 않는다면(색종이가 없다면) 0을 출력한다.
    if (N == 0)
    {
        cout << 0 << '\n';
        return;
    }
    // 각 칸은 아무것도 없음을 -1로 초기화하여 구현하고, 각 색종이들의 면적은 0으로 초기화한다.
    memset(board, -1, sizeof(board));
    memset(answer, 0, sizeof(answer));
    int y, x, row, col;
    // 0 ~ N - 1번째 색종이들의 면적을 입력받아 각 칸에 저장한다.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> x >> y >> row >> col;
        for (int i = 0; i < col; ++i)
            for (int j = 0; j < row; ++j)
                board[y + i][x + j] = iter;
    }

    // 모든 칸을 순회하며 현재 저장되어있는(마지막으로 덮혀진) 색종이의 번호들을 저장하여 더한다.
    for (int i = 0; i <= 1000; ++i)
        for (int j = 0; j <= 1000; ++j)
            if (board[i][j] != -1)
                ++answer[board[i][j]];

    // 모든 색종이들의 면적을 출력한다.
    for (int i = 0; i < N; ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}