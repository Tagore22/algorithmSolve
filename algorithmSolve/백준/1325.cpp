#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

//풀이
//A가 B를 신뢰한다는건 B를 해킹했을때 A로 넘어갈수 있다는것을 뜻한다. 그럼으로 2차원 벡터를 생성하여 A가 B를 신뢰할때
//board[B]에 A를 넣어 그 다음으로 도달할수 있다는걸 기록해둔다. 그 이후 1~N번 컴퓨터에서 시작하여 도달할수 있는 최대값을
//계산하여 가장 많이 도달할수 있는 컴퓨터의 번호를 출력한다.

vector<vector<int>> board;
int answer[10001];
bool check[10001];
int N, M;

void BFS(int from)
{
    queue<int> que;
    que.push(from);
    check[from] = true;
    int ans = 0;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();
        ++ans;

        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i];
            if (!check[there])
            {
                que.push(there);
                check[there] = true;
            }
        }
    }
    answer[from] = ans;
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
    {
        memset(check, false, sizeof(check));
        BFS(i);
    }

    int num = *max_element(answer, answer + N + 1);
    for (int i = 1; i <= N; ++i)
        if (answer[i] == num)
            cout << i << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(answer, 0, sizeof(answer));

    cin >> N >> M;
    board.resize(N + 1, vector<int>());
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        board[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}