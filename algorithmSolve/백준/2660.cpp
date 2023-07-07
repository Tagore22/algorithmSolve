#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 플로이드 알고리즘 문제이나 생각해 내기가 어려웠다.
// 바로 친구는 1점, 친구의 친구는 2점 등의 방식은 즉, 바로 방문 가능한 정점은 1점,
// 방문 가능한 정점에서 방문 가능한 정점은 2점과 동일하다.
// 즉, 모든 정점에서 다른 모든 정점들의 점수들중 가장 큰 점수를 골라서 그 점수가
// 가장 낮은 정점들을 찾는 것이 풀이 방법이다.
// 또한, 모든 정점들간의 점수를 구하기 위해서 단순 BFS가 아닌 플로이드 알고리즘을 사용해야 한다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
int N, answer;

// 모든 정점들간의 점수를 구하는 함수.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void MakeAnswer()
{
    answer = 987654321;
    Floyd();

    int cur;
    vector<int> ans;
    for (int iter = 1; iter <= N; ++iter)
    {
        // 모든 정점들의 점수들중 가장 큰 점수를 찾는다.
        cur = 0;
        for (int i = 1; i <= N; ++i)
            if (i != iter)
                cur = max(cur, board[iter][i]);

        // 그 점수가 현재 최소 점수보다 작다면 정점들의 배열을 새로 꾸리며
        // 점수를 갱신한다.
        if (cur < answer)
        {
            answer = cur;
            ans.clear();
            ans.push_back(iter);
        }
        // 그 점수가 현재 최소 점수와 같다면 현재 정점을 정점들의 배열에 포함시킨다.
        else if (cur == answer)
        {
            ans.push_back(iter);
        }
    }

    // 정말 어이없으나 바로 이 부분에서 1시간 가까이를 날렸다;;
    // 그냥 띄어쓰기만 출력하면 되는데 ", "를 출력하고 있었다 T^T
    cout << answer << ' ' << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>(N + 1, 987654321));
    int first, second;
    while (true)
    {
        cin >> first >> second;
        if (first == -1 && second == -1)
            break;
        board[first][second] = 1;
        board[second][first] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}