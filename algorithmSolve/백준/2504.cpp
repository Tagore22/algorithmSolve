#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 눈으로 풀기는 쉬우나 막상 원리를 파악하기가 무척 어려웠다.
// 결과적으로 시작하는 괄호일때는 현재값을 곱해주고 
// 끝나는 괄호중 첫번째 끝나는 괄호일때 현재값을 최종값에 더해준다.
// 그후 곱해준 값으로 나누어준다.

// 마지막에 스택이 비어있지 않다면 0을 출력하면 된다.

string str;

void MakeAnswer() // 홀수일때는 무조건 답이 안된다.
{
    if (str.size() % 2 == 1 || str[0] == ')' || str[0] == ']')
    {
        cout << 0 << '\n';
        return;
    }

    stack<char> cha;

    int cur = 1, answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            cur *= 2;
            cha.push(str[i]);
        }
        else if (str[i] == '[')
        {
            cur *= 3;
            cha.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (cha.empty() || cha.top() != '(')
            {
                cout << 0 << '\n';
                return;
            }

            if (str[i - 1] == '(')
                answer += cur;

            cur /= 2;
            cha.pop();
        }
        else
        {
            if (cha.empty() || cha.top() != '[')
            {
                cout << 0 << '\n';
                return;
            }

            if (str[i - 1] == '[')
                answer += cur;

            cur /= 3;
            cha.pop();
        }
    }
    cout << (cha.empty() ? answer : 0) << '\n';
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