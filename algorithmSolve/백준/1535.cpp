#include <iostream>

using namespace std;

//풀이
//전형적인 배낭문제로 주어진 길이 N이 최대 20이기에 최대 연산량은 2의 20제곱으로 100만이 조금 넘기에 아무런 무리가 없다.
//각 원소별로 2가지 경우의 수가 있는데 첫번째로는 현재 체력이 인사시 줄어드는 체력보다 클경우 인사를 하는 것이고
//두번째로는 인사를 하지 않는 것이다. 이 모든 경우의 수를 따져 마지막 원소까지 모드 순회한 다음 최대값을 출력하며 된다.

int L[20], J[20];
int N, answer = 0;

void Max_Happy(int idx, int health, int happy)
{
    if (idx == N)
    {
        answer = max(answer, happy);
        return;
    }

    if (L[idx] < health)
        Max_Happy(idx + 1, health - L[idx], happy + J[idx]);

    Max_Happy(idx + 1, health, happy);
}

void MakeAnswer()
{
    Max_Happy(0, 100, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> L[i];
    for (int i = 0; i < N; ++i)
        cin >> J[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}