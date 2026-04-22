#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int iter = 0; iter < n; ++iter)
    {
        int num;
        cin >> num;
        cout << num << ' ' << num << '\n';
    }
    return 0;
}