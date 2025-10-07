#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int p = 0;
    while (true)
    {
        getline(cin, str);
        if (str == "문제")
            ++p;
        else if (str == "고무오리")
            p = p == 0 ? 2 : p - 1;
        else if (str == "고무오리 디버깅 끝")
            break;
    }
    cout << (p == 0 ? "고무오리야 사랑해" : "힝구") << '\n';
    return 0;
}