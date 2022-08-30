#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
int N;

void MakeAnswer()
{
    vector<int> lis;
    lis.push_back(board[0]);
    for (int i = 1; i < N; ++i)
    {
        if (board[i] > lis.back())
        {
            lis.push_back(board[i]);
        }
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), board[i]) - lis.begin();
            lis[idx] = board[i];
        }
    }
    cout << lis.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        board.push_back(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}