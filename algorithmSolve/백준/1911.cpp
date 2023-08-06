#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 맨 첫번째 웅덩이의 시작지점부터 시작해서 널빤지를 하나씩 덮어나간다.
// 다만 현재 널빤지가 다음 웅덩이까지 덮을수 있다면 시작점을 이미 덮은 웅덩이의 다음위치부터
// 옮겨서 그부분부터 덮어나가야 가장 적은 수의 널빤지를 구할수 있다.
// 또한 널빤지가 커서 현재 웅덩이를 이미 모두 덮은 상태라면 무시하고 넘어가야하기에
// 현재 지점의 위치를 계속 갱신하는 것이 중요하다. 마지막으로 주어지는 웅덩이의 마지막 지점은
// 덮는 부분에 포함되지 않는 것에 유의해야한다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[10000];
int N, L;

void MakeAnswer()
{
    // 웅덩이를 정렬시켜 시작지점부터 순회할수 있도록 한다. 웅덩이는 겹치지 않기 때문에
    // 정렬로 그 순서를 모두 맞출수 있다.
    sort(board, board + N);
    int cur = board[0].first;
    int answer = 0;
    int from, to;

    // 위 상술하였듯 모든 웅덩이를 순회하며 현재 위치부터 현재 웅덩이의 끝 이전까지 덮는다.
    // 다만 이미 덮혀져 있다면 무시하고 넘어간다.
    for (int i = 0; i < N; ++i)
    {
        from = board[i].first;
        to = board[i].second;
        // 현재 지점이 현재 웅덩이보다 크다면 시작지점을 바꾼다.
        if (cur > from)
            from = cur;
        // 그렇지 않다면 현재 지점이 현재 웅덩이의 시작지점이 된다.(웅덩이 사이가 긴 경우)
        else
            cur = from;

        // 만약 시작점이 현재 웅덩이의 끝보다 같거나 큰경우 이미 덮혀져 있는 것이므로 무시한다.
        if (from >= to)
            continue;

        // 덮어야 하는 웅덩이의 길이를 널빤지의 크기로 나누어 널빤지의 개수를 구한다.
        // 다만 널빤지의 크기가 2, 웅덩이의 길이가 5인것처럼 나누어도 나머지 부분이 있다면
        // 하나를 추가하여 모두 다 덮어야 한다.
        int dis = to - from;
        int plus = dis / L;
        if (plus * L != dis)
            ++plus;

        // 널빤지의 개수를 최종값 answer에 추가하고 현재 위치를 널빤지들의 길이만큼 더하여
        // 앞으로 나아간다.
        answer += plus;
        cur += plus * L;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}