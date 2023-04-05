#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ������ ��������. �켱 Ʈ�� ������� �־����� ������ Ʈ���� ������� �ʾ��� ���ɼ��� �ְ�,
// ������ 1���� ��Ʈ��� ���ɼ��� �־���. �׷��� ���ŷο쳪 ��� ������ �����ϵ� �θ������
// ���� �����Ͽ� ���������� ��� ������ ��ȸ�ϸ� ��Ʈ�� ã�ƾ� �Ѵ�.

// �� �ķδ� ������ȸ�� ���� ��ȣ�� ������ ��ȣ�� �����ذ��� �� ����� ��ġ�� ���ϵ�,
// ������ �ּҰ��� �ִ밪���� �����ذ��� �ִ��� �޸𸮸� �ٿ���.

// ���������� �� ������ ��ȸ�ϸ� �Ÿ��� �ִ밪�� �Ǵ� ������ �� �Ÿ����� ����ϸ� �ȴ�.

// ����� ����. ��Ʈ ����� ��ȣ�� �˾Ƴ��� �ϱ⿡ �θ� ����� �������� �Ű����Ѵ�.
struct node
{
    int parent = -1;
    int left;
    int right;
};

vector<pair<int, int>> tree;
node board[10001];
int N, row;

// ������ȸ�� �����ϴ� �Լ�. ����, ����, ���������� ��ȸ�ϸ� ����� ��ġ���� ����Ѵ�.
void LocateLeftFirst(int num, int level)
{
    if (board[num].left != -1)
        LocateLeftFirst(board[num].left, level + 1);

    // �޸𸮸� �Ƴ��� ���� �ּҰ��� �ִ밪���� ������.
    tree[level].first = min(tree[level].first, row);
    tree[level].second = max(tree[level].second, row);
    ++row;
    if (board[num].right != -1)
        LocateLeftFirst(board[num].right, level + 1);
}

void MakeAnswer()
{
    // �� ������ �ּҰ� �� �ִ밪�� �ʱ�ȭ. �ִ� 10000���� ��尡 �ֱ⿡ 15000������ �ϸ� ����ϴ�.
    tree.resize(N + 1, make_pair(15000, -15000));
    int root_num;
    
    // ��Ʈ ����� ��ȣ�� �˾ư��� ����.
    for (int i = 1; i <= N; ++i)
        if (board[i].parent == -1)
        {
            root_num = i;
            break;
        }
    row = 1;
    LocateLeftFirst(root_num, 1);

    // �� ������ ��ȸ�ϸ� �ּҰ��� �ִ밪�� ����, �� �Ÿ����� ����Ͽ� �������� �����Ѵ�.
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