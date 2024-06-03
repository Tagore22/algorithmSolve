#include <iostream>

using namespace std;

// 풀이.
// 어디서 풀어본거 같은데 정확히 기억은 안난다. 돌의 개수가 1조에 달하는건 둘째치고
// 애시당초 한번에 뺄수 있는 돌의 개수가 홀수개라서 게임 시작시 짝수라면 창영이가 이기고
// 홀수라면 무조건 상근이가 이긴다.

int main()
{
    long long N;
    cin >> N;
    string answer = N % 2 == 0 ? "CY" : "SK";
    cout << answer << '\n';
    return 0;
}