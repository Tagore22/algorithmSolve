#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 오랜만에 위상 정렬 문제였다.
// 문제 자체는 낯이 익었으나, 풀이가 생각나지 않아서 한 3초정도 당황했는데
// 직접 써보면서 풀어보니 머리가 핑그르르 돌면서 풀이가 술술 생각났다. 넘모 좋았다.
// 이 문제에서는 2개의 배열과 벡터가 필요한데 각각 다음과 같다.

// 1. 자신이 선수과목이 되는 경우를 담당하는 벡터.
// 2. 자신의 선수과목들의 수를 저장하는 배열.

// 이 2개가 핵심이다. 이후에 BFS에서 현재 선수과목의 수가 0개인 과목을
// 큐에 집어넣고 순회를 돌며 자기 자신이 선수과목인 과목들에서 자기자신을 제외(선수과목을 1제외)시킨다.
// 만약 그때 선수과목의 수가 0이 된다면 이 과목을 큐에 집어넣기를 반복한다.

// 또한, 2번 벡터는 2가지의 용도로 사용되었는데 첫째로는, 상술하였듯 선수과목들의 수를 저장하였고,
// 두번째로는 과목들의 듣는 학기수인 최종값을 저장하였다. 학기수를 구했다는 것은 이미 큐에 들어갔다는 것이고
// 그렇다는 것은 현재 선수과목의 수가 0(board[현재 과목] = 0)이라는 것이기에 더이상 배열의 의미가 없으므로
// 최종답을 저장하는데 재활용할수 있기 때문이다.


// 자세한 설명은 주석으로 남긴다.

// 상술한 1번 벡터.
vector<vector<int>> vec;
// 상술한 2번 벡터. 이후에 최종답을 저장하는데 사용된다.
int board[1001];
int N, M;

void BFS()
{
    queue<int> que;
    // 현재 선수과목이 없는 과목들을 큐에 집어넣는다.
    for (int i = 1; i <= N; ++i)
        if (board[i] == 0)
            que.push(i);

    int turn = 0;
    while (!que.empty())
    {
        int Qsize = que.size();
        ++turn;
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int here = que.front();
            que.pop();
            // 상술하였듯 큐에 들어갔다는 것은 board[here]가 0이라는 것이므로 더이상 board[here]가 의미가 없어진다.
            // 그렇기에 최종답을 저장할 용도로 재활용 할수 있다.
            board[here] = turn;

            // 현재 과목이 선수과목이 되는 다른 과목들에서 현재 과목을 지워준다.
            // 그랬을때 선수과목이 0이 된다면 역시 큐에 집어넣는다.
            for (int i = 0; i < vec[here].size(); ++i)
            {
                int there = vec[here][i];
                --board[there];
                if (board[there] == 0)
                    que.push(there);
            }
        }
    }
}

void MakeAnswer()
{
    BFS();
    for (int i = 1; i <= N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vec.resize(N + 1, vector<int>());
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        ++board[to];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}