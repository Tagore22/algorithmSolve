#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 정답율이 증명하듯 복잡한 문제였다. 푸는 방식이 복잡하기 보단
// 자료구조에 대해 조금 생각해야하는 문제였다. 풀이 자체는 그리 어렵지 않다.
// 다만 2가지 실수를 했는데 다음과 같다.

// 1. 상술하였듯 자료를 저장하는 방식.
// 2. 중복 방문에 대한 실수.

// 첫번째가 메모리 초과로 이어지는 실수인데 문제에서 주어지듯 하나의 튜브에 묶인
// 역들은 서로 이동이 가능하다. 나는 이것을 이용해서 2차원 배열을 만들어 각 역끼리
// 이동이 가능함을 저장했었는데 이러면 최대 10만 * 10만으로 인해 100억개의 변수가 필요하고
// 메모리를 초과하게 된다. 이것은 station과 tube로 나누어 각 역에서 몇번 튜브와 연결이 되었는지,
// 몇번 튜브에 포함된 역들은 무엇인지로 나누어 저장할수 있었다.

// 두번째는 시간초과로 이어지는 실수인데 최소값으로 인해 BFS순회를 돌아야하는데 이때 이미 방문한
// 역은 당연히 체크를 했으나 이미 방문한 하이퍼튜브를 생각하지 못했다. 역의 중복 방문 방지와 똑같은
// 개념으로 어떤 튜브에서 마지막 N번역까지 이동이 가능했다면 진작에 큐의 순회가 끝났을텐데 그러지 못하고
// 다시 이전에 방문했던 튜브로 방문하는건 의미없는 일이기 때문이다.

// 이 2가지를 주의하면 된다. 꽤나 신선했던 문제다.

// 자세한 설명은 주석으로 남긴다.

// 위 상술하였듯 각 역들의 이동 여부를 tube와 station으로 나누어 저장한다.
vector<vector<int>> tube, station;
int N, K, M;

void BFS()
{
    // 각 역과 튜브의 방문 여부를 초기화한다.
    vector<bool> visit_s(N + 1, false);
    visit_s[1] = true;
    vector<bool> visit_t(M, false);
    // 현재 위치해있는 역과 그 역까지의 이동수.
    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));

    while (!que.empty())
    {
        int here = que.front().first;
        int cost = que.front().second;
        que.pop();

        // 현재 N번째 역에 도착했다면 이동수를 출력하고 탈출한다.
        if (here == N)
        {
            cout << cost << '\n';
            return;
        }

        // 현재 역에서 이용할수 있는 모든 튜브를 순회한다.
        for (auto t : station[here])
        {
            // 이미 방문한적 있는 튜브라면 무시한다.
            if (!visit_t[t])
            {
                visit_t[t] = true;
                // 튜브에 묶여 있는 역들을 순회한다. 어차피 방문여부로 한번 걸러지기 때문에
                // here -> here은 처리할 필요가 없다.
                for (auto there : tube[t])
                {
                    // 아직 방문하지 않은 역들만 순회한다.
                    if (!visit_s[there])
                    {
                        // 현재 역의 방문 여부를 갱신하고 큐에 집어넣는다.
                        visit_s[there] = true;
                        que.push(make_pair(there, cost + 1));
                    }
                }
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> M;
    tube.resize(M);
    station.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int num;
        for (int j = 0; j < K; ++j)
        {
            cin >> num;
            tube[i].push_back(num);
            station[num].push_back(i);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}