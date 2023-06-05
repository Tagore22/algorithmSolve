#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Ǯ��.
// ���� ���� Ž���� ������ȸ�� ���� ��������.
// ��͸� ����Ͽ� ���� >> �ڱ��ڽ� >> ���������� ��ȸ �� ���� �����Ͽ�
// ������ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

// �� ���̸��� ���� ����ϴ� ����.
vector<vector<int>> answer;
vector<int> board;
int K;

// ���� ��ȸ�� �����ϴ� �Լ�. ����Ͽ���
// ���� >> �ڱ� �ڽ� >> ������ ������ ��ȸ�ϸ� �� ���� answer�� ����Ѵ�.
void Inorder(int dep, const vector<int>& cur)
{
    // ���� ���� ���ܳ�忡 �����ߴٸ� �� ���� ����ϰ� ������.
    if (cur.size() == 1)
    {
        answer[dep].push_back(cur[0]);
        return;
    }

    int piv = cur.size() / 2;
    Inorder(dep + 1, vector<int>(cur.begin(), cur.begin() + piv));
    answer[dep].push_back(cur[piv]);
    Inorder(dep + 1, vector<int>(cur.begin() + piv + 1, cur.end()));
}

void MakeAnswer()
{
    // ���� ��ȸ.
    Inorder(0, board);
    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer[i].size(); ++j)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    answer.resize(K, vector<int>());
    int iter = pow(2, K) - 1;
    for (int i = 0; i < iter; ++i)
    {
        int num;
        cin >> num;
        board.push_back(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}