#include <iostream>

using namespace std;

int N, r, e, c;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        cin >> r >> e >> c;
        if (r < e - c)
            cout << "advertise" << '\n';
        else if (r == e - c)
            cout << "does not matter" << '\n';
        else
            cout << "do not advertise" << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}