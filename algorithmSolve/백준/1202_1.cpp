#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

//1202번 문제의 더 빠른풀이
//가방별로 담을수 있는 모든 보석들을 우선순위 큐에 저장하여
//가장 가치 있는 보석의 값을 더한다.
//이전 풀이는 보석들의 수 * long(가방들의 수)만큼의 시간복잡도가 필요하였으나,
//이 풀이는 가방들의 수 + 보석들의 수의 시간복잡도가 필요하여 더 빠르다.
//핵심은 변수 now로, 매번 보석들을 순회하지 않고 최대 순회하였던 인덱스를 저장하여
//시간복잡도가 곱셈이 아닌 덧셈이 되게 한다.

const int MAXNUM = 300000;
pair<int, int> board[MAXNUM];
int backpack[MAXNUM];
int N, K;


void MakeAnswer()
{
    sort(board, board + N);
    sort(backpack, backpack + K);

    long long answer = 0;
    priority_queue<int> que;
    int now = 0;
    for (int i = 0; i < K; ++i)
    {
        while (now < N && backpack[i] >= board[now].first)
            que.push(board[now++].second);
        if (!que.empty())
        {
            answer += que.top();
            que.pop();
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
    for (int i = 0; i < K; ++i)
        cin >> backpack[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}