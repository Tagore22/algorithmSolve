#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 엄청나게 어려운 문제였다. 실제로 정답율도 30퍼가 안된다. 초반에는 대강 틀은 잡았었다.
// 분명 DP를 이용한 냅색문제였다. 그런데 idx번째 아이를 선택했을때 그 아이의 친구들을 찾는것이
// 문제였다. 처음에는 bool 배열 visit같은걸 이용해서 idx번째의 친구들을 모두 찾은후 visit = true;로
// 갱신한후 나중에 고를때 혹여라도 중복을 막게끔 했었다. 불가능했다. 결과적으로는 유니온 파인드를 이용하여
// 가장 루트에 있는 정점을 골라서 30000명의 정점을 고르는게 아닌 그 루트들만 순회하여 고르는것이 정답이었다.
// 또한, 냅색을 재귀호출 비슷하게 함수로 구현했는데 그 부분에서도 시간초과가 났다. 굉장히 빽빽한 문제인것 같다.
// 애시당초 냅색, DP, 그래프, 유니온 파인드까지 섞여있는 매우 복합적인 문제인데, 아무래도 출제자가 그냥 다 섞어버린듯하다.

// 자세한 설명은 주석으로 남긴다.

int N, M, K;
int c[30001], dp[30001][3001], p[30001], all[30001];
vector<int> f[30001], board;

// 유니온 파인드의 Find() 함수. 특별할게 없다.
int Find(int num)
{
    if (p[num] == num)
        return num;

    // 이 부분이 최적화된 부분인데 재귀호출과 동시에 값을 갱신하기 때문이다.
    return p[num] = Find(p[num]);
}

// 유니온 파인드의 Merge() 함수. 원래는 rank[]를 이용하여
// 탐색을 최적화시켜야 하지만 용량이 애매하여 그냥 빼버렸다.
void Merge(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    p[b] = a;
}

void MakeAnswer()
{
    // 가장 루트들만을 모으는 단계. 또한 친구들의 수까지 파악한다.
    for (int i = 1; i <= N; ++i)
    {
        int h = Find(i);
        f[h].push_back(i);
        board.push_back(h);
    }
    // 위 부분에서 같은 값이 여러개 들어간다. 왜냐하면 예를 들어 1, 2, 3이 친구인데
    // 이중 루트가 1이라면 N까지 순회하면서 1, 2, 3의 루트인 1이 3번 들어가기 때문이다.
    // 따라서 아래 부분에서 중복된 값을 삭제하기 위해 정렬후 인접한 값들이 같다면 모두 삭제하는
    // unique 함수를 사용한다.
    sort(board.begin(), board.end());
    board.erase(unique(board.begin(), board.end()), board.end());
    // 각 루트별로 얻는 사탕의 수를 구한다.
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < f[board[i]].size(); ++j)
            all[i] += c[f[board[i]][j]];
    int answer = 0;
    // 재귀호출이 아닌 단순 for문을 이용한 DP 풀이.
    // 잘봐두자.
    for (int i = 0; i < board.size(); ++i)
    {
        int cur = board[i];
        int num = f[cur].size();
        int candy = all[i];
        for (int j = K - 1; j >= 0; --j)
        {
            if (j >= num)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - num] + candy);
            else
                dp[i + 1][j] = dp[i][j];
            answer = max(answer, dp[i + 1][j]);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i)
        p[i] = i;
    for (int i = 1; i <= N; ++i)
        cin >> c[i];
    int a, b;
    // 처음엔 유니온 파인드를 어떻게 적용해야 할까 했는데 이거였다.
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        Merge(a, b);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}