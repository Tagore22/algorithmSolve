#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> first, second, third;
    for (int i = 0; i < N; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        first.push_back(a + b);
        second.push_back(b + c);
        third.push_back(a + c);
    }

    sort(first.begin(), first.end(), greater<>());
    sort(second.begin(), second.end(), greater<>());
    sort(third.begin(), third.end(), greater<>());

    long long firstnum = 0, secondnum = 0, thirdnum = 0;
    for (int i = 0; i < K; ++i)
    {
        firstnum += first[i];
        secondnum += second[i];
        thirdnum += third[i];
    }
    long long answer = max({ firstnum, secondnum, thirdnum });
    cout << answer << '\n';

    return 0;
}