#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, num;
    cin >> N;
    bool answer = true;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        if (num < 48)
            answer = false;
    }
    cout << (answer ? "True" : "False") << '\n';
    return 0;
}