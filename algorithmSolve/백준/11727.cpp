#include <iostream>
#include <cstring>

using namespace std;

//11726번의 상위호환문제이다. 다른점은 2x2타일이 추가되었단 건데 2x2타일은 1x2타일을 2개써서 n칸을 지우는것과 같지만 다른 방법으로 
//쳐야하기 때문에 결과적으로 n-2일때에는 2가지 방법이 존재한다. 이를 코드에 반영하여 2칸을 제거할때에는 그 방법수를 2로 곱하면 된다.

const int DIV_NUM = 10007;
int cashe[1001];
int n;

//기존과 달라진 점은 단 하나로 상술하였듯이 2칸을 제거 할때에는 그 방법수가 2가지가 된다는것을 반영하여 2를 곱해준다.

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
            ans += Cal(num - i) * i; //2칸을 제거할때는 방법수에 2를 곱해준다.
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