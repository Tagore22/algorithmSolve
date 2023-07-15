#include <iostream>

using namespace std;

// 10159번의 플로이드 와셜 풀이법.
// 처음에도 플로이드 알고리즘 자체는 떠올렸으나 어떻게 적용시켜야 할지가 떠오르지 않았다.
// 알고보면 간단한데, 주어진 연결들을 이용하여 각 물건들이 접근 가능한지를 파악하면 된다.
// 접근이 가능하다면 비교가 가능하다는 것이기 때문이다.
// 다만, 무거움을 비교하는 경우와 가벼움을 비교하는 경우 2가지로 나누어 파악해야한다.
// 나누지 않으면 2가지 경우가 합쳐진 그래프가 생성되기 때문에 답을 찾을수 없다.

// 자세한 설명은 주석으로 남긴다.

bool heavy[101][101], light[101][101];
int N, M;

void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                // 희안하게 2차원 bool타입 벡터에서는 이 |= 연산이 되질 않았다.
                heavy[i][j] |= heavy[i][k] & heavy[k][j];
                light[i][j] |= light[i][k] & light[k][j];
            }
}

void MakeAnswer()
{
    Floyd();
    int answer;
    for (int iter = 1; iter <= N; ++iter)
    {
        answer = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (heavy[iter][i])
                ++answer;
            if (light[iter][i])
                ++answer;
        }

        cout << N - answer - 1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        light[from][to] = true;
        heavy[to][from] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}