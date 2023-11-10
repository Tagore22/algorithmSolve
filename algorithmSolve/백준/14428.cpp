#include <iostream>

using namespace std;

// 풀이.
// 구간 쿼리 문제다. 다만 가장 작은 값의 인덱스를 알아야 했기에 단순 int형 배열이 아닌 pair<int, int>형 배열을 사용해야했다.
// 또한, 인덱스 번호가 0이 아닌 1번부터 시작했기에 구간 쿼리 역시 1번부터 시작하게끔 구현해야했다.
// 다만 마지막에 작지만 큰 실수로 해맸는데 쿼리함수에서 범위가 아예 어긋날때 최대값을 반환하는 부분이다. 평소 습관처럼 987654321을
// 반환했는데 주어지는 값이 최대 10억이다. 987654321는 10억보다 작은 9억의 값이기에 무시하기 위한 터무니 없이 큰 값이 되지 못해서
// 96퍼센트에서 몇번씩 틀렸다. 그래도 찾아다서 다행이나 다음번엔 조금더 세심하게 풀자.

// 자세한 설명은 주석으로 남긴다.

int board[100001];
pair<int, int> q_array[400004];
int N, M;

// 구간 쿼리의 초기화 함수.
pair<int, int> Init(int left, int right, int node)
{
    // 맨 마지막까지 이르렀다면 값을 대입해준다.
    if (left == right)
        return q_array[node] = make_pair(board[left], left);
    // 양쪽으로 나뉘어 재귀호출한다.
    int mid = (left + right) / 2;
    return q_array[node] = min(Init(left, mid, node * 2), Init(mid + 1, right, node * 2 + 1));
}

// 구간 쿼리의 쿼리 함수.
pair<int, int> Query(int left, int right, int node_left, int node_right, int node)
{
    // 찾으려는 범위가 현재 쿼리의 범위와 아예 어긋난다면 터무니 없이 큰 값을 반환하여 무시한다.
    if (left > node_right || node_left > right)
        return make_pair(1987654321, 1987654321);
    // 쿼리 범위가 찾으려는 범위에 포함된다면 현재 값을 출력한다.
    if (node_left >= left && right >= node_right)
        return q_array[node];
    // 양쪽으로 나뉘어 재귀호출한다.
    int mid = (node_left + node_right) / 2;
    return min(Query(left, right, node_left, mid, node * 2),
        Query(left, right, mid + 1, node_right, node * 2 + 1));
}

// 구간 쿼리의 갱신 함수.
pair<int, int> Update(int idx, int value, int left, int right, int node)
{
    // 범위를 벗어났다면 무시한다.
    if (idx < left || idx > right)
        return q_array[node];
    // 마지막에 이르렀다면 값을 변경한다.
    if (left == right)
        return q_array[node] = make_pair(value, idx);
    // 양쪽으로 나뉘어 재귀호출한다.
    int mid = (left + right) / 2;
    return q_array[node] = min(Update(idx, value, left, mid, node * 2),
        Update(idx, value, mid + 1, right, node * 2 + 1));
}

void MakeAnswer()
{
    Init(0, N - 1, 1);
    int num, first, second;
    for (int i = 0; i < M; ++i)
    {
        cin >> num >> first >> second;
        if (num == 1)
            Update(first - 1, second, 0, N - 1, 1);
        else
            cout << Query(first - 1, second - 1, 0, N - 1, 1).second + 1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}