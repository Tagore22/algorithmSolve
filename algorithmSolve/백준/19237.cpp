#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

// 풀이.
// 엄청 복잡한 문제였다. 데이터들의 저장과 사용 방식도 많아서 생각할게 많았다.

// 다만 크게 보면 어렵지 않는데 원리는 다음과 같다.

// 1. 상어들이 주어진 방향과 우선순위에 따라 이동한다.
// 1-1. 다만 상어 이동시 기존 칸에 있던 냄새가 1씩 감소한다.
// 2. 모든 상어가 이동했을때 한칸에 여러마리의 상어가 존재한다면 번호가 가장 작은 상어를 제외하고 모두 제외시킨다.

// 이것이 큰 틀이다. 다만 상술하였듯 데이터 자체가 방대하기 때문에 그 데이터를 사용하는 것이 더 어려웠던 것 같다.

// 자세한 설명은 주석을 남긴다.


// 상어 자체를 구현하는 구조체.
struct shark
{
    int y;
    int x;
    int dir;
};

int rot[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 위, 아래, 왼쪽, 오른쪽.

// 상어마다 방향과 그에 따른 우선순위를 저장하는 벡터.
vector<vector<vector<int>>> shark_rot;
// 좌표칸에 존재하는 상어들을 저장하는 컨테이너.
vector<vector<deque<int>>> board;
// 상어들 자체를 저장하는 벡터.
vector<shark> sharks;
// 좌표의 냄새와 그 번호를 저장하는 벡터.
vector<vector<pair<int, int>>> small; // 상어의 번호, 냄새의 지속시간.
int N, M, K, shark_num; // 격자의 길이, 상어의 수, 냄새의 지속시간.
// 이번턴에 해당 좌표의 냄새가 감소하였는지 확인하는 bool 배열.
bool check[20][20];

// 냄새를 감소시키는 함수. 상어가 이동한 좌표 이외의 다른 좌표들은 모든 상어가
// 이동한 후 자체적으로 1씩 감소시킨다.
void SmallDown()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j] && small[i][j].first != 0)
            {
                --small[i][j].second;
                if (small[i][j].second == 0)
                    small[i][j].first = 0;
            }
}

// idx번 상어를 이동시키는 함수.
void SharkMove(int idx)
{
    int y = sharks[idx].y;
    int x = sharks[idx].x;
    int dir = sharks[idx].dir - 1;

    vector<int>& cur_rot = shark_rot[idx - 1][dir];
    int dy, dx;

    // 상어의 방향에 따라 우선순위 순으로 순회하며 새로운 방향을 찾아보고
    // 그 방향으로 이동할수 있다면(배열값을 벗어나지 않고 해당 좌표값에 냄새가 없다면) 이동한다.
    for (int i = 0; i < 4; ++i) // 방향과 좌표를 바꾸는걸 잊지말자.
    {
        dy = y + rot[cur_rot[i] - 1][0];
        dx = x + rot[cur_rot[i] - 1][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || small[dy][dx].first != 0)
            continue;

        // 여기서 갱신해야할 것들이 상당히 많다.
        // 1. 상어값(좌표값과 방향).
        // 2. 상어가 존재하는 컨테이너의 갱신.
        // 3. 기존칸의 냄새를 1 감소시킴.(만약 이번에 냄새가 사라진다면 그것까지도)
        // 4. 기존 좌표값과 새로운 좌표값은 후에 자체적으로 냄새를 감소시키는 부분에서
        // 제외되기에 그것을 체크하는 bool 배열.
        sharks[idx].y = dy;
        sharks[idx].x = dx;
        sharks[idx].dir = cur_rot[i];
        board[dy][dx].push_back(idx);
        board[y][x].pop_front();
        --small[y][x].second;
        if (small[y][x].second == 0)
            small[y][x].first = 0;
        check[y][x] = true;
        check[dy][dx] = true;
        return;
    }

    // 모두 냄새가 존재하여 방향을 찾지 못하였을때.
    // 마찬가지로 우선순위로 순회하며 현재 자신의 냄새를 찾아
    // 그곳으로 이동한다.

    for (int i = 0; i < 4; ++i)
    {
        dy = y + rot[cur_rot[i] - 1][0];
        dx = x + rot[cur_rot[i] - 1][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || small[dy][dx].first != idx)
            continue;

        // 여기서 갱신해야할 것들이 상당히 많다.
        // 1. 상어값(좌표값과 방향).
        // 2. 상어가 존재하는 컨테이너의 갱신.
        // 3. 기존칸의 냄새를 1 감소시킴.(만약 이번에 냄새가 사라진다면 그것까지도)
        // 4. 기존 좌표값과 새로운 좌표값은 후에 자체적으로 냄새를 감소시키는 부분에서
        // 제외되기에 그것을 체크하는 bool 배열.
        sharks[idx].y = dy;
        sharks[idx].x = dx;
        sharks[idx].dir = cur_rot[i];
        board[dy][dx].push_back(idx);
        board[y][x].pop_front();
        --small[y][x].second;
        if (small[y][x].second == 0)
            small[y][x].first = 0;
        check[y][x] = true;
        check[dy][dx] = true;
        return;
    }
}

// 모든 상어를 이동시키는 함수.
// 모든 이동이 끝난 후에 어떤 좌표값에 여러마리의 상어가
// 존재한다면 가장 작은 번호의 상어를 제외하고 나머지를 제외시킨다.
void SharkAllMove()
{
    for (int i = 1; i <= M; ++i)
    // 여기서 이미 제외된 상어들을 걸러내는 조건문을 구현한다.
        if (sharks[i].y != -1)
            SharkMove(i);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deque<int>& cur = board[i][j];

            // 하나의 좌표값안에 2마리 이상의 상어가 존재한다면 번호순으로 정렬하여
            // 가장 작은 번호의 상어를 제외하고 모두 제외시킨다. y값을 -1로 변경시켜
            // 이 함수 첫번째 for문에 존재하는 y != -1에서 걸리게 만든다.
            if (cur.size() >= 1)
            {
                sort(cur.begin(), cur.end());
                int cur_size = cur.size() - 1;
                for (int iter = cur_size; iter >= 1; --iter)
                {
                    sharks[cur[iter]].y = -1;
                    cur.pop_back();
                    // 현재 존재하는 상어의 수를 감소시킨다.
                    --shark_num;
                }
                // 새로운 냄새의 갱신.
                small[i][j] = make_pair(cur[0], K);
            }
        }
}

void MakeAnswer()
{
    int answer = 0;
    while (shark_num > 1)
    {
        ++answer;
        memset(check, false, sizeof(check));
        SharkAllMove();
        SmallDown();

        if (answer > 1000)
        {
            answer = -1;
            break;
        }
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    board.resize(N, vector<deque<int>>(N, deque<int>()));
    sharks.resize(M + 1, shark{ 0, 0, 0 });
    shark_rot.resize(M, vector<vector<int>>(4, vector<int>(4, 0)));
    small.resize(N, vector<pair<int, int>>(N, make_pair(0, 0)));
    shark_num = M;
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> cur;
            if (cur != 0)
            {
                sharks[cur].y = i;
                sharks[cur].x = j;
                small[i][j] = make_pair(cur, K);
                board[i][j].push_back(cur);
            }
        }

    for (int i = 1; i <= M; ++i)
        cin >> sharks[i].dir;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < 4; ++j)
            for (int idx = 0; idx < 4; ++idx)
            {
                vector<int>& cur = shark_rot[i][j];
                cin >> cur[idx];
            }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}