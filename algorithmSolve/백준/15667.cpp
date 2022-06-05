#include <iostream>

using namespace std;

int main() // n = 1 + k + (k * k);
{
    int n;
    cin >> n;
    int answer = 0;
    for (int i = 0; i <= 10101; ++i)
        if (i * (i + 1) == n - 1)
        {
            answer = i;
            break;
        }
    cout << answer << '\n';
}