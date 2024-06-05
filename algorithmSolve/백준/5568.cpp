#include <iostream>
#include <set>
#include <string>

using namespace std;

// 풀이.
// 이 문제를 건너뛰고 다른 문제들이 푼걸 보니 어떻게 푸는지 감이 안왔던 문제였던것 같다. 풀어서 다행이다.
// DP와 재귀, 백트래킹을 기존과는 조금 다른 방식으로 뒤틀어 풀어야했다. 랜덤 방식으로 K개의 수를 골라서 하나의 정수를
// 만드는데 그것이 이미 존재한다면 무시해야하기 때문이다. 다만 만들수 있는 수가 1억 - 1이기 때문에 int로
// DP배열을 만들기 어려워 Set<>을 사용해야했다.

// 자세한 설명은 주석으로 남긴다.

set<string> dp;
bool check[10] = { false, };
int board[10];
int N, K, answer = 0;

// 모든 조합을 찾아보는 재귀함수.
void CalNum(int num, string str)
{
    // K개를 모두 골랐다면.
    if (num == K)
    {
        // 현재 조합을 이전에 고르지 않았다면.
        if (dp.find(str) == dp.end())
        {
            // 최종값 answer를 1 증가하고, set<>에 현재 조합을 추가한다.
            ++answer;
            dp.insert(str);
        }
        return;
    }

    // 모든 정수(카드)를 순회한다.
    for (int i = 0; i < N; ++i)
    {
        // 현재 고르지 않은 정수(카드)라면
        if (!check[i])
        {
            check[i] = true;                             // 선택유무를 수정하고
            CalNum(num + 1, str + to_string(board[i]));  // 다음번째 카드를 고른다.
            check[i] = false;                            // 이후 선택유무를 복구시킨다.
        }
    }
}

void MakeAnswer()
{
    CalNum(0, "");
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}