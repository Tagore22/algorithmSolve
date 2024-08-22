#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 2가지 실수가 있었다.

// 1. string.substr()의 매개변수는 반복자가 아닌 int 변수이다. 2가지 오버로드가 존재하였다. 
// int 변수가 하나짜리는 문자열의 맨 처음부터 n개를 이용한 부분문자열을 만드는 것이고,
// int 변수가 2개짜리는 n번째 문자부터 시작해서 m개를 이용한 부분문자열을 만드는 것이다.

// 2. stoi()의 매개변수에 string의 문자는 매개변수로 넣을수 없다. char >> string으로의 변환이
// 되지 않기 때문이다.

int main()
{
    string str;
    cin >> str;

    if (str.size() == 2)
    {
        cout << stoi(str.substr(0, 1)) + stoi(str.substr(1, 1)) << '\n';
    }
    else if (str.size() == 3)
    {
        if (str[1] == '0')
            cout << stoi(str.substr(0, 2)) + stoi(str.substr(2)) << '\n';
        else
            cout << stoi(str.substr(0, 1)) + stoi(str.substr(1)) << '\n';
    }
    else
    {
        cout << 20 << '\n';
    }
    return 0;
}