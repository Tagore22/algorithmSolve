#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 1. 100부터 1까지 역순으로 순회하며 양쪽에 등장하는 가장 큰 수를 찾아 벡터에 넣는다. 최초값은 0으로.
// 2. 존재하지 않는다면 수를 1 줄이고 위치값은 그대로인 상태로 반복한다.
// 3. 찾았다면 위치값을 갱신하고 같은 수를 다시 반복한다. 같은 수가 여러번 나올 수 있기 때문이다.
// 4. 1까지 모두 순회후 벡터의 사이즈와 원소들을 출력한다.

// 최악의 경우는 100 ~ 1을 순회로 100, 각 배열들을 순회할 때 결코 제자리 혹은 이전으로 되돌아가지
// 않기 때문에 N, M만큼을 순회하여 100 * (N + M)으로 O(20000)이 된다.

int N, M;
int boardA[100], boardB[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> boardA[i];
    cin >> M;
    for (int i = 0; i < M; ++i)
        cin >> boardB[i];

    vector<int> ans;
    int idxA = -1, idxB = -1, nowA, nowB;
    for (int i = 100; i > 0; --i)
    {
        nowA = nowB = -1;
        for (int j = idxA + 1; j < N; ++j)
        {
            if (boardA[j] == i)
            {
                nowA = j;
                break;
            }
        }
        for (int j = idxB + 1; j < M; ++j)
        {
            if (boardB[j] == i)
            {
                nowB = j;
                break;
            }
        }
        if (nowA != -1 && nowB != -1)
        {
            idxA = nowA;
            idxB = nowB;
            ++i;
            ans.push_back(boardA[idxA]);
        }
    }
    cout << ans.size() << '\n';
    for (const auto& cur : ans)
        cout << cur << ' ';
    cout << '\n';
    return 0;
}