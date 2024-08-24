#include <iostream>

using namespace std;

int T;

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        int y = 0, k = 0, a, b;
        for (int i = 0; i < 9; ++i)
        {
            cin >> a >> b;
            y += a;
            k += b;
        }
        if (y > k)
            cout << "Yonsei" << '\n';
        else
            cout << "Korea" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}