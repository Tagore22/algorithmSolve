#include <iostream>

using namespace std;

//1057번의 전체적으로 같은 문제지만, 약간 다른 풀이. 기존에는 1라운드부터 시작하기에 a,b 두 변수를 시작부터 새로 배정했으나,
//0라운드부터 시작하면 while문을 한번 더 실행하나, 코드가 조금 더 깔끔해지고 길이도 미약하게나마 줄어든다.

int N, a, b;

void MakeAnswer()
{
    int answer = 0;

    while (a != b)
    {
        a = a % 2 == 0 ? a / 2 : a / 2 + 1;
        b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}