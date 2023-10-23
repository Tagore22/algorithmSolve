#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 공백이 포함된 문자열을 입력받아야 하기 때문에 getline()을 사용해야 한다.
// 최대 100줄동안 주어지는 문자열을 모두 입력받아 그대로 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    string str;
    // 입력이 계속되는 동안 그대로 출력한다.
    while (getline(cin, str))
    {
        cout << str << '\n';
    }
    return 0;
}