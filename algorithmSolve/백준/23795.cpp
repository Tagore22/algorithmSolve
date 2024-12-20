#include <iostream>

using namespace std;

int main()
{
    int n, answer = 0;
    while (true)
    {
        cin >> n;
        if (n == -1)
        {
            cout << answer << '\n';
            break;
        }
        answer += n;
    }
    return 0;
}