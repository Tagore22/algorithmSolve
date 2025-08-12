#include <iostream>

using namespace std;

// 풀이.
// 처음에는 이중 for문을 사용하는 로직밖에 생각이 안났으나 아무리 봐도 최대 50억이
// 넘어가는 연산량을 필요로 하기에 불가능했다. 잘 생각해보면 로직은 board[1] * board[2]
// ~ board[1] * board[N - 1]인데 이것은 곱셈의 원리에 따라 board[2] + ... board[N - 1]
// * board[1]로 바꿀 수 있다. 이것은 누적 합과 일치하기에 구현만 하면 된다.

int N;
int board[100000];
long long sum = 0;

void Solve()
{
    long long answer = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        sum -= board[i];
        answer += sum * board[i];
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}