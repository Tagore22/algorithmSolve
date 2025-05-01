#include <iostream>

using namespace std;

// 풀이.
// 내 치명적인 단점이 오랜만에 드러났는데 너무 어렵게 생각한다는 것이다. 처음에는
// 각 부서진 카메라의 왼쪽과 오른쪽값들 계산해서 구현하는 방법을 떠올렸는데 마치 모기를 잡기
// 위해 코끼리 잡는 무기를 쓰는 느낌이 들었다. 이 문제의 실제 풀이는 매우 간단하다. 누적 합과 
// 슬라이딩 윈도우의 원리를 이용하여 맨 왼쪽부터 K개에서 한칸씩 옮겨가며 존재하는 부서진 카메라의 최소값을 구하면
// 된다. 조금 더 침착해보자.

int N, K, B;
int broken[100001];

void Solve()
{
    int minbroken = 0;
    for (int i = 1; i <= K; ++i)
        minbroken += broken[i];

    int curbroken = minbroken;
    for (int i = K + 1; i <= N; ++i)
    {
        curbroken += broken[i] - broken[i - K];
        minbroken = min(minbroken, curbroken);
    }
    cout << minbroken << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> B;
    for (int i = 0; i < B; ++i)
    {
        int num;
        cin >> num;
        broken[num] = 1;
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}