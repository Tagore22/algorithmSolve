#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// 풀이.
// 문제 자체의 난이도는 낮을지 모르겠으나 정답율이 그러하듯 어려운 문제였다. 
// 한번의 순회에서 ppap를 발견할시 p로 교체하여 결과값을 출력하는것이 분명했는데 그 구현을
// 떠올리는것이 쉽지 않았다. 문자열을 순회하며 각 P와 A를 만날때 다음과 같은 행동을 하게 된다.

// 1. P를 만났을때. P를 스택에 추가한후 P의 개수 p를 1 늘린다.
// 2. A를 만났을때. p가 2이상인 경우면서 바로 뒷 문자가 p일 경우 ppap에 해당하는 결과이므로
// 스택의 원소 2개를 제외한후 p를 추가하면서 인덱스값을 1개 늘려 한칸 건너 뛴다.
// 그렇지 않은 경우 그냥 A를 스택에 넣는다.
// A의 첫번째 경우가 조금 헷갈렸는데 어차피 제대로 된 PPAP가 등장했을때에만 순회 끝에 P 또는
// PPAP가 등장하게 되기 때문이다. 예를 들어 PAPAP같은 경우 두번째 A에서 2의 첫번째 조건에
// 의해 앞의 2개의 원소가 날라가고 P가 추가되지만 제대로된 PPAP가 아니기에 결과적으로 PP가 남아
// NP가 출력된다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> sta;
    int p = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'P')
        {
            sta.push(str[i]);
            ++p;
        }
        else
        {
            if (p >= 2 && str[i + 1] == 'P')
            {
                // 상술한대로 제대로된 PPAP의 A가 아닐 경우 값이 뒤틀리게 되어
                // NP가 출력하게 된다.
                sta.pop();
                sta.pop();
                sta.push('P');
                --p;
                ++i;
            }
            else
            {
                sta.push(str[i]);
            }
        }
    }

    string answer = "";
    while (!sta.empty())
    {
        answer += sta.top();
        sta.pop();
    }

    reverse(answer.begin(), answer.end());
    if (answer == "PPAP" || answer == "P")
        cout << "PPAP" << '\n';
    else
        cout << "NP" << '\n';
    return 0;
}