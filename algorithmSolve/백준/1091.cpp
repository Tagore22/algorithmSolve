#include <iostream>

using namespace std;

// 풀이.
// 내가 엄청 이해를 못했다던가 혹은 엄청 개같은 문제였다. 솔직히 아직도 잘 이해가 되지 않는다.
// 근데 수정해달라는 요청이 많았던 문제다보니 문제가 이상한것도 없진 않은가 보다.
// 어쨌든 주어진 P가 의도대로 0, 1, 2의 반복이 되어야 하는 문제이며, 그렇기 위해선 마찬가지로 주어진
// s에 맞게 원소들을 재배열해야 했다. 그 와중 사이클이 존재할수 있게 되는데 그건 답을 구할수 없다는 뜻이 되어
// -1을 출력해야 한다. 처음에는 set을 이용해서 사이클을 검출했는데 굳이 그럴 필요없이 맨 처음값을 알아두었다가
// 그것과 일치하는 배열이 된다면 사이클이 존재함을 알수 있다.

// 자세한 설명은 주석으로 남긴다.

int P[48], S[48], board[48], to[48];
int N;

// 정답인지 확인하는 함수. 상술한대로 현재 배열의 순서가 0, 1, 2의 반복이라면 정답이다.
bool IsAnswer()
{
    for (int i = 0; i < N; ++i)
        if (P[i] % 3 != i % 3)
            return false;
    return true;
}

// 사이클이 존재하는지 검출하는 함수. 기존값 board와 현재 배열이 일치한다면 사이클이 일어난다.
bool IsCycle()
{
    for (int i = 0; i < N; ++i)
        if (to[i] != board[i])
            return false;
    return true;
}

void MakeAnswer()
{
    int answer = 0;
    // 사이클이 존재하거나, 정답을 찾을때까지 반복한다.
    while (true)
    {
        if (IsAnswer())
        {
            cout << answer << '\n';
            return;
        }
        // 현재 배열값을 S에 맞게 재배열하여 to에 저장한다.
        for (int i = 0; i < N; ++i)
            to[S[i]] = P[i];
        if (IsCycle())
        {
            cout << -1 << '\n';
            return;
        }
        for (int i = 0; i < N; ++i)
            P[i] = to[i];
        ++answer;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
        board[i] = P[i];
    }
    for (int i = 0; i < N; ++i)
        cin >> S[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}