#include <iostream> 
#include <algorithm>
#include <queue>

using namespace std;

// 풀이.
// 정렬을 이용한 자주 볼수 있는 문제중 꽤나 어려운 문제다.
// 분명 시작과 끝을 정렬하여 어떻게 하는건데 그 두가지를 비트는 방법이 힘들었다.
// 정답은 끝을 기준으로 정렬하여 시작을 우선순위 큐에 넣는것이었다.
// 풀이의 큰 틀은 다음과 같다.

// 1. 주어진 위치의 시작점들에서 시작하여 D만큼 이동하였을때 한번에 담을수 있는 위치들의 최대값을 알아내야 한다.
// 2. 어떠한 위치의 시작점부터 D만큼 나아가면 끝이 가까운 위치들을 처음에 만난다. 즉, 끝을 기준으로 정렬하여야 한다.
// 3. 각 위치들을 끝을 기준으로 정렬하여 끝점 - 시작점이 D보다 작거나 같다면 어떠한 위치에서 포함시킬수 있는 위치이므로
// 우선순위 큐에 시작점을 집어넣는다.(이 위치의 시작에서 얻을수 있는 위치들을 파악하기 위해)
// 4. 그후 우선순위 큐의 가장 위(시작점)에서 D만큼 이동시켰을때 현재의 끝점이 포함되는지를 확인한다.
// (현재 위치가 우선순위 큐의 가장 위의 위치에서 시작했을때 중첩시킬수 있는 위치인가)
// 5. 포함이 된다면 현재 큐의 크기를 최종값 answer와 비교하여 answer을 갱신한다.
// 6. 포함되지 않는다면 que를 하나 비우고 (pop) 반복한다.
// 7. 마지막 최종값 answer를 출력한다.

// 조금더 자세히 기록하기 위해 내용을 추가한다.
// 1. 어째서 큐의 맨위와 현재 위치의 끝값의 계산으로 최종값 answer를 갱신시킬수 있는가?
// - 위 상술하였듯 배열은 끝을 기준으로 정렬된다. 어떠한 시작지점에서 포함할수 있는 위치들을 확인할때
// 끝이 가까운것부터 포함되기 때문이다. 이 이야기는 N번째 위치의 시작지점을 que에 집어넣었을때 현재의 N번째 위치의 끝지점이
// 여태까지 나온 모든 끝지점들중 가장 뒤에 존재하는것을 의미한다. 즉, 가장 작은 시작지점인 que.top()에서 가장 큰 현재의 끝지점을
// 비교하여 그것이 D이하라면 다른 끝지점들은 무조건 D이하라는 것이기에 현재의 끝지점과 que.top()으로 비교할수 있는 것이다.
// 결과적으로 이 연산의 순회는 D의 마지막이 현재의 끝지점일때 중첩시킬수 있는 위치값들의 비교 갱신임을 알수 있다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100000];
priority_queue<int> que;
int N, D;

void MakeAnswer()
{
    // 끝을 기준으로 오름차순 정렬.
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // 끝점 - 시작점이 D이하라면 우선순위 큐에 집어넣는다.
        if (board[i].first - board[i].second <= D)
            que.push(-board[i].second);


        // 현재 큐에 있는 가장 짧은 시작위치와 가장 긴 현재의 끝지점을 비교하여
        // 그것이 D이하라면 현재 큐에 담긴 모든 수만큼의 위치를 중첩시킬수 있다.
        while (!que.empty())
        {
            if (-que.top() + D >= board[i].first)
            {
                int qsize = que.size();
                answer = max(answer, qsize);
                break;
            }
            else
            {
                que.pop();
            }
        }
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
        cin >> board[i].second >> board[i].first;
        if (board[i].second > board[i].first)
            swap(board[i].first, board[i].second);
    }
    cin >> D;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}