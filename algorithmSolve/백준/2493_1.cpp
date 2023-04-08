#include <iostream>
#include <stack>

using namespace std;

// 2493���� �ٸ� Ǯ��.
// �ڿ������Ͱ� �ƴ� �տ������� ����Ͽ��⿡ ������ �迭�� �ʿ������
// ��ƸԴ� �뷮�� Ȯ�پ�����. ������ ������ �� ��ų�, �ڱ� �ڽź���
// ū ���Ұ� ��Ÿ�������� ���ÿ� ����� ���ҵ��� ��� �����Ѵ�.
// ������ �� ����ٸ� ���Ź����� �ִ� ž�� ���⿡ 0�� ����ϰ�
// �����Ѵٸ� �ٷ� �װ��� ���Ź޴� ž�̴�.

int N;

void MakeAnswer()
{
    stack<pair<int, int>> sta; // ����, ��ȣ.    
    int cur;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        while (!sta.empty() && sta.top().first < cur)
            sta.pop();
        if (sta.empty())
            cout << 0 << ' ';
        else
            cout << sta.top().second + 1 << ' ';
        sta.push(make_pair(cur, i));
    }
    cout << '\n';
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