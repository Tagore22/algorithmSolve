#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
long long sum[300000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    long long cur = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        cur += num;
        sum[i] = cur;
    }
    sort(sum, sum + N, greater<>());
    long long answer = 0;
    for (int i = 0; i < K; ++i)
        answer += sum[i];
    cout << answer << '\n';
    return 0;
}