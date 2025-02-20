#include <iostream>

using namespace std;

int main()
{
    int A[10], B[10];
    for (int i = 0; i < 10; ++i)
        cin >> A[i];
    for (int i = 0; i < 10; ++i)
        cin >> B[i];
    int A_Win = 0, B_Win = 0, Draw = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (A[i] > B[i])
            ++A_Win;
        else if (A[i] < B[i])
            ++B_Win;
        else
            ++Draw;
    }
    if (A_Win > B_Win)
        cout << 'A' << '\n';
    else if (A_Win < B_Win)
        cout << 'B' << '\n';
    else
        cout << 'D' << '\n';
    return 0;
}