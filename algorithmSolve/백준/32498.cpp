#include <iostream>

using namespace std;

int main()
{
    int N, num, answer = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        answer = num % 2 == 1 ? answer + 1 : answer;
    }
    cout << answer << '\n';
    return 0;
}