#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Ǯ��.
// ó������ ��ư� �����ߴ�. �ִ� ���ڿ��� ���̰� 500�̰� ���� N�� M�� 10000�̱� ������
// �ִ� ���귮�� 500�￡ ���ߴ�. Ʈ���̸� ���������� �װͺ��� �� ������ Ǯ�̰� �־���.
// �ֽô��ʿ� �κ� ���ڿ����� Ȯ���ϴ� ���ڿ��� ã�� �� �� �տ������� ��ȸ���� �ʰ�
// lower_bound()�� ���ؼ� �̺� Ž���� �����ϸ� ���귮�� Ȯ �پ��� �����̴�.

vector<string> board;
int N, M;

void Solve()
{
    sort(board.begin(), board.end());
    int answer = 0;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;

        auto iter = lower_bound(board.begin(), board.end(), str);
        if (iter->substr(0, str.size()) == str)
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}