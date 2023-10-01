#include <iostream>

using namespace std;

long long board[4000004];
int N, M;

// 풀이.
// 오랜만에 세그먼트 트리(구간 트리)문제다. 문제부터 '이 문제는 구간 트리로 푸는 것이라오'라고 광고를 하고 있어서
// 풀기 쉬웠다. 다만 구간 트리를 업데이트함에 있어 한가지 실수를 하였는데 업데이트 된 값을 반영을 안해주고 있었다.
// 나머지는 어렵지 않았다. 다만 다른 풀이들을 보면 속도가 거의 절반에 요상한 풀이들이 있었는데 먼지 감도 안잡혔다.
// 다만 나는 종만북에 나온 풀이로 풀었기 때문에 나쁜 풀이는 아닐것이다.

// 자세한 설명은 주석으로 남긴다.

// left ~ right까지의 범위를 순회하며 모든 합을 반환하는 함수.
long long Query(int node_left, int node_right, int left, int right, int node)
{
    // 구하고자 하는 범위가 현재 범위와 아예 겹치지 않는다면 무시한다.
    if (node_left > right || left > node_right)
        return 0;
    // 현재 범위가 구하고자 하는 범위안에 속한다면 현재 값을 반환한다.
    if (left <= node_left && node_right <= right)
        return board[node];

    // 절반으로 나누어 실행한다.
    int mid = (node_left + node_right) / 2;
    return Query(node_left, mid, left, right, node * 2) +
        Query(mid + 1, node_right, left, right, node * 2 + 1);
}

// 기존값을 변경하여 구간 트리에 반영하는 함수.
long long Update(int idx, int num, int left, int right, int node)
{
    // 변경하고자 하는 위치가 현재 범위내에 존재하지 않는다면 무시한다.
    if (left > idx || idx > right)
        return board[node];
    // 결국 시작과 끝이 같을때까지 내려왔다면 그곳이 변경될 위치기에 값을 변경해준다.
    if (left == right)
        return board[node] = num;

    // 절반으로 나누어 실행하고 현재 값을 변경해준다.
    // 이부분에서 변경해주는걸 잊어버려서 한참 헤맸다.
    int mid = (left + right) / 2;
    return board[node] = Update(idx, num, left, mid, node * 2) +
        Update(idx, num, mid + 1, right, node * 2 + 1);
}

void MakeAnswer()
{
    int func, from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> func >> from >> to;

        if (func == 0)
        {
            if (from > to)
                swap(from, to);
            cout << Query(1, N, from, to, 1) << '\n';
        }
        else
        {
            Update(from, to, 1, N, 1);
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}