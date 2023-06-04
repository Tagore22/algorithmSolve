#include <iostream>
#include <cstring>

using namespace std;

// 14225���� �ٸ� Ǯ��.
// �̹����� map�� �ƴ϶� bool�迭�� ���� ���� ���θ� üũ�ߴ�.
// �ִ� 200���̶�� �Ϳ� ���� ���� �������ϴ�.
// �ӵ��� �� ������ �޸𸮵� �� ���� �Դ´�.

int board[20];
bool check[2000000];
int N;

void BackTrack(int idx, int sum)
{
    if (sum != 0)
        check[sum] = true;

    for (int i = idx + 1; i < N; ++i)
        BackTrack(i, sum + board[i]);
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(-1, 0);
    int answer = 1;
    while (true)
    {
        if (!check[answer])
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