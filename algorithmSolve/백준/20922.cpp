#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 풀이.
// 범위값을 이용한 투포인터 문제였다.
// 처음엔 한참을 헤맸기에 거의 몇시간동안 풀었다. 실버 문제인데 후..
// 문제풀이의 큰 틀은 다음과 같다.

// 1. 0 ~ N - 1까지 순회한다.
// 2. 현재 등장한 수가 등장함을 visit 배열을 이용해 갱신한다. 또한 현재값을 que에 집어넣는다.
// 3. 만약 K보다 더 많이 등장하였다면 현재 수를 제외한 값들의 개수를 최종값 answer와 비교한다.
// 4. que를 순회하며 하나씩 수를 빼내며 등장횟수를 줄여준다. 이번에 빼낸수가 K보다 더 많이 등장한 수라면 탈출한다.
// 5. N - 1까지 반복하며 최대값 answer를 출력한다.

// 문제를 너무 어렵게 생각했던것 같다. 애시당초 너무 깊이 파고드니 여기저기 꼬여서 화만 났던듯.

// 자세한 설명은 주석으로 남긴다.

queue<int> que;
int board[200000];
int visit[100001];
int N, K;

// erase가 K번보다 더 많이 등장하였을때 que를 갱신하는 함수.
void RenewQueue(int erase)
{
    // que의 맨 앞부터 하나씩 수를 줄여가되
    // 이번에 제거한 수가 erase라면 탈출한다.
    while (true)
    {
        int here = que.front();
        que.pop();
        --visit[here];
        if (here == erase)
            break;
    }
}

void MakeAnswer()
{
    memset(visit, 0, sizeof(visit));
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // 0 ~ N - 1까지 순회하며 현재수를 que에 집어넣고
        // 등장횟수를 갱신해 나간다.
        int here = board[i];
        que.push(here);
        ++visit[here];
        // 현재수 here가 K보다 더 많이 등장하였다면 여태까지의 개수를 최종값 answer와 비교하고
        // que를 최초 here가 등장할때까지 갱신시킨다.
        if (visit[here] > K)
        {
            int compose = que.size() - 1;
            answer = max(answer, compose);
            RenewQueue(here);
        }
    }
    int compose = que.size();
    answer = max(answer, compose);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}