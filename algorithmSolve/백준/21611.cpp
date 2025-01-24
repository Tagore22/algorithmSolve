#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 오랜만이다. 삼성 문제다. 어렵진 않으나 복잡한 문제 여러개가 얽혀있다. 늘 생각하지만 삼성문제는
// 풀이의 발상보다 구현의 능력을 더 평가하는듯하다. 실제로 이 문제도 수학적인 알고리즘을 떠올리기보다
// 주어진걸 구현하기 급급하다. 정답율이 낮은 만큼 쉽지 않은 문제였다.

// 자세한 설명은 주석으로 남긴다.

int board[50][50], answer[4] = { 0, };
int rot[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int dir[2][2] = { {-1, 1}, {1, -1} };
pair<int, int> magic[101]; // 방향, 거리.
int N, M, from;
vector<int> cou;

// 블리자드를 쏜 이후의 배열을 갱신하는 함수.
void Blizzard(int idx)
{
    int y = from, x = from;
    // 블리자드의 길이만큼 현재 좌표를 이동해가며 값을 0으로 만든다.
    for (int i = 0; i < magic[idx].second; ++i)
    {
        int ny = y + rot[magic[idx].first][0];
        int nx = x + rot[magic[idx].first][1];
        board[ny][nx] = 0;
        y = ny;
        x = nx;
    }
}

// 구슬들을 이동시키는 함수.
bool Move()
{
    // isEnd는 이후에 Move()를 한번 더 호출하는지의 여부를 구하는 함수다.
    // 한번의 순회끝에 이동이 존재하지 않을때까지 Move()는 계속 호출된다.
    bool isEnd = true, isX = true;
    int y = from, x = from, num = 1;

    // 반복의 횟수를 가늠하기가 힘들었다. 
    // 무한의 while문을 순회하다가 일정 조건에 의해 탈출한다.
    while (true)
    {
        if (isX)
        {
            // 좌우상하를 움직여야하는데 좋은 아이디어가 떠오르지 않아 이렇게 구현했다.
            // 좌하우상으로 움직이기 때문에 좌, 우와 상, 하를 따로 묶어서 배열을 이용해
            // 이동값을 구현했다.
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                // 이동하려는 좌표값이 배열을 벗어났다면 무시한다.
                if (nx <= 0 || nx > N)
                    // 현재 2중 반복문안에 존재하기 때문에 단한번의 break로는 탈출할수 없었다.
                    // 따라서 bool 변수를 갱신하고 이후에 한번 더 탈출한다.
                    return isEnd;
                // 맨 처음 상어의 위치는 0이다. 이것을 조건문에서 걸러내야하기 때문에
                // 좌표가 시작점이라면 무시하고 현재값이 0이며 다음값이 0이 아닐때에만
                // 둘을 교환한다. 왜냐하면 현재도 0이고 다음도 0이면 교환해봤자이며
                // 현재도 0이 아니고 다음도 0이 아니면 교환자체가 불가능하기 때문이다.
                if ((y != from || x != from) && board[y][x] == 0 && board[y][nx] != 0)
                {
                    swap(board[y][x], board[y][nx]);
                    // 이번에 교환이 존재했으므로 이후에 Move()를 한번 더 호출한다.
                    isEnd = false;
                }
                x = nx;
            }
            isX = false;
        }
        // y로 이동할때. 반복.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                    return isEnd;
                if (board[y][x] == 0 && board[ny][x] != 0)
                {
                    swap(board[y][x], board[ny][x]);
                    isEnd = false;
                }
                y = ny;
            }
            ++num;
            isX = true;
        }
    }
}

// 구슬이 4개 이상 연속으로 존재하여 폭발할때의 함수.
bool Explode()
{
    bool isX = true, isEnd = true, isCross = false;
    int y = from, x = from, num = 1, prev = -1;
    vector<pair<int, int>> overlap;

    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                if (nx <= 0 || nx > N)
                {
                    isCross = true;
                    break;
                }
                x = nx;
                // 이전의 구슬 번호와 현재의 구슬 번호가 다를때
                // vector에 넣어놨던 원소들을 정리한다.
                // 만약 4개 이상이라면 폭발이 존재하여 0으로 만들고
                // 그렇지 않다면 그냥 지워버린다.
                if (board[y][x] != prev)
                {
                    int osize = overlap.size();
                    if (osize >= 4)
                    {
                        isEnd = false;
                        for (auto& p : overlap)
                        {
                            ++answer[board[p.first][p.second]];
                            board[p.first][p.second] = 0;
                        }
                    }
                    prev = board[y][x];
                    overlap.clear();
                }
                // 현재 번호와 이전 번호가 같은지에 상관없이 현재 구슬을 무조건 vector에 들어간다.
                // 단 0은 폭발이 존재하지 않기에 연산량을 줄이기 위해 무시한다.
                if (board[y][x] != 0)
                    overlap.push_back(make_pair(y, x));
            }
            if (isCross)
                break;
            isX = false;
        }
        // y가 움직일때. 반복.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                {
                    isCross = true;
                    break;
                }
                y = ny;
                if (board[y][x] != prev)
                {
                    int osize = overlap.size();
                    if (osize >= 4)
                    {
                        isEnd = false;
                        for (auto& p : overlap)
                        {
                            ++answer[board[p.first][p.second]];
                            board[p.first][p.second] = 0;
                        }
                    }
                    prev = board[y][x];
                    overlap.clear();
                }
                if (board[y][x] != 0)
                    overlap.push_back(make_pair(y, x));
            }
            if (isCross)
                break;
            ++num;
            isX = true;
        }
    }
    // 순회 이후에 vector에 원소가 남아있을수가 있다. 상술하였듯 순회 횟수를 명확하게
    // 계산하기가 모호하기에 일단 다 넣는다. 
    int osize = overlap.size();
    if (osize >= 4)
    {
        isEnd = false;
        for (auto& p : overlap)
        {
            ++answer[board[p.first][p.second]];
            board[p.first][p.second] = 0;
        }
    }
    return isEnd;
}

// 재배치전 구슬의 번호와 개수를 계산하는 함수.
void Count()
{
    bool isX = true, isCross = false;
    int y = from, x = from, num = 1, prev = -1, sum = 1;
    vector<pair<int, int>> overlap;

    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                // 현재는 Move() 함수에 의해 빈칸이 전부 채워진 상태이다.
                // 이때 board[y][x]가 0이라는 것은 모든 구슬을 순회하고 난 이후이다.
                // 이것을 배열값을 벗어났을때처럼 제외시켜주어야 한다.
                // 그렇지 않으면 0의 개수가 함께 vector에 포함되어 이후 재배치에 악영향을 끼쳐
                // 제대로 된 답을 출력하지 못하기 때문이다.
                if (nx <= 0 || nx > N || board[y][nx] == 0)
                {
                    isCross = true;
                    break;
                }
                x = nx;
                // 이전 구슬값과 현재 구슬값이 다르다면
                // 기존의 구슬 번호와 개수를 vector에 저장하고
                // 현재 구슬 번호와 1로 갱신한다.
                if (board[y][x] != prev)
                {
                    cou.push_back(sum);
                    cou.push_back(prev);
                    prev = board[y][x];
                    sum = 1;
                }
                else
                {
                    ++sum;
                }
            }
            if (isCross)
                break;
            isX = false;
        }
        // y가 움직일때. 반복.
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N || board[ny][x] == 0)
                {
                    isCross = true;
                    break;
                }
                y = ny;
                if (board[y][x] != prev)
                {
                    cou.push_back(sum);
                    cou.push_back(prev);
                    prev = board[y][x];
                    sum = 1;
                }
                else
                {
                    ++sum;
                }
            }
            if (isCross)
                break;
            ++num;
            isX = true;
        }
    }
    // Explode()와 마찬가지로 vector에 원소값이 남아있을수 있기에 추가해준다.
    cou.push_back(sum);
    cou.push_back(prev);
}

// 배열을 최종적으로 재배치하는 함수.
void Resort()
{
    bool isX = true;
    int y = from, x = from, num = 1, idx = 2;
    vector<pair<int, int>> overlap;

    // vector 변수 cou를 모든 배열좌표만큼 순회하며 각 원소값으로 대체한다.
    while (true)
    {
        if (isX)
        {
            int plus = dir[num % 2][1];
            for (int i = 0; i < num; ++i)
            {
                int nx = x + plus;
                if (nx <= 0 || nx > N)
                    return;
                x = nx;
                board[y][x] = cou[idx];
                ++idx;
                if (idx >= cou.size())
                    return;
            }
            isX = false;
        }
        else
        {
            int plus = dir[num % 2][0];
            for (int i = 0; i < num; ++i)
            {
                int ny = y + plus;
                if (ny <= 0 || ny > N)
                    return;
                y = ny;
                board[y][x] = cou[idx];
                ++idx;
                if (idx >= cou.size())
                    return;
            }
            ++num;
            isX = true;
        }
    }
}

void MakeAnswer()
{
    from = (N + 1) / 2;
    for (int iter = 0; iter < M; ++iter)
    {
        cou.clear();
        Blizzard(iter);
        // 상술한대로 Move()에서 더이상 움직임이 없을때까지
        // 반복하여 호출한다.
        while (!Move())
        {
        }
        // 마찬가지로 폭발이 더이상 존재하지 않을때까지
        // 폭발과 이동을 반복하낟.
        while (!Explode())
        {
            while (!Move())
            {
            }
        }
        Count();
        Resort();
    }
    cout << (1 * answer[1] + 2 * answer[2] + 3 * answer[3]) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < M; ++i)
        cin >> magic[i].first >> magic[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}