#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    pair<int, int> ans = make_pair(-1, -1);
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num > ans.first)
            ans = make_pair(num, i);
    }
    cout << (ans.second == 0 ? 'S' : 'N') << '\n';
    return 0;
}