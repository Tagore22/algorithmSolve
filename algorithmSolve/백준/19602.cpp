#include <iostream>

using namespace std;

int main()
{
    int S, M, L;
    cin >> S >> M >> L;
    int answer = S * 1 + M * 2 + 3 * L;
    cout << (answer >= 10 ? "happy" : "sad") << '\n';
    return 0;
}