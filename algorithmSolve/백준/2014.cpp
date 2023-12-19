#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 소수들이 주어질때 각 소수들의 곱으로 배열을 늘려나간다. 이때 N번째 수를 출력하면 된다.
// 개인적으로는 실패한 문제같다. 문제내에서 애매한 부분이 너무 많다.
// 소수들끼리 곱하는 방식을 설명하는 것도 애매했고, 질문게시판을 보면 여러가지 애매해서 올라온
// 질문글이 많다. 결과적으로는 처음에 주어진 K개의 소수들을 오름차순으로 정렬된 결과값들과 곱하여
// 가장 작은 값이 추가되는 방식인데 이 K가 최대 100개이고 N이 최대 10만이었으므로
// 매번 K만큼 순회하며 현재 만들어지는 값들의 최소값을 추가하는 방식으로 풀면 된다.
// 그랬을때 최대 연산량 1000만으로 안정적으로 풀수 있다.
// 다만 한가지 주의해야할점이 있는데 N번째 값은 2의 31제곱보다 작다고 나와 있기에
// int배열을 생각했었는데 이건 오산이었다. 상술하였듯 매번 만들어지는 수들중 가장 작은수를
// 추가하는데 만약 맨 마지막 수가 2의 31제곱 - 1 일때 다른수들은 이미 int값들을 벗어난 값이기 때문이다.
// 따라서 int 배열이 아닌 long long 배열을 사용해야 한다.

// 자세한 설명은 주석으로 남긴다.

long long board[100001], multi[100], prime[100];
int K, N;

void MakeAnswer()
{
    // 모든 소수들은 0번째 원소값(1)을 곱하며 시작한다.
    memset(multi, 0, sizeof(multi));
    board[0] = 1;
    // 현재 추가되는 원소값의 인덱스 번호.
    int idx = 1;
    // N개의 수를 추가한다.
    for (int iter = 0; iter < N; ++iter)
    {
        // 여기서 한 10분을 헤맸다. 상술하였듯 int값을 벗어나는 경우가 존재하기에
        // long long 타입을 사용해야하기에 최대값도 987654321이 아닌 더 큰수여야 한다.
        // 현재 만들어지는 수와 그 원소값.
        pair<long long, int> ans = make_pair(98765432199, -1);
        // 모든 소수들을 순회하며 각 소수가 현재 만드는 값들을 찾는다.
        for (int i = 0; i < K; ++i)
        {
            long long cur = prime[i] * board[multi[i]];
            // 현재 만들어지는 값은 바로 이전값보다 커야한다.
            while (cur <= board[idx - 1])
            {
                ++multi[i];
                cur = prime[i] * board[multi[i]];
            }
            // 현재 만든 값들중 최소값을 찾는다.
            if (cur < ans.first)
            {
                ans.first = cur;
                ans.second = i;
            }
        }
        // 새로운 값을 추가하고 인덱스의 번호를 갱신한다.
        board[idx] = ans.first;
        ++idx;
    }
    cout << board[N] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; ++i)
        cin >> prime[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}