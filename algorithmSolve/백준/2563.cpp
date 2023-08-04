#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 별거 아닌데 어렵게 푼 문제다.
// 각 0 ~ 100, 0 ~ 100의 2차원 배열에서 덮은 색종이의 공간을 bool 배열을 이용하여 체크해놓고
// 새로운 색종이를 덮을때마다 이미 덮은 공간인지 확인하여 겹치는 부분을 매번 빼주면 된다.

// 자세한 설명은 주석으로 남긴다.

bool board[101][101];
int N;

void MakeAnswer()
{
    // 최초값은 색종이(각각 크기가 100이다)의 수 N * 100;
    int answer = N * 100;
    memset(board, false, sizeof(board));
    int col, row;
    // 모든 색종이들을 덮되, 이미 덮은 공간이라면 겹치는 부분을 구하여 빼준다.
    for (int i = 0; i < N; ++i)
    {
        cin >> row >> col;
        int a = 0;
        for (int i = col; i < col + 10; ++i)
            for (int j = row; j < row + 10; ++j)
            {
                // 이미 덮은 공간임. 겹치는 부분.
                if (board[i][j])
                    ++a;
                board[i][j] = true;
            }
        answer -= a;
    }
    cout << answer << '\n';
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