#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에 문제만 봤을땐 엄청 쉬워보였는데 막상 풀어보니 발상을 떠올리기가 어려운 문제였다.
// 또한, 정답율이 25퍼센트조차 되지 않았다. 문제의 의도 자체는 상술하였듯 굉장히 쉽다.
// 주어진 수열이 수없이 많은 BFS순회 순서중 하나인지를 구별하는 것이다.
// 처음에는 BFS의 성질을 이용하여 현재 정점에서 이동가능한 모든 정점들을 큐에 집어넣고
// 그 집어넣은 큐들을 현재 수열과 비교하려고 했었는데 https://www.acmicpc.net/board/view/60231의 반례를 보면
// 알수 있듯이 애시당초 불가능하다. 앞서 큐에 들어간 순서를 전혀 알수 없기 때문이다.
// 방법은 아예 주어진 수열대로 순회를 도는 것이다. 애시당초 주어진 수열이 가능한 순회라면
// 직접 순회를 하면서 값을 비교할때 다를리가 없기 때문이다. 다만 주어진 수열대로 각 이동가능한 정점들의
// 순서를 새로 정렬해야 했다. 어려운 개념같으나 실상은 주어진 순서대로 우선순위를 부여하여 각 이동가능한 정점들을
// 모두 정렬하기만 하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> tree;
int board[100000], order[100001];
int N;

// 이동가능한 정점들의 순서를 다시 정렬하는 함수.
bool SortFunc(int lhs, int rhs)
{
    // 각 우선순위에 맞춰서 정렬한다.
    if (order[lhs] < order[rhs])
        return true;
    return false;
}

// BFS 순회 함수.
void BFS()
{
    queue<int> que;
    que.push(0);
    vector<int> visit(N + 1, false);
    visit[0] = true;
    int idx = 0;

    // 딱 한가지 부분만을 제외하고는 일반적인 BFS와 다를것이 없다.
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto there : tree[here])
        {
            if (!visit[there])
            {
                // 실제 현재 방문하는 정점과 주어진 수열이 다르다면 0을 출력한다.
                if (there != board[idx])
                {
                    cout << 0 << '\n';
                    return;
                }
                visit[there] = true;
                que.push(there);
                ++idx;
            }
        }
    }
    // 주어진 수열대로 BFS 순회를 마칠수 있었기에 1을 출력한다.
    cout << 1 << '\n';
}

void MakeAnswer()
{
    tree[0].push_back(1);
    // 각 모든 정점들의 이동가능한 정점들을 우선순위에 맞춰 새롭게 정렬한다.
    for (int i = 0; i <= N; ++i)
        sort(tree[i].begin(), tree[i].end(), SortFunc);
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    tree.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        // 입력된 순서대로 우선순위를 부여한다.
        order[board[i]] = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}