#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// find()�� ���Ͽ� ķ�������� �ش����� �ʴ� ���ĺ��鸸 ����ϸ� �ȴ�.

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