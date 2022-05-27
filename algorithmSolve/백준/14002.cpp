#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> answer;
vector<int> board;
vector<pair<int, int>> LIS;

void Calcul()
{
    answer.push_back(board[0]);
    LIS.push_back(make_pair(0, board[0]));
    for (int i = 1; i < board.size(); ++i)
    {
        if (board[i] > answer.back())
        {
            answer.push_back(board[i]);
            LIS.push_back(make_pair(answer.size() - 1, board[i]));
        }
        else
        {
            int idx = distance(answer.begin(), lower_bound(answer.begin(), answer.end(), board[i]));
            answer[idx] = board[i];
            LIS.push_back(make_pair(idx, board[i]));
        }
    }
    int idx = answer.size() - 1;
    for (int i = LIS.size() - 1; i >= 0; --i)
        if (LIS[i].first == idx)
        {
            answer[idx] = LIS[i].second;
            --idx;
            if (idx == -1)
                break;
        }
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    board.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    Calcul();
    return 0;
}