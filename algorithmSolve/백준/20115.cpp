#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int N;
float drink[MAX];

void Solve()
{
    sort(drink, drink + N);
    float sum = drink[N - 1];
    for (int i = 0; i < N - 1; ++i)
        sum += drink[i] / 2;

    cout << sum << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> drink[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}