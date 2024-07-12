#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이. 
// 크게 어렵진 않았다. 어제 푼 17609번 문제처럼 지혜 하나를 짜내야 하는 문제다. 사대와 동물의 위치가 최대
// 10만씩 주어지기 때문에 주먹구구식으로 생각하자면 10만 * 10만으로 최대 100억의 연산량을 필요로 하는데
// 이러면 시간초과에 걸린다. 따라서 이걸 하나를 지혜로 해결해야 한다. 아래 풀이는 이분 탐색을 사용하였다.
// 사대는 어차피 y값이 모두 0이기 때문에 x값만 생각하면 되는데 사대의 위치를 정렬한 상태에서 동물들의 위치를
// 받는다. 이때 동물의 x값에서 가장 가까운 사대의 x값을 찾는다. lower_bound나 upper_bound나 크게 상관은 없다.
// 중요한건 가장 가까운 왼쪽과 오른쪽 사대를 찾는 것이다. 이후 각 사대와의 거리를 구하고 이것이 L보다 작거나 크다면
// 사거리내에 존재하는 것이다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int M, N, L;

// 어차피 y값은 상관이 없다. 각 사대의 y값이 0이기 때문이다. 
// 각 동물의 위치에서 x값과 사대의 x값을 비교하여 가장 가까운 사대를 찾는다. 
// 그 사대와의 거리를 비교하여 사거리내에 들어있는지 확인한다.

// idx번째 사대와 좌표값이 x, y인 동물의 거리를 구하는 함수.
bool FindRange(int idx, int x, int y)
{
    // 만약 인덱스값이 벗어났다면 무시한다.
    if (idx < 0 || idx >= M)
        return false;

    return L >= abs(board[idx] - x) + y;
}

void MakeAnswer()
{
    // 이분탐색을 위한 정렬.
    sort(board.begin(), board.end());
    int x, y, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        // lower_bound로 가장 가까운 오른쪽 사대를 찾는다.
        int idx = lower_bound(board.begin(), board.end(), x) - board.begin();
        // 왼쪽 혹은 오른쪽 사대와의 거리를 구하고 사거리내에 존재한다면 최종답 answer를 1 증가시킨다.
        if (FindRange(idx - 1, x, y) || FindRange(idx, x, y))
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N >> L;
    int cur;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        board.push_back(cur);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}