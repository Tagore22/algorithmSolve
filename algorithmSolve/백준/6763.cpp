#include <iostream>

using namespace std;

int main()
{
    int N, F;
    cin >> N >> F;
    if (N >= F)
        cout << "Congratulations, you are within the speed limit!" << '\n';
    else if (N + 1 <= F && F <= N + 20)
        cout << "You are speeding and your fine is $100." << '\n';
    else if (N + 21 <= F && F <= N + 30)
        cout << "You are speeding and your fine is $270." << '\n';
    else
        cout << "You are speeding and your fine is $500." << '\n';
    return 0;
}