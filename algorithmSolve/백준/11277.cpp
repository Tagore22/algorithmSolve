#include <iostream>

using namespace std;

// 풀이.
// 백트래킹 문제이다. 1 ~ N번까지의 변수를 각각 true 혹은 false를 대입시킨후 그 때의
// 절값들이 모두 true가 되는지를 확인하면 된다.

// 자세한 설명은 주석으로 남긴다.

bool board[21];
int clause[200];
int N, M;
bool isfind = false;

// 각 절의 값이 모두 true인지 확인하는 함수.
bool Check()
{
    for (int i = 0; i < M; i += 2)
    {
        // 각 절의 첫번째 변수와 두번째 변수.
        bool first = board[abs(clause[i])];
        bool second = board[abs(clause[i + 1])];

        // 각 절의 변수가 - 상태라면.
        if (clause[i] < 0)
            first = !first;
        if (clause[i + 1] < 0)
            second = !second;

        // 둘중 하나라도 true가 아니라면 현재 상태로는 답을 찾을수 없다.
        if (!first && !second)
            return false;
    }
    return true;
}

void BackTrack(int idx)
{
    if (isfind)
        return;

    if (idx == N + 1)
    {
        // 여기서 식을 true로 만들수 있나 확인한다.
        // 만들수 있다면 isfind를 true로 갱신하고 탈출한다.
        if (Check())
            isfind = true;
        return;
    }

    for (int i = 0; i < 2; ++i)
    {
        board[idx] = i;
        BackTrack(idx + 1);
    }
}

void MakeAnswer()
{
    // 여기서 백트래킹
    BackTrack(1);

    cout << (isfind ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    M *= 2;
    for (int i = 0; i < M; ++i)
        cin >> clause[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}