#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이.
// 어렵게 생각해서 한참 헤맸다. 매개 변수 탐색을 통해 거리값을 주는것까지는 어렵지 않게 생각해내었으나
// 그 이후 넘겨진 값으로 휴게소를 세우는 로직이 생각나질 않았다. 0부터 거리값만큼 + 해서 해야하나 이런저런
// 생각이 났다. 결과적으로는 각 휴게소 사이의 값들을 구해 거리값으로 나누어 만들수 있는 개수만을 따지면 되었다.

// 자세한 설명은 주석으로 남긴다.

int N, M, L;
vector<int> board;

// 거리값 num으로 M개의 휴게소를 추가적으로 세울수 있는지 확인하는 함수.
bool CheckFunc(int num)
{
    int ans = 0;
    // 각 휴게소간의 차이값들을 순회하며 추가적으로 세울수 있는 휴게소의 수를 구한다.
    for (int i = 0; i < board.size() - 1; ++i)
    {
        int dist = board[i + 1] - board[i];
        ans += dist / num;
        // 만약 나머지값이 0이라면 이미 세워진 휴게소까지 포함되므로 한개를 뺀다.
        ans = dist % num == 0 ? ans - 1 : ans;
    }
    return ans <= M;
}

void MakeAnswer()
{
    // 각 휴게소간의 거리를 구하기 위해 0과 L을 추가해준다.
    board.push_back(0);
    board.push_back(L);
    sort(board.begin(), board.end());

    int l = 1, r = L;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (CheckFunc(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    // 이 부분에서 조금 헤매었다. 생각해보면 간단한것인데 만약 CheckFunc 함수가 성공한다면 
    // r은 r - 1이 되어 다시 while문으로 돌아간다. 이 상태에서 정답은 r이며, 마지막
    // r과 l이 동일할때에도 성공했다면 r은 다시 r - 1로, 실패했다면 그 이전 r값인 r + 1이
    // 정답이 된다. 결과적으로 r + 1을 출력하면 된다.
    cout << r + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> L;
    for (int i = 0; i < N; ++i)
    {
        int here;
        cin >> here;
        board.push_back(here);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}