#include <iostream>
#include <map>

using namespace std;

// Ǯ��.
// ������ ���������� Ǭ Ǯ��. ��Ʈ��ŷ���� ����� �ִ� ��� ���� ������
// map�� �� ���� ��������� �ִ� ������ üũ�Ѵ�.
// ���������� 1���� �����ϵ�, 1�� �����ϸ鼭 ���� ���� ��������� �ִ����� Ȯ������
// ��������� ���� ����� ����Ѵ�.

// map�� ��⿡ �ӵ��� ��û ������ �޸𸮵� ��û ��ƸԴ´�.

map<int, int> check;
int board[20];
int N;

void BackTrack(int idx, int sum)
{
    if (sum != 0)
        check.insert(make_pair(sum, 1));

    for (int i = idx + 1; i < N; ++i)
        BackTrack(i, sum + board[i]);
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    int answer = 1;
    while (true)
    {
        if (check[answer] == 0)
        {
            cout << answer << '\n';
            return;
        }
        ++answer;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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