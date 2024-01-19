#include <iostream>

using namespace std;

// 풀이.
// 1부터 N까지 약수들의 합을 구해 그 총합을 출력하는 문제다.
// 에라토스테네스의 체를 이용하여 사전에 미리 모든 약수들의 합을 구하고
// 다시 N까지의 합을 구하여 출력한다.

// 자세한 설명은 주석으로 남긴다.

int board[1000001];
int N;

// 에라토스테네스의 체. 미리 모든 약수들의 합을 구한다.
// 이러면 약수의 연산과 약수들의 합의 연산이 곱에서 합으로 나뉘어진다.
void Era()
{
    for (int i = 1; i <= 1000000; ++i)
        board[i] = 1;
    for (int i = 2; i <= 1000001; ++i)
        for (int j = i; j < 1000001; j += i)
            board[j] += i;
}

int main()
{
    cin >> N;
    Era();
    long long answer = 0;
    // 미리 구해놓은 약수들의 합의 합을 구한다.
    for (int i = 1; i <= N; ++i)
        answer += board[i];
    cout << answer << '\n';
    return 0;
}