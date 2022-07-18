#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long MinNum, MaxNum;

void Era()
{
    int Bsize = MaxNum - MinNum + 1;
    vector<bool> board(Bsize, true);
    int SqrtNum = sqrt(MaxNum);
    for (long long i = 2; i <= SqrtNum; ++i)
    {
        long long DivNum = MinNum / (i * i);
        if (DivNum * i * i < MinNum)
            ++DivNum;
        for (long long j = DivNum * i * i; j <= MaxNum; j += i * i)
            board[j - MinNum] = false;
    }
    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
        if (board[i])
            ++answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> MinNum >> MaxNum;
}

int main()
{
    Input();
    Era();
    return 0;
}