#include <iostream>

using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        int from = 1, to = 50, mid = -1;
        while (true)
        {
            mid = (from + to) / 2;
            cout << mid << ' ';
            if (mid > N)
                to = mid - 1;
            else if (mid < N)
                from = mid + 1;
            else
                break;
        }
        cout << '\n';
    }
    return 0;
}