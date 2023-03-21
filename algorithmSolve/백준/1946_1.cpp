#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 기존의 1946번 풀이보다 더 빠르고 용량도 적게 차지하는 풀이.
// map도 없고, 반복자도 없으며 로직도 더 간단하다.
// y값을 기준으로 정렬한다음 값들을 순회하며, 현재 x값보다 더 적은 원소를 만날시
// 답이 1씩 증가하고 현재 x값이 갱신된다.

vector<pair<int, int>> board;
int T, N;

void MakeAnswer()
{
    int y, x, answer;
    for (int i = 0; i < T; ++i)
    {
        board.clear();
        cin >> N;
        for (int j = 0; j < N; ++j)
        {
            cin >> y >> x;
            board.push_back(make_pair(y, x));
        }

        // 모든 원소값들을 y값을 기준으로 정렬한다.
        sort(board.begin(), board.end());

        answer = 1; // y값이 1인 원소는 최소한 무조건 된다.
        int cur = board[0].second; // 무조건 되는 원소의 x값보다 작아야 한다.
        for (int j = 1; j < N; ++j)
            if (cur > board[j].second)
            {
                // 더 작은 값을 발견했다면 최종값 answer가 1증가하며, 최신값이 cur이 갱신한다. (점점 감소함)
                ++answer;
                cur = board[j].second;
            }
        cout << answer << '\n';
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