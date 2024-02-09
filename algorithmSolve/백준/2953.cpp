#include <iostream>

using namespace std;

// 풀이.
// 주어지는 점수들중 최고 점수와 그 번호를 출력한다.

int main()
{
    pair<int, int> answer = make_pair(-1, -1);
    int num, ans;
    for (int i = 1; i <= 5; ++i)
    {
        ans = 0;
        for (int j = 0; j < 4; ++j)
        {
            cin >> num;
            ans += num;
        }
        if (answer.second < ans)
            answer = make_pair(i, ans);
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}