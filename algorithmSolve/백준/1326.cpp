#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 각 징검다리에서 이동시 징검다리에 쓰여있는 수의 배수만큼 이동하는 것을
// 주의해야 하는 문제다. 왼쪽 혹은 오른쪽으로 이동해야하는데 얼마만큼 이동
// 할 수 있는지 알 수 없기에 두부분으로 나누어야만 했다.

// 자세한 설명은 주석으로 남긴다.

int N, a, b;
int board[10001], visit[10001];

void BFS()
{
    queue<int> que;
    que.push(a);
    // 각 징검다리에 도착한 최소 수들의 초기화.
    for (int i = 1; i <= N; ++i)
        visit[i] = 987654321;
    visit[a] = 0;
    int answer = 0;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            // 오른쪽으로 이동할 경우.
            for (int i = 1; ; ++i)
            {
                int next = here + board[here] * i;
                // b에 도달하였다면 더이상의 연산없이 최소값 answer를 출력후 탈출한다.
                if (next == b)
                {
                    cout << answer << '\n';
                    return;
                }
                if (next > N)
                    break;
                if (visit[next] <= answer)
                    continue;
                que.push(next);
            }
            // 왼쪽으로 이동할 경우.
            for (int i = 1; ; ++i)
            {
                int next = here - board[here] * i;
                if (next == b)
                {
                    cout << answer << '\n';
                    return;
                }
                if (next <= 0)
                    break;
                if (visit[next] <= answer)
                    continue;
                que.push(next);
            }
        }
    }
    // 끝끝내 b에 도달하지 못할 경우 -1을 출력한다.
    // 이 부분을 빠뜨려서 한번 틀렸다.
    cout << -1 << '\n';
}

void Solve()
{
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    cin >> a >> b;
}

int main()
{
    Input();
    Solve();
    return 0;
}