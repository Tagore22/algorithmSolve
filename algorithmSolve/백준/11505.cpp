#include <iostream>

using namespace std;

// Ǯ��.
// ����Ʈ��, �� ���׸�Ʈ Ʈ���� �����̴�.
// ������ �˰� ������ �׳� ���Ը� �ϸ� �Ǵ� ������ �����ε� ������ ���ؾ� �Ѵٴ� �� �ϳ��� �ٸ���.
// ����, �α����� ���������� �� ���� �ִ� 100���� �����ϱ� ������ ������ ����� int���� ����� long long��
// �ʿ��ϴ�. �Ź� long long���� Ÿ�Ժ�ȯ�� �����Ƽ� �׳� long long�� �迭�� ����Ͽ���.

// �ڼ��� ������ �ּ����� �����.

const int MAX_NUM = 1000001;
const int DIV_NUM = 1000000007;
int board[MAX_NUM];
long long ran[MAX_NUM * 4];
int N, M, K;

long long Init(int from, int to, int node)
{
    // ���۰� ���� ������ ��, �� �������� �ٴٶ����� ���� �ʱ�ȭ�Ѵ�.
    if (from == to)
        return ran[node] = board[from];

    // �ѷ� ������ �ݺ�.
    int mid = (from + to) / 2;
    long long left = Init(from, mid, node * 2);
    long long right = Init(mid + 1, to, node * 2 + 1);
    return ran[node] = left * right % DIV_NUM;
}

long long Query(int from, int to, int q_from, int q_to, int node)
{
    // ���ϰ��� �ϴ� �������� �ƿ� �ٸ��ٸ� �����Ѵ�.
    if (to < q_from || q_to < from)
        return 1;
    // ���� �������� ���ϰ����ϴ� �������ȿ� �����Ѵٸ� ���� ���� ����Ѵ�.
    if (from <= q_from && q_to <= to)
        return ran[node];

    // �ѷ� ������ �ݺ�.
    int mid = (q_from + q_to) / 2;
    long long left = Query(from, to, q_from, mid, node * 2);
    long long right = Query(from, to, mid + 1, q_to, node * 2 + 1);
    return left * right % DIV_NUM;;
}

long long Update(int from, int to, int idx, int newvalue, int node)
{
    // ������Ʈ�ϰ��� �ϴ� ���� ���� �ƿ� ��ġ���� �ʴ´ٸ� ���� ������Ʈ ���ʿ���� ���簪�� ��ȯ�Ѵ�.
    if (idx < from || to < idx)
        return ran[node];

    // Init�� ���������� �� �������� �ٴٶ��ٸ� ���� �����Ѵ�.
    if (from == to)
        return ran[node] = newvalue;

    // �ѷ� ������ �ݺ�.
    int mid = (from + to) / 2;
    long long left = Update(from, mid, idx, newvalue, node * 2);
    long long right = Update(mid + 1, to, idx, newvalue, node * 2 + 1);
    return ran[node] = left * right % DIV_NUM;
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    Init(1, N, 1);

    int a, b, c;
    for (int i = 0; i < M + K; ++i)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(1, N, b, c, 1);
        else
            cout << Query(b, c, 1, N, 1) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}