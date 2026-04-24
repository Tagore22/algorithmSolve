#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0, answer = 0;;
    for (int i = 1; i <= n; ++i)
    {
        sum += i;
        answer += sum;
    }
    cout << answer << '\n';
    return 0;
}