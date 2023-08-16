#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �־����� �迭�� ũ�⸦ ���ϴ� ������. �ٸ� �׳� �迭�� ����ϸ� �ּҰ��� ���ϱ� ������
// �Ұ����ϰ� ���͸� �̿��ؾ� �Ѵ�. �̰͸� �˸� ������ ������ ���� ����� �ʴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> a, b;
int N, num;

void MakeAnswer()
{
    for (int iter = 0; iter < N; ++iter)
    {
        // ������ ������� ������Ѵ�.
        a.clear();
        b.clear();

        cin >> num;
        int cur;
        // a�� �����.
        for (int i = 0; i < num; ++i)
        {
            cin >> cur;
            a.push_back(cur);
        }
        cin >> num;
        // b�� �����.
        for (int i = 0; i < num; ++i)
        {
            cin >> cur;
            b.push_back(cur);
        }

        // a�� b�� ������������ �����Ѵ�.
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());

        // ���� ����� ����Ѵ�.
        if (a > b)
            cout << 'A' << '\n';
        else if (a < b)
            cout << 'B' << '\n';
        else
            cout << 'D' << '\n';
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