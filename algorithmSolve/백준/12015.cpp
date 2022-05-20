#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
vector<int> answer;
int n;

int Calcul()
{
    answer.push_back(board[0]);
    for (int i = 1; i < n; ++i)
    {
        if (board[i] > answer.back())
            answer.push_back(board[i]);
        else
            *(lower_bound(answer.begin(), answer.end(), board[i])) = board[i];
    }
    return answer.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    cout << Calcul() << '\n';
    return 0;
}