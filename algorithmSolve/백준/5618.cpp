#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    int N;
    cin >> N;
    int board[3];
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    int gcd = GCD(board[0], board[1]);
    for (int i = 2; i < N; ++i)
        gcd = GCD(gcd, board[i]);
    int sqrtnum = sqrt(gcd);
    vector<int> answer;
    for (int i = 1; i <= sqrtnum; ++i)
    {
        if (gcd % i != 0)
            continue;
        answer.push_back(i);
        if (gcd / i != i)
            answer.push_back(gcd / i);
    }
    sort(answer.begin(), answer.end());
    for (auto c : answer)
        cout << c << '\n';
    return 0;
}