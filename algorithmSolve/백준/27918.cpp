#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int D = 0, P = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        char num;
        cin >> num;
        if (num == 'D')
            ++D;
        else
            ++P;
        if (D > P + 1 || P > D + 1)
        {
            cout << D << ':' << P << '\n';
            return 0;
        }
    }
    cout << D << ':' << P << '\n';
    return 0;
}