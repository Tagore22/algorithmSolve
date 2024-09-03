#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 그래도 침착하게 생각했는지 금방 풀었다. 다만 한가지 어이없는 실수로 11분을 날렸다.
// 처음에는 그래프를 사용하지 않고 단순 사칙연산으로 풀수 없을까 생각했으나 겹치는 부분이 존재했기에
// 불가능했다. 따라서 각각 가벼운 배열과 무거운 배열을 준비하여 DFS()를 통해 현재 구슬보다 가벼운 것들,
// 무거운 것들을 따로 계산하여 그것이 N / 2 + 1개보다 크거나 같다면 그 구슬은 절대로 무게가 중간이 될수
// 없는 것을 계산했다. 힌트에는 플로이드 와샬도 있었다.

// 자세한 설명은 주석으로 남긴다.

vector<int> l[100], h[100];
bool visit[100];
int N, M, num;

// 더 가벼운 쪽으로만 이동하는 DFS 함수.
void CalLow(int idx)
{
    // 현재 위치로 도달했기에 num값을 증가시키고 방문여부를 갱신한다.
    ++num;
    visit[idx] = true;

    // 더 가벼운 배열들안의 원소들로 이동한다. 다만 이미 방문한곳은 무시한다.
    for (auto& a : l[idx])
    {
        if (!visit[a])
            CalLow(a);
    }
}

// 더 무거운 쪽으로만 이동하는 DFS 함수.
void CalHeavy(int idx)
{
    // 현재 위치로 도달했기에 num값을 증가시키고 방문여부를 갱신한다.
    ++num;
    visit[idx] = true;

    // 더 무거운 배열들안의 원소들로 이동한다. 다만 이미 방문한곳은 무시한다.
    for (auto& a : h[idx])
    {
        if (!visit[a])
            // 상술한 실수가 여기다. 복붙을 하다가 CalHeavy가 아닌 CalLow()를 복사했다;
            CalHeavy(a);
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        // 모든 방문 여부를 갱신한다.
        for (int j = 1; j <= N; ++j)
            visit[j] = false;
        // 시작 지점에서도 num이 증가하기 때문에 초기화값은 0이 아닌 -1이여야한다.
        num = -1;
        // DFS순회를 한다.
        CalLow(i);
        // 도달할수 있는 정점의 수가 N / 2 + 1개보다 많다면 무게가 중심이 될수없다.
        if (num >= N / 2 + 1)
            ++answer;
        // 무거운쪽도 행한다.
        for (int j = 1; j <= N; ++j)
            visit[j] = false;
        num = -1;
        CalHeavy(i);
        if (num >= N / 2 + 1)
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        l[a].push_back(b);
        h[b].push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}