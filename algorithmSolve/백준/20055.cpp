#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 어려울것 없는 시뮬레이션 문제다.
// 문제에서 주어진 기본적인 틀은 다음과 같다.

// 1. 벨트를 한칸씩 옮긴다. 로봇 또한 벨트와 함께 이동한다.
// 2. 로봇이 한칸 이동가능하다면 이동한다. 다만 이동시 해당 칸의 내구도가 1 줄어든다.
// 3. 첫번째 칸에 내구도가 0이 아니라면 새로운 로봇을 올린다.
// 4. 내구도가 0인 칸이 K개 이상이라면 그때의 턴을 출력한다.

// 다만, 주의해야할 조건들이 몇가지 있는데 

// 1. N - 1칸(문제에서는 N번칸)에는 로봇이 도달시 바로 내린다.

// 이점을 유의해야한다.
// 자세한 설명은 주석으로 남긴다.

int N, K;
// 각각 칸의 내구도와 로봇의 존재 유무를 담당하는 deque들.
deque<int> board;
deque<bool> visit;

// 첫번째 단계에 해당하는 이동을 구현하는 함수.
// deque를 이용하면 더 쉽게 구현할수 있다.
void First()
{
    int cur = board.back();
    board.pop_back();
    board.push_front(cur);

    bool now = visit.back();
    visit.pop_back();
    visit.push_front(now);
    // 상술하였듯 N - 1칸은 로봇이 도달시 바로 내리므로
    // 어떤 상황에서도 비어있어야한다.
    visit[N - 1] = false;
}

// 2 ~ 3번째 단계를 구현하는 함수.
void Second_Third()
{  
    // 맨뒤칸(N - 1번째칸)의 조건은 다른곳과는 조금 다르기에 따로 구현했다.
    // 상술하였듯 N - 1칸은 언제나 비어있어야 하기 때문에 조건문에서도 뺄수 있고
    // 값을 갱신하지 않아도 된다.
    if (visit[N - 2] && board[N - 1] > 0)
    {
        --board[N - 1];
        visit[N - 2] = false;
        if (board[N - 1] == 0)
            --K;
    }
    // 다음 3가지의 조건에 해당된다면 현재 로봇의 위치를 한칸 이동시킴.
    
    // 1. 현재칸에 로봇이 존재.
    // 2. 다음칸에 로봇이 존재하지 않음.
    // 3. 다음칸의 내구도가 0보다 크다.
    for (int i = N - 3; i >= 0; --i)
        if (visit[i] && !visit[i + 1] && board[i + 1] > 0)
        {
            --board[i + 1];
            visit[i] = false;
            visit[i + 1] = true;
            if (board[i + 1] == 0)
                --K;
        }

    // 첫번째칸(올리는 위치)의 내구도가 0보다 크다면 로봇을 올린다.
    if (board[0] > 0)
    {
        visit[0] = true;
        --board[0];
        if (board[0] == 0)
            --K;
    }
}

void MakeAnswer()
{
    int answer = 0;
    while (K > 0)
    {
        ++answer;
        First();
        Second_Third();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    int num;
    for (int i = 0; i < 2 * N; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
    visit.resize(2 * N, false);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}