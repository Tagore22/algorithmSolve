#include <iostream>
#include <stack>

using namespace std;

// Ǯ��.
// ������ �̿��Ͽ� ������ �����ϴ� ���̾��� Ǯ��.
// �ٸ� ���ÿ� ����� ������ ������ �������δ� �˼� ��� ���� ����� ������ �ľ��ϴ� ������ �̿��ߴ�.

int N;

void MakeAnswer()
{
    stack<int> sta;
    int menu, idx = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> menu;
        switch (menu)
        {
        case 1:
            int num;
            cin >> num;
            ++idx;
            sta.push(num);
            break;
        case 2:
            if (idx != 0)
            {
                int num = sta.top();
                sta.pop();
                --idx;
                cout << num << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
            break;
        case 3:
            cout << idx << '\n';
            break;
        case 4:
            if (idx == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
            break;
        case 5:
            if (idx != 0)
                cout << sta.top() << '\n';
            else
                cout << -1 << '\n';
            break;
        }
    }
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
    MakeAnswer();
    return 0;
}