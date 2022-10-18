#include <iostream>

using namespace std;

//11727번의 다른 풀이. 재귀를 사용하지 않고 단순 반복문으로 푸는 방법. 재귀로 푼것과 메모리나 속도의 차이는 미미하나, 코드가 더 짧기에
//구현도 빠르고 보기도 편하다. 재귀에 의존하지 말고 다른 방법도 찾아보자.

const int DIV_NUM = 10007;
int cashe[1001];
int n;

void MakeAnswer()
{
    cashe[1] = 1;
    cashe[2] = 3;
    for (int i = 3; i <= n; ++i)
        cashe[i] = (cashe[i - 1] + cashe[i - 2] * 2) % DIV_NUM;
    cout << cashe[n] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}