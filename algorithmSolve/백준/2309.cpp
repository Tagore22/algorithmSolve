#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ������. �������� Ǯ�̰� �ְڴٸ�, ���� ��Ʈ��ŷ ������ Ǯ����.
// �Ѱ��� ���Ϳ� ���Ұ��� ���, ������ ������ 7���϶� �� ���� 100�̶�� ����� �ϰ�
// ��Ʈ��ŷ ��ȸ�� ���߾���. �ٸ� Ǯ�̰� �ֳ� ���۸��� �� �غ��Ҵµ� �ϳ����� Ǯ�� �Ӹ� �ƴ϶�
// �ڵ���ü�� �Ȱ��� ���� ���� �ƴ�. ���� �����ߴ�.

// �ڼ��� ������ �ּ����� �����.

int board[9];
vector<int> answer;
bool isfind = false;

// ���� ���Ϳ� ��� ���ҵ��� ���� 100���� Ȯ���ϴ� �Լ�.
bool Check()
{
    int ans = 0;
    for (int i = 0; i < answer.size(); ++i)
        ans += answer[i];

    return ans == 100;
}

// ��Ʈ��ŷ �Լ�. �ϳ��� ���Ϳ� ��ƺ��鼭 ������ ������ 7������, �� ���� 100���� Ȯ����
// �´ٸ� ����� ��ȸ�� �����.
void BackTrack(int num)
{
    if (isfind)
        return;

    if (answer.size() == 7 && Check())
    {
        sort(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
        cout << '\n';
        isfind = true;
        return;
    }

    for (int i = num + 1; i < 9; ++i)
    {
        answer.push_back(board[i]);
        BackTrack(i);
        answer.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}