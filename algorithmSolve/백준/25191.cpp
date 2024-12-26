#include <iostream>

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int answer = A / 2 + B;
    answer = min(N, answer);
    cout << answer << '\n';
    return 0;
}