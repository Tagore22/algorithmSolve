#include <iostream>
#include <cmath>

using namespace std;

//처음엔 2진수 >> 10진수 >> 8진수를 생각했으나 예제를 보니 최대 100만자리길래 아니구나 싶었다.
//2진수 >> 8진수를 하면 되는데 각 자리수 3개씩을 구해서 붙이기만 하면 된다.
//또한 답의 맨앞 즉, answer[0]이 0일시 없애버렸었는데 다시 생각해보면 8진수 자체를 출력해야함으로
//그럴 필요가 없었다.

constexpr int DIVNUM = 3;
string str;

void MakeAnswer()
{
    string answer = "";
    int check = 0;
    int str_size = str.size();
    for (int i = 0; i < str_size; ++i)
    {
        int pow_num = (str_size - i - 1) % DIVNUM;

        if (str[i] == '1')
            check += pow(2, pow_num);

        if (pow_num == 0)
        {
            answer.push_back(check + '0');
            check = 0;
        }
    }

    //int idx = answer[0] == '0' ? 1 : 0; << 맨 앞이 0이면 출력에서 제외하는 코드. 그러나 8진수 자체를 출력해야함으로 필요없음.
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i];
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}