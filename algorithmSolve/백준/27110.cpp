#include <iostream>

using namespace std;

int main()
{
    int N, answer = 0;
    cin >> N;
    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        answer += min(num, N);
    }
    cout << answer << '\n';
    return 0;
}