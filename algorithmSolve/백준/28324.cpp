#include <iostream>

using namespace std;

// 풀이.
// 문제를 푸는 로직 자체는 잘 맞추었다. 속력이 증가하는데는 아무런 제한이 없으나, 감소하는데는 현재 속도에서
// 1씩밖에 감소하지 못하기 때문이다. 따라서 뒤에서부터 속력을 측정해나가야 했다. 이 때 첫번째 실수를 하였는데
// 시작 지점과 도착 지점을 계산에서 아예 빼버렸다. 도착 지점에 속력이 0인 상태로 도달해야한다는 것은 마지막
// 중간 지점에서 속력이 1이여야 한다는 것이다. 그러므로 맨 뒤에서 순회를 시작할때 속력은 1로 시작해야 한다.
// 이 후 두번째 실수를 했는데 각 속력의 최대치는 10억이기 때문에 int 범위를 벗어날 수 있으므로 최종값을 담는
// 변수 answer는 long long 타입이여야 한다.

int N;
const int MAX = 500000;
int board[MAX];

void Solve()
{
    int cur = 1;
    long long answer = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        cur = min(cur, board[i]);
        answer += cur;
        ++cur;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}