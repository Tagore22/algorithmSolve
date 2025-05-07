#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// BFS로도 간단히 풀 수 있을 것 같으나 값이 너무 크다. 따라서 각 방법별로 값을 계산한 후에 
// 최소값을 구해야했다. 각 방법은 다음과 같다.

// 1. 가로, 세로로만 가는 방법
// 2. 대각선으로만 가는 방법
// 3. 두 방법을 혼합하는 방법

// 주의해야할 점은 대각선으로만 갈 때인데 짝수만큼만 이동이 가능하다는 점이다. 따라서 총 거리가
// 홀수일때는 대각선으로 최대한 이동하고 나머지는 1번 방식으로 이동하게끔 구현한다.
// 이것은 아래 CalMinWay()로 구현하였다. 3번 방법은 X와 Y중 최소값만큼 대각선으로 움직이고
// 나머지 거리는 다시 1번과 2번 방법중 최소값을 더해주면 된다.

// 자세한 설명은 주석으로 남긴다.

long long X, Y, W, S;

// 거리 len만큼 이동할때 최소 비용을 구하는 함수.
long long CalMinWay(long long len)
{
    // 1번 방식으로 이동할 때.
    long long OnlyStraight = len * W;
    // 2번 방식으로 이동할 때.
    long long OnlyDiagonal = len / 2 * 2 * S + len % 2 * W;
    return min(OnlyStraight, OnlyDiagonal);
}

void Solve()
{
    long long FirstWay = CalMinWay(X + Y);
    long long Commonlen = min(X, Y);
    // 3번 방식으로 이동할 때.
    long long SecondWay = Commonlen * S;
    SecondWay += CalMinWay(X + Y - Commonlen * 2);
    long long answer = min(FirstWay, SecondWay);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> X >> Y >> W >> S;
}

int main()
{
    Input();
    Solve();
    return 0;
}