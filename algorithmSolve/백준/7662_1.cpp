#include <iostream>
#include <queue>
#include <map>

//7662���� long long Ÿ���� ����Ͽ� �켱���� ť�� Ÿ���� �ϳ��� ���� Ǯ��. �ٸ� long long�� ���⿡ �뷮�� ������ ���̸Դ´�.

using namespace std;

int T, k;

void MakeAnswer()
{
    char command;
    long long num;
    priority_queue<long long> gr, le;
    map<long long, long long> check;
    for (int i = 0; i < T; ++i)
    {
        while (!gr.empty())
            gr.pop();
        while (!le.empty())
            le.pop();
        check.clear();
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            cin >> command >> num;
            if (command == 'I')
            {
                gr.push(num);
                le.push(-num);
                if (check[num] == 0)
                    check[num] = 1;
                else
                    ++check[num];
            }
            else
            {
                if (num == 1)
                {
                    while (!gr.empty() && check[gr.top()] == 0)
                        gr.pop();
                    if (!gr.empty())
                    {
                        --check[gr.top()];
                        gr.pop();
                    }
                }
                else
                {
                    while (!le.empty() && check[-le.top()] == 0)
                        le.pop();
                    if (!le.empty())
                    {
                        --check[-le.top()];
                        le.pop();
                    }
                }
            }
        }
        while (!gr.empty() && check[gr.top()] == 0)
            gr.pop();
        while (!le.empty() && check[-le.top()] == 0)
            le.pop();

        if (gr.empty() || le.empty())
            cout << "EMPTY" << '\n';
        else
            cout << gr.top() << ' ' << -le.top() << '\n';
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