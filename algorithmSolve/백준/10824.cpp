#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 4개의 문자열 s1, s2, s3, s4가 주어질때 각각 s1과 s2, s3과 s4를 더한후
// 두 문자열을 long long타입으로 변환하여 합을 출력한다.
// 각 문자열들이 최대 100만에 도달함으로 int로 변환시 오버플로우가 발생하기 때문에
// int가 아닌 long long으로 변환하여야 한다.

int main()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    cout << stol(s1 + s2) + stol(s3 + s4) << '\n';
    return 0;
}