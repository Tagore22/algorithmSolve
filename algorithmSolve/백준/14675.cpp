#include <iostream>

using namespace std;

// 풀이.
// 처음에는 bool 배열 2개로 각각 부모와 자식 정점들을 파악하여
// 부모 정점이 없거나 자식 정점이 없는 정점은 단절점이 아닌 것으로
// 구현을 하였었다. 하지만 많은 반례가 있었고, 진짜 정답은 연결된 
// 정점의 수를 파악하는 것인데 그 수가 1보다 작거나 같다면 무조건 끝자락에
// 존재하는 정점이기에 단절점이 될 수 없다. 단절선의 같은 경우는 주어지는
// 것이 트리이기 때문에 모든 간선이 단절선이 된다.

int N, Q;
int connect[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int p, c;
        cin >> p >> c;
        ++connect[p];
        ++connect[c];
    }
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int T, K;
        cin >> T >> K;
        if (T == 1)
            cout << (connect[K] <= 1 ? "no" : "yes") << '\n';
        else
            cout << "yes" << '\n';
    }
    return 0;
}