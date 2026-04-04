#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        int num;
        cin >> num;
        answer = (num != i) ? answer + 1 : answer;
    }
    cout << answer << '\n';
    return 0;
}