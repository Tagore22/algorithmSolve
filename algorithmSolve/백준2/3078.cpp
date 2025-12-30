#include <iostream>

using namespace std;

// 풀이.
// 알고리즘 분류에는 자료 구조, 집합과 맵, 슬라이딩 윈도우, 큐라고
// 나와있으나 나는 누적합 비스므리한 방식으로 풀었다. N번째에서
// 오른쪽으로 K만큼 확인하면 N + 1번째에서 왼쪽으로는 확인하지 않아도
// 되는걸 이용한건데 말 그대로 처음에 K + 1명의 이름을 넣어놓고
// 그 이후 가장 좌측을 제외하고 우측을 추가하는 방식이다. 다만
// 1가지 실수를 하여 몇분 헤맸는데 문제에서 주어지는 최악의 경우는
// n(n + 1)/2로 답의 최대치 역시 n(n + 1)/2이다. n의 최대값이
// 30만이니 당연히 최대값은 int을 넘어가는데 이걸 넘겼다.

// 자세한 설명은 주석으로 남긴다.

int N, K;
int cur[21];
string board[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    // 최초에 K + 1개를 넣어놓는다.
    for (int i = 0; i <= K; ++i)
    {
        int idx = board[i].size();
        ++cur[idx];
    }
    // 상술한듯 정답의 최대값은 int값을 벗어나기에 long long을 써야한다.
    long long answer = 0;
    for (int i = 0; i < N; ++i)
    {
        // i번째 사람의 이름수와 같은 사람의 수에서 자신의 이름을 제외한 값이
        // i번째 사람의 좋은 친구의 수다.
        int idx = board[i].size();
        answer += cur[idx] - 1;
        --cur[idx];
        // 현재 범위가 끝까지 도달하지 못해 추가해야할 부분이 남아있다면
        // 추가해준다.
        if (i < N - K - 1)
        {
            idx = board[i + K + 1].size();
            ++cur[idx];
        }
    }
    cout << answer << '\n';
    return 0;
}