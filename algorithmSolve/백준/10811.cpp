#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// N개의 바구니가 있을때 M번 주어지는 범위를 반전시켜 맨 마지막의 바구니 상태를 출력하는 함수다.
// reverse()로 M번 뒤집고 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // 바구니의 초기값은 1, 2, 3, 4 ~
    for (int i = 1; i <= N; ++i)
        board.push_back(i);

    int from, to;
    // M번 반복한다.
    for (int i = 0; i < M; ++i)
    {
        // 범위를 입력받아 그 범위만큼 reverse()로 바구니의 번호를 반전시킨다.
        cin >> from >> to;
        reverse(board.begin() + from - 1, board.begin() + to);
    }

    // M번의 반전 이후 바구니의 번호들을 출력한다.
    for (int i = 0; i < N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
    return 0;
}