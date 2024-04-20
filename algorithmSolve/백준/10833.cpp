#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, S, A, answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> S >> A;
        answer += A % S;
    }
    cout << answer << '\n';
    return 0;
}