#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board;
vector<int> answer;
vector<pair<int, int>> LIS;
int n;

void Calcul()
{
    int idx = 0;
    answer.push_back(board[0]);
    LIS.push_back(make_pair(0, board[0]));
    for (int i = 1; i < n; ++i)
    {
        if (board[i] > answer.back())
        {
            answer.push_back(board[i]);
            LIS.push_back(make_pair(++idx, board[i]));
        }
        else
        {
            int loweridx = distance(answer.begin(), lower_bound(answer.begin(), answer.end(), board[i]));
            answer[loweridx] = board[i];
            LIS.push_back(make_pair(loweridx, board[i]));
        }
    }
    int FindNum = answer.size() - 1;
    for (int i = LIS.size() - 1; i >= 0; --i)
        if (LIS[i].first == FindNum)
        {
            answer[FindNum] = LIS[i].second;
            --FindNum;
            if (FindNum == -1)
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
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    Calcul();
    return 0;
}