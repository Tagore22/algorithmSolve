#include <iostream>

using namespace std;

// 풀이.
// 주어진 회전초밥들중 연속으로 K개를 집을때 집을수 있는 초밥종류의 최대를 출력하는 문제이다.
// 모든 초밥들을 연속으로 고르기 때문에 투포인터를 이용해서 간단한게 구현할수 있다.
// 다만 실수 하나를 해서 한 10분 헤맸는데 이는 후술한다.

// 자세한 설명은 주석으로 남긴다.

int board[3000000], sushi[3001];
int N, D, K, C;

void MakeAnswer()
{
    // 쿠폰으로 얻을수 있는 초밥과 0번째부터 K개의 초밥을 미리 확인하여 최종값 answer를
    // 초기화한다.
    sushi[C] = 1;
    int answer = 1;
    for (int iter = 0; iter < K; ++iter)
    {
        int here = board[iter];
        // 현재 초밥을 0개 집은 상태라면 가짓수가 1 증가한다.
        if (sushi[here] == 0)
            ++answer;
        // here번째 초밥을 집는다.
        ++sushi[here];
    }
    // 현재 집은 번호와 현재 놓은 번호, 현재 최대 수량을 초기화한다.
    // 이 이후는 위와 동일하다.
    int idx_b = K, cur = answer, idx_f = 0;
    for (int iter = 1; iter < N; ++iter)
    {
        int here = board[idx_b];
        // 현재 집은 초밥이 처음 집은 상태라면 가짓수가 1 증가한다.
        if (sushi[here] == 0)
            ++cur;
        // here번째 초밥을 집는다.
        ++sushi[here];
        int prev = board[idx_f];
        // prev번째 초밥을 놓는다.
        --sushi[prev];
        // 현재 놓은 초밥의 종류가 0개가 된다면 가짓수가 1 감소한다.
        if (sushi[prev] == 0)
            --cur;
        // 현재 가짓수와 최종답 answer를 비교하여 answer를 갱신한다.
        answer = max(answer, cur);
        // 놓은 번호와 집은 번호를 1씩 증가한다.
        // 다만 집은 번호는 무조건 배열을 한바퀴 돌아 처음으로 되돌아가기 때문에
        // 이에 따른 처리를 해준다.
        ++idx_f;
        idx_b = idx_b + 1 == N ? 0 : idx_b + 1;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}