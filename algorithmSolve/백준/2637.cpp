#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 오랜만에 위상 정렬 문제다. 그런데 여러번 잘못 풀었다.
// 첫번째에는 브루트포스 비스므리하게 풀어서 시간초과가 났었다.
// 틀린 코드들을 보면 알겠으나, 같은 부품을 같은 수로 만드는 경우가 여러번 있을 경우
// 불필요한 연산이 중복되기 때문에 dp로 묶어서 시간을 줄였어야 했다.

// 두번째에는 위상 정렬로 풀었는데 DFS방식으로 풀어서 상술한 dp를 어떻게 묶어야할지를 몰랐었다.
// 그래서 과거에 푼 다른 위상 정렬 문제들을 보니 앗... BFS였다.
// 의존도를 이용하여 현재 의존하지 않은 정점들을 BFS에서 처리해주면 되었다.

// 그리고 마지막에는 그 처리를 어떻게 해주어야할지 감이 안잡혔다.
// 결과적으로는 [시작점][도착점]을 이용해서 기존값을 현재 배수로 곱해서 더하면 되는 것이었다.
// 애매하면 과거에 풀었던것을 보는게 더 이해가 쉬웠다. 다른 사람이 푼 방식보다는 내 방식이
// 내가 보기에 더 이해가 쉽기 때문이다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<pair<int, int>>> board;
int answer[101][101], depend[101];
int N, M;

void BFS()
{
    queue<int> que;

    for (int i = 1; i <= N; ++i)
    {
        if (depend[i] == 0)
        {
            que.push(i);
        }
        // 나에서 나에게로를 1로 초기화해야 하술할 부분에서 연산이 제대로 된다.
        answer[i][i] = 1;
    }

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        // 이 처리 방식이 생각이 나질 않았다.
        // 설명하자면 다음과 같다. 어떤 정점 i에서 이전값으로의 개수가 존재한다면
        // 현재값으로의 개수는 배수 * 이전값을 더하면 된다.
        for (auto& temp : board[here])
        {
            int there = temp.first;
            int cost = temp.second;
            for (int i = 1; i <= N; ++i)
            {
                answer[i][there] += cost * answer[i][here];
            }
            // 의존도를 1 감소시키고 만약 의존도가 0이라면 큐에 삽입한다.
            --depend[there];
            if (depend[there] == 0)
                que.push(there);
        }
    }
}

void MakeAnswer()
{
    BFS();

    for (int i = 1; i < N; ++i)
    {
        // 기본 부품만을 출력해야 하기에 board[i]의 개수를 확인한다.
        if (board[i].size() == 0)
        {
            cout << i << ' ' << answer[N][i] << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    int parent, child, num;
    for (int i = 0; i < M; ++i)
    {
        cin >> parent >> child >> num;
        board[parent].push_back(make_pair(child, num));
        ++depend[child];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}