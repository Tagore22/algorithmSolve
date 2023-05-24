#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 평범한 구간트리(세그먼트 트리)문제이다.
// N의 개수가 최대 10만이고 찾아야 하는 범위의 수 M이 최대 10만이라
// 일반적으로 풀면 10만 * 10만의 연산량이 나오기에 풀수없다.
// 쉽게 찾을수 있는 구간트리 문제와 거의 다르지 않기에 정답률도 매우 높다.
// 다만 한가지 놓친부분이 있었는데 나는 int 최대값을 거의 987654321으로 하는데
// 이번에도 그러했다. 하지만 이번 문제는 최대값이 10억이기에 987654321이 제대로
// 엄청 큰 수의 값을 해주지 못했다. 결과적으로 앞에 1을 덧붙여 해결하였다.

// 자세한 설명은 주석으로 남긴다.

const int MAX_NUM = 100000;
int board[MAX_NUM];
pair<int, int> iter[MAX_NUM];
int N, M;

// 트리 구현.
struct tree
{
    vector<int> tree_board;

    tree()
    {
        tree_board.resize(N * 4);
    }

    // 트리의 초기화. 기본적으로 이진 탐색처럼 두갈래로 나뉘어
    // 로그의 연산량을 지닌다.
    int Init(int idx, int left, int right)
    {
        // 나뉘고 나뉘어 left 혹은 right 하나만 남았다면 그 지점이 자신의 자리다.
        if (left == right)
            return tree_board[idx] = board[left];

        // 두갈래로 나뉘어 현재 범위의 최소값을 찾는다.
        int mid = (left + right) / 2;
        int first = Init(idx * 2, left, mid);
        int second = Init(idx * 2 + 1, mid + 1, right);
        // 나뉜 두갈래의 최소값들중 더 최소값을 현재의 최종 최소값으로 지님.
        return tree_board[idx] = min(first, second);
    }

    int Init()
    {
        return Init(1, 0, N - 1);
    }

    // 범위 from ~ to가 주어졌을때 그 범위내 최소값을 찾는 함수.
    int Find(int idx, int left, int right, int from, int to)
    {
        // 1. 범위가 아예 겹치지 않는다면 가장 큰 수를 반환하여 무시.
        // 2. from ~ to가 left ~ right와 범위가 같거나 더 커진다면 현재를 그대로 반환.
        // 3. 그렇지 않다면 다시 반으로 나누어 재귀.
        if (right < from || to < left)
            // 바로 이부분이 놓친 부분이었는데 상술하였듯 이번에는 98765431이 엄청 큰 최대값의
            // 몫을 해주지 못한다.
            return 1987654321;
        if (from <= left && right <= to)
            return tree_board[idx];
        int mid = (left + right) / 2;
        int first = Find(idx * 2, left, mid, from, to);
        int second = Find(idx * 2 + 1, mid + 1, right, from, to);
        return min(first, second);
    }

    int Find(int from, int to)
    {
        return Find(1, 0, N - 1, from, to);
    }
};

void MakeAnswer()
{
    tree t;
    t.Init();

    int answer;
    for (int i = 0; i < M; ++i)
    {
        answer = t.Find(iter[i].first - 1, iter[i].second - 1);
        cout << answer << '\n';
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
    for (int i = 0; i < M; ++i)
        cin >> iter[i].first >> iter[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}