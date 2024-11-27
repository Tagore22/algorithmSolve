#include <iostream>

using namespace std;

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int answer = 0;
        for (int i = n; i >= 1; --i)
            answer += i;
        cout << answer << '\n';
    }
    return 0;
}