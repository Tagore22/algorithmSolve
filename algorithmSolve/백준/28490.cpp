#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int first, second;
        cin >> first >> second;
        answer = max(answer, first * second);
    }
    cout << answer << '\n';
    return 0;
}