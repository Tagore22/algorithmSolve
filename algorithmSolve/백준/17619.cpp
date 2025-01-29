#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 30프로가 안되는 정답율답게 어려운 문제였다. 오랜만에 유니온 파인드였는데 마지막에
// 주어지는 두 수의 머리값을 구해 같은지 아닌지 확인하는것은 확실했으나 두 지점의 비교하는
// 방식이 잘 떠오르질 않았다. 결과적으로는 왼쪽을 기준으로 정렬하여 각 범위를 갱신하는 것이었다.

// 자세한 설명은 주석으로 남긴다.

struct pos
{
    int l;
    int r;
    int idx;
};

pos board[100001];
int p[100001];
int N, Q;

// 정렬의 기준이 되는 함수. 왼쪽위치를 기준으로 정렬하며
// 같은 위치는 나오지 않으므로 시작부분만 비교해보면 된다.
bool SortFunc(const pos& lhs, const pos& rhs)
{
    if (lhs.l != rhs.l)
        return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}

// 각 지점의 머리위치를 출력하는 함수.
int Find(int idx)
{
    if (p[idx] == idx)
        return idx;
    // 이 부분이 최적화의 핵심인데 한번 값이 갱신될때 차례대로 올라가며
    // 모두 갱신이 되기 때문이다.
    return p[idx] = Find(p[idx]);
}

// 두 지점을 병합하는 함수.
void Merge(int lhs, int rhs)
{
    lhs = Find(lhs), rhs = Find(rhs);

    if (lhs != rhs)
        p[rhs] = lhs;
}

void MakeAnswer()
{
    // 왼쪽부터 오른쪽으로 스위핑을 해나가며 순회하기 때문에
    // 정렬이 필수적이다.
    sort(board, board + N, SortFunc);
    // p는 부모의 값이며 최대 N까지 주어진다.
    for (int i = 0; i <= N; ++i)
        p[i] = i;
    int from = board[0].l, to = board[0].r;
    for (int i = 1; i <= N; ++i)
    {
        // 만약 새로운 범위가 기존 범위와 겹친다면
        if (board[i].l <= to)
        {
            // 새로운 범위는 기존 범위의 병합되고 기존 범위의 끝을
            // 갱신한다.
            Merge(board[i - 1].idx, board[i].idx);
            to = max(to, board[i].r);
        }
        else
        {
            from = board[i].l;
            to = board[i].r;
        }
    }
    for (int i = 0; i < Q; ++i)
    {
        cin >> from >> to;
        // 두 지점이 같이 묶여있다면 이동이 가능하다.
        cout << (Find(from) == Find(to) ? 1 : 0) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].l >> board[i].r >> board[i].idx;
        board[i].idx = i + 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}