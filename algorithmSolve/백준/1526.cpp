#include <iostream>

using namespace std;

int N;

//�� ���ڸ��� 4 Ȥ�� 7�� �߰��ذ��� N�� �ִ��� ������ ��, ���� ū���� DFS�� ����Ѵ�.

int DFS(int now)
{
    if (now > N)
        return 0;
    int ans = max(now, DFS(now * 10 + 7));
    ans = max(ans, DFS(now * 10 + 4));

    return ans;
}

void ShowAnswer()
{
    cout << DFS(0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    ShowAnswer();
    return 0;
}