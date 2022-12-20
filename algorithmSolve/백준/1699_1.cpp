#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//재귀형 함수가 아닌 다른 방식의 DP. 더 빠르고 용량도 더 작게 차지한다.

//풀이
//어떤 수 N을 제곱수들의 합으로 치환하는데 가장 큰 수는 모든 수를 1의 제곱인 1로 더했을 경우 이기에 자기 자신 N이 된다.
//이상태에서 이전 풀이와 비슷하게 N에서 자신보다 작은 제곱수 S를 뺀 cashe[N - S] + 1과 cashe[N]을 비교하여 최소값을 얻어낼수 있다.

vector<int> board, cashe;
int N;


void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        cashe[i] = i;
        for (int j = 1; j * j <= i; ++j)
            cashe[i] = min(cashe[i], cashe[i - j * j] + 1);
    }

    cout << cashe[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cashe.resize(N + 1, 0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}