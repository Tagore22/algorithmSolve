#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 정답율이 보여주듯 어려운 문제였다. 처음에는 그리디하게 풀려고 했으나 변수가 너무 많았다.
// 따라서 모든 경우를 파악한후 비교해보는 수밖에 없었다. 백트래킹을 사용해야했는데
// 4번의 테스트케이스가 존재하므로 모든 경우를 미리 구해서 나중에는 비교만 하는것으로 더 빠르게 구현하고
// 싶었으나 그러기엔 3의 15제곱만큼의 경우가 존재하여 불가능했다. 결과적으로는 속도를 포기하되, 용량을 선택하여
// 매번 처음부터 모든 결과를 계산해야만 했다. 다른 풀이를 보니 훨씬 더 빠른게 있는데 잘 모르겠다.

// 자세한 설명은 주석으로 남긴다.

int board[6][3], cur[6][3];
vector<pair<int, int>> vs;
bool isFind;
int sum;

// 모든 경우의 수를 파악해보는 백트래킹 함수.
void BackTrack(int num)
{
    // 모든 경우를 다 파악했다면 배열들을 비교해본다.
    if (num == 15)
    {
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
                // 다르다면 그냥 탈출한다.
                if (board[i][j] != cur[i][j])
                    return;
        // 탈출하지 않고 두 배열이 일치한다면 isFind를 갱신하고 탈출한다.
        isFind = true;
        return;
    }

    // 처음에는 vector를 사용하지 않으려 했으나, 그렇지 않으면 백트래킹 함수가 더 복잡해진다.
    // 총 15번의 경기에서 맞붙는 두 팀을 미리 계산하여 백트래킹 함수에서는 가져다 사용만한다.
    int first = vs[num].first;
    int second = vs[num].second;

    // first가 이겼을 경우.
    ++cur[first][0];
    ++cur[second][2];
    BackTrack(num + 1);
    --cur[first][0];
    --cur[second][2];

    // 비겼을 경우.
    ++cur[first][1];
    ++cur[second][1];
    BackTrack(num + 1);
    --cur[first][1];
    --cur[second][1];

    // second가 이겼을 경우.
    ++cur[first][2];
    ++cur[second][0];
    BackTrack(num + 1);
    --cur[first][2];
    --cur[second][0];
}

void MakeAnswer()
{
    // 상술한대로 총 15번의 경기에서 맞붙을 두 팀을 미리 계산해둔다.
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            vs.push_back(make_pair(i, j));
    for (int iter = 0; iter < 4; ++iter)
    {
        isFind = false;
        sum = 0;
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 3; ++j)
            {
                cin >> board[i][j];
                sum += board[i][j];
            }

        // 총 경기가 15번이므로 모든 계산들의 합은 30이 나와야 한다.
        // 가지치기.
        if (sum != 30)
        {
            cout << 0 << '\n';
            continue;
        }
        BackTrack(0);
        if (isFind)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}