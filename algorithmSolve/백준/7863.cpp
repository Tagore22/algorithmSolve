#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
int board[MAX][MAX];
int N, P, half;
vector<int> answers;

void Solve()
{
    for (int i = 0; i < P; ++i)
    {
        int num = 0;
        bool isCan = true;
        for (int j = 0; j < N; ++j)
        {
            int low = 0, high = 0;
            for (int k = 0; k < P; ++k)
            {
                if (board[j][i] > board[j][k])
                    ++low;
                else if (board[j][i] < board[j][k])
                    ++high;
            }
            if (high == 0)
            {
                isCan = false;
                break;
            }
            else if (low == 0)
            {
                ++num;
            }
        }
        if (isCan && num >= half)
            answers.push_back(i + 1);
    }
    if (answers.size() == 0)
    {
        cout << 0 << '\n';
    }
    else
    {
        for (auto& a : answers)
            cout << a << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> P;
    half = N % 2 == 0 ? N / 2 : N / 2 + 1;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < P; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    Solve();
    return 0;
}