#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 20920���� ���� Ǯ��.
// ������ �����ϴ� vector�� ������ Ǯ��.
// unordered_map ���� �ߺ��� �����ϱ� ������ ���� vector�� �ߺ��� ������
// ���ڿ����� �Է����� �ʾƵ� �Ŀ� unordered_map�� ���� �״�� �����ϸ� �ȴ�.
// ���� �������� unordered_map�� ���� �����Ͽ� �� ���� ���¾��µ�
// ���� �����̳ʴ� ���� �׼����� �Ұ����ϱ� ������ �Ź� �ݺ��ڸ� �̿��Ͽ� �ش�
// ���ڿ��� ���� ���Ҹ� ã�������� ��ȸ�� ����ؾ� �Ѵ�. ���� �ſ� ����
// ���귮�� �ʿ�� �Ѵ�. �׷��� ������ ���Ľ� �ƿ� pair<string, int> ���� �Ѱ�
// unordered_map������ ������ �����Ͽ� ����ȭ�� �븱�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

int N, M;

bool CompareString(const pair<string, int>& lhs, const pair<string, int>& rhs)
{
    // ����Ƚ���� �ٸ��� �� ���� ������ ���ڿ��� �տ� �´�.
    if (lhs.second != rhs.second)
        return lhs.second > rhs.second;
    // �� ���ڿ��� ���̰� �ٸ��� �� �� ���ڿ��� �տ� �´�.
    else if (lhs.first.size() != rhs.first.size())
        return lhs.first.size() > rhs.first.size();
    // �׷��� ������ ������ ���Ĵ�� �����Ѵ�.
    else
    else
        return lhs.first < rhs.first;
}

void MakeAnswer()
{
    string str;
    unordered_map<string, int> strs;
    // N���� ���ڿ��� �Է¹޴´�.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        // ���ڿ��� ���̰� M���� ª�ٸ� �����Ѵ�.
        if (str.size() < M)
            continue;
        // ����Ƚ���� 1 ������Ų��.
        ++strs[str];
    }

    // ������ ���� vector��, unordered_map�� ������ ���� �ʱ� ���� pair<string, int>��
    // unordered_map������ ���� �����ؿ´�.
    vector<pair<string, int>> board(strs.begin(), strs.end());
    // �������� ���õ� �������� ���ڿ����� ���Ľ�Ų�� ����Ѵ�.
    sort(board.begin(), board.end(), CompareString);
    for (auto s : board)
        cout << s.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}