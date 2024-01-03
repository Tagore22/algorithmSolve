#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 가장 가까운 공통 조상을 찾는 문제다. 보통은 부모 배열을 이용하여 위로 같은 원소를 만날때까지
// 쭉쭉 올라가면 될것 같지만 실제로는 그렇지 않다. 왜냐하면 깊이가 다를 경우가 존재하기 때문이다.
// 따라서 각 원소의 부모와 깊이를 계산하여 깊이가 같을때까지 어느 한쪽을 끌어올려야 한다.
// 그 후부터는 상술한대로 두 원소를 하나씩 부모쪽으로 끌어올리며 같을때까지 반복하면 된다.
// 다만 매번 노드들의 부모 자식 입력을 받을때 기존의 값들을 갱신해주어야 한다.
// 이 부분에서 한가지 실수를 했는데 자식 깊이의 초기값을 부모의 깊이값으로 해주었다는 것이다.
// 부모의 깊이값 + 1로 해주어야하는데 후... 이것때문에 30분은 헤맨것 같다. 

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board;
vector<int> child;
int T, N;

// 두 노드의 가장 가까운 공통 조상을 찾는 함수.
void FindParent(int a, int b)
{
    while (true)
    {
        // b의 깊이가 더 깊다면 한단계 끌어올린다.
        if (board[a].second < board[b].second)
        {
            b = board[b].first;
        }
        // a의 깊이가 더 깊다면 한단계 끌어올린다.
        else if (board[a].second > board[b].second)
        {
            a = board[a].first;
        }
        // 둘의 깊이가 같다면 둘다 부모쪽으로 끌어올린다.
        else
        {
            a = board[a].first;
            b = board[b].first;
        }
        // 두 노드가 같다면 출력한다.
        if (a == b)
        {
            cout << a << '\n';
            return;
        }
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 벡터를 비우고 초기화한다.
        board.clear();
        child.clear();
        cin >> N;
        board.resize(N + 1, make_pair(0, 0));
        child.resize(N + 1, -1);
        int p, c;
        for (int node = 0; node < N - 1; ++node)
        {
            cin >> p >> c;
            // 각 부모와 깊이 정보를 저장한다.
            board[c] = make_pair(p, board[p].second + 1);
            // 현재 자식의 자식들의 깊이값을 갱신한다.
            child[p] = c;
            int d = board[c].second + 1;
            while (child[c] != -1)
            {
                c = child[c];
                board[c].second = d;
                ++d;
            }
        }
        cin >> p >> c;
        FindParent(p, c);
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