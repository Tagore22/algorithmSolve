#include <iostream>

using namespace std;

// 풀이.
// L의 거리를 최소한의 시간으로 도달한다는 것은 매번 최대 거리로 이동해야 한다는 것이다.
// 따라서 L을 5로 나누고 만약 나머지가 존재한다면 그 거리만큼 1분 더 이동해야한다.

int main()
{
    int L;
    cin >> L;
    int answer = L % 5 == 0 ? L / 5 : L / 5 + 1;
    cout << answer << '\n';
    return 0;
}