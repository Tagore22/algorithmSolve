#include <iostream>

using namespace std;

// 풀이.
// 처음엔 조금 당황스러웠던 문제이다. 언제까지고 F()를 할수도 없는 노릇이기 때문이다.
// 하지만 잘 생각해보면 NFA인 경우는 존재하지 않는다. 그 어떤 경우에도 맨 앞자리와 자리수를 곱해나가면
// 점점 수가 줄어들다가 결국 한자리가 되어서 반복하는 구간이 등장하기 때문이다. 따라서
// 10의 100제곱을 string으로 입력받고 FA를 출력하기만 하면 된다.

int main()
{
    string str;
    cin >> str;
    cout << "FA" << '\n';
    return 0;
}