#include <iostream>
#include <cstring>

using namespace std;

//17626번의 또다른 풀이이다. 재귀가 아닌 반복문 위주의 풀이로써 1부터 주어진 N까지 순회하며 N보다 작은 2제곱수의 DP값+1 들을 비교하여
//최소값이 dp[N]이 된다. 앞에 풀이는 최초의 순회시 무조건 1씩 줄이는 재귀를 최대 5만번 돌아야 하기에 모든 수를 검사 + 5만번가량의 콜스택
//으로 인해 이 풀이보다 훨씬 느리다. 이 풀이는 가능한 부분만을 더구나 단순 반복문으로 순회하기에 메모리도 더 작게 차지한다.
//너무 재귀에만 의존하지말자.

int cashe[50001];
int N;

int Cal(int num)
{
    if (num == 0)
        return 0;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 987654321;
    for (int i = 1; i * i <= num; ++i)
        ans = min(ans, Cal(num - i * i) + 1);

    return ans;
}

void MakeAnswer()
{
    cout << Cal(N) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}