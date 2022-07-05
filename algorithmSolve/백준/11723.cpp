#include <iostream>

using namespace std;

int M, mask;

void AddX(int x)
{
    if ((mask & (1 << (x - 1))) == 0)
        mask |= 1 << (x - 1);
}

void RemoveX(int x)
{
    if (mask & (1 << (x - 1)))
        mask &= ~(1 << (x - 1));
}

void CheckX(int x)
{
    if (mask & (1 << (x - 1)))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
}

void ToggleX(int x)
{
    mask ^= 1 << (x - 1);
}

void All()
{
    mask = (1 << 20) - 1;
}

void Empty()
{
    mask = 0;
}

void MakeAnswer()
{
    mask = 0;
    for (int i = 0; i < M; ++i)
    {
        string str;
        int x;
        cin >> str;
        if (str == "add")
        {
            cin >> x;
            AddX(x);
        }
        else if (str == "remove")
        {
            cin >> x;
            RemoveX(x);
        }
        else if (str == "check")
        {
            cin >> x;
            CheckX(x);
        }
        else if (str == "toggle")
        {
            cin >> x;
            ToggleX(x);
        }
        else if (str == "all")
            All();
        else
            Empty();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}