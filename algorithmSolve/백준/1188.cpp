#include <iostream>

using namespace std;

int N, M;

int gcd(int p, int q)
{
    if (q == 0)
        return p;
    return gcd(q, p % q);
}

void MakeAnswer()
{
    cout << M - gcd(N, M) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}