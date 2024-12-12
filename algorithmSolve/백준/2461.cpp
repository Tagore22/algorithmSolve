#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 처음에 풀이를 생각치 못해서 힌트를 봤는데 투포인터가 있었다. 그 이후로 투포인터에 집착하게 되어서
// 이미 생각해냈던 풀이를 넘겨버리는 실수를 저질렀다. 풀이는 이러하다. 

// 1. 각 반에서 가장 높은 능력치의 학생들을 모아 최대값 - 최소값을 구한다.
// 2. 이후 최대 능력치의 학생을 제외하고 그 반의 그 다음으로 높은 능력치의 학생을 포함시켜 다시 최대값 - 최소값을 구한다.
// 3. 위를 반복하다가 더이상 학생이 존재하지 않는 반이 존재한다면 여태까지의 최소값을 출력한다.

// 중간값은 중요하지 않고 최대값과 최소값만이 중요하기 때문에 매번 최대값을 지닌 학생을 바꾸어주면 된다.
// 시간 복잡도는 최초에 모든 반의 학생들을 정렬하는데 NMlogM + 모든 학생들을 포함시키는데 NM * 매 순간 큐에서 빼오는데
// logM이 들기에 2NMlogM이 걸린다. 2 * 1000 * 1000 * 9.99..으로 2천만의 연산량이 예상된다.

// 자세한 설명은 주석으로 남긴다.

int N, M, minnum = 9876543211, answer = 9876543211;
priority_queue<int> board[1000];
priority_queue<pair<int, int>> ans;

void MakeAnswer()
{
    // 최초의 학생들을 포함시킨다. 우선순위 큐는 맨 위는 알아도 맨 아래는 알수 없기에
    // 따로 최소값을 구한다.
    for (int i = 0; i < N; ++i)
    {
        int here = board[i].top();
        minnum = min(minnum, here);
        board[i].pop();
        ans.push(make_pair(here, i));
    }
    while (true)
    {
        // 최대값과 최소값의 차이를 구한다.
        pair<int, int> here = ans.top();
        ans.pop();
        answer = min(answer, here.first - minnum);

        int idx = here.second;
        // 만약 현재 가장 큰 학생의 반에 더이상 학생이 존재하지 않는다면 while문을 탈출한다.
        if (board[idx].empty())
            break;
        // 해당 반에서 그 다음으로 높은 학생을 투입시킨다.
        int now = board[idx].top();
        minnum = min(minnum, now);
        board[idx].pop();
        ans.push(make_pair(now, idx));
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        int now;
        for (int j = 0; j < M; ++j)
        {
            cin >> now;
            board[i].push(now);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}