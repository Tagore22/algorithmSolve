#include <iostream>
#include <cstring>

//주어진 수 N을 제곱수들(4,9,16등 어떠한 수의 2제곱이 되는 수들)로 빼가면서 최소한의 덧셈으로 N을 표현할수 있는지를 구하는 문제이다.
//단순히 최대한 제곱수에 가까운 큰 수로 빼나가면 될거라 생각했지만, 그러한 그리디적 접근은 불가능했고, 결국 완전탐색을 이용하여
//1~제곱근까지의 수를 모두 한번씩 빼가며 최소값을 구해야한다. 그래서 아래 풀이와 같이 재귀와 DP를 이용하여 풀었으나, N이 최대값인 5만일때
//1씩 계속 빼나가면 콜스택이 5만번 쌓이기에 도중에 무시되었다. 대략 2926부터 오류가 났는데 여태까지 문제를 풀면서 너무 재귀에만 의지해온건
//아닌가 생각이 들었다.

using namespace std;

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