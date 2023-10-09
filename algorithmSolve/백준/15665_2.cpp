#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 15665번의 또다른 풀이.
// 결국 정답은 순열의 출력을 int 배열이 아닌 string 방식으로 출력하는 것이었다.
// 개인적인 추측으로는 int 배열은 어쩔수 없이 for문을 이용하여 모든 원소를 돌아야하지만
// string은 이미 모든 문자가 붙어있다는 것을 보장받은 상태이기 때문에 여러개의 문자 혹은 원소의
// 출력에서 조금더 유리한게 아닌가 생각이 든다.

int board[7];
int N, M;

void BackTrack(int idx, string str)
{
    if (idx == M)
    {
        // int 배열을 순회하며 출력하는 것이 아닌 string 문자열 하나를 출력한다.
        cout << str << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] == prev)
            continue;

        BackTrack(idx + 1, str + to_string(board[i]) + " ");
        prev = board[i];
    }
}

void MakeAnswer()
{
    sort(board, board + N);
    BackTrack(0, "");
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