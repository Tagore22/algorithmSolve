#include <iostream>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    long long answer = 0;
    for (int i = 1; i < L; ++i)
    {
        answer *= 10;
        ++answer;
    }
    answer *= 10;
    answer += N;
    cout << answer << '\n';
    return 0;
}