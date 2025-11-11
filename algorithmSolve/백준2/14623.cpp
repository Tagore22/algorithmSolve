#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 풀이.
// 본래 이진수의 범위는 int를 넘지 않으나 곱셈이 진행되므로
// long long 타입을 써야한다.

long long TwoToTen(const string& lhs)
{
    int idx = 1;
    long long ans = 0;
    for (int i = lhs.size() - 1; i >= 0; --i)
    {
        if (lhs[i] == '1')
            ans += idx;
        idx *= 2;
    }
    return ans;
}

string TenToTwo(long long num)
{
    string ans = "";
    while (num >= 2)
    {
        ans += to_string(num % 2);
        num /= 2;
    }
    ans += to_string(num);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string B1, B2;
    cin >> B1 >> B2;
    long long iB1 = TwoToTen(B1);
    long long iB2 = TwoToTen(B2);
    cout << TenToTwo(iB1 * iB2) << '\n';
    return 0;
}