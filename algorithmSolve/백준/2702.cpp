#include <iostream>

using namespace std;

int T, A, B;

int GCD(int l, int r)
{
    if (r == 0)
        return l;
    return GCD(r, l % r);
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> A >> B;
        int g = GCD(A, B);
        cout << A * B / g << ' ' << g << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}