#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 빡쎈 문제였다. 정렬해서 어떻게 순서를 세우는것까진 알겠는데 가격순과 높이순 어떻게 해야할질 감이 안잡혔다.
// 결국 힌트를 봤는데 DP와 이분탐색이 있었다. 로직을 다시 세워야했다. 요약하자면 모든 원소를 순회한다.
// idx번째 원소를 순회할때 idx - 1번째 원소와의 거리를 파악해서 S보다 크거나 같다면 dp[idx번째 원소의 높이]는 
// dp[idx - 1번째 원소의 높이] + idx번째 원소의 가격과 기존값의 최대값이 된다. 즉, 각 dp는 어떤 높이에서의 최대 가격이 된다.
// 또한, 거리가 S보다 작다면 둘중 하나만 놓을수 있기에 가격을 비교해야하는데 idx번째 원소의 높이 - S값보다 같거나 작은 인덱스값
// prev를 구해야한다. 이것을 위해서 upper_bound를 구한후 prev값을 1 감소시킨다. lower_bound는 값이 같거나 큰 첫번째 원소를
// 구하기 때문에 실제로 적용되는 원소값을 가릴수 있어서 불가능하다. 이렇게 prev를 구한후 dp[idx번째 원소의 높이]는 
// dp[idx - 1번째 원소의 높이]와 dp[prev번째 원소의 높이] + idx번째 원소의 가격중 최대값이 된다. 이것을 마지막까지 순회하여
// dp[가장 높은 높이]를 출력하면 된다. 여러므로 복잡한 문제였다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board;
int dp[20000001];
int N, S;

void MakeAnswer()
{
    // 순회를 위해서도, 이분탐색을 위해서도 정렬을 해야한다.
    sort(board.begin(), board.end());
    // 모든 원소들을 순회한다. 다만 0번째 원소에 0을 넣어주어야 한다. 예를 들어 S가 5이고 첫번째 원소의 높이가 8,
    // 두번째 원소의 높이가 10일때 두번째 원소의 순서에서 8은 함께 할수 없기에 upper_bound를 이용해야 하는데 
    // 그 결과값으로 8이 나오기에 제대로 된 정답을 구할수 없다. 따라서 0을 맨 앞에 넣어서 최소값을 조절해야한다.
    for (int iter = 1; iter <= N; ++iter)
    {
        // iter번째 원소의 높이와 그 이전 높이의 차이가 S보다 크거나 같을때
        if (board[iter].first - S >= board[iter - 1].first)
        {
            // 기존값과 이전값의 dp값 + 현재의 가격을 더한값중 최대값이 dp값이 된다.
            dp[board[iter].first] = max(dp[board[iter].first], dp[board[iter - 1].first] + board[iter].second);
        }
        // S보다 작을때.
        else
        {
            // 현재의 높이값 - S값보다 작은 가장 큰값 idx를 구하여 이전값의 dp와 dp[idx] + 현재값의 가격 둘중 최대값이
            // 현재값의 dp값이 된다.
            int idx = distance(board.begin(), upper_bound(board.begin(), board.end(), make_pair(board[iter].first - S, 20000001))) - 1;
            dp[board[iter].first] = max(dp[board[iter - 1].first], dp[board[idx].first] + board[iter].second);
        }
    }
    cout << dp[board.back().first] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S;
    board.push_back(make_pair(0, 0));
    int h, c;
    for (int i = 0; i < N; ++i)
    {
        cin >> h >> c;
        board.push_back(make_pair(h, c));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}