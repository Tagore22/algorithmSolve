#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 2696���� �켱����ť ������ ���İ��� �ٲ��� Ǯ��.
// �־��� ���� ��� int�̸� ����Ǯ�̿ʹ� �ٸ��� - �������� ���� int���� ������ �Ѵ� ���� �����Ƿ�, 
// long longŸ���� �켱����ť�� ���� �ʿ䵵 ����. ����, �Ź� ���Ұ��� �ǵ帱�� -������ ���� �ʾƵ� �ȴ�.
// ������ �� ���ø����� ������� �ϳ� ���İ� �ξ� ���ϴ� �����ε� �̷��� �ؾ߰ڴ�.

int T;

void MakeAnswer()
{
    int M;
    vector<int> answer;
    for (int i = 0; i < T; ++i)
    {
        priority_queue<int> max_top;
        priority_queue<int, vector<int>, greater<int>> min_top;
        answer.clear();
        cin >> M;
        int num;
        for (int j = 1; j <= M; ++j)
        {
            cin >> num;
            if (max_top.size() == min_top.size())
                max_top.push(num);
            else
                min_top.push(num);

            if (!max_top.empty() && !min_top.empty() && max_top.top() > min_top.top())
            {
                int from_min = min_top.top();
                min_top.pop();
                int from_max = max_top.top();
                max_top.pop();
                min_top.push(from_max);
                max_top.push(from_min);
            }

            if (j % 2 != 0)
                answer.push_back(max_top.top());
        }

        cout << answer.size() << '\n';
        for (int i = 0; i < answer.size(); ++i)
        {
            if (i != 0 && i % 10 == 0)
                cout << '\n';
            cout << answer[i] << ' ';
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}