#include <iostream>

using namespace std;

// 풀이.
// 구간쿼리의 복습이다. 크게 다를것이 없다.

int board[100001], arr[400004];
int N, M;

int Init(int from, int to, int node)
{
    if (from == to)
        return arr[node] = board[from];
    int mid = (from + to) / 2;
    int left = Init(from, mid, node * 2);
    int right = Init(mid + 1, to, node * 2 + 1);
    return arr[node] = min(left, right);
}

int Query(int from, int to, int node, int node_from, int node_to)
{
    if (from > node_to || node_from > to)
        return 1987654321;
    if (from <= node_from && node_to <= to)
        return arr[node];
    int mid = (node_from + node_to) / 2;
    int left = Query(from, to, node * 2, node_from, mid);
    int right = Query(from, to, node * 2 + 1, mid + 1, node_to);
    return min(left, right);
}

int Update(int idx, int value, int node, int from, int to)
{
    if (idx < from || idx > to)
        return arr[node];
    if (from == to)
        return arr[node] = value;
    int mid = (from + to) / 2;
    int left = Update(idx, value, node * 2, from, mid);
    int right = Update(idx, value, node * 2 + 1, mid + 1, to);
    return arr[node] = min(left, right);
}

void MakeAnswer()
{
    Init(1, N, 1);
    int a, b, c;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(b, c, 1, 1, N);
        else
            cout << Query(b, c, 1, 1, N) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}