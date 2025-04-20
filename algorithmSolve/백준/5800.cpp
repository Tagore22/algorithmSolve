#include <iostream>
#include <algorithm>

using namespace std;

int score[100];
int K;

void Solve()
{
    for (int iter = 0; iter < K; ++iter)
    {
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i)
            cin >> score[i];
        sort(score, score + num);
        int gap = 0;
        for (int i = 1; i < num; ++i)
            gap = max(gap, score[i] - score[i - 1]);
        cout << "Class " << iter + 1 << '\n';
        cout << "Max " << score[num - 1] << ", Min " << score[0] << ", Largest gap " << gap << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
}

int main()
{
    Input();
    Solve();
    return 0;
}