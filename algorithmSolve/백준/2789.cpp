#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// find()를 통하여 캠프리지에 해당하지 않는 알파벳들만 출력하면 된다.

int main()
{
    string str1, str2 = "CAMBRIDGE";
    cin >> str1;
    for (int i = 0; i < str1.size(); ++i)
        if (find(str2.begin(), str2.end(), str1[i]) == str2.end())
            cout << str1[i];
    cout << '\n';
    return 0;
}