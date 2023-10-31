#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// 풀이.
// 말그대로 3자리수와 그때에 따른 스트라이크, 볼의 수가 주어질때 결과적으로
// 정답이 될수 있는 경우의 수를 출력하면 된다.
// 모두 다른 3자리수이기에 범위는 123 ~ 987이며, 모두 다른 3자리수여야 하고 0이 존재해서는 안된다.
// 위 경우의 맞는 수들을 먼저 걸러내고 그 이후 주어지는 스트라이크, 볼을 비교하여 마지막까지 남는
// 수들의 수를 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

bool board[988];
int N, cur, s, b;

// 초기에 수들을 걸러내는 함수.
bool CheckWrong(int num)
{
    string str = to_string(num);

    // 모두 다른 수들로 이루어져 있어야 하며, 0이 존재해서는 안된다.
    if (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]
        || str[0] == '0' || str[1] == '0' || str[2] == '0')
        return false;

    return true;
}

// 현재수 num과 주어지는 수 cur을 비교하는 함수.
bool ComposeNum(int num)
{
    int cur_s = 0, cur_b = 0;
    string from = to_string(cur);
    string to = to_string(num);

    // 각 자리수들을 비교한다.
    if (from[0] == to[0])
        ++cur_s;
    else if (from[0] == to[1] || from[0] == to[2])
        ++cur_b;

    if (from[1] == to[1])
        ++cur_s;
    else if (from[1] == to[0] || from[1] == to[2])
        ++cur_b;

    if (from[2] == to[2])
        ++cur_s;
    else if (from[2] == to[0] || from[2] == to[1])
        ++cur_b;

    // 주어진 스트라이크, 볼의 수와 현재 스트라이크, 볼의 수를 비교하여 출력한다.
    return cur_s == s && cur_b == b;
}

void MakeAnswer()
{
    memset(board, true, sizeof(board));
    // 123 ~ 987중 일단 한번 걸러낸다.
    for (int i = 123; i <= 987; ++i)
    {
        if (!CheckWrong(i))
            board[i] = false;
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> cur >> s >> b;

        // 123 ~ 987을 순회한다.
        for (int j = 123; j <= 987; ++j)
        {
            // 이미 걸러진 수라면 무시한다.
            if (!board[j])
                continue;

            // 현재 주어진 스트라이크, 볼의 개수와 비교결과가 다르다면 걸러낸다.
            if (!ComposeNum(j))
                board[j] = false;
        }
    }

    int answer = 0;
    // 마지막까지 남은 수들의 갯수를 출력한다.
    for (int i = 123; i <= 987; ++i)
    {
        if (board[i])
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}