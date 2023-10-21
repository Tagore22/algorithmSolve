#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 풀이.
// 정렬의 조건을 구현하는 함수였다. 문제에서 주어지듯
// 첫째로 점수를 비교하고 그 이후 3점을 받은 횟수, 2점을 받은 횟수를 비교하면 된다.
// 만약 2점을 받은 횟수까지 동일하다면 문제에서도 주어진듯 필연적으로 1점을 받은 횟수도 동일하기 때문에
// 그냥 무시하면 된다. 후술할 마지막 부분을 까먹어서 헤맸다. ㅠㅠ

// 자세한 설명은 주석으로 남긴다.

pair<int, int> point[3];
int board[4][4];
int N;

// 각 후보들의 우위를 비교하는 함수.
bool Compose(const pair<int, int>& lhs, const pair<int, int>& rhs)
{
    // 1. 현재 받은 점수가 다르다면 비교한다.
    if (lhs.first != rhs.first)
        return lhs.first > rhs.first;
    // 2. 점수가 같다면 3점을 받은 횟수가 다른지 확인후 비교한다.
    else if (board[lhs.second][3] != board[rhs.second][3])
        return board[lhs.second][3] > board[rhs.second][3];
    // 3. 3점을 받은 횟수마저 같다면 2점을 받은 횟수가 다른지 확인후 비교한다.
    else if (board[lhs.second][2] != board[rhs.second][2])
        return board[lhs.second][2] > board[rhs.second][2];
    // 4. 2점을 받은 횟수마저 같다면 비교가 불가능하기에 무시한다.
    else
        return false;
}

void MakeAnswer()
{
    // 각 후보들의 점수와 받은 횟수들의 초기화.
    for (int i = 0; i < 3; ++i)
        point[i] = make_pair(0, i + 1);
    memset(board, 0, sizeof(board));
    int cur;
    for (int iter = 0; iter < N; ++iter)
    {
        // 각 학생마다 받은 점수를 최종 점수에 더해주고 횟수를 증가시킨다.
        for (int i = 0; i < 3; ++i)
        {
            cin >> cur;
            point[i].first += cur;
            ++board[i + 1][cur];
        }
    }

    // 각 학생들의 우위를 비교한다.
    sort(point, point + 3, Compose);
    // 1번 후보와 2번 후보가 점수가 같고, 1점을 받은 횟수마저 같다면 비교가 불가능하므로 0과 최종 점수를 출력한다.
    // 위 정렬 함수에 따르면 맨 앞 2명의 후보는 가장 점수가 크며 3점을 가장 많이 받고 2점을 가장 많이 받은 후보들인데
    // 이 후보들의 점수와 1점을 받은 횟수가 같다는건 가장 우위에서 높은 2명이상이 비교가 불가능하다는 것이다.
    // 여기서 1번을 받은 횟수는 구현했으나, 점수가 같다는걸 빼먹었었다.
    if (board[point[0].second][1] == board[point[1].second][1] &&
        point[0].first == point[1].first)
        cout << 0 << ' ' << point[0].first;
    // 비교가 가능했다면 맨 앞 후보의 번호와 최종 점수를 출력한다.
    else
        cout << point[0].second << ' ' << point[0].first;
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}