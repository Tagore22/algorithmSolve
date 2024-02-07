#include <iostream>

using namespace std;

// 풀이.
// 구간별 총합을 구하는 문제이다. 다만 쿼리값이 매우 크기 때문에 구간 쿼리를 사용해야했다.
// 한가지 실수를 했는데 N일 값은 하나로 고정되는줄 알았는데 0에서 추가로 입력된 값이 증가하는 것이었다.

// 자세한 설명은 주석으로 남긴다.

long long board[4000004];
int N, Q;

// left ~ right의 총합을 구하는 함수.
long long Query(int left, int right, int node, int node_left, int node_right)
{
    if (node_right < left || right < node_left)
        return 0;
    if (left <= node_left && node_right <= right)
        return board[node];
    int mid = (node_left + node_right) / 2;
    long long lhs = Query(left, right, node * 2, node_left, mid);
    long long rhs = Query(left, right, node * 2 + 1, mid + 1, node_right);
    return lhs + rhs;
}

// idx번 값을 value로 교체하는 함수. 하지만 이 문제에선느 교체가 아니라 증가하는 함수다.
long long Update(int value, int idx, int node, int left, int right)
{
    if (idx < left || right < idx)
        return board[node];
    if (left == right)
        return board[node] += value;
    int mid = (left + right) / 2;
    long long lhs = Update(value, idx, node * 2, left, mid);
    long long rhs = Update(value, idx, node * 2 + 1, mid + 1, right);
    return board[node] = lhs + rhs;
}

void MakeAnswer()
{
    int a, b, c;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(c, b, 1, 1, N);
        else
            cout << Query(b, c, 1, 1, N) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}