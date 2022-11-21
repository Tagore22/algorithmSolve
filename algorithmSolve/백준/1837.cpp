#include <iostream>
#include <cstring>
#include <cmath>

//2061번과 풀이가 동일하다. 참고할것

using namespace std;

bool primes[1000000];
string P;
int K;

void CalEratos()
{
    int idx = sqrt(K - 1);
    primes[0] = primes[1] = false;

    for (int i = 2; i <= idx; ++i)
        if (primes[i])
            for (int j = i * i; j < K; j += i)
                primes[j] = false;
}

void MakeAnswer()
{
    for (int i = 2; i < K; ++i)
    {
        if (!primes[i])
            continue;

        int check = 0, mul = 1;
        for (int j = P.size() - 1; j >= 0; --j)
        {
            check = (check + (P[j] - '0') * mul) % i;
            mul *= 10;
            mul %= i;
        }

        if (check == 0)
        {
            cout << "BAD" << ' ' << i << '\n';
            return;
        }
    }
    cout << "GOOD" << '\n';
}

void Input()
{
    memset(primes, true, sizeof(primes));
    cin >> P >> K;
}

int main()
{
    Input();
    CalEratos();
    MakeAnswer();
    return 0;
}