#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> board[100000];

void Solve()
{
    long long answer = 0;
    for (auto& vec : board)
    {
        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size(); ++i)
        {
            if (i == 0)
                answer += vec[1] - vec[0];
            else if (i == vec.size() - 1)
                answer += vec[vec.size() - 1] - vec[vec.size() - 2];
            else
                answer += min(vec[i + 1] - vec[i], vec[i] - vec[i - 1]);
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int idx, col;
        cin >> idx >> col;
        board[col].push_back(idx);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}