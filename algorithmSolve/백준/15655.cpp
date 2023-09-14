#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// N개의 수를 오름차순으로 중복되지 않게 M개를 만들어 출력하는 문제다.
// 전혀 어려울게 없다.

// 자세한 설명은 주석으로 남긴다.

int board[8], answer[8];
int N, M;

// 모든 경우를 순회하는 함수.
void BackTrack(int idx, int cur)
{
    // M개 골랐을때 출력후 탈출한다.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 중복되지 않게 이전에 고른값 + 1부터 만들수 있는 모든 경우를 순회한다.
    for (int i = cur + 1; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1, i);
    }
}

void MakeAnswer()
{
    // 오름차순으로 만들어야 하기에 오름차순으로 원소값들을 정렬한다.
    sort(board, board + N);
    BackTrack(0, -1);
}

void Input()
{
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