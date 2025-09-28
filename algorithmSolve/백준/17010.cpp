#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        int num;
        char c;
        cin >> num >> c;
        for (int i = 0; i < num; ++i)
            cout << c;
        cout << '\n';
    }
    return 0;
}