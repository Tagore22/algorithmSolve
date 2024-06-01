#include <iostream>

using namespace std;

// 2355번에서의 식이다. 어이없게도 내가 이미 찾아냈던 식이다.
// 2355.cpp에서 기술하였듯 주어진 수들이 홀수개일때에는 가운데에 (A + B) / 2가 존재하는데 어차피 
// (A + B)들의 합의 절반이므로 (B - A + 1) / 2에 적용되어 n.5만큼 곱해지는 식이다.
// 그래도 혼자 풀었다!

int main()
{
    long long A, B;
    cin >> A >> B;
    if (A > B)
        swap(A, B);
    cout << ((A + B) * (B - A + 1) / 2) << '\n';
    return 0;
}