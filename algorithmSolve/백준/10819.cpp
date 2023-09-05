#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 얼핏보면 그리디하게 풀수 있을것 같으나 실제로는 그렇지 않다.
// 따라서 완전탐색을 사용해야한다. 다만 보통 완전탐색을 할때에는 중복을 막기 위해
// dp를 같이 사용하나 이번 문제는 중복이 존재하지 않기에 dp를 사용하지 않는다.
// 풀이는 의외로 간단한데 최대 N개의 수들중 중복을 방지하여 한개씩 골라가면 된다.
// |a[0] - a[1]| + |a[1] - a[2]| ... |a[N - 2] - a[N - 1]|을 이루는 점화식에 각 순서대로 하나씩
// 그 값을 골라서 그 결과의 최대값을 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

// P.S solved를 보면 알겠지만 이전 풀이에는 BackTrack()의 매개변수가 2개였다. 근데 막상 정리하며 보니
// 첫번째 매개변수 idx가 필요없어서 다시 풀었는데 속도가 오히려 떨어졌다. 역시 자잘한 속도차이는 신경쓰지
// 말아야겠다. 맹신하지말자.

int board[8];
bool check[8];
int N;

// 모든 조합을 구현하는 함수.
int BackTrack(int prev_num)
{
    int ans = 0;
    // 0 ~ N - 1번째 원소를 순회하며 아직 사용하지 않은 원소를 찾아 다음 수로 대입해보며
    // 나아간다. 결과값의 최대값을 반환한다.
    for (int i = 0; i < N; ++i)
    {
        if (check[i])
            continue;
        check[i] = true;
        ans = max(ans, BackTrack(i) + abs(board[prev_num] - board[i]));
        check[i] = false;
    }
    return ans;
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        check[i] = true;
        answer = max(answer, BackTrack(i));
        check[i] = false;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}