#include <iostream>

using namespace std;

//풀이
//1월 1일로부터 몇일이나 지났는지를 모두 더한후 7일로 나누어 월요일부터 지난 일수만큼 넘기면 된다.

int month[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
string days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int x, y;

void MakeAnswer()
{
    int check = 0;
    for (int i = 1; i < x; ++i)
        check += month[i];
    check += y - 1;
    check %= 7;
    cout << days[check] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}