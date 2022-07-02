#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> board;
int K;

void MakeAnswer()
{
    vector<pair<int, int>> row, col;
    for (int i = 0; i < 6; ++i)
    {
        if (board[i].first == 1 || board[i].first == 2)
            row.push_back(make_pair(board[i].second, i));
        else
            col.push_back(make_pair(board[i].second, i));
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());


    int RowMax = row[2].first;
    int ColMax = col[2].first;
    int RowMin, ColMin;

    if (row[2].second == (col[2].second + 1) % 6)
    {
        RowMin = board[(row[2].second + 2) % 6].second;
        ColMin = board[(col[2].second + 6 - 2) % 6].second;
    }
    else
    {
        RowMin = board[(row[2].second + 6 - 2) % 6].second;
        ColMin = board[(col[2].second + 2) % 6].second;
    }
    cout << ((RowMax * ColMax) - (RowMin * ColMin)) * K << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    for (int i = 0; i < 6; ++i)
    {
        int a, b;
        cin >> a >> b;
        board.push_back(make_pair(a, b));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}