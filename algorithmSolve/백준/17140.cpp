#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 어렵진 않은데 이 조건 저 조건이 덕지덕지 붙은 문제다.
// 문제의 큰 틀은 다음과 같다.

// 1. 2차원 배열의 가장 긴 행의 길이와 열의 길이를 비교하여
// 행이 길다면 각 행을 정렬하고, 열이 길다면 각 열을 정렬한다.
// 2. 정렬은 각 수와 그 등장횟수인데 등장횟수가 길수록 뒤이며 그 수가 같다면 수가 클수록 뒤이다.
// 3. 정렬을 마친후 다시 가장 긴 행의 길이와 가장 긴 열의 길이를 갱신하고 이것을 반복한다.
// 4. 만약 100번을 연산해도 답을 찾을수 없다면 -1을 출력한다.

// 위 상술하였듯 복잡하지만 어려운건 아니기 때문에 집중하면 한번에 풀수 있다.
// 자세한 설명은 주석으로 남긴다.


int board[101][101];
int visit[101], len[101];
int R, C, K, row_num, col_num;

// 행의 길이와 열의 길이를 비교하여 한번의 정렬을 구현하는 함수.
int CalAnswer(int time)
{
    // 답을 찾았다면 그 순간 반환한다.
    if (board[R][C] == K)
        return time;
    // 100번을 연산해도 찾을수 없다면 -1을 반환한다.
    if (time > 100)
        return -1;

    int max_len = 0;
    // 행의 길이가 열의 길이보다 크거나 같다면 모든 행을 정렬한다.
    if (col_num >= row_num)
    {
        for (int i = 1; i <= col_num; ++i)
        {
            memset(visit, 0, sizeof(visit));
            // 각 행을 순회하며 0을 제외한 모든 수의 등장횟수를 파악한다.
            for (int j = 1; j <= row_num; ++j)
            {
                if (board[i][j] == 0)
                    continue;

                int cur = board[i][j];
                ++visit[cur];
            }

            // 위에서 파악한 각 수와 그 등장횟수를 정렬하여 현재 행의 길이를 계산하고
            // 행들의 최대 길이 max_len을 갱신한다.
            vector<pair<int, int>> ans;
            for (int iter = 1; iter <= 100; ++iter)
                if (visit[iter] != 0)
                    ans.push_back(make_pair(visit[iter], iter));
            sort(ans.begin(), ans.end());
            len[i] = ans.size() * 2;
            max_len = max(max_len, len[i]);

            // 위에서 구한 순서대로 현재 행을 갱신한다.
            for (int iter = 0; iter < ans.size(); ++iter)
            {
                board[i][iter * 2 + 1] = ans[iter].second;
                board[i][iter * 2 + 2] = ans[iter].first;
            }
        }

        // 각 행들중 최대 길이보다 작은 행들의 뒤에 0을 추가해준다.
        for (int i = 1; i <= col_num; ++i)
            for (int j = len[i] + 1; j <= max_len; ++j)
                board[i][j] = 0;
        // 가장 긴 행의 길이 갱신.
        row_num = max_len;
    }
    // 행의 길이가 열의 길이보다 작다면 모든 열을 정렬한다.
    else
    {
        for (int j = 1; j <= row_num; ++j)
        {
            memset(visit, 0, sizeof(visit));
            // 각 열을 순회하며 0을 제외한 모든 수의 등장횟수를 파악한다.
            for (int i = 1; i <= col_num; ++i)
            {
                if (board[i][j] == 0)
                    continue;

                int cur = board[i][j];
                ++visit[cur];
            }

            // 위에서 파악한 각 수와 그 등장횟수를 정렬하여 현재 열의 길이를 계산하고
            // 열들의 최대 길이 max_len을 갱신한다.
            vector<pair<int, int>> ans;
            for (int iter = 1; iter <= 100; ++iter)
                if (visit[iter] != 0)
                    ans.push_back(make_pair(visit[iter], iter));
            sort(ans.begin(), ans.end());
            len[j] = ans.size() * 2;
            max_len = max(max_len, len[j]);

            // 위에서 구한 순서대로 현재 열을 갱신한다.
            for (int iter = 0; iter < ans.size(); ++iter)
            {
                board[iter * 2 + 1][j] = ans[iter].second;
                board[iter * 2 + 2][j] = ans[iter].first;
            }
        }

        // 각 열들중 최대 길이보다 작은 열들의 뒤에 0을 추가해준다.
        for (int j = 1; j <= row_num; ++j)
            for (int i = len[j] + 1; i <= max_len; ++i)
                board[i][j] = 0;
        // 가장 긴 열의 길이 갱신.
        col_num = max_len;
    }
    return CalAnswer(time + 1);
}

void MakeAnswer()
{
    row_num = col_num = 3;
    int answer = CalAnswer(0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> K;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}