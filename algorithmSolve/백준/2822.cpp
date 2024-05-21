#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 정렬을 두번해야하는 문제였다. 첫번째로는 각 문제의 점수별로 정렬해야했고, 그 이후에는
// 문제의 번호를 기준으로 정렬해야했다.

int main()
{
    pair<int, int> board[8];
    for (int i = 0; i < 8; ++i)
    {
        cin >> board[i].first;
        board[i].second = i + 1;
    }
    sort(board, board + 8, greater<pair<int, int>>());
    int answer = 0;
    int point[5];
    for (int i = 0; i < 5; ++i)
    {
        answer += board[i].first;
        point[i] = board[i].second;
    }
    cout << answer << '\n';
    sort(point, point + 5);
    for (int i = 0; i < 5; ++i)
        cout << point[i] << ' ';
    cout << '\n';
    return 0;
}