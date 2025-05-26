#include <iostream>
#include <algorithm>

using namespace std;

int N;
const int MAX = 100000;
int tree[MAX];

void Solve()
{
    sort(tree, tree + N, greater<>());
    long long answer = 1;
    int cur = 0;
    for (int i = 0; i < N; ++i)
    {
        ++answer;
        --cur;
        cur = max(cur, tree[i]);
    }
    answer += cur;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> tree[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}