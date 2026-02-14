#include <iostream>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int num, ans = 0, answer = 0;
        cin >> num;
        for (int i = 0; i < num; ++i)
        {
            char cur;
            cin >> cur;
            if (cur == 'X')
            {
                ++ans;
            }
            else
            {
                answer = max(answer, ans);
                ans = 0;
            }
        }
        answer = max(answer, ans);
        cout << "The longest contiguous subsequence of X's is of length " << answer << '\n';
    }
    return 0;
}