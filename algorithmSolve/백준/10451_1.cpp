#include <iostream>
#include <cstring>

using namespace std;

// 10451의 다른 풀이.
// 모든 정점은 다음을 가지기 때문에 끊어질일 없이 연결되어 있다.
// 그렇기에 각 컴포넌트의 개수를 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1001];
bool visit[1001];
int T, N, answer;

void DFS(int here)
{
    visit[here] = true;
    int next = board[here];

    // 이미 방문한 곳은 무시한다.
    if (!visit[next])
        DFS(next);
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        answer = 0;
        memset(visit, false, sizeof(visit));
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> board[i];

        // 이미 방문한 정점은 무시하고
        // 매번 DFS가 호출될때마다 새로운 컴포넌트를 찾게 된다.
        for (int i = 1; i <= N; ++i)
        {
            if (visit[i])
                continue;

            ++answer;
            DFS(i);
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