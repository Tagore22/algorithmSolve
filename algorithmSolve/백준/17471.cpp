#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 늘 생각하지만 삼성 문제답게 복잡한 문제다.
// 처음엔 감도 안잡혀서 공원돌면서 계속 생각해나가며 풀었다.
// 처음 막막했던 것은 어떻게 나눌지였다. 그러다가 생각난게 비트마스크였다.
// N이 최대 10개이니 int 하나로 충분히 모든 상황을 그려낼수 있었다.
// 그후에는 생각보다 잘 풀렸는데 비트마스크로 이미 idx번이 1번(1)인지 2번(0)인지 확인만 하면 되었기 때문이다.
// 어쨌든 풀었으니 다행이다. 이젠 좀 쉬자.

// 자세한 설명은 주석으로 남긴다.
// P.S 알고리즘 분류를 보면 알수 있듯이 무시무시한 문제인것 같은데 이상하리만치 정답율은 높다.
// 삼성 문제라 많은 사람들이 도전했던 문제인가보다.

// 각 번호별 인구수.
int board[10];
// 각 번호에서 연결된 번호들을 저장하는 벡터.
vector<vector<int>> way;
int N, first_num, second_num, mask;

// 현재 상황(mask에 따른)이 주어졌을때 각 선거구별로 연결되어있는지 확인하는 BFS.
int BFS(int idx, bool check)
{
    vector<bool> visit(N, false);
    visit[idx] = true;
    queue<int> que;
    que.push(idx);
    int ans = 1;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < way[here].size(); ++i)
        {
            int there = way[here][i];
            // there번째 구역이 이미 도달했거나, 시작지점과 같은 선거구가 아니라면 무시한다.
            if (!visit[there] && (((mask & (1 << there)) > 0) == check))
            {
                que.push(there);
                visit[there] = true;
                ++ans;
            }
        }
    }
    return ans;
}

// 각 선거구별 총 인원의 차이를 계산하는 함수.
int CalPeople()
{
    int first = 0;
    int second = 0;
    // 모든 지역을 순회하며 각 선거구별로 총 인원수를 구해 그 차이를 반환한다.
    for (int i = 0; i < N; ++i)
    {
        if (mask & (1 << i))
            first += board[i];
        else
            second += board[i];
    }
    return abs(first - second);
}

void MakeAnswer()
{
    // 1. 마스크(선거구 상태)를 순회한다.
    // 2. 두개의 선거구의 수를 구한다.(1번 선거구는 a개, 2번 선거구는 b개).
    // 3. 두개의 선거구중 아무거나 하나(가장 앞의것)에서 BFS를 돌려 선거구의 최대수를 구한다.
    // 4. 3번에서 구한 선거구가 2번에서 구한 선거구와 같다면 각 선거구별로 인구수를 구해 차이값을
    // 구한후 갱신한다.
    int answer = 987654321;
    // 1번.
    for (mask = 1; mask < ((1 << N) - 1); ++mask)
    {
        first_num = second_num = 0;
        int first_from, second_from;
        // 2번.
        for (int i = 0; i < N; ++i)
        {
            if (mask & (1 << i))
            {
                ++first_num;
                first_from = i;
            }
            else
            {
                ++second_num;
                second_from = i;
            }
        }
        // 3번.
        int cur_first = BFS(first_from, true);
        int cur_second = BFS(second_from, false);

        // 4번.
        if (first_num == cur_first && second_num == cur_second)
            // 여기서 인구수의 차이를 구한다.
            answer = min(answer, CalPeople());
    }
    cout << (answer == 987654321 ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    way.resize(N, vector<int>());
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j)
        {
            int next;
            cin >> next;
            way[i].push_back(next - 1);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}