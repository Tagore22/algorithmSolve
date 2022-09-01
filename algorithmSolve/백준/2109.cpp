#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> board[10000];

//1781번과 매우 비슷한 문제이다. 풀이까지 똑같은데 조금 다른점이라면 이문제에선 day라는 변수를 통해서 현재의 날짜를
//추적해 나가며 풀었으나, 1781번에서는 큐의 크기로 대체했다는 점이다. 어차피 day는 직접적으로 큐에 삽입되는 첫번째
//if문에서만 증가해야 함으로 둘다 다를바가 없다는 점이다.

void MakeAnswer() //d, p 순
{
    priority_queue<int> que;
    int day = 0;
    sort(board, board + N);
    for (int i = 0; i < N; ++i)
    {
        if (board[i].first > day)
        {
            que.push(-board[i].second);
            ++day;
        }
        else
        {
            if (board[i].second > -que.top())
            {
                que.pop();
                que.push(-board[i].second);
            }
        }
    }
    int answer = 0;
    while (!que.empty())
    {
        answer += -que.top();
        que.pop();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].second;
        cin >> board[i].first;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}