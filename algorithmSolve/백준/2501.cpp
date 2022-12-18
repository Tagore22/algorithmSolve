#include <iostream>

using namespace std;

//풀이
//N의 K번째 약수를 구하는 문제이기에 1부터 N까지 모든 수를 대입해가며 K의 약수인지 구하고 구한다면 idx를 증가하여 몇번째 약수인지를 기록한다.
//그리고 idx가 K라면 답을 찾았으므로 출력하고, N까지 도달했음에도 K번째 약수를 구하지 못했다면 반복문에서 빠져나와 0을 출력한다.

int N, K;

void MakeAnswer()
{
    int idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (N % i == 0)
            ++idx;
        if (idx == K)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}