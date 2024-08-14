#include <iostream>

using namespace std;

int main()
{
    int N, cur = 0, answer = 0;
    cin >> N;
    while (N > 0)
    {
        ++cur;
        if (N < cur)
            cur = 1;

        N -= cur;
        ++answer;
    }
    cout << answer << '\n';
    return 0;
}