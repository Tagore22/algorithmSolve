#include <iostream>

using namespace std;

// Ǯ��.
// �������� ���� Ʈ�� ������ ���Դ�.
// ���� Ʈ�� ������ �������� �����߱⿡ ���� ���� �ɷȴ�.

// ���� Ʈ���� ���� Ʈ���� ���� �迭�� ���� ���� ���� ���ϱ� ������ ����� logN�̴�.
// �ٸ� ���� �Ź� ������ �ѷ� ������ ���� �˻�ó�� ���� ���� ã�´�.

// �� ������ ���� Ʈ���� �˸� ����� ����, �� �״�� ���Ը� �ϸ� �Ǵ� �����̱⿡ �ּ��� ����
// �ٽ� �ѹ� ������ Ȯ���� �����ؾ߰ڴ�.


int board[100000];

// ���� Ʈ���� from ~ to�� �ش��ϴ� ������ �迭�� ���� Ʈ���� ��� �����ϱ⿡ �迭�� ũ�Ⱑ N * 4�� ���Ѵ�.
pair<int, int> RQ[400000]; // �ּ�, �ִ�.
int N, M;

// ���� Ʈ���� �ʱ�ȭ �Լ�. 
pair<int, int> Init(int node, int from, int to)
{
    // �� �Ѱ��� ���Ҹ� ����Ű��, ���� ���� �������� �����Դٸ� �� ���� ���ʰ��� �ȴ�.
    if (from == to)
        return RQ[node] = make_pair(board[from], board[from]);

    int mid = (from + to) / 2;
    
    // ����Ͽ��� ���� Ʈ���� ������ �ѷ� ������ ��������.
    pair<int, int> lhs = Init(node * 2, from, mid);
    pair<int, int> rhs = Init(node * 2 + 1, mid + 1, to);

    // �������� ã�� ���簪�� �������ش�.
    return RQ[node] = make_pair(min(lhs.first, rhs.first), max(lhs.second, rhs.second));
}


// �������� ã�� �Լ�. �Ű������� ���� ã���� �ϴ� ����, ���� ����ȣ(1���� ����), ���� ����� �������̴�.
pair<int, int> Query(int left, int right, int node, int from, int to)
{
    // ã���� �ϴ� ������ ���� ����� ������ �ƿ� ��ġ�� �ʴ´ٸ� �����Ѵ�.
    if (left > to || right < from)
        return make_pair(1000000001, 0);

    // ã���� �ϴ� ������ ���� ��� ������ �ڵ��´ٸ� ���� ���� ��ȯ�Ѵ�.
    else if (left <= from && to <= right)
        return RQ[node];

    // ���� Ž��.
    int mid = (from + to) / 2;
    pair<int, int> lhs = Query(left, right, node * 2, from, mid);
    pair<int, int> rhs = Query(left, right, node * 2 + 1, mid + 1, to);

    // ���� ���� ��ȯ�Ѵ�.
    return make_pair(min(lhs.first, rhs.first), max(lhs.second, rhs.second));
}

void MakeAnswer()
{
    Init(1, 0, N - 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to;
        cin >> from >> to;
        pair<int, int> ans = Query(from - 1, to - 1, 1, 0, N - 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}