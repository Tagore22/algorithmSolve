#include <iostream>

using namespace std;

// 풀이.
// 이분 탐색을 금방 떠올려서 전혀 어려운 문제가 아니었는데 한가지 치명적인 실수가
// 있었다. 후술하겠으나 마지막에 남은 파의 양을 구하는 부분인데 예를 들어 3, 5,
// 100, 100, 100이 주어질 때 각 파닭에 넣는 파의 양은 50이고 남은 파의 양은
// 50이다. 하지만 기존에는 남은 파의 양을 구하는 방식을 각 파를 순회하며
// 파닭에 넣는 파의 양으로 나눈 나머지값들을 더하고 있었기에 50이 아닌 0이
// 나왔다. 따라서 파의 총 값에서 파닭에 넣는 파의 양 * 파닭의 개수를 뺀
// 값을 출력해야한다.

// 자세한 설명은 주석으로 남긴다.

int S, C;
int board[1000000];
long long sum = 0;

// mid값으로 몇개의 파닭에 파를 넣을 수 있는지 구하는 함수.
bool CalMax(int mid)
{
    int ans = 0;
    for (int i = 0; i < S; ++i)
        ans += board[i] / mid;

    return ans >= C;
}

void Solve()
{
    // 원래는 from ~ to가 int 범위를 넘어서지 않으나 후에 C와 곱해지는
    // 과정에서 그 값이 int값을 벗어날 수도 있기에 둘중 하나는 long long
    // 타입이여야 한다.
    long long from = 1, to = 1000000000;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (CalMax(mid))
            from = mid + 1;
        else
            to = mid - 1;
    }

    // 상술한대로 이곳에서 실수가 있었다. 기존처럼 각 파를 순회하며
    // 파닭에 넣을 파의 양을 나눈 값들을 더하면 안된다.
    long long answer = sum - (from - 1) * C;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> C;
    for (int i = 0; i < S; ++i)
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