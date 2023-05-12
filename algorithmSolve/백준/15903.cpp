#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 문제의 큰틀은 다음과 같다.

// 1. 어떤 카드 2장을 골라 그 카드의 수들을 더한다.
// 2. 더한 값이 그 카드 2장의 새로운 값이 된다.
// 3. 이것을 M번 반복한후 모든 카드들의 수를 더했을때 최소값을 출력한다.

// 그리디적으로 매번 2장의 카드를 고를때 그 수가 가장 작은 수를 골라 더하면 된다.
// 처음에는 매번 정렬하여 더하였으나 너무 오래걸렸다.
// 우선순위큐나 set, map들을 사용해도 되나 굳이 연관 컨테이너를 사용할 필요가 없었으므로
// 우선순위큐를 사용하여 구현하였다. 또한, 카드의 수가 최대 100만이기에 여러번 더할시
// int값을 벗어날수가 있어 long long타입의 변수를 사용해야 했다.

// 자세한 설명은 주석으로 남긴다.

priority_queue<long long> que;
int N, M;

void MakeAnswer()
{
    long long first, second, sum;
    // 앞에서 2개(가장 작은 2개)를 꺼내어 더한후 다시 2번 큐에 삽입한다.
    // 이것을 M번 반복한다.
    for (int i = 0; i < M; ++i)
    {
        first = -que.top();
        que.pop();
        second = -que.top();
        que.pop();
        sum = first + second;
        que.push(-sum);
        que.push(-sum);
    }

    // 모든 값들을 더해 출력한다.
    long long answer = 0;
    while (!que.empty())
    {
        answer += -que.top();
        que.pop();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        que.push(-num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}