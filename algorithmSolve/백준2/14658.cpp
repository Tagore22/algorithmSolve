#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

// 풀이.
// 오랜만에 아침에 일어나서 P.S를 했더니 머리가 안돌아간다. 컨디션을 유지해야한다.
// 문제의 의도는 결국 사각형의 트램펄린에 최대한 많이 별의 좌표를 담아야하는데
// 2차원의 방식을 한번에 하려면 매우 힘들기 때문에 둘로 나누어서 생각해보았다.
// 각 X, Y축에 투포인터를 사용하여 좌표의 차이가 L보다 작거나 같은 최대한의
// 개수를 구하면 되는데 X축을 먼저하든 Y축을 먼저하든 상관은 없다.
// 따라서 X축으로 투포인터 순회를 하며 더이상 불가능할 때 X축에서는 가능했던
// 현재 원소들을 다시 Y축으로 검사하여 그중 살아남은 좌표들을 구하고 그중
// 최대값을 구하면 된다. 로직의 큰 틀은 꽤 빠르게 생각해냈으나 후술할 자질구레한
// 부분이 발목을 잡았다. 분류에는 그냥 브루트포스 알고리즘으로 나와있는데 원래
// 의도가 그런건지 뭔지 모르겠다.

// 자세한 설명은 주석으로 남긴다.

int N, M, L, K, answer = 0;
pair<int, int> board[100];
deque<int> deq;

// X축 검사가 끝났을 때 구한 원소들로 Y축을 검사하는 함수.
void CheckMaxNum()
{
    if (deq.empty())
        return;

    deque<int> cur = deq;
    sort(cur.begin(), cur.end());
    int from = 0, to = 0, ans = 0, num = 0, idx = deq.size();
    while (from <= to && to < idx) // 범위 확인
    {
        if (cur[to] - cur[from] <= L)
        {
            ++to;
            ++num;
        }
        else
        {
            ans = max(ans, num);
            // 이 부분이 상술한 실수한 곳이다. num을 갱신하지 않았다던가
            // 0으로 갱신했다던가 온갖 삽질을 다했다.
            --num;
            ++from;
        }
    }
    // 만약 cur에 존재하는 원소가 3개고 각 좌표값이 1, 2, 3이며 L의 값이 4일때
    // 위에 while문 중에 else문은 늘 무시되기 때문에 결과적으로 ans값은 변하지
    // 않기에 마지막에 최종적으로 검사를 해보아야한다.
    ans = max(ans, num);
    answer = max(answer, ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L >> K;
    for (int i = 0; i < K; ++i)
        cin >> board[i].first >> board[i].second;

    sort(board, board + K);
    int from = 0, to = 0;
    while (from <= to && to < K) // 조건 확인.
    {
        if (board[to].first - board[from].first <= L)
        {
            deq.push_back(board[to].second);
            ++to;
        }
        else
        {
            // X축 검사가 끝났을 때 현재 원소들로 Y축 검사를 해본다.
            CheckMaxNum();
            deq.pop_front();
            ++from;
        }
    }
    // CheckMaxNum()안에서처럼 만약 else문이 늘 무시될 경우를 대비하여
    // 마지막으로 한번 더 검사한다.
    CheckMaxNum();
    cout << K - answer << '\n';
    return 0;
}