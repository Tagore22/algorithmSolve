#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        cin >> num;
        int last = num;
        int sum = (1 + last) * (num / 2);
        sum = num % 2 != 0 ? sum + (1 + num) / 2 : sum;
        cout << sum << ' ';

        last = (num - 1) * 2 + 1;
        sum = (1 + last) * (num / 2);
        sum = num & 2 != 0 ? sum + (1 + last) / 2 : sum;
        cout << sum << ' ';

        last = num * 2;
        sum = (2 + last) * (num / 2);
        sum = num % 2 != 0 ? sum + (2 + last) / 2 : sum;
        cout << sum << '\n';
    }
    return 0;
}