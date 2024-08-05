#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ó������ BFS�� Ǯ���� �ߴ� �����̴�. �׷����� Ʈ�����Ŀ� ������ ���� ���� ������ �����ؼ�
// �ϳ��� ���� �ö󰡸鼭 ����Ϸ��� �ߴ�. �׷��� �� �������� 1�ۼ�Ʈ���� �ö��� �ʾҰ�
// DFS�� Ǯ��� �ߴ�. �켱 �θ� �ڽİ��踦 �����Ͽ� �Ŀ� ��ȸ�� ���� ���۾��� �Ͽ���.
// �� ���� DFS�� 1�� ������ �������鼭 ����� �ش�. �������� �򰥸��� ���밡 ��ƸԴ� ����̾��µ�
// �Ź� ��ƸԴ°� �ƴ϶� ��� ������ ��Ʋ�� �Ѹ����� ���밡 �� �ѹ��� ��ƸԴ´ٴ� ���̾���.
// ������ ���� ��ȣ�ϴٸ� ������ �κ��̴�. �׷��� �׷��� �������� 30�۵� �ȵȴ�.

// �ڼ��� ������ �ּ����� �����.

struct island
{
    char animal;
    int num;
    int path;
};

island board[123457];
vector<int> child[123457];
int N;

// idx��° ������ ������ ������ ���� ���� ���ϴ� �Լ�.
long long DFS(int idx)
{
    // ���� ��忡 �����Ͽ��ٸ� �װ��� ���밡 ��ٸ� 0��, ���� ��ٸ� ���� ���� ��ȯ�Ѵ�.
    if (child[idx].size() == 0)
    {
        if (board[idx].animal == 'W')
            return 0;
        else
            return board[idx].num;
    }

    long long ans = 0;
    // ��� ���� ���� ���Ѵ�.
    for (auto& n : child[idx])
        ans += DFS(n);

    // �� ������ ���� ū �����ε� ���밡 ���� �� �Ѹ����� ��ƸԴ´�. �Ź� �Ѹ����� �ƴ϶�
    // ��� ������ �� �Ѹ�����. ���� ��� ���� ���� ������ �ű⿡�� �� �ѹ��� ������ ���� ����.
    if (board[idx].animal == 'W')
        ans -= board[idx].num;
    else
        ans += board[idx].num;

    // ���� ���밡 �� ���Ƽ� ������ ���� �ȴٸ� ���� �����Ƿ� 0�� ��ȯ�Ѵ�.
    return ans >= 0 ? ans : 0;
}

void MakeAnswer()
{
    cout << DFS(1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 2; i <= N; ++i)
    {
        cin >> board[i].animal >> board[i].num >> board[i].path;
        // ����� �θ� �ڽİ��� ����. �θ����� �̹� �־����Ƿ� ���� �ʿ䰡 ����.
        child[board[i].path].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}