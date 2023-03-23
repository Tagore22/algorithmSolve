#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 문제가 복잡하다 싶으면 다 삼성sw문제였다. 이번에도 역시였다.
// 어렵지는 않으나 여러가지로 복잡하게 꼬아놔서 머리가 아픈 문제다.

// 구현해야할 것은 다음 3가지이다.
// 
// 1. 0 ~ N까지 중에서 궁수의 위치 3곳을 선택하는 백트래킹 함수.
// 2. 궁수의 위치를 골랐을때 적군을 공격하는 함수.
// 3. 공격이 끝났을때 적군이 이동하는 함수.

// 그중 가장 복잡한것은 2번이다. 조건이 다음 2가지 이기 때문이다.

// 1. 우선적으로 거리가 가장 짧은 적을 공격함.
// 2. 가장 가까운 적이 2명 이상이라면 가장 왼쪽에 있는 적을 공격함.

// 그래서 2중 조건문으로 다음 대상을 골라야한다.
// 자세한 설명은 주석을 달아놓겠다.


// 초기 배열과 이동 후를 위한 대체용 배열.
vector<vector<int>> board, temp;
int N, M, D, enemy_num = 0, answer = 0;


// 궁수가 적을 공격하는 함수. 
int Attack(const vector<int>& archer)
{
    // 이번턴에서 궁수가 맞춘 적들.
    vector<pair<int, int>> dead;
    
    // 최종 대상의 위치. 초기값은 궁수의 위치 + 오른쪽으로 사거리(D)만큼이다.
    pair<int, int> cur;

    // 현재 거리와 새로운 적군과의 거리.
    int cur_dis, new_dis;
    for (int iter = 0; iter < archer.size(); ++iter)
    {
        // 상술하였듯 초기값은 궁수의 위치에서 오른쪽으로 사거리(D)만큼 이동한 곳이다.
        cur = make_pair(N, archer[iter] + D);
        cur_dis = D;
        for (int i = N - 1; i >= 0; --i)
            for (int j = 0; j < M; ++j)

                // 적군이 존재한다면 조건문을 실행한다.
                if (temp[i][j] == 1)
                {
                    // 새로운 적군과의 거리 계산.
                    new_dis = abs(N - i) + abs(archer[iter] - j);

                    // 새로운 거리가 더 가깝거나, 현재 거리와 같으나 새로운 적이 더 왼쪽에 있는 경우에는 공격 대상이 바뀐다.
                    if (new_dis < cur_dis || ((new_dis == cur_dis) && j < cur.second))
                    {
                        cur = make_pair(i, j);
                        cur_dis = new_dis;
                    }
                }

        // 공격 대상이 이미 존재하거나, 아예 공격 대상을 찾지 못한게 아니라면 새로 포함시킨다.
        if (find(dead.begin(), dead.end(), cur) == dead.end() && cur.second != archer[iter] + D)
            dead.push_back(cur);
    }

    for (int i = 0; i < dead.size(); ++i)
        temp[dead[i].first][dead[i].second] = 0;

    // 이번에 공격한 수를 반환.
    return dead.size();
}


// 적군의 이동을 구현하는 함수. 그냥 아래쪽으로 값을 복사하면 된다.
int Move()
{
    int ans = 0;
    for (int i = 0; i < M; ++i)
        if (temp[N - 1][i] == 1)
            ++ans;

    for (int i = N - 1; i >= 1; --i)
        for (int j = 0; j < M; ++j)
            temp[i][j] = temp[i - 1][j];

    for (int i = 0; i < M; ++i)
        temp[0][i] = 0;

    // 마지막에 사라진 적군의 수 반환.
    return ans;
}

// 궁수의 공격과 적군의 이동을 모두 호출하는 함수.
// 적군이 모두 사라질때까지 계속되기에 적군의 수를 갱신해가야 한다.
void Play(const vector<int>& archer)
{
    temp = board;
    int cur_enemy = enemy_num;
    int ans = 0, cur;

    while (cur_enemy > 0)
    {
        cur = Attack(archer);
        ans += cur;
        cur_enemy -= cur;
        cur_enemy -= Move();
    }

    answer = max(answer, ans);
}

void BackTrack(int idx, vector<int> archer)
{
    if (archer.size() == 3)
    {
        Play(archer);
        return;
    }

    for (int i = idx + 1; i < M; ++i)
    {
        archer.push_back(i);
        BackTrack(i, archer);
        archer.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, vector<int>());

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    board.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                ++enemy_num;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}