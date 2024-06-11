#include <iostream>

using namespace std;

// 풀이.
// 2018번의 느린 풀이.
// 거의 주먹구구식 풀이다. 범위가 겹치는 것은 존재할수 없으므로 DP로 묶지 않았다.
// 덧셈이 시작되는 수열이 자기 자신의 절반보다 큰 상황은 존재할수 없으므로 1 ~ N / 2까지
// 함수를 호출하여 이전값보다 1큰수를 빼나간다. 현재 수가 0보다 작다면 탈출하고 0이라면 1을 반환하여
// 결과적으로 만들수 있는 모든 가짓수를 출력한다.

int N;

int FindTree(int cur, int minus)
{
    if (cur == 0)
        return 1;
    else if (cur < 0)
        return 0;
    return FindTree(cur - minus, minus + 1);
}

int main()
{
    cin >> N;
    int answer = 1;
    for (int i = 1; i <= N / 2; ++i)
        answer += FindTree(N, i);
    cout << answer << '\n';
    return 0;
}