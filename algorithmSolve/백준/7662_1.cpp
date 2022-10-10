#include <iostream>
#include <queue>
#include <map>

//7662번을 long long 타입을 사용하여 우선순위 큐의 타입을 하나로 구한 풀이. 다만 long long을 쓰기에 용량을 굉장히 많이먹는다.

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