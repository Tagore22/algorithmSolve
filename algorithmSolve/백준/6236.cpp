#include <iostream>

using namespace std;

// 풀이.
// 오랜만에 푸는 이진 탐색 문제다. 이진 탐색에는 2가지 풀이가 존재하는데 다음과 같다.

// 1. for문을 무조건 100번 도는 방법.
// 2. 투포인터를 사용하여 두 위치가 엇갈릴때까지 이동시키며 순회하는 방법.

// 연산량이 100번을 초과하느냐 안하느냐에 따라 둘중 하나를 사용하면 되는데 이번에는 2번째 방법을 사용하였다.
// 다만 이진 탐색에서 늘 헷갈리는 것은 마지막에 무엇을 출력하느냐이다. 이번 문제를 복기할때 이것을 중점으로 할것인데
// 다음과 같다. 

// 1. 어떤 위치 mid에서 인출을 하였을때의 반환값이 M보다 작거나 같다면 수를 줄여야 한다. 그러므로 
// 범위는 to = mid - 1이 되어서 총 범위는 from ~ mid - 1이 된다.
// 2. 반대로 M보다 크다면 수를 늘려야 하기에 from = mid + 1이 되어 총 범위는 mid + 1 ~ to가 된다.
// 3. 따라서 성공하였을때는 1번이 되므로 이때 역대 최소값은 mid or to + 1이 된다. 현재까지 조사한 수들중
// 조건에 부합하는 가장 최소값이기 때문이다. 

// 번외로 문제가 거지같은 문제였다. 문제 자체는 어렵지 않으나 정답율이 30프로도 안됀다. 
// 하루에 인출은 한번만 가능하다. 따라서 모든 사용금액을 비교하여 최대값을 구한후 순회 전에 그 최대값을 시작값으로
// 해야 한다. 이부분의 설명이 어설프지 않았나 싶다.

// 자세한 설명은 주석으로 남긴다.

int board[100000];
int N, M, sum = 0, min_num = -1;

int WithdrawMoney(int money)
{
    int cur = 0, ans = 0;
    for (int i = 0; i < N; ++i)
    {
        // 현재 가진 돈보다 적다면 인출한다.
        if (cur < board[i])
        {
            ++ans;
            cur = money;
        }
        cur -= board[i];
    }
    return ans;
}

void MakeAnswer()
{
    int from = min_num, to = sum, mid;
    while (from <= to)
    {
        mid = (from + to) / 2;
        if (WithdrawMoney(mid) <= M)
            to = mid - 1;
        else
            from = mid + 1;
    }
    cout << mid << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
        min_num = max(min_num, board[i]);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}