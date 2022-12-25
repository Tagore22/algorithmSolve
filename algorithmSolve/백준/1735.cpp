#include <iostream>

using namespace std;

//풀이
//두 분수값 4개를 입력받아 분모들간의 최소공배수를 구한다. 그 후, 각 분자들을 분모들의 최소공배수 / 자신의 분모값으로 곱해준후
//두 분자값을 더하면 더 분수값을 더한값이 되는데, 기약분수를 출력하라고 했기에 마지막으로 최종 분모와 분자값의 최대공약수로 나누어
//분모와 분자값을 출력하면 된다. 또한, 입력되는 수의 최대값은 3만이기에 곱해지는 최대값은 9억이라서 int값만으로도 충분히 구현이 가능하다.

pair<int, int> board[2];

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int Lcm(int a, int b)
{
    return a * b / Gcd(a, b);
}

void MakeAnswer()
{
    int lcm_num = Lcm(board[0].second, board[1].second);
    int first_mul = lcm_num / board[0].second;
    int second_mul = lcm_num / board[1].second;

    int up_num = board[0].first * first_mul + board[1].first * second_mul;
    int down_num = lcm_num;
    int gcd_num = Gcd(up_num, down_num);

    cout << up_num / gcd_num << ' ' << down_num / gcd_num << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}