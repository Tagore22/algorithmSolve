#include <iostream>
#include <vector>

using namespace std;

int T;
vector<int> primes;

void GetPrimes()
{
    vector<bool> IsPrimes(1000001, true);
    IsPrimes[0] = IsPrimes[1] = false;

    for (int i = 2; i <= 1000; ++i)
        if (IsPrimes[i])
            for (int j = i * i; j <= 1000000; j += i)
                IsPrimes[j] = false;

    for (int i = 2; i <= 1000000; ++i)
        if (IsPrimes[i])
            primes.push_back(i);
}

void MakeAnswer()
{
    GetPrimes();
    for (int iter = 0; iter < T; ++iter)
    {
        int num;
        cin >> num;
        int now = num;
        for (auto& n : primes)
        {
            if (now == 1)
                break;
            int ans = 0;
            while (now % n == 0)
            {
                now /= n;
                ++ans;
            }
            if (ans != 0)
                cout << n << ' ' << ans << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}