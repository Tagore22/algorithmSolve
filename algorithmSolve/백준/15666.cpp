#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 어째서인지 시리즈가 엄청 많은 문제다. 결과적으로 어렵진 않았으지만.
// 고를수 있는 모든 수열을 오름차순으로 출력하는 문제다. 다만 이번에는
// 어떠한 수열을 고를때 i번째 수가 뒤에 나오는 수들보다 무조건 작거나 같아야한다.
// 즉 백트래킹을 구현하되, 현재값을 고를때 이전값부터 시작해야한다는 것이다.
// 또한 중복 사용도 사용가능하니 굳이 bool배열을 통해 중복여부를 체크할 필요도 없다.

// 자세한 설명은 주석으로 남긴다.

int board[8], answer[8];
int N, M;

// 모든 수열을 만드는 함수.
void BackTrack(int num, int idx)
{
    // M개의 수열을 만든 경우 출력하고 탈출한다.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_num = 0;
    // 이전값부터 N - 1까지 순회하며 모든 수열을 만든다.
    // 다만 같은 수열을 2번 이상 만들지는 못하기에 이전에 고른값을
    // 체크하며 비교한다.
    for (int i = idx; i < N; ++i)
    {
        if (board[i] == prev_num)
            continue;

        prev_num = board[i];
        answer[num] = board[i];
        BackTrack(num + 1, i);
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0, 0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}