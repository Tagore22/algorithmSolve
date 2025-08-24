#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {
        int num;
        cin >> num;
        sum += num;
    }

    cout << (sum <= 1500 ? "Yes" : "No") << '\n';
    return 0;
}