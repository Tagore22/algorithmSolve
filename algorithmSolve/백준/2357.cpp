#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 구간 트리 문제가 나왔다.
// 구간 트리 개념을 오랜만에 생각했기에 조금 오래 걸렸다.

// 구간 트리는 이진 트리로 만든 배열을 통해 범위 값을 구하기 때문에 빅오가 logN이다.
// 다른 말로 매번 범위를 둘로 나누어 이진 검색처럼 범위 값을 찾는다.

// 이 문제는 구간 트리만 알면 어렵지 않은, 말 그대로 대입만 하면 되는 문제이기에 주석을 보며
// 다시 한번 개념을 확실히 이해해야겠다.


int board[100000];

// 구간 트리는 from ~ to에 해당하는 범위를 배열로 만든 트리에 모두 저장하기에 배열의 크기가 N * 4에 달한다.
pair<int, int> RQ[400000]; // 최소, 최대.
int N, M;

// 구간 트리의 초기화 함수. 
pair<int, int> Init(int node, int from, int to)
{
    // 단 한개의 원소를 가리키는, 가장 작은 범위까지 내려왔다면 그 값이 최초값이 된다.
    if (from == to)
        return RQ[node] = make_pair(board[from], board[from]);

    int mid = (from + to) / 2;
    
    // 상술하였듯 구간 트리는 범위를 둘로 나누어 내려간다.
    pair<int, int> lhs = Init(node * 2, from, mid);
    pair<int, int> rhs = Init(node * 2 + 1, mid + 1, to);

    // 최종값을 찾아 현재값에 대입해준다.
    return RQ[node] = make_pair(min(lhs.first, rhs.first), max(lhs.second, rhs.second));
}


// 범위값을 찾는 함수. 매개변수는 각각 찾고자 하는 범위, 현재 노드번호(1부터 시작), 현재 노드의 범위값이다.
pair<int, int> Query(int left, int right, int node, int from, int to)
{
    // 찾고자 하는 범위가 현재 노드의 범위와 아예 겹치지 않는다면 무시한다.
    if (left > to || right < from)
        return make_pair(1000000001, 0);

    // 찾고자 하는 범위가 현재 노드 범위를 뒤덮는다면 현재 값을 반환한다.
    else if (left <= from && to <= right)
        return RQ[node];

    // 이진 탐색.
    int mid = (from + to) / 2;
    pair<int, int> lhs = Query(left, right, node * 2, from, mid);
    pair<int, int> rhs = Query(left, right, node * 2 + 1, mid + 1, to);

    // 최종 값을 반환한다.
    return make_pair(min(lhs.first, rhs.first), max(lhs.second, rhs.second));
}

void MakeAnswer()
{
    Init(1, 0, N - 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        pair<int, int> ans = Query(from - 1, to - 1, 1, 0, N - 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}