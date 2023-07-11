#include <iostream>

using namespace std;

// 풀이.
// 정말 짜증났던 문제다. 정확히 말하자면 나 스스로에게 짜증이 났지만.
// 문제 하나를 잘못봐서 한 4시간을 헤맸던것 같다. ㅠㅠ 문제를 잘좀 보자.
// 큰 틀은 아래와 같다. 다만 하나 추가해야하는 치명적인 부분이 있는데 바로 계란은 단 한번 부딪힌다는 것이다.

// 1. 0번째 계란부터 N - 1번째 계란까지 순회한다.
// 2. 순서에 상관없이 모든 계란을 때려본다(단한번단한번단한번단한번단한번단한번단한번). 다만 다음과 같을 경우 다음 계란으로 넘어간다.
// 2-1. 현재 계란이 부숴짐.
// 2-2. 다른 모든 계란이 부숴짐(때릴 계란이 없음).
// 2-3. 모든 계란을 때렸음.
// 3. N - 1번째 계란까지 행동한후 N에 도달하였다면 탈출한다.

// 이 풀이 말고도 if(cur == N)을 기저조건으로 하며 ans를 반환하는 풀이도 존재하나
// 그렇게 되면 0 ~ 8까지 모든 재귀를 호출해야함으로 속도가 느리다.
// 따라서 현재 내구도가 0이상인 계란의 순서로 바로 이동하는 풀이가 좋은데 그렇게 되면
// ans를 반환할수 없기에 전역변수 answer을 갱신하는 이 풀이를 사용해야 한다.

// 자세한 설명은 주석으로 남긴다.

int S[8], W[8];
int N, answer = 0;

void BackTrack(int cur, int sum)
{
    for (int i = 0; i < N; ++i)
    {
        // 현재 계란과 같거나 이미 내구도가 떨어진 계란이라면 무시한다.
        if (i == cur || S[i] <= 0)
            continue;

        // 현재 계란과 부딪힐 계란을 부딪혀 내구도가 감소한다.
        S[cur] -= W[i];
        S[i] -= W[cur];
        // 깨진 계란 개수 확인.
        int here = S[cur] <= 0 ? 1 : 0;
        int there = S[i] <= 0 ? 1 : 0;
        // 여기서 next_sum을 새로 만들지 않고 기존의 sum을 이용하면 이 이후의 연산이 꼬인다. 주의할것.
        int next_sum = sum + here + there;
        // 현재 깨진 계란의 수를 최종값과 비교하여 갱신한다.
        answer = max(answer, next_sum);
        // 현재 계란 이후(오른쪽의) 계란중 내구도가 1이상인 계란으로 바로 넘어간다.
        for (int iter = cur + 1; iter < N; ++iter)
            if (S[iter] > 0)
            {
                BackTrack(iter, next_sum);
                break;
            }
        // 이 이후의 연산을 위해 계란의 내구도를 복원시킨다.
        S[cur] += W[i];
        S[i] += W[cur];
    }
}

void MakeAnswer()
{
    BackTrack(0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> S[i] >> W[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}