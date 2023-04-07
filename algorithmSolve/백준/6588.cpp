#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 테스트 케이스가 최대 10만개이고, 주어지는 수 N이 최대 100만이기에 주먹구구식으로 풀면 무조건
// 시간 초과가 나는 상황이다. 따라서 에라토스테네스의 체를 이용하여 0 ~ 100만을 각각
// 홀수 소수인지 전처리로 확인한후, 주어지는 수 N을 3 ~ 100만까지 순회하며 자기 자신과
// N - 자기자신이 모두 홀수 소수인 첫번째 상황을 출력하면 된다.
// 두 수의 차이가 가장 클때이므로 상술하였듯 첫번째로 만났을때 바로 출력하면 된다.

const int MAX_NUM = 1000000;
bool check[MAX_NUM + 1];
int num;

// 홀수 소수인지 미리 전처리하는 함수.
void Era()
{
    memset(check, true, sizeof(check));
    check[0] = false;
    check[1] = false;

    for (int i = 2; i <= 1000; ++i)
        if (check[i])
            for (int j = i * i; j <= MAX_NUM; j += i)
                check[j] = false;

    // 2는 유일한 짝수 소수이다. 반드시 사용할수 없음으로 바꾸어놔야한다.
    check[2] = false;
}

void MakeAnswer()
{
    Era();

    bool isfind;
    while (true)
    {
        cin >> num;
        if (num == 0)
            return;

        isfind = false;
        for (int i = 3; i < MAX_NUM; i += 2)
            // 자기자신 i와 num - i 모두가 홀수 소수인 첫번째 상황을 출력한다.
            if (check[i] && check[num - i])
            {
                cout << num << " = " << i << " + " << num - i << '\n';
                isfind = true;
                break;
            }
        // 찾지 못했다면 예외를 출력함.
        if (!isfind)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}