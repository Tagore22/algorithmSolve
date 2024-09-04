#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    for (int i = 0; i < 6; ++i)
    {
        int cur;
        cin >> cur;
        answer += cur * 5;
    }
    cout << answer << '\n';
    return 0;
}