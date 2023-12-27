#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 오랜만에 구간쿼리 문제였다. 주어진 수열들의 최소값을 출력하되,
// 중간중간 값이 바뀔수도 있다. 구간 쿼리를 대입하기만 하면 되는 문제다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> arr;
int board[100001];
int N, M;

// 초기화 함수. 후술하겠으나 from, to는 쿼리의 범위가 아닌 주어지는 배열의 범위다.
// 따라서 1 ~ N이 되어야 한다.
pair<int, int> Init(int from, int to, int node)
{
    if (from == to)
        return arr[node] = make_pair(board[from], from);
    int mid = (from + to) / 2;
    pair<int, int> left = Init(from, mid, node * 2);
    pair<int, int> right = Init(mid + 1, to, node * 2 + 1);
    return arr[node] = min(left, right);
}

// from ~ to범위내의 최소값을 출력하는 함수. node_from, node_to는 쿼리의 범위가 아닌
// 배열의 범위다. 따라서 최초로 호출할때에는 1 ~ N이 되어야한다.
pair<int, int> Query(int from, int to, int node, int node_from, int node_to)
{
    if (from > node_to || node_from > to)
        return make_pair(1987654321, 1987654321);
    if (from <= node_from && to <= node_to)
        return arr[node];
    int mid = (from + to) / 2;
    pair<int, int> left = Query(from, to, node * 2, node_from, mid);
    pair<int, int> right = Query(from, to, node * 2 + 1, mid + 1, node_to);
    return min(left, right);
}

// 쿼리에서 idx번째 원소값을 value로 바꾸는 함수.
pair<int, int> Update(int idx, int value, int node, int from, int to)
{
    if (idx < from || idx > to)
        return arr[node];
    if (from == to)
        return arr[node] = make_pair(value, idx);
    int mid = (from + to) / 2;
    pair<int, int> left = Update(idx, value, node * 2, from, mid);
    pair<int, int> right = Update(idx, value, node * 2 + 1, mid + 1, to);
    return arr[node] = min(left, right);
}

void MakeAnswer()
{
    arr.resize(N * 4);
    Init(1, N, 1);
    int act;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> act;
        if (act == 1)
        {
            int idx, num;
            cin >> idx >> num;
            Update(idx, num, 1, 1, N);
        }
        else
        {
            cout << Query(1, N, 1, 1, N).second << '\n';
        }
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