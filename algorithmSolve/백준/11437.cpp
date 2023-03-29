#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// LCA문제는 처음봐서 대강의 개념은 이해해야했다.
// https://4legs-study.tistory.com/121

// LCA의 기본적인 개념은 이러하다.

// 1. 두 정점을 부모 정점으로 올려가며 두 정점이 같을때 바로 그 정점이 최소 공통 부모이다.
// 2. 다만 현재 두 정점의 깊이가 다를시 최소 공통 부모를 찾을수 없기에 깊이를 맞춰주어야 한다.
// (현재 정점에서 부모 정점으로 올리며 두 정점의 깊이를 맞춤.)

// 개념자체는 어려울게 없어서 풀어봤는데 자꾸 시간초과가 났었다.
// 이유는 의외로 간단했는데 문제의 예시에는 연결의 연결이 이어지는 상태로 새로운 연결이
// 주어졌지만 그렇지 않을 수도 있었다. 예를 들어 1 ~ 4번의 노드가 있는데 각각
// 1 - 2, 2 - 3, 3 - 4로 이어 졌을때 1 - 2, 3 - 4, 2 - 3순으로 연결상태가 주어진다면
// 중간에 3 - 4의 상태를 평범하게는 알아낼수 없었다.

// 그래서 연결된 모든 정점들을 저장하여 부모가 아니라면 제외하고 그렇지 않다면
// 연결하는 식으로 트리를 짜야 했다.

// 자세한 것은 주석으로 남기며 LCA가 어렵지 않아서 다행이다.

vector<vector<int>> board;
int parent[50001], level[50001];
int N, M, lhs, rhs;

// 트리를 연결하는 함수. 상술하였듯 평범하게 연결해서는 허점이 생긴다.
// 또한 0번이 추가되어 의아할수 있으나, 문제에서 루트는 1번이라고 나와 있기에
// 0번과 연결된 정점은 있을수 없다. 그렇기에 0번이 존재해도 상관은 없다.
void MatchParent(int c, int p)
{
    parent[c] = p;
    level[c] = level[p] + 1;

    // 연결된 모든 정점들을 자신의 아래로 연결한다. 다만 부모는 제외한다.
    for (int i = 0; i < board[c].size(); ++i)
    {
        int cur = board[c][i];
        if (cur == p)
            continue;

        MatchParent(cur, c);
    }
}

// 깊이의 차이가 존재할시 공통된 부모를 찾기 복잡해지기에 
// 깊이를 맞춘다.
void FindAnswer()
{
    // 현재 깊이가 다를시 현재 정점에서 부모 정점으로 올라가며 깊이를 맞춘다.
    while (level[lhs] != level[rhs])
    {
        if (level[lhs] > level[rhs])
            lhs = parent[lhs];
        else
            rhs = parent[rhs];
    }

    // 부모 정점으로 올라가며 두 정점이 동일할시 공통 부모가 된다.
    while (lhs != rhs)
    {
        lhs = parent[lhs];
        rhs = parent[rhs];
    }

    cout << lhs << '\n';
}

void MakeAnswer()
{
    MatchParent(1, 0);
    for (int i = 0; i < M; ++i)
    {
        cin >> lhs >> rhs;
        FindAnswer();
    }
}

void Input() // 트리가 연결되지 않은 상태로 주어질수도 있다.
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    parent[0] = 0;
    level[0] = 0;

    cin >> N;
    board.resize(N + 1, vector<int>());
    for (int i = 1; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}