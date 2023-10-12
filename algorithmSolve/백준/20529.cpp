#include <iostream>

using namespace std;

// 풀이.
// 처음 문제를 봤을땐 조금 당황했다. 10만개중 3개를 골라야하는데 이것은 10억을 훌쩍 넘기 때문이다.
// 정답은 dp에 적용되는 비둘기집 알고리즘이었다. 각 유형은 최대 16종류가 있는데 N의 크기가 33이상일때에는
// 무조건 같은 유형의 사람이 3명이상 존재하기 때문이다. 따라서 N의 크기가 32초과 혹은 33이상일 경우
// 0을 출력하고 그렇지 않은 경우는 완전탐색으로 최소값을 계산해서 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

string board[100000];
int T, N, answer, ans;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 최종답의 초기화.
        answer = 987654321;
        cin >> N;

        for (int i = 0; i < N; ++i)
            cin >> board[i];
        // 위 상술하였듯 N이 33이상일 경우 같은 유형의 사람이 3명이상 무조건 존재하므로 0을 출력함.
        if (N > 32)
        {
            cout << 0 << '\n';
            continue;
        }

        // 그렇지 않을 경우 모든 인원들을 완전탐색으로 계산한다.
        for (int i = 0; i < N - 2; ++i)
        {
            for (int j = i + 1; j < N - 1; ++j)
            {
                for (int k = j + 1; k < N; ++k)
                {
                    for (int z = 0; z < 4; ++z)
                    {
                        if (board[i][z] != board[j][z])
                            ++ans;
                        if (board[j][z] != board[k][z])
                            ++ans;
                        if (board[i][z] != board[k][z])
                            ++ans;
                    }
                    // 최종답 및 현재값의 갱신.
                    answer = min(answer, ans);
                    ans = 0;
                }
            }
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