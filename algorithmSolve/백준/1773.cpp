#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 브2인데 잠이 덜깨서 그런가 생각보다 복잡한 문제였다. 각 주기마다 폭죽이 터지는 시간을
// 기록하되, 복수의 폭죽이 터지는때는 하나로 여기는 방식이다. 처음에는 최소공배수를 생각했으나
// N이 최대 100이기 때문에 복잡해졌다. 따라서 그냥 단순히 모든 경우를 기록하되, 첫 주기가
// 이미 방문한 상태라면 그보다 작은 수가 이미 한번 순회를 한 상태이기 때문에 순회를 할 필요가 없어진다는
// 것을 이용해야했고 당연히 정렬이 선행되어야 했다.

int main()
{
    int N, C;
    int board[100];
    bool visit[2000001] = { false, };
    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (visit[board[i]])
            continue;
        for (int j = board[i]; j <= C; j += board[i])
        {
            if (visit[j])
                continue;
            ++answer;
            visit[j] = true;
        }
    }
    cout << answer << '\n';
    return 0;
}