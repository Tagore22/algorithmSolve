#include <iostream>

using namespace std;

int N;
int jump[200000], answer[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> jump[i];
    for (int i = N - 1; i >= 0; --i)
    {
        int next = i + 1 + jump[i];
        answer[i] = next >= N ? 1 : answer[next] + 1;
    }
    for (int i = 0; i < N; ++i)
        cout << answer[i] << ' ';
    cout << '\n';
    return 0;
}