#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 생각보다 번거로웠던 문제이다. 수들의 조합을 만들되 오름차순으로 만들어야하고 어떤 수를 선택할때
// 이전수부터 시작해야 한다. (예시를 참고할것)
// 따라서 이전 수의 원소 번호를 알아야 했다. 매개변수에 그 이전 번호를 저장하여 백트래킹으로 모든 조합을
// 순회하면 된다. 또한 저번에 배운 하나에 배열에 값이 덧씌워져 사용할수 있는 방법도 써먹어봤다.

// 자세한 설명은 주석으로 남긴다.

int board[8], answer[8];
int N, M;

// 모든 조합을 순회하는 함수. 두번째 매개변수에 이전 값의 원소번호를 저장한다.
void BackTrack(int idx, int prev_num)
{
    // M개를 골랐을시 출력하고 재귀를 종료한다.
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 이전 값부터 마지막까지 조합해본다.
    for (int i = prev_num; i < N; ++i)
    {
        answer[idx] = board[i];
        BackTrack(idx + 1, i);
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