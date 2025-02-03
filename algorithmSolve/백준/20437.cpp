#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 골5 ~ 골4에서 이런 주먹구구식 느낌의 문제가 많았다. 처음에는 생각을 복잡하게 했다.
// 무조건 처음 등장한 문자부터 셀수도 없는 것이 뒤에서부터 셀때 더 크거나 작을수도 있기 때문이다.
// 따라서 모든 원소값을 같은 알파벳끼리 저장하여 후에 따로 비교하여 큰값과 작은값을 계산했다.

// 자세한 설명은 주석으로 남긴다.

const int MAXNUM = 26;
int T;

void MakeAnswer()
{
    string str;
    int K, min_ans, max_ans; // 가장 작은 값과 가장 큰 값. 매번 초기화해주어야 한다.
    vector<int> board[MAXNUM]; // 알파벳별로 등장한 인덱스값들을 저장하는 벡터 배열. 매번 초기화해주어야 한다.
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str >> K;
        // 상술한 벡터 배열과 값들의 초기화.
        for (int i = 0; i < MAXNUM; ++i)
            board[i].clear();
        min_ans = 10001, max_ans = -1;
        // 모든 문자들을 순회하며 등장 위치를 벡터 배열에 저장한다.
        for (int i = 0; i < str.size(); ++i)
        {
            int idx = str[i] - 'a';
            board[idx].push_back(i);
        }
        // 모든 알파벳들을 순회하며 답을 찾는다.
        for (int i = 0; i < MAXNUM; ++i)
        {
            // 해당 알파벳이 K개보다 적게 등장했다면 무시한다.
            if (board[i].size() < K)
                continue;
            // j번째 위치값과 j - K + 1번째 위치값을 비교하여 값들을 갱신한다. 정확히 K개가 포함되어야하므로
            // board[i][j] - board[i][j - K + 1] + 1의 점화식이 증명된다.
            for (int j = board[i].size() - 1; j >= K - 1; --j)
            {
                min_ans = min(min_ans, board[i][j] - board[i][j - K + 1] + 1);
                max_ans = max(max_ans, board[i][j] - board[i][j - K + 1] + 1);
            }
        }
        // K개이상 등장한 문자가 없어 값의 변동이 없을때에는 -1을 출력한다.
        if (min_ans == 10001)
            cout << -1 << '\n';
        // 그 외에는 작은값과 큰값을 순서대로 출력한다.
        else
            cout << min_ans << ' ' << max_ans << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}