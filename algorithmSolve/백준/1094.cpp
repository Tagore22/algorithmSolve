#include <iostream>

using namespace std;

void Calcul(int x)
{
    const int start = 64;
    int now = start;
    int answer = 0;
    while (x != 0)
    {
        if (now <= x)
        {
            x -= now;
            ++answer;
        }
        else
            now /= 2;
    }
    cout << answer << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    Calcul(x);
    return 0;
}