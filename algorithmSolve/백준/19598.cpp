#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 종만 북에 그리디 알고리즘을 설명하며 비슷한 문제가 나왔었다. 그때는 종료시각을 기준으로 정렬하여
// 문제를 풀었고 그 기억을 되살려 똑같이 하였는데 답이 나오질 않았다. 이러한 판례 또한 존재했다.
// 큐에 30, 40이 남아있고 다음 회의가 50 ~ 60, 30 ~ 70일 때 종료시각을 기준으로 한다면 
// 50 ~ 60이 먼저 큐에 접근한다. 50이 30보다 작기에 대체되고 그다음 30 ~ 70이 큐에 접근했을 때
// 30은 둘 모두보다 작기에 새로운 회의실이 생긴다. 하지만 시작시각을 기준으로 정렬한다면
// 추가로 회의실이 필요 없다.

// 예전에도 이런 적이 있던 것 같은데 잘 기억해두어야겠다. 회의실이 한 개고 가능한 회의의 개수라면 종료시각을
// 회의실이 여러 개일 때에는 시작시각을 기준으로. 무조건은 아니겠으나 지침으로는 될 것 같다.

// 자세한 설명은 주석으로 남긴다.


pair<int, int> board[100000];
int N;

void MakeAnswer()
{
    sort(board, board + N);
    priority_queue<int> que;
    que.push(-board[0].second);
    int answer = 1;
    for (int i = 1; i < N; ++i)
    {
        int prev = -que.top();
        if (prev <= board[i].first)
            que.pop();
        else
            ++answer;
        que.push(-board[i].second);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}