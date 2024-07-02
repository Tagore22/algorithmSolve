#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 매번 두개의 파일을 합쳐서 결과적으로 하나의 파일을 만드는 문제인데 합칠때마다 두 파일의 크기만큼의 비용이 든다.
// 따라서 가장 작은 2개의 파일을 매번 합쳐서 그 비용을 최소화해야한다. 결과적으로 우선순위 큐를 이용하여
// 가장 작은 2개를 찾아내야했다. 다만 매번 정렬을 하다보니 시간이 엄청나게 잡아먹었다. 또한, 최초로 주어지는 비용이
// 최대 10000이기 때문에 합치다보면 int값을 벗어날수가 있어 long long 타입으로 구현해야 한다.

// 자세한 설명은 주석으로 남긴다.

priority_queue<long long, vector<long long>, greater<>> que;
int T, K;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 우선순위 큐에는 clear()가 없다.
        // 따라서 큐가 텅 빌때까지 일일히 pop()을 호출해야 한다.
        while (!que.empty())
            que.pop();
        cin >> K;
        int num;
        for (int i = 0; i < K; ++i)
        {
            cin >> num;
            // 모든 파일들을 큐에 넣으며 정렬한다.
            que.push(num);
        }
        long long answer = 0;
        // 큐에 최종적으로 합쳐진 파일 하나만 남을때까지 반복한다.
        while (que.size() > 1)
        {
            // 가장 작은 2개를 찾아내어 더하고 다시 그 값을 큐에 넣는다.
            // 또한, 최종닶 answer에도 더해준다.
            long long first = que.top();
            que.pop();
            long long second = que.top();
            que.pop();
            answer += first + second;
            que.push(first + second);
        }
        // 최종답 출력.
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}