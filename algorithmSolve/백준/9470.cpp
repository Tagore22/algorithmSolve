#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 정답율이 40퍼도 안되는 꽤나 복잡한 문제지만 생각보다 쉽게 풀었다. 요즘 잘 풀리는 거 같아 다행이다.
// 규칙이 하나 정해져 있는데 어떤 정점의 순서는 그 정점에 도달할수 있는 정점들의 순서들중 가장 큰 순서를 max라고 할때
// max가 2개 이상이라면 + 1이며 그렇지 않다면 max가 해당 정점의 순서가 된다. M번 정점이 무조건 바다로 통하기 때문에
// 결과적으로 M번 정점의 순서를 구하는것이 된다. 도달한 정점의 순서를 정해야했기에 아이러니하게 역순으로 풀어야했다.
// 입력때부터 방향을 반대로 바꾸어서 오히려 M번에서 시작해서 순서를 구하면 된다. 또한 하나의 정점에 여러번 도달할수 있기에
// DP까지 함께 구현했다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board[1001];
int dp[1001];
int T, K, M, P;

// idx번째 정점의 순서를 구하는 함수.
int DFS(int idx)
{
    // DP처리. 다만 기존에는 -1로 초기화하는 일이 많았는데 이번에는
    // 모든 정점의 순서가 최소 1이기 때문에 0으로 초기화해도 된다.
    int& ans = dp[idx];
    if (ans != 0)
        return ans;
    ans = 1;

    // 얻은 모든 순서들을 저장한다.
    vector<int> cur;
    for (auto& a : board[idx])
        cur.push_back(DFS(a));
    // 도달할수 있는 곳이 없다면 현재 ans가 1이기 때문에 그대로 반환한다.
    if (cur.empty())
    {
        return ans;
    }
    // 도달할수 있는 곳이 1군데라면 ans을 그 값으로 갱신하여 반환한다. 현재 ans가 최소값이기 때문에
    // cur[0]보다 작으면 작았지 더 큰일은 없기 때문이다.
    else if (cur.size() == 1)
    {
        return ans = cur[0];
    }
    // 2군데 이상일 경우에는 최대값이 2개 이상이여서 + 1 된 값을 반환해야할수도 있기에
    // 모든 순서들을 내림차순으로 정렬하여 0번째 원소와 1번째 원소를 비교하여 ans값을 갱신후
    // 반환한다.
    else
    {
        sort(cur.begin(), cur.end(), greater<>());
        return ans = cur[0] == cur[1] ? cur[0] + 1 : cur[0];
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        for (auto& a : board)
            a.clear();
        for (int j = 0; j <= M; ++j)
            dp[j] = 0;
        cin >> K >> M >> P;
        int from, to;
        for (int j = 0; j < P; ++j)
        {
            cin >> from >> to;
            board[to].push_back(from);
        }
        cout << iter + 1 << ' ' << DFS(M) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}