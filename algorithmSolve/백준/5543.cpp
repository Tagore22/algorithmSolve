#include <iostream>
#include <algorithm>

//최대값, 최소값 구현 문제

using namespace std;

int burger[3];
int drink[2];

void MakeAnswer()
{
    int cheap_burger = min({ burger[0], burger[1], burger[2] });
    int cheap_drink = min(drink[0], drink[1]);

    cout << cheap_burger + cheap_drink - 50 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 3; ++i)
        cin >> burger[i];

    for (int i = 0; i < 2; ++i)
        cin >> drink[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}