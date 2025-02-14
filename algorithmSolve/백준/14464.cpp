#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 풀이.
// 난이도도 꽤 있고 정답율도 낮은대로 어려운 문제였다. 정렬과 우선순위 큐를 이용한 문제였으나
// 그 정렬 방식이 잘 생각나지 않았다. 구글링을 했는데 그냥 N * C번만큼 순회하며 찾는 것이었다.
// 처음에는 연산량이 4억을 넘어가기에 긴가민가 했으나 if문에 의한 가지치기가 있고,
// 그 연산이 복잡하지 않기에 가능한듯 싶다. 또한, 우선순위큐와 정렬후 큐에 넣는 두 방법에서
// 연산량이 크게 차이나는데 우선순위큐는 따로 저장없이 바로 큐에 넣어도 되지만, 후자는
// 정렬을 하기 위해 따로 저장을 해둔후에 다시 순회하며 큐에 넣기에 훨씬 느렸다.

// 또한, 정렬 방식은 범위가 작은것부터 채워나가야 하는데 가장 작은수로 범위가 작은 수부터
// 탐색을 해야 최대한 많은 소를 고를수 있다.

// 자세한 설명은 주석으로 남긴다.

// 우선순위 큐의 사용자 정의 정렬 함수.
struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

int C, N;
int chi[20000];
bool visit[20000] = { false, };
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;

void MakeAnswer()
{
    sort(chi, chi + C);
    int answer = 0;
    while (!que.empty())
    {
        int from = que.top().first, to = que.top().second;
        que.pop();
        // 모든 닭들을 순회하며 조건에 맞는 크기가 가장 작은 첫번째 닭을 고른다.
        for (int i = 0; i < C; ++i)
        {
            if (from <= chi[i] && chi[i] <= to && !visit[i])
            {
                ++answer;
                visit[i] = true;
                break;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> C >> N;
    for (int i = 0; i < C; ++i)
        cin >> chi[i];
    for (int i = 0; i < N; ++i)
    {
        int num1, num2;
        cin >> num1 >> num2;
        que.push(make_pair(num1, num2));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}