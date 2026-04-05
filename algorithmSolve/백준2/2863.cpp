#include <iostream>

using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    pair<double, int> answer = { -1, -1 };
    for (int i = 0; i < 4; ++i)
    {
        double cur = a / c + b / d;
        if (answer.first < cur)
            answer = { cur, i };

        double temp1 = a;
        a = c;
        double temp2 = b;
        b = temp1;
        temp1 = d;
        d = temp2;
        c = temp1;
    }
    cout << answer.second << '\n';
    return 0;
}