#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 스택을 이용하여 스택을 구현하는 어이없는 풀이.
// 다만 스택에 저장된 정수의 개수를 스택으로는 알수 없어서 따로 저장된 개수를 파악하는 변수를 이용했다.

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