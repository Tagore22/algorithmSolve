#include <iostream>

using namespace std;

int main()
{
    int e, f, c;
    cin >> e >> f >> c;

    e += f;
    int answer = 0;
    while (e >= c)
    {
        answer += e / c;
        e = e / c + e % c;
    }

    cout << answer << '\n';
    return 0;
}