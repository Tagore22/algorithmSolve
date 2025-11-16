#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        cin >> str;
        int mul = 1, first = 0;
        for (int i = 2; i >= 0; --i)
        {
            first += mul * (str[i] - 'A');
            mul *= 26;
        }
        int second = stoi(str.substr(4));
        cout << (abs(first - second) <= 100 ? "nice" : "not nice") << '\n';
    }
    return 0;
}