#include <iostream>
#include <stack>

using namespace std;

string str;

//스택을 써야하는데 나도 모르게 큐를 써버려서 한참 돌아왔다. T^T

void MakeAnswer()
{
    stack<char> que;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('A' <= str[i] && str[i] <= 'Z')
        {
            cout << str[i];
        }
        else
        {
            if (que.empty() || str[i] == '(')
            {
                que.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-')
            {
                while (!que.empty() && que.top() != '(')
                {
                    cout << que.top();
                    que.pop();
                }
                que.push(str[i]);
            }
            else if (str[i] == '*' || str[i] == '/')
            {
                while (!que.empty() && que.top() != '(' && que.top() != '+' && que.top() != '-')
                {
                    cout << que.top();
                    que.pop();
                }
                que.push(str[i]);
            }
            else
            {
                while (!que.empty() && que.top() != '(')
                {
                    cout << que.top();
                    que.pop();
                }
                que.pop();
            }
        }
    }
    while (!que.empty())
    {
        cout << que.top();
        que.pop();
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}