#include <iostream>

using namespace std;

int main()
{
    int R, B;
    cin >> R >> B;

    for (int i = 1; i <= B; ++i)
    {
        int div = B / i;
        if (i * div != B)
            continue;
        int R_row = i + 2;
        int R_col = div + 2;
        if (R_row * 2 + R_col * 2 - 4 == R)
        {
            if (R_row < R_col)
                swap(R_row, R_col);
            cout << R_row << ' ' << R_col << '\n';
            break;
        }
    }
    return 0;
}