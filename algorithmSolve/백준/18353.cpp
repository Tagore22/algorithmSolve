#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� �� ������ ����� LCS �����̴�. �ٸ� ������ ���� ���� ���������� �ƴ� ���������̴�.
// ���� lower_bound�� ��ġ�� �� �����ؾ��ߴ�.

vector<int> lcs;
int board[2000];
int N;

void MakeAnswer()
{
    lcs.push_back(board[0]);
    int answer = 0;
    for (int i = 1; i < N; ++i)
    {
        if (lcs.back() > board[i])
        {
            lcs.push_back(board[i]);
        }
        else
        {
            ++answer;
            int idx = lower_bound(lcs.begin(), lcs.end(), board[i], greater<int>()) - lcs.begin();
            lcs[idx] = board[i];
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}