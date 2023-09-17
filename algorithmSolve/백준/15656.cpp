#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 중복이 가능한 모든 수열을 출력하는 문제다.
// 전혀 어렵지 않다. 다만 속도가 좀 느린데
// answer[]을 사용한 int 배열 대신 string을 사용하여 하니
// 더 빨랐다. 왠지는 모르겠으나 int보다 char가 더 작아서 그런거 같기도 하다.

// 자세한 설명은 주석으로 남긴다.

int board[7], answer[7];
int N, M;

// 모든 경우의 수를 순회하는 함수.
void BackTrack(int idx)
{
    // M개를 골랐으면 출력한다.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 중복 여부가 상관없기에 0부터 다시 N - 1까지 순회하며 한개씩 추가해나간다.
    for (int i = 0; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0);
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