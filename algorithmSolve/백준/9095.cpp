#include <iostream>
#include <cstring>

//각 수를 어떠한 순서로 1,2,3의 합으로 나타낼수 있는지 그 수를 구하는 문제이다. 주의해야 할점은 1+2나 2+1처럼 순서가 다를 경우에도
//각각 다른 경우로 생각한다는 점이다. 그렇기에 주어진 예제를 각각 1,2,3보다 큰지 비교하여 크다면 빼가며 결국 0에 도착할 경우
//1가지 방법임을 뜻하여 1을 더해준다.

using namespace std;

int cashe[11];
int T;

int Cal(int num)
{
    if (num == 0)
        return 1;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 1; i <= 3; ++i)
        if (num >= i)
            ans += Cal(num - i);

    return ans;
}

void MakeAnswer()
{
    int num;
    for (int i = 0; i < T; ++i)
    {
        cin >> num;
        cout << Cal(num) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}