#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 처음에 어떻게 푸는지 전혀 감이 안잡혀서 결국 힌트를 봤는데 X보다 앞 또는 뒤에 있는 사람의 수를 찾는
// 그래프 탐색 문제였다. 그 이후로는 간단했는데 주어진 A, B를 2개의 벡터를 이용해서 자신보다 빠른수, 늦은수를
// 각각 입력받아 두번의 BFS순회를 하면 된다. 이 과정에서 치명적인 실수를 하나 했는데 ㅎㅎ.... 후술한다.

// 자세한 설명은 주석으로 남긴다.

// 각각 자신보다 빠른수, 느린수.
vector<int> upper[100001], lower[100001];
queue<int> que;
bool visit[100001] = { false, };
int N, M, X;

// 최대 등수를 구하는 함수. 자신의 뒤에 있는 사람들의 수를 구한다.
void BFSUpper()
{
    que.push(X);
    for (int i = 1; i <= N; ++i)
        visit[i] = false;
    visit[X] = true;
    // 상술한 치명적인 실수가 이부분이다. 엄청 어이없었는데 기존 answer의 초기값은 5였다...
    // 예시에서 N이 5였는데 그렇기 때문에 그냥 생각없이 5로 두었다. ㅎㅎ;; 피곤한건지
    // 아니면 그렇게도 알고리즘이 풀기 싫은건지.. 어쨌든 가장 마지막 등수부터 하나하나 치고 올라간다.
    int answer = N;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& next : upper[here])
        {
            if (visit[next])
                continue;
            que.push(next);
            // 새로운 사람을 찾을때마다 등장 여부를 갱신하고 자신의 등수를 올린다.
            visit[next] = true;
            --answer;
        }
    }
    cout << answer << '\n';
}

// 최소 등수를 구하는 함수. 자신의 앞에 있는 사람들의 수를 구한다.
void BFSLower()
{
    que.push(X);
    visit[X] = true;
    // 1등부터 하나씩 내려간다.
    int answer = 1;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& next : lower[here])
        {
            if (visit[next])
                continue;
            que.push(next);
            // 새로운 사람을 찾을때마다 등장 여부를 갱신하고 자신의 등수를 내린다.
            visit[next] = true;
            ++answer;
        }
    }
    cout << answer << ' ';
}

void MakeAnswer()
{
    BFSLower();
    BFSUpper();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> X;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        upper[from].push_back(to);
        lower[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}