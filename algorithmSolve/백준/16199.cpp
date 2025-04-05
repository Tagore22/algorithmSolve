#include <iostream>

using namespace std;

int main()
{
    int y1, m1, d1, y2, m2, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

    int answer = m2 > m1 || (m2 == m1 && d2 >= d1) ? y2 - y1 : y2 - y1 - 1;
    cout << answer << '\n';
    answer = y2 - y1 + 1;
    cout << answer << '\n';
    cout << answer - 1 << '\n';
    return 0;
}