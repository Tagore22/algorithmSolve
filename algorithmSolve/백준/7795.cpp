#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// A의 각 원소별로 B의 원소들중 자신보다 작은 값들의 수를 구하면 되는 문제다.
// 주먹구구식 풀이.

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

        // 가지치기를 위한 정렬.
        sort(B, B + M);
        int answer = 0;
        // A를 순회한다.
        for (int i = 0; i < N; ++i)
            // B를 순회한다.
            for (int j = 0; j < M; ++j)
            {
                // A가 크다면 최종답 answer가 1이 증가하고 계속 순회한다.
                if (A[i] > B[j])
                    ++answer;
                // 만약 A가 같거나 작다면 정렬에 의해 그 뒤는 무조건 A가 작아지므로 탈출.
                else
                    break;
            }
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