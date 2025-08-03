#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    char ans[4] = { 'N', 'E', 'S', 'W' };
    int answer = 0;
    for (int i = 0; i < 10; ++i)
    {
        int num;
        cin >> num;

        answer = (answer + num) % 4;
    }
    cout << ans[answer] << '\n';
    return 0;
}