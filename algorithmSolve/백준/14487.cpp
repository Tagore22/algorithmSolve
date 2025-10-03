#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, sum = 0, maxnum = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        sum += num;
        maxnum = max(maxnum, num);
    }
    cout << sum - maxnum << '\n';
    return 0;
}