#include <iostream>

using namespace std;

// 풀이.
// 처음에는 앞과 뒤에 넣는 모든 경우를 따질까 생각도 해보았으나 N이 최대 10만이었기에
// 절대로 불가능했다. 조금만 생각해보면 의외로 간단한데 누군가 맨 앞에 서야한다.
// 이 때 자신보다 앞에 학생들은 새치기를 당해서 -가 된 상태이고, 뒤에 학생들은
// 맨 뒤로가서 0이 된 상태이므로 이 때 만족도의 총합은 (i번째 학생의 만족도) - 
// (0 ~ i - 1번째 학생들의 만족도)가 된다. 따라서 0 ~ N - 1번째를 순회하며
// 상술한 만족도의 총합중 가장 큰 값을 출력하면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    long long sum = 0, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;

        answer = max(answer, num - sum);
        sum += num;
    }
    cout << answer << '\n';
    return 0;
}