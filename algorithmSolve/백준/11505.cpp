#include <iostream>

using namespace std;

// 풀이.
// 구간트리, 즉 세그먼트 트리의 문제이다.
// 개념을 알고 있으면 그냥 대입만 하면 되는 수준의 문제인데 곱셈을 구해야 한다는 것 하나만 다르다.
// 또한, 두군데로 나누었을때 각 값이 최대 100만에 도달하기 때문에 곱셈의 결과가 int값을 벗어나서 long long이
// 필요하다. 매번 long long으로 타입변환이 귀찮아서 그냥 long long형 배열을 사용하였다.

// 자세한 설명은 주석으로 남긴다.

const int MAX_NUM = 1000001;
const int DIV_NUM = 1000000007;
int board[MAX_NUM];
long long ran[MAX_NUM * 4];
int N, M, K;

long long Init(int from, int to, int node)
{
    // 시작과 끝이 같을때 즉, 맨 마지막에 다다랐을때 값을 초기화한다.
    if (from == to)
        return ran[node] = board[from];

    // 둘로 나누어 반복.
    int mid = (from + to) / 2;
    long long left = Init(from, mid, node * 2);
    long long right = Init(mid + 1, to, node * 2 + 1);
    return ran[node] = left * right % DIV_NUM;
}

long long Query(int from, int to, int q_from, int q_to, int node)
{
    // 구하고자 하는 범위값과 아예 다르다면 무시한다.
    if (to < q_from || q_to < from)
        return 1;
    // 현재 구간값이 구하고자하는 구간값안에 존재한다면 현재 값을 출력한다.
    if (from <= q_from && q_to <= to)
        return ran[node];

    // 둘로 나누어 반복.
    int mid = (q_from + q_to) / 2;
    long long left = Query(from, to, q_from, mid, node * 2);
    long long right = Query(from, to, mid + 1, q_to, node * 2 + 1);
    return left * right % DIV_NUM;;
}

long long Update(int from, int to, int idx, int newvalue, int node)
{
    // 업데이트하고자 하는 범위 값과 아예 겹치지도 않는다면 따로 업데이트 할필요없이 현재값을 반환한다.
    if (idx < from || to < idx)
        return ran[node];

    // Init과 마찬가지로 맨 마지막에 다다랐다면 값을 갱신한다.
    if (from == to)
        return ran[node] = newvalue;

    // 둘로 나누어 반복.
    int mid = (from + to) / 2;
    long long left = Update(from, mid, idx, newvalue, node * 2);
    long long right = Update(mid + 1, to, idx, newvalue, node * 2 + 1);
    return ran[node] = left * right % DIV_NUM;
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    Init(1, N, 1);

    int a, b, c;
    for (int i = 0; i < M + K; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(1, N, b, c, 1);
        else
            cout << Query(b, c, 1, N, 1) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}