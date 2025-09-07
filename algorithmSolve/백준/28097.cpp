#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int sum = -8;
    for (int iter = 0; iter < N; ++iter)
    {
        sum += 8;
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum / 24 << ' ' << sum % 24 << '\n';
    return 0;
}