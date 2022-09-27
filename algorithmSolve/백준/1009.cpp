#include <iostream>

using namespace std;

int T, a, b; //a의 b제곱 형태.

//수가 꽤나 크지만 결국 필요로 하는 것은 맨 마지막 끝자리였기에 수를 제곱해가며 나누기 10을 해서 맨 마지막자리만 추적하면 된다.
//다만 0일때에는 0번 컴퓨터가 아닌 10번 컴퓨터인것을 놓쳐서 한번 틀렸다.

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> a >> b;
        int now = 1;
        for (int j = 0; j < b; ++j)
        {
            now *= a;
            now %= 10;
        }
        now = now == 0 ? 10 : now;
        cout << now << '\n';
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