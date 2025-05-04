#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    int answer = min(A / 2, B);
    cout << answer << '\n';
    return 0;
}