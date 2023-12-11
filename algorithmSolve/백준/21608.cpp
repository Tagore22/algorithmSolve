#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 각 학생들을 배치후 만족도의 총합을 출력하는 문제다.
// 배치는 다음과 같은 조건에 의해 실행된다.

// 1. 좋아하는 친구들이 가장 인접한 위치.
// 2. 1번이 2개 이상일 경우 그중 빈칸이 가장 인접한 위치.
// 3. 2번도 2개 이상일 경우 행이 더 작은 위치로, 행이 모두 같다면 열이 더 작은 위치.

// 그 후 만족도를 구해야 하는데 만족도는 인접한 4칸들중 좋아하는 친구들의 수를 구해
// 0, 1, 10, 100, 1000까지 구할수 있다.

// 삼성 문제답게 자잘하게 복잡한게 많다.
// 자세한 설명은 주석으로 남긴다.

int fri[401][4], board[20][20];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 왼쪽, 위쪽, 오른쪽, 아래쪽.
int stu[400];
int point[5] = { 0, 1, 10, 100, 1000 };
vector<pair<int, int>> points;
int N;

// 1번 조건을 찾는 함수.
void FindOne(int num)
{
    int max_stu = -1;
    points.clear();
    // 모든 칸을 순회한다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            // 이번 칸이 빈칸이라면
            if (board[i][j] == -1)
            {
                int cur = 0;
                // 인접한 4칸을 모두 순회한다.
                for (int iter = 0; iter < 4; ++iter)
                {
                    int y = i + rot[iter][0];
                    int x = j + rot[iter][1];

                    // 인접한 칸이 비어있거나 배열을 벗어난다면 무시한다.
                    if (board[y][x] == -1 || y < 0 || y >= N || x < 0 || x >= N)
                        continue;

                    // 인접한 칸이 좋아하는 친구인지 체크한다.
                    for (int k = 0; k < 4; ++k)
                    {
                        if (board[y][x] == fri[num][k])
                        {
                            ++cur;
                            break;
                        }
                    }
                }
                // 인접하는 친구의 수가 역대급이라면 현재까지 저장했던 위치들을 모두 지우고
                // 다시 저장하고 최대수를 갱신한다.
                if (cur > max_stu)
                {
                    max_stu = cur;
                    points.clear();
                    points.push_back(make_pair(i, j));
                }
                // 인접하는 친구의 수가 최대수와 동일하다면
                // 저장한다.
                else if (cur == max_stu)
                {
                    points.push_back(make_pair(i, j));
                }
            }
}

// 2번 및 3번 조건을 찾는 함수.
void FindTwoAndThree(int num)
{
    // 1번 조건에서 아무것도 찾지 못했다면 빈칸을 다시 전부 순회한다.
    if (points.empty())
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] == -1)
                    points.push_back(make_pair(i, j));
    }

    int max_stu = -1, idx = points.size();
    vector<pair<int, int>> answer;
    // 현재 저장한 위치들을 모두 순회한다.
    for (int iter = 0; iter < idx; ++iter)
    {
        int cur = 0;
        // 인접한 4칸을 모두 순회한다.
        for (int i = 0; i < 4; ++i)
        {
            int y = points[iter].first + rot[i][0];
            int x = points[iter].second + rot[i][1];

            // 인접한 위치가 배열을 벗어난다면 무시한다.
            if (y < 0 || y >= N || x < 0 || x >= N)
                continue;

            // 인접한 칸이 비어있다면 그 수를 갱신한다.
            if (board[y][x] == -1)
                ++cur;
        }
        // 인접하는 빈칸의 수가 역대급이라면 현재까지 저장했던 위치들을 모두 지우고
        // 다시 저장하고 최대수를 갱신한다.
        if (cur > max_stu)
        {
            answer.clear();
            max_stu = cur;
            answer.push_back(points[iter]);
        }
        // 인접하는 빈칸의 수가 최대수와 동일하다면
        // 저장한다.
        else if (cur == max_stu)
        {
            answer.push_back(points[iter]);
        }
    }
    // 어차피 필요한 것은 행 번호가 가장 적고 그중 열 번호가 가장 적은 칸이기 때문에
    // 정렬하여 맨 앞의 위치를 찾는다.
    sort(answer.begin(), answer.end());
    // num번의 위치를 갱신한다.
    board[answer[0].first][answer[0].second] = num;
}

void MatchStu(int num)
{
    // 1번 조건 탐색.
    FindOne(num);
    // 1번 조건 탐색후 찾은 위치가 1개라면 무조건 그곳으로 위치시킨다.
    if (points.size() == 1)
    {
        board[points[0].first][points[0].second] = num;
        return;
    }
    // 2번 및 3번 조건 탐색.
    FindTwoAndThree(num);
}

// 만족도의 총 합을 구하는 함수.
void CalPoint()
{
    int answer = 0;
    // 모든 칸을 순회한다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            int num = 0;
            // 인접한 4칸을 순회한다.
            for (int iter = 0; iter < 4; ++iter)
            {
                int y = i + rot[iter][0];
                int x = j + rot[iter][1];

                // 인접한 칸이 배열의 범위를 벗어났다면 무시한다.
                if (y < 0 || y >= N || x < 0 || x >= N)
                    continue;

                // 인접한 위치에서 좋아하는 친구의 수를 구한다.
                for (int k = 0; k < 4; ++k)
                {
                    if (fri[board[i][j]][k] == board[y][x])
                        ++num;
                }
            }
            // 총합을 구한다.
            answer += point[num];
        }
    cout << answer << '\n';
}

void MakeAnswer()
{
    memset(board, -1, sizeof(board));
    for (int iter = 0; iter < N * N; ++iter)
        MatchStu(stu[iter]);

    CalPoint();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N * N; ++i)
    {
        cin >> stu[i];
        for (int j = 0; j < 4; ++j)
            cin >> fri[stu[i]][j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}