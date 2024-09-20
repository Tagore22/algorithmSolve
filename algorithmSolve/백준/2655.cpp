#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 어려운 문제였다. 쉬운 문제들은 거진 다 풀고 어려운것만 남은건지...
// 처음에는 냅색풀이와 DP를 섞어야 되는줄 알았으나 전혀 아니었다. DP를 이용해서 각각 최대값을 구한후
// N부터 역순으로 순회하며 최대값과 일치하는 값들을 찾아 계산하면 되었다. 2가지 의아한 부분들이 있었는데 다음과 같다.

// 1. 왜 꼭 1부터 시작해야하는가. 그냥 0부터 시작해서 인덱스값에 1을 더해 출력하면 안되는가?
// 하술하겠으나 0부터 시작하면 자기 자신의 값이 이상하게 나온다. 즉, 벽돌이 단 하나만 존재할때 그 하나는 무조건 쌓을수
// 있는데 이 경우가 무시될수 있다.
// 2. 아래 풀이에는 넓이를 우선으로 정렬했는데 무게를 먼저 정렬하면 안되는가?
// 상관없음.

// 정답율이 36퍼에 육박하는 어려운 문제였다. 후... 조금만 더 힘내보자.
// 자세한 설명은 주석으로 남긴다.

// 벽돌의 구조체. 정렬을 해야하기에 기존의 인덱스값을 알수 있기 위해 따로 int 변수 num을 추가해야만 했다.
struct stone
{
    int e;
    int h;
    int w;
    int num;
};

stone board[101];
int N, sum = 0;
int dp[101];

// 넓이를 기준으로 정렬하기 위한 비교 함수.
bool SortByExtent(const stone& l, const stone& r)
{
    return l.e < r.e;
}

void MakeAnswer()
{
    // 넓이를 기준으로 정렬한다.
    sort(board, board + N + 1, SortByExtent);
    // 0번은 무시된다. 이것은 상술한 1번 질문과 연결되어있는데 각 dp값은 최소한 자신의 벽돌 높이와 같다.
    // 왜냐하면 벽돌이 단 한개만 있을때 무조건 나 자신은 쌓을수 있기 때문이다. 이 부분을 계산하기 위해
    // 언제나 모든값이 0인 0번 인덱스가 필요했다. 이 0번 인덱스와의 계산을 통해 각 dp값은 나 하나만 있을
    // 경우를 무조건 구할수 있다.
    board[0] = { 0, };
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (board[j].w < board[i].w)
                dp[i] = max(dp[i], dp[j] + board[i].h); // 상술한대로 j가 0일때로 인해 무조건 dp[i]값은 board[i].h 이상이다. 
        sum = max(sum, dp[i]);
        // 최대값을 갱신한다.
    }

    vector<int> answer;
    // N이 가장 긴 값을 지녔을 것이기 때문에 N부터 역순으로 순회한다.
    for (int i = N; i > 0; --i)
        // i번째에서 최대값이라면 i번째 벽돌은 무조건 포함된다. 따라서 벡터에 넣고
        // i번째 벽돌의 높이만큼 최대값을 빼주어 다음 포함되는 벽돌을 찾는다.
        if (dp[i] == sum)
        {
            answer.push_back(board[i].num);
            sum -= board[i].h;
        }
    // 벽돌의 개수와 인덱스값 출력.
    cout << answer.size() << '\n';
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> board[i].e >> board[i].h >> board[i].w;
        board[i].num = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}