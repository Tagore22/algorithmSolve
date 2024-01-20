#include <iostream>

using namespace std;

// 풀이.
// 요근래 자주 푸는 구간 쿼리 문제다. 왠지 모르게 골드1 문제에 엄청 많다.
// 기본적으로 큰 틀은 동일하나 짝수와 홀수를 구분해야 한다.
// 어려울것 없이 0, 1로 홀수와 짝수를 구분한 후 홀수일 경우 구간의 길이 - 짝수의 개수를
// 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100001], arr[400004];
int N, M;

// 초기화 함수.
int Init(int left, int right, int node)
{
    if (left == right)
        return arr[node] = board[left] % 2 == 0 ? 1 : 0;
    int mid = (left + right) / 2;
    int lhs = Init(left, mid, node * 2);
    int rhs = Init(mid + 1, right, node * 2 + 1);
    return arr[node] = lhs + rhs;
}

// 쿼리 함수.
int Query(int left, int right, int node, int node_left, int node_right)
{
    if (node_right < left || right < node_left)
        return 0;
    if (left <= node_left && node_right <= right)
        return arr[node];
    int mid = (node_left + node_right) / 2;
    int lhs = Query(left, right, node * 2, node_left, mid);
    int rhs = Query(left, right, node * 2 + 1, mid + 1, node_right);
    return lhs + rhs;
}

// 기존값을 새로운 값으로 변경하는 업데이트 함수.
int Update(int value, int idx, int node, int left, int right)
{
    if (idx < left || right < idx)
        return arr[node];
    if (left == right)
        return arr[node] = value % 2 == 0 ? 1 : 0;
    int mid = (left + right) / 2;
    int lhs = Update(value, idx, node * 2, left, mid);
    int rhs = Update(value, idx, node * 2 + 1, mid + 1, right);
    return arr[node] = lhs + rhs;
}

void MakeAnswer()
{
    Init(1, N, 1);
    int a, b, c;
    for (int iter = 0; iter < M; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(c, b, 1, 1, N);
        else if (a == 2)
            cout << Query(b, c, 1, 1, N) << '\n';
        else
            cout << ((c - b + 1) - Query(b, c, 1, 1, N)) << '\n';
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