#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 복잡한 문제였다. 우선 트리 문제답게 주어지는 순으로 트리가 연결되지 않았을 가능성도 있고,
// 무조건 1번이 루트라는 가능성도 있었다. 그래서 번거로우나 모든 노드들을 연결하되 부모노드까지
// 따로 구현하여 최종적으로 모든 노드들을 순회하며 루트를 찾아야 한다.

// 그 후로는 중위순회로 열의 번호와 레벨의 번호를 조절해가며 각 노드의 위치를 구하되,
// 레벨의 최소값과 최대값만들 갱신해가며 최대한 메모리를 줄였다.

// 마지막으로 각 레벨을 순회하며 거리가 최대값이 되는 레벨과 그 거리값을 출력하면 된다.

// 노드의 구현. 루트 노드의 번호를 알아내야 하기에 부모 노드의 구현까지 신경써야한다.
struct node
{
    int parent = -1;
    int left;
    int right;
};

vector<pair<int, int>> tree;
node board[10001];
int N, row;

// 중위순회를 구현하는 함수. 왼쪽, 현재, 오른쪽으로 순회하며 노드의 위치값을 계산한다.
void LocateLeftFirst(int num, int level)
{
    if (board[num].left != -1)
        LocateLeftFirst(board[num].left, level + 1);

    // 메모리를 아끼기 위해 최소값과 최대값만을 가진다.
    tree[level].first = min(tree[level].first, row);
    tree[level].second = max(tree[level].second, row);
    ++row;
    if (board[num].right != -1)
        LocateLeftFirst(board[num].right, level + 1);
}

void MakeAnswer()
{
    // 각 레벨별 최소값 및 최대값의 초기화. 최대 10000개의 노드가 있기에 15000씩으로 하면 충분하다.
    tree.resize(N + 1, make_pair(15000, -15000));
    int root_num;
    
    // 루트 노드의 번호를 알아가는 과정.
    for (int i = 1; i <= N; ++i)
        if (board[i].parent == -1)
        {
            root_num = i;
            break;
        }
    row = 1;
    LocateLeftFirst(root_num, 1);

    // 각 레벨을 순회하며 최소값과 최대값의 차이, 즉 거리값을 계산하여 최종답을 갱신한다.
    pair<int, int> answer = make_pair(0, -1);
    int cur;
    for (int i = 1; i <= N; ++i)
    {
        if (tree[i] == make_pair(15000, -15000))
            break;
        cur = abs(tree[i].second - tree[i].first) + 1;
        answer = cur > answer.second ? make_pair(i, cur) : answer;
    }

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int parent, left, right;
    for (int i = 0; i < N; ++i)
    {
        cin >> parent >> left >> right;
        board[parent].left = left;
        board[parent].right = right;
        if (left != -1)
            board[left].parent = parent;
        if (right != -1)
            board[right].parent = parent;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}