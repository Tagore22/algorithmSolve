#include <iostream>

using namespace std;

//현재 번호는 승리시 새로 배정되는데 그 패턴은 현재 번호가 홀수일 경우 /2+1이고, 짝수일 경우 /2가 된다. 또한, 둘이 붙는 경우, 예를 들어
//1번과 2번은 승리시 새로 배정되는 번호가 같기에 이걸 이용해서 두명의 번호를 새로 배정해가며 동일할 경우를 찾고 이 라운드가 바로 답이 된다.

int N, a, b;

void MakeAnswer()
{
    int answer = 1;
    a = a % 2 == 0 ? a / 2 : a / 2 + 1; //현재 라운드에서 이길 경우 새로 배정되는 번호.
    b = b % 2 == 0 ? b / 2 : b / 2 + 1;

    while (a != b) //새로 배정되는 번호가 같을 경우 이번 라운드에서 둘이 경기를 한다. 다를 경우 다음 라운드까지 계속 이겨나감.
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