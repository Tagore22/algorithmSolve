#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    pair<int, string> maxi = make_pair(-1, "");
    int answer = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        string str;
        int K, M, cur = 0;
        cin >> str >> K >> M;
        while (M / K > 0)
        {
            int mul = M / K;
            cur += mul;
            M -= mul * K - mul * 2;
        }
        maxi = maxi.first < cur ? make_pair(cur, str) : maxi;
        answer += cur;
    }
    cout << answer << '\n';
    cout << maxi.second << '\n';
    return 0;
}