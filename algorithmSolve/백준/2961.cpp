#include <iostream>

using namespace std;

//풀이
//각 원소를 쓰는가 안쓰는가로 냅색문제 형식으로 풀면 된다. 또한 주어지는 재료의 수가 최대 10개이므로 최대 연산량도
//2의 10제곱으로 시간안에 충분히 풀수 있다. 또한, 모든 재료를 사용해도 그 총합은 10억을 넘지 않기에 int만으로도 
//모두 해결가능하다.

pair<int, int> board[10];
int N;
int answer = 987654321;

void UseOrNot(int idx, int S, int B)
{
    if (idx >= N)
    {
        if (S != 1 && B != 0)
            answer = min(answer, abs(S - B));
        return;
    }

    UseOrNot(idx + 1, S, B);
    UseOrNot(idx + 1, S * board[idx].first, B + board[idx].second);
}

void MakeAnswer()
{
    UseOrNot(0, 1, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}