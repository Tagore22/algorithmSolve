#include <iostream>
#include <algorithm>

using namespace std;

// 7795번의 더 나은 풀이.
// 이중 for문으로 최대 4억번의 연산을 매 테스트 케이스마다 계산하지 않고
// lower_bound()를 이용하여 이분 탐색을 실행한다.

// 자세한 설명은 주석으로 남긴다.

int A[20000], B[20000];
int T, N, M;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> M;
        for (int i = 0; i < N; ++i)
            cin >> A[i];
        for (int i = 0; i < M; ++i)
            cin >> B[i];

        sort(B, B + M);
        int answer = 0;
        // A를 순회한다.
        for (int i = 0; i < N; ++i)
            // 이중 for문을 사용하지 않고 lower_bound()를 이용하여 A와 같거나 더 큰 인덱스를 구한다.
            answer += lower_bound(B, B + M, A[i]) - B;

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}