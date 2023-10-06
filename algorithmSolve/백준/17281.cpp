#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 문제가 그지같아서 찾아보니 삼성 문제였다.
// 엄청 어려웠던 문제다. 큰틀만 보자면 처음에 전처리로 4만개의 순열들을 미리 구해놓고
// 그 순열대로 4만개의 모든 경우를 재귀호출로 진행해가며 최대 점수를 구해 출력해냈다.
// 다만 속도가 너무 느렸다. 대략 평균의 3배정도 느렸다.
// 나중에 다시 찾아보자.

// 자세한 설명은 주석으로 남긴다.

int point[51][10];
vector<vector<int>> board;
vector<bool> visit;
int N, answer, ans, board_num;

// 점수를 더하는 함수. 비트마스크를 이용하였다.
int AddPoint(int mask, int point)
{
    // 비트마스크를 왼쪽으로 밀어내며 루를 구현하였다.
    // 이 함수가 호출되었다는 것은 무조건 안타이상 쳤다는 것이기에
    // 반드시 주자가 등장하게 된다. 따라서 mask의 시작을 1로 바꾼다.
    mask |= 1;
    // 3 ~ 4 - 타수동안 순회하며 각 루에 주자가 존재하는지 확인한다.
    // 만약 존재한다면 이번 안타로 인해 점수가 날것이다.
    for (int i = 3; i >= 4 - point; --i)
        if (mask & (1 << i))
            ++ans;

    // 주자가 이동한다.
    mask <<= point;
    // mask가 계속 커질텐데 int값을 벗어날수도 있을것 같기에 새로운 mask로 최대 3루까지만 복사하여
    // 반환해준다.
    int temp = 0, mul = 0;
    for (int i = 0; i <= 3; ++i)
    {
        if (mask & (1 << i))
            temp |= (1 << i);
    }
    return temp;
}

// 모든 경우를 다해보는 함수.
void BackTrack(int cur, int mask, int ining, int out) // 몇번째 백트래킹 순서, 루의 상태, 몇 아웃인가
{
    // 모든 이닝이 지나고 경기가 끝났을 경우 현 게임의 값을 최대값과 비교하여 갱신한다.
    if (ining == N + 1)
    {
        answer = max(answer, ans);
        return;
    }

    // 현재 점수를 구한다.
    int plus = point[ining][board[board_num][cur]];

    // 점수가 0이라면 1아웃이 추가되고 만약 3아웃이 되었다면
    // 이닝이 바뀐다. 이때 모든 루는 비어진다.
    if (plus == 0)
    {
        ++out;
        if (out == 3)
        {
            ++ining;
            mask = 0;
            out = 0;
        }
    }
    // 그렇지 않다면 루가 갱신되고 점수가 갱신된다.
    else
    {
        mask = AddPoint(mask, plus);
    }

    cur = cur + 1 >= 9 ? 0 : cur + 1;
    BackTrack(cur, mask, ining, out);
}

// 모든 순열을 만드는 함수.
void MakeBoard(vector<int> vec)
{
    int v_size = vec.size();
    // 9개가 만들어졌다면 다만들어진 경우이므로 board에 추가하고 탈출함.
    if (v_size == 9)
    {
        board.push_back(vec);
        return;
    }

    // 현재 3개가 만들어지고 4번째라면 무조건 1번 선수를 추가한다.
    if (v_size == 3)
    {
        vec.push_back(1);
        MakeBoard(vec);
        return;
    }

    for (int i = 2; i <= 9; ++i)
    {
        if (visit[i])
            continue;

        vec.push_back(i);
        visit[i] = true;
        MakeBoard(vec);
        vec.pop_back();
        visit[i] = false;
    }
}

void MakeAnswer()
{
    visit.resize(10, false);
    // 모든 경우의 수를 만들어본다. 다만 1번 선수는 무조건 4번타자이기에
    // 제외된다.
    for (int i = 2; i <= 9; ++i)
    {
        visit[i] = true;
        vector<int> vec(1, i);
        MakeBoard(vec);
        visit[i] = false;
    }

    answer = 0;
    // 미리 만들어놓은 순열대로 점수를 구해보고 그중 최대값을 출력함.
    for (int i = 0; i < board.size(); ++i)
    {
        ans = 0;
        board_num = i;
        BackTrack(0, 0, 1, 0);
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= 9; ++j)
            cin >> point[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}