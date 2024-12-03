#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 두 문자열에서 부분 문자열을 찾는 문제이기에 string::find()를 떠올렸으나 
// find()의 시간복잡도는 최대 O(nm)이었고, 문제에서 주어지는 문자열은 각각 최대 100만의 길이를
// 가질수 있었기에 불가능했다. strstr은 O(n + m)으로 구현되어 있었고 적용할수 있었다. 잘 기억해두자.

int main()
{
    string s, p;
    cin >> s >> p;
    cout << (strstr(s.c_str(), p.c_str()) == nullptr ? 0 : 1) << '\n';
    return 0;
}