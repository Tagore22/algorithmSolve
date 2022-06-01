#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int n;

void Calcul(int num, int a, int b, int c)
{
    if (num == 1)
        cout << a << ' ' << c << '\n';
    else
    {
        Calcul(num - 1, a, c, b);
        cout << a << ' ' << c << '\n';
        Calcul(num - 1, b, a, c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    string answer = to_string(pow(2, n));
    int idx = answer.find('.');
    answer = answer.substr(0, idx);
    answer[answer.size() - 1] -= 1;
    cout << answer << '\n';
    if (n <= 20)
        Calcul(n, 1, 2, 3);
    return 0;
}