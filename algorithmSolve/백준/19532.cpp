#include <iostream>

using namespace std;

// 풀이.
// x와 y의 연립방정식을 푸는 문제이다. 아래처럼 모두 대입해도 되고,
// x와 y에 대한 연립방정식으로 치환하여 풀어도 된다.

int a, b, c, d, e, f;

void MakeAnswer()
{
    for (int x = -999; x <= 999; ++x)
        for (int y = -999; y <= 999; ++y)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}