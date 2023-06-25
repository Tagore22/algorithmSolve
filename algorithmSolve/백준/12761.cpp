#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 어렵지 않은 문제라 빨리 풀었음에도 이상한곳 한군데에서 시간을 잡아먹은 문제이다.
// 일단 이 문제의 큰 틀을 보면 다음과 같다.

// 1. 콩콩이 A, B와 현재 위치 N, 도착 지점 M이 주어진다.
// 2. N에서 시작하여 이동할수 있는 방법 8가지를 모두 실행한다.
// 3. 도달한곳이 0보다 같거나 크고 10만보다 작거나 같아야하며, 중복 연산을 막기 위해 아직 방문하지 않은 곳이여야한다.
// 4. 현재 도달한곳이 도착 지점 M이라면 움직인 수만큼 출력한다.

// 내가 한가지 놓친 부분은 움직인 위치가 10만 이상일 경우였다. 후술할 조건문에서 잘못처리되서 visit 배열에서의 처리가 
// 오류가 나게 되어 제대로 된 답이 나오질 않았다.

// 자세한 설명은 주석으로 남긴다.

queue<int> que;
const int MAX_NUM = 100000;
bool visit[MAX_NUM + 1];
int A, B, N, M;

// 현재 위치에 대한 조건을 판별하는 함수.
// 상술하였듯 조건은 3가지이다.

// 1. 아직 방문하지 않은것이여야 한다.
// 2. 0보다 크거나 같아야 한다.
// 3. 10만보다 작거나 같아야 한다.
void Check(int now)
{
    // 상술한 조건을 만족할시 que에 집어넣는다(그곳으로 이동한다).
    // 바로 이 조건문에서 실수가 있었는데, 주석처리된 곳이 기존 조건문이었다. 언뜻 보면 별차이 없어보이나
    // now가 10만 이상인 수일때 첫번째 조건문에서 에러나게 되어 올바른 답을 출력할수 없었다.
    // if (!visit[now] && now >= 0 && now <= MAX_NUM)
    if (now >= 0 && now <= MAX_NUM && !visit[now])
    {
        visit[now] = true;
        que.push(now);
    }
}

// 8가지 이동을 구현하는 함수.
void Move(int here)
{
    // + 1.
    int now = here + 1;
    Check(now);

    // - 1.
    now = here - 1;
    Check(now);

    // A 콩콩이로 우측.
    now = here + A;
    Check(now);

    // A 콩콩이로 좌측.
    now = here - A;
    Check(now);

    // B 콩콩이로 우측.
    now = here + B;
    Check(now);

    // B 콩콩이로 우측.
    now = here - B;
    Check(now);

    // A 콩콩이로 힘껏.
    now = here * A;
    Check(now);

    // B 콩콩이로 힘껏.
    now = here * B;
    Check(now);
}

// BFS구현 함수. que의 용량을 줄이기 위해 현재 que에 들어가 있는 원소만큼만 반복문을 순회하는 방식으로 구현하였는데
// 굳이 이렇게 하지 않고, que를 pair<int, int> 형식으로 하여도 상관은 없다.
int BFS()
{
    que.push(N);
    visit[N] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            if (here == M)
                return answer;

            // 여기서 8가지 방법을 모두 해보고 que에 넣는다.
            Move(here);
        }
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));

    // 여기서 BFS.
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}