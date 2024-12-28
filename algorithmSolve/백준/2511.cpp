#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int boardA[10], boardB[10];
    for (int i = 0; i < 10; ++i)
        cin >> boardA[i];
    for (int i = 0; i < 10; ++i)
        cin >> boardB[i];

    int A = 0, B = 0;
    char cur = 'D';
    for (int i = 0; i < 10; ++i)
    {
        if (boardA[i] > boardB[i])
        {
            A += 3;
            cur = 'A';
        }
        else if (boardA[i] < boardB[i])
        {
            B += 3;
            cur = 'B';
        }
        else
        {
            ++A;
            ++B;
        }
    }
    cout << A << ' ' << B << '\n';
    if (A > B)
        cout << 'A' << '\n';
    else if (A < B)
        cout << 'B' << '\n';
    else
        cout << cur << '\n';
    return 0;
}