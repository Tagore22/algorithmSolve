#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int A = 0, B = 0;
    for (int i = 0; i < N; ++i)
    {
        int num1, num2;
        cin >> num1 >> num2;
        if (num1 > num2)
            ++A;
        else if (num1 < num2)
            ++B;
    }
    cout << A << ' ' << B << '\n';
    return 0;
}