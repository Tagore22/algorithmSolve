#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// N개의 수들중 M개를 사용하는 순열을 만드는 문제이다. 다만 다음과 같은 제약이 있다.

// 1. 중복이 허용되지 않는다.
// 2. 뒷자리가 앞자리보다 작아서는 안된다.

// 따라서 다음과 같은점을 주의해야 한다.

// 1. 백트래킹으로 모든 경우를 순회하되, for문이 시작되는 시작점이 기존의 idx보다 1씩 크면 된다.
// 2. 다만 중복이 허용되지 않기에 기존에 선택했던 값을 체크하여 같다면 무시한다.

// 자세한 설명은 주석으로 남긴다.

int board[8], answer[8];
int N, M;

// 모든 경우를 순회하는 백트래킹 함수.
void BackTrack(int cur, int num)
{
    // M개를 모두 골랐을 경우 출력하고 탈출한다.
    if (num == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 상술한 주의해야할점 2번에 중복을 무시하기 위해 사용할 기존값.
    int prev = -1;
    // 1번에 나오듯이 앞자리가 더 커야함으로 오름차순으로 정렬된 배열의 idx + 1부터 시작한다.
    for (int i = cur + 1; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        answer[num] = board[i];
        BackTrack(i, num + 1);
        // 중복을 피하기 위해 기존값을 저장한다.
        prev = board[i];
    }
}

void MakeAnswer()
{
    // 더 큰 수를 사용하기 위한 정렬.
    sort(board, board + N);
    BackTrack(-1, 0);
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