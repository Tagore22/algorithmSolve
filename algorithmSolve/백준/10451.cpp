#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 그래프들중에서 순환의 개수를 구하는 문제다.
// 나는 조금 복잡하게 풀었는데 간단하게 DFS를 이용한 컴포넌트의 개수를 구하는 방식으로 풀어도 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1001];
bool visit[1001], isCircle[1001];
int T, N, answer;

// 모든 순환을 찾는 함수.
void DFS(int here)
{
    visit[here] = true;
    int next = board[here];

    // 이미 방문한곳에 다시 도달하였다면 사이클을 이룬다.
    if (visit[next])
    {
        // 방향 그래프이기 때문에 이전을 찾아볼 필요가 없다.
        if (!isCircle[next])
        {
            isCircle[next] = true;
            int there = next;
            while (board[there] != next)
            {
                isCircle[board[there]] = true;
                there = board[there];
            }
            isCircle[board[there]] = true;
            ++answer;
        }
        return;
    }
    DFS(next);
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        answer = 0;
        memset(visit, false, sizeof(visit));
        memset(isCircle, false, sizeof(isCircle));
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> board[i];

        for (int i = 1; i <= N; ++i)
        {
            if (visit[i])
                continue;

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