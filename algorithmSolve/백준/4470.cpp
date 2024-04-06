#include <iostream>
#include <string>

using namespace std;

// 풀이.
// cin.ignore()와 getline()을 알아야 하는 문제이다. cin >> 으로 입력받을때에는 개행문자를 버리고,
// getline()은 개행문자까지 모두 입력받는다. 따라서 cin >> 으로 입력받은후에 바로 getline()을 호출하면
// 입력버퍼에 남아있던 개행문자를 getline()이 입력받고 바로 끝나버리기 때문에 제대로 된 답이 나오지 않는다.
// 따라서 그 중간에 cin.ignore()를 호출하여 개행문자를 없애야한다. 다만 상술하였듯 getline()은 개행문자까지
// 모두 입력받기 때문에 getline()이 반복되는 사이에 cin.ignore()가 호출되면 오히려 이후 입력받을 문자열의 맨앞을
// 무시하기 때문에 주의가 필요하다.

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 1; i <= N; ++i)
    {
        string str;
        getline(cin, str);
        cout << i << ". " << str << '\n';
    }
    return 0;
}