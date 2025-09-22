#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        int cur = i;
        while (cur > 0)
        {
            int div = cur % 10;
            if (div == 3 || div == 6 || div == 9)
                ++answer;
            cur /= 10;
        }
    }
    cout << answer << '\n';
    return 0;
}