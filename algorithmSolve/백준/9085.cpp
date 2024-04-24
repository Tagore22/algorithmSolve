#include <iostream>

using namespace std;

int main()
{
    int T, N, num;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N;
        int answer = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            answer += num;
        }
        cout << answer << '\n';
    }
    return 0;
}