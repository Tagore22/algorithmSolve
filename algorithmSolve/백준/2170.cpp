#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 처음에는 문제를 잘못보았다. x와 y를 이용한 2차원 문제인줄 알았으나 그냥 1차원 문제였다.
// 스위핑 알고리즘을 사용하는 문제인데 스위핑 알고리즘은 정렬등의 순서를 정해서 한쪽에서 쓸어담듯이 순회하는
// 알고리즘이다. 즉, 주어진 범위들을 시작점을 기준으로 정렬한다. 그 후 주어진 범위들의 최대값을 구해나간다.
// 다만 시작점이 기존의 끝점보다 커지는 경우가 존재할수 있는데 이때 기존 범위값을 구해 최종답 answer에 추가해주고
// 현재 시작점과 끝점으로 새로운 범위를 만든다. 상술하였듯 스위핑 알고리즘의 진가가 여기서 발휘되는데 시작점을 기준으로
// 정렬하였기에 이 이후에 현재 시작점보다 작은 시작점은 존재할수 없다. 그러므로 안심하고 기존의 범위값을 answer에 더할수
// 있는 것이다. 생소한 알고리즘이었는데 잘 기억해두어야겠다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[1000000];
int N;

void MakeAnswer()
{
    // 스위핑 알고리즘을 위한 정렬.
    sort(board, board + N);
    // 범위값은 처음 시작점과 끝점으로 초기화한다.
    int from = board[0].first;
    int to = board[0].second;
    int answer = 0;
    // 모든 범위들 순회.
    for (int iter = 0; iter < N; ++iter)
    {
        // 만약 새로운 시작점이 기존 범위의 끝점보다 커서 겹치지 않는다면
        // 기존 범위값의 길이를 최종답 answer에 더하고 현재 시작점과 끝점으로
        // 새로운 범위를 만든다.
        if (board[iter].first > to)
        {
            answer += to - from;
            from = board[iter].first;
            to = board[iter].second;
        }
        // 그렇지 않으면 현재 끝점을 기존 범위의 끝점과 비교하여 갱신한다.
        // 스위핑 알고리즘을 이용해 시작점을 정렬하였기에 현재 시작점은 무조건
        // 범위의 시작값과 같거나 크기 때문에 따로 건드릴 필요가 없다.
        else
        {
            to = max(to, board[iter].second);
        }
    }
    // 최종답 answer의 갱신 및 출력.
    answer += to - from;
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