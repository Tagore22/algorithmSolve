#include <iostream>

using namespace std;

// 풀이.
// 두 문자열의 겹치는 문자들을 제외하고 모두 삭제해야 한다. 따라서 각 문자열들을 순회하며 등장하는 문자들의 횟수를 저장하고
// 다시 모든 문자들을 순회하며 각 문자의 등장한 횟수중 더 적은쪽들을 찾는다. 이 수가 겹치는 부분들이며 겹치는 부분들 * 2를 하여
// 두 문자열의 길이에서 빼주면 된다.

// 자세한 설명은 주석으로 남긴다.

string str1, str2;
int board1[26] = { 0, }, board2[26] = { 0, };

int main()
{
    cin >> str1 >> str2;
    // 두 문자열을 순회하며 각 문자들의 등장횟수를 저장한다.
    for (int i = 0; i < str1.size(); ++i)
        ++board1[str1[i] - 'a'];
    for (int i = 0; i < str2.size(); ++i)
        ++board2[str2[i] - 'a'];
    int minus = 0;
    // 모든 문자들을 순회하며 각 문자가 두 문자열에 등장한 횟수중 적은쪽을 저장한다. 이것이 겹치는 수이다.
    for (int i = 0; i < 26; ++i)
        minus += min(board1[i], board2[i]);
    // 겹치는 부분은 두 문자열에 모두 나왔으므로 * 2를 하여 두 문자열의 길이에서 빼주면 된다.
    cout << str1.size() + str2.size() - minus * 2 << '\n';
    return 0;
}