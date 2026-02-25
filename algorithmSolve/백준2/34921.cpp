#include <iostream>

using namespace std;

int main()
{
    int A, T;
    cin >> A >> T;

    int answer = 10 + 2 * (25 - A + T);
    answer = max(answer, 0);
    cout << answer << '\n';
    return 0;
}