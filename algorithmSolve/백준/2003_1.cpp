#include <iostream>
#include <queue>

using namespace std;

// 2003의 더 빠른풀이.
// 이중 for문이 아닌 하나의 for문만을 이용하여 푼 풀이다.
// 원리는 투포인터와 비슷한데, 0번째 원소부터 쭉 더하다가 그 합이 M이거나 더 커진다면
// 더작아질때까지 맨 앞원소부터 삭제한다. 그 와중에 합이 M이면 최종값 answer를 1 더해주고
// 다시 N번째 원소까지 순회를 반복한다. 사용하는 메모리는 조금더 늘었는데 일반 배열이 아닌
// deque를 사용해서 그런것 같다.

// 자세한 설명은 주석으로 남긴다.

deque<int> deq;
int N, M;

void MakeAnswer()
{
    int answer = 0;
    int ans = 0;
    int cur;
    // 0번째부터 N - 1번째 원소까지 순회를 한다.
    for (int i = 0; i < N; ++i)
    {
        // 현재 값을 입력받아 원소들의 합 ans에 더한후 deq에 추가한다.
        cin >> cur;
        ans += cur;
        deq.push_back(cur);
        // 합 ans가 M보다 작아질때까지 가장 처음에 추가한 원소를 삭제해나간다.
        while (ans >= M)
        {
            // 그 와중에 ans가 M이 된다면 최종값 answer를 1 추가한다.
            answer = ans == M ? answer + 1 : answer;
            int erase = deq.front();
            ans -= erase;
            deq.pop_front();
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}