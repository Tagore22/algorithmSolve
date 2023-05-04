#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 스택을 이용한 구현 문제인데 규칙이 생각나질 않아서 의외로 시간을 많이 썼다.
// 하술하겠으나 조금더 다듬어 쓰기 위해 미리 한번 더 원리를 적는다.

// 1. 시작점 cur이 있다. 초기값은 0번째 높이값.
// 2. 1번째 원소부터 W - 1번째 원소까지 순회를 하되 다음과 같은 조건문을 거친다.
// 2-1. 현재값이 cur보다 크거나 같다면 더이상 빗물을 받을 공간이 존재하지 않기에
// 스택에 담긴 모든 값들을 cur에서 빼고 그 값을 최종값 answer에 더한다.
// 2-2. 그렇지 않다면 그냥 스택에 현재값을 추가하고 넘어간다.
// 3. W - 1번째까지 순회가 끝난 후 혹여나 스택이 비어있지 않다면 cur을 스택의 맨 위값으로
// 다시 초기화한다.
// 4. 그 후 스택의 값을 하나 빼서 cur과 비교하는데 이는 스택이 빌때까지 진행된다.
// 4-1. cur이 현재 스택값보다 크다면 cur - 스택값을 answer에 더한다.
// 4-2. 더 작다면 현재 스택값이 새로운 cur이 된다.
// 5. 순회가 끝난후 최종값 answer을 출력한다.

// 자세한 설명은 주석으로 남긴다.

int board[500];
int H, W;


// cur의 시작은 board[0]이며 스택에 board[0]이 들어가있음.

// 현재값이 cur보다 같거나 크다면
// 스택에 있는 모든 값들을 cur과 비교하여 answer을 증강.
// 현재값이 cur이 된다.

// 현재값을 스택에 넣는다.

// for문(상술한 내용)이 끝난후 스택의 맨 위를 저장후
// 저장된 수보다 스택의 수가 작다면 answer를 증강한다.
// 저장된 수와 같거나 크다면 값을 교체한다.
// 스택이 빌때까지 반복.

void MakeAnswer()
{
    stack<int> sta;
    sta.push(board[0]);
    int cur = board[0], answer = 0;
    for (int i = 1; i < W; ++i)
    {
        if (board[i] >= cur)
        {
            while (!sta.empty())
            {
                int now = sta.top();
                sta.pop();
                answer += cur - now;
            }
            cur = board[i];
        }

        sta.push(board[i]);
    }


    // 문제의 예시로 주어진것처럼 빗물을 담을 공간이 존재하나 cur보다 크진 않아서
    // 무시된 부분이 있을수 있다. 그렇기에 스택을 순회하며 공간이 존재하는지 확인한다.
    if (!sta.empty())
    {
        cur = sta.top();
        sta.pop();
    }

    while (!sta.empty())
    {
        int now = sta.top();
        sta.pop();

        if (cur > now)
            answer += cur - now;
        else
            cur = now;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    for (int i = 0; i < W; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}