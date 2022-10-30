#include <iostream>
#include <string>

using namespace std;

//앞뒤에 0 때문에 고생을 좀 했는데 결과적으로 string끼리의 덧셈으로 가상 연산이 아닌 실제 int로 바꾸어 실제 연산을 시키면 0에 관한
//걱정들은 모두 사라진다. 최대값이 1000이기에 오버플로우등을 걱정할 필요도 없다.

string a, b;

int ReverseConvert(const string& str)
{
    int con = 0, iter = 1;
    for (int i = 0; i < str.size(); ++i)
    {
        con += (str[i] - '0') * iter;
        iter *= 10;
    }

    return con;
}

void MakeAnswer()
{
    int first = ReverseConvert(a);
    int second = ReverseConvert(b);

    cout << ReverseConvert(to_string(first + second)) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}