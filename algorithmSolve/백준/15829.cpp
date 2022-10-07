#include <iostream>

using namespace std;

//단순한 아스키코드 + 곱셈문제인데 처음엔 mul을 구할때 pow함수를 썼었다. 하지만 pow함수를 쓸경우 답이 너무커져서 
//오버플로우가 발생하기 전에 제어가 불가능하여 답을 풀수 없고, 따라서 직접 31을 곱해가며 DIVNUM을 넘겼을때
//값을 줄여가며 결과값을 계산하면 된다.

string str;
int L;
constexpr int ASC = 96;
constexpr int MULNUM = 31;
constexpr int DIVNUM = 1234567891;

//mul을 int로 잘못 선언했었다. 만약 mul이 int라면 for문 세번째줄에서 int 변수 2개가 곱해져서 
//int의 최대값을 넘겨 오버플로우가 되고, 답을 구할수가 없다.

void MakeAnswer()
{
    long long answer = 0;
    long long mul = 1;
    for (int i = 0; i < L; ++i)
    {
        answer += (str[i] - ASC) * mul;
        answer %= DIVNUM;
        mul = mul * MULNUM % DIVNUM;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}