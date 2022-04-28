#include <iostream>

using namespace std;

const int divv = 1000000007;

long long calcul(long long a, int b)
{
    if (b == 1)
        return a % divv;
    if (b % 2 == 1)
        return ((a % divv) * calcul(a, b - 1)) % divv;
    else
    {
        long long half = calcul(a, b / 2);
        return (half * half) % divv;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;
    long long answerUp = 1;
    long long answerDown = 1;
    int t = b;
    for (int i = 0; i < t; ++i)
    {
        answerUp = (answerUp * a) % divv;
        --a;
        answerDown = (answerDown * b) % divv;
        --b;
    }
    answerDown = calcul(answerDown, divv - 2);
    cout << (answerUp * answerDown) % divv << '\n';
    return 0;
}