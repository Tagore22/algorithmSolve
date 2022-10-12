#include <iostream>
#include <cstring>

using namespace std;

//바로 전에 풀었던 9095번과 매우 유사한 문제이다. 2XN개의 타일을 1X2, 혹은 2X1 타일로 채우는 것이며 순서가 다르면 다른 경우로 친다.
//이 말은 어떠한 수 N을 1 혹은 2로 더해가는 것과 같은데 즉, 어떠한 수 N을 1 혹은 2로 빼가며 0이 나올경우 한가지 수로 파악하면 된다.
//막상 풀고보니 피보나치 정리와 같았다.

const int DIV_NUM = 10007;
const int MAX_NUM = 1000 + 1;
int cashe[MAX_NUM];
int n;

int Cal(int num)
{
    if (num == 0)
        return 1;

    int& ans = cashe[num];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 1; i <= 2; ++i)
        if (num >= i)
            ans += Cal(num - i);

    return ans %= DIV_NUM;
}

void MakeAnswer()
{
    cout << Cal(n) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}