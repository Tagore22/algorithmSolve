#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// ��Ʊ⵵ ������ ���� �߸������ؼ� ���� ��� ������. 18�ñ��� Ǯ����. T^T.
// �켱���� ť�� �̿��ؼ� ������ Ǫ�°� �¾Ҵ�. �ٸ� 2���� ������ �ϳ��� ť���� Ǯ���� �ߴµ�
// �װ� �Ұ����� ���̾��� ť�� 2���� ��������ߴ�. Ǯ�̰� �� �ּ����� ������ڴ�.
// ����, �̰����� ��¤����� ���Ҵ� ��������.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    // ���� id, �ɸ��� �ð�(������ ��), ������ ��ġ.
    int id;
    long long num;
    int w;
};

// ���뿡�� �������� ����. �켱���� ť���� ���Ǳ� ������ ��� ������
// ���ݴ�� �Ǿ�� �Ѵ�.
struct out_cmp
{
    bool operator()(const pos& a, const pos& b)
    {
        // �ð��� �ٸ��ٸ� �ð��� ū���� �տ� �д�. ����ߵ� �켱����ť�� ���ݴ��.
        if (a.num != b.num)
            return a.num > b.num;
        // �ð��� ���ٸ� ���밡 �������� �տ� �д�. ���������� ���ݴ��.
        else
            return a.w < b.w;
    }
};

// ����� ������ ����. �켱���� ť���� ���Ǳ� ������ ��� ������
// ���ݴ�� �Ǿ�� �Ѵ�.
struct in_cmp
{
    bool operator()(const pos& a, const pos& b)
    {
        // �ð��� �ٸ��ٸ� �ð��� ū���� �տ� �д�. ����ߵ� �켱����ť�� ���ݴ��.
        if (a.num != b.num)
            return a.num > b.num;
        // �ð��� ���ٸ� ���밡 ū���� �տ� �д�. ���������� ���ݴ��.
        else
            return a.w > b.w;
    }
};

int N, K, id, num;

void MakeAnswer()
{
    // ���� ������ ť�� �������� ť.
    priority_queue<pos, vector<pos>, in_cmp> in_que;
    priority_queue<pos, vector<pos>, out_cmp> out_que;

    // ���� ť�� �ð��� id�� 0����, ������ ���� �־���´�.
    // ���� ������� �ð��� �������� �� �̿��� ������ ��� �����ؾ��ϳ� �׷��� ������ ť�� ��ȸ���Ѿ��Ѵ�.
    // �׷��� �ʰ� ���� ���� ���� �������� ���� ��ȸ�� ���´�. �ٸ� ���� ���� 0���� �߱⿡ �߰������� ����������
    // ������ ���밪�� �����ȴ�.
    // ���⼭ ġ������ �Ǽ��� �ϳ� �ߴµ� K���� ��ȸ�� N���� �߸� �����߾���. ��....
    for (int i = 0; i < K; ++i)
        in_que.push(pos{ 0, 0, i });

    for (int i = 0; i < N; ++i)
    {
        cin >> id >> num;
        pos prev = in_que.top();
        in_que.pop();

        // id�� ������ ������, ����Ѵ�� �߰��Ǵ� ���� �ð��� ������ ���� �ð��� �߰��ؼ� �ð��� ����� �����Ѵ�.
        // ���������� ���� ���� ��ȭ�� ����.
        in_que.push(pos{ id, num + prev.num, prev.w });
        out_que.push(pos{ id, num + prev.num, prev.w });
    }

    long long answer = 0, idx = 1;
    // ������ ť�� ���͵��� ���������� ����Ͽ� ����Ѵ�.
    while (!out_que.empty())
    {
        answer += out_que.top().id * idx;
        ++idx;
        out_que.pop();
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}