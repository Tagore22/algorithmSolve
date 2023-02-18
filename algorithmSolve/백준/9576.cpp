#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이
// 신청서를 정렬하여 줄수 있는 가장 많은 책의 수를 구하는 문제이다.
// 처음에는 신청서의 범위를 기준으로 잡아서 맞추지 못하였고, 생각해보니 어차피 앞에서 주기 때문에
// 신청서의 끝값이 적은 순으로 정렬을 하여야 앞에서부터 최대한 많은 양의 책을 줄수 있기 때문에
// 다시 말해, 범위 값이 아닌 신청서의 끝값을 기준으로 정렬해야했다. 또한 끝값이 같다면 시작값이 적은순으로 정렬한다.
// 그후 신청서의 시작값부터 끝값까지 순회하여 줄수 있는 책의 수를 체크하여 매 테스트 케이스마다 출력하면 된다.

// P.S 나 자신의 이해를 좀더 깊게 하기 위해 추가한다.
// 기본적으로 범위가 좁은 신청서의 학생에게 우선적으로 책을 주어야 하는데, 범위는 신청서의 끝값 - 시작값이라고 생각할수 있으나
// 실제로는 그렇지 않다. 앞에서부터(1번책부터) 책을 주기 때문에 끝값 자체가 범위가 된다. 그래서 시작값은 상관없이 끝값만을
// 기준으로 하여 정렬하면 된다.

vector<pair<int, int>> board;
int T, N, M;

bool CompareFunc(pair<int, int> lhs, pair<int, int> rhs)
{
    if (lhs.second != rhs.second)
        return lhs.second < rhs.second;
    else
        return lhs.first < rhs.first; // 시작값은 상관없기에 굳이 신경쓰지 않아도 된다.
}

void CalAnswer()
{
    sort(board.begin(), board.end(), CompareFunc);
    vector<bool> check(N + 1, true);
    int answer = 0;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = board[i].first; j <= board[i].second; ++j)
            if (check[j])
            {
                ++answer;
                check[j] = false;
                break;
            }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        int from, to;
        board.clear();
        for (int j = 0; j < M; ++j)
        {
            cin >> from >> to;
            board.push_back(make_pair(from, to));
        }
        CalAnswer();
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