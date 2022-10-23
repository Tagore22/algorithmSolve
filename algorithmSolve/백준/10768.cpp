#include <iostream>

using namespace std;

int m, d;

void MakeAnswer()
{
    if (m > 2)
    {
        cout << "After" << '\n';
        return;
    }
    else if (m < 2)
    {
        cout << "Before" << '\n';
        return;
    }
    else
    {
        if (d > 18)
        {
            cout << "After" << '\n';
            return;
        }
        else if (d < 18)
        {
            cout << "Before" << '\n';
            return;
        }
        else
        {
            cout << "Special" << '\n';
            return;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> d;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}