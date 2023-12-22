#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// ������ Ǯ�̿� ������ �����ϳ� map�� unordered_map���� ��ü�� Ǯ�̴�.
// ���ڿ� ����� �ǹ̾��� ������ ���������ν� �ӵ��� �뷫 4���� 1�� �پ�����.

unordered_map<string, int> strs;
vector<string> board;
int N, M;

// �� ���ڿ����� �־��� ���Ǵ�� �����ϴ� �Լ�.
bool CompareString(const string& lhs, const string& rhs)
{
    // ����Ƚ���� �ٸ��� �� ���� ������ ���ڿ��� �տ� �´�.
    if (strs[lhs] != strs[rhs])
        return strs[lhs] > strs[rhs];
    // �� ���ڿ��� ���̰� �ٸ��� �� �� ���ڿ��� �տ� �´�.
    else if (lhs.size() != rhs.size())
        return lhs.size() > rhs.size();
    // �׷��� ������ ������ ���Ĵ�� �����Ѵ�.
    else
        return lhs < rhs;
}

void MakeAnswer()
{
    string str;
    // N���� ���ڿ��� �Է¹޴´�.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        // ���ڿ��� ���̰� M���� ª�ٸ� �����Ѵ�.
        if (str.size() < M)
            continue;
        // ó�� ������ ���ڿ��̶�� vector�� �ִ´�.
        if (strs[str] == 0)
            board.push_back(str);
        // ����Ƚ���� 1 ������Ų��.
        ++strs[str];
    }

    // ���Ϳ� ������ �ߺ����� ���� ���ڿ����� ���Ľ�Ų�� ����Ѵ�.
    sort(board.begin(), board.end(), CompareString);
    for (auto s : board)
        cout << s << '\n';
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