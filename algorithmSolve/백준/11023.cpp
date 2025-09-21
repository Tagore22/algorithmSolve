#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int answer = 0, num;
    while (cin >> num)
    {
        answer += num;
    }
    cout << answer << '\n';
    return 0;
}