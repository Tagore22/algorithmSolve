#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀이
// 1461번 도서관 문제와 비슷한 문제다. 두 수끼리 묶어 그 합을 최대화 시키려면 이왕이면 큰 두수끼리 묶어야 하는데 주의할점이 몇가지 있다.
// 
// 1. 양수는 양수끼리 묶는다.
// 2. 음수는 음수끼리 묶는다.
// 3. 양수는 0과 곱해서 절대로 커지지 않는다.
// 4. 음수는 0과 곱해서 더 커진다.

// 위 조건에 따라 음수는 0까지 처리를 하고 양수는 0을 제외한 순서까지 처리를 해야한다. 즉, 양수와 음수는 나누어야한다.
// 경계값 bound를 생성후 N개의 수를 입력받을때 해당 수가 0보다 작거나 같다면 bound를 증가시켜 위치를 조정한다.
// 그후 왼쪽부터(0부터) bound - 1까지 2칸씩 뛰며 두 수의 곱이 합보다 크다면 곱해주며 연산에 사용되었다는 뜻으로
// check를 true로 갱신시킨다. 오른쪽도(N-1부터) bound를 제외한 순서까지 진행하며 반복한다.
// 그후 check를 순회하며 아직 연산에 포함되지 않은 수들을 모두 더해 출력하면 된다.

int board[50];
bool check[50];
int N, bound = 0;

void MakeAnswer()
{
    int answer = 0;
    sort(board, board + N);

    for (int i = 0; i < bound - 1; i += 2)
        if (board[i] * board[i + 1] > board[i] + board[i + 1])
        {
            check[i] = true;
            check[i + 1] = true;
            answer += board[i] * board[i + 1];
        }

    for (int i = N - 1; i > bound; i -= 2)
        if (board[i] * board[i - 1] > board[i] + board[i - 1])
        {
            check[i] = true;
            check[i - 1] = true;
            answer += board[i] * board[i - 1];
        }

    for (int i = 0; i < N; ++i)
        if (!check[i])
            answer += board[i];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, false, sizeof(check));

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        if (board[i] <= 0)
            ++bound;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}