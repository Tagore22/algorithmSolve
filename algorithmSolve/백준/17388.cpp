#include <iostream>

using namespace std;

// 풀이.
// 브론즈치고는 꽤나 번거로운 문제이다. 단순 정렬을 하지 못하는게 각 원소들을 정렬할때 정렬 이후 어떤 원소가
// 어느 대학인지 알아야하기 때문이다. 따라서 그냥 정렬을 하지 않고 각 원소값들을 입력받을때 idx에 인덱스값을
// 저장하였다. 그 이후 인덱스값에 의해 어느 대학인지 구분하여 대학명을 출력한다.

int main()
{
    int sum = 0, idx = 0, num, cur = 987654321;
    for (int i = 0; i < 3; ++i)
    {
        cin >> num;
        if (cur > num)
        {
            idx = i;
            cur = num;
        }
        sum += num;
    }
    if (sum >= 100)
    {
        cout << "OK" << '\n';
    }
    else
    {
        if (idx == 0)
            cout << "Soongsil" << '\n';
        else if (idx == 1)
            cout << "Korea" << '\n';
        else
            cout << "Hanyang" << '\n';
    }
    return 0;
}