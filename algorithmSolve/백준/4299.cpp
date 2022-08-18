#include <iostream>

using namespace std;

int plus_, minus_;

void MakeAnswer()
{
    if (minus_ > plus_)
    {
        cout << -1 << '\n';
        return;
    }
    int minteam = (plus_ - minus_) / 2;
    int maxteam = minteam + minus_;

    if (maxteam - minteam != minus_ || maxteam + minteam != plus_)
        cout << -1 << '\n';
    else
        cout << maxteam << ' ' << minteam << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> plus_ >> minus_;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}