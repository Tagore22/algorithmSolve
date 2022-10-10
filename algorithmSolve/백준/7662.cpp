#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

//문제 자체는 어려울게 없다. 수를 입력 받거나 최대값 혹은 최소값을 제거해나가며 맨 마지막에 최소값과 최대값을 출력하면 된다.
//처음엔 priority_queue를 2개 사용해서 풀려고 했으나, 예를 들어 최소값을 삭제하면 최대값을 담은 큐의 맨 마지막에는 그 최소값이 삭제되지
//않고 남아 있다. 이걸 어떻게 처리해야하나 한참을 고민했는데 map을 이용해서 매핑하면 간단하게 할수 있었다.
//또한, 처음에는 우선순위 큐의 타입을 하나로(그냥 priority_queue를 이용하여 값을 삽입 및 꺼낼때 -를 곱하는 방식으로) 사용하였는데
//계속 96퍼에서 오답이 나왔다. 생각해보니 주어지는 예제는 32 - @비트값이 주어지는데 이 값에 -1을 곱하는 과정에서 오버플로우가 될수 있었다.
//그래서 입력받는 변수의 타입을 더 큰 long long으로 바꾸어주거나 아니면 아래 나왔듯이 큐의 타입을 2개로 나누어 -1을 곱하는 방식을 없애야
//답을 구할수 있다.

int T, k;

void MakeAnswer()
{
    char command;
    int num;
    priority_queue<int, vector<int>, less<int>> gr;
    priority_queue<int, vector<int>, greater<int>> le;
    map<int, int> check;
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
                le.push(num);
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
                    while (!le.empty() && check[le.top()] == 0)
                        le.pop();
                    if (!le.empty())
                    {
                        --check[le.top()];
                        le.pop();
                    }
                }
            }
        }
        while (!gr.empty() && check[gr.top()] == 0)
            gr.pop();
        while (!le.empty() && check[le.top()] == 0)
            le.pop();

        if (gr.empty() || le.empty())
            cout << "EMPTY" << '\n';
        else
            cout << gr.top() << ' ' << le.top() << '\n';
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