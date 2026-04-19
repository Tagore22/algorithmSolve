#include <iostream>

using namespace std;

const int DIVNUM = 7 * 24 * 60 * 60;

int main()
{
    int N;
    cin >> N;

    long long sum = 1;
    for (int i = 2; i <= N; ++i)
        sum *= i;
    cout << sum / DIVNUM << '\n';
    return 0;
}