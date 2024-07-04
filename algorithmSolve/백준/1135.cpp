#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 문제를 완전히 잘못 이해하고 있었다. 정확하게는 풀이 방법을 말이다. 처음에는 자식이 많은 노드쪽으로 이동하며
// 연락을 취하면 된다고 생각했다. 거의 2 ~ 3시간동안... 그런데 그리디를 이용하여 풀어야했다. 리프 노드는 애시당초
// 연락할 자식 노드가 없으므로 무조건 1의 시간을 필요로 한다. 그 이후로 부모 노드쪽으로 올라가며 값을 구하면 되는데
// 재귀로 얻은 자식의 값이 바로 연락값이 되는 것이 아니다. 가장 많은 시간을 필요로 하는 자식에게 먼저 연락을 취해야 하므로
// 자식값 + 자식값의 순위가 진짜 연락값이 된다. 이걸을 재귀호출하여 DFS(0)을 구하되, DFS()에는 자기 자신이 연락을 받는 1값이
// 추가되어 있으므로 마지막에 1을 제외하여 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board[50];
int N;

// num번째 노드에서 필요로 하는 최소한의 시간을 구하는 함수.
int DFS(int num)
{
    int ans = 0;

    vector<int> cur;
    // 자식 노드들을 모두 순회하며 다시 각 자식 별 필요로 하는 최소한의 시간값을 구하여
    // 벡터에 넣는다.
    for (auto& a : board[num])
        cur.push_back(DFS(a));

    // 벡터를 내림차순으로 정렬한다.
    sort(cur.begin(), cur.end(), greater<>());
    // 상술하였듯 가장 많은 시간을 필요로 하는 자식 먼저 연락을 해야 현재 노드에서의 최소값을 구할수 있다.
    // 따라서 자식값 + 연락을 주는 순서중에서 가장 최대걊을 구한다. 어째서 최대값을 구해야 하느냐는 간단한다.
    // 다른 자식들이 필요로 하는 시간을 모두 만족해야 하기 때문이다.
    for (int i = 0; i < cur.size(); ++i)
        ans = max(ans, cur[i] + i);
    // 현재 노드 역시 연락을 받아야 하므로 1을 더해 반환한다.
    return ans + 1;
}

void MakeAnswer()
{
    // 상술하였듯 DFS(0)은 0번째 인덱스가 연락을 받는것까지 구해진 값이다. 0번째 인덱스는 실제로
    // 연락을 주기만 하므로 1을 빼야 진짜 답이 된다.
    cout << DFS(0) - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        if (num != -1)
            board[num].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}