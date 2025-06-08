#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int answer = max(b - a - 1, c - b - 1);
    cout << answer << '\n';
    return 0;
}