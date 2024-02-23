#include <iostream>
#include <deque>

using namespace std;

// 풀이.
// 원소제거와 원소를 맨뒤로 옮겨야했는데 특히나 원소제거를 깔끔하게 할수 있는 컨테이너는 별로 없었다.
// 그중에서 Queue를 생각했는데 맨앞의 원소를 삭제해야했으므로 Deque로 전환했다.
// 맨앞의 원소를 삭제하고 두번째 원소를 맨마지막으로 옮기는 것을 원소의 개수가 1개가 남을때까지 반복하면 된다.

// 자세한 설명은 주석으로 남긴다.

deque<int> deq;
int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    // 1 ~ N까지의 원소로 초기화.
    for (int i = 1; i <= N; ++i)
        deq.push_back(i);
    // Deque의 원소가 한개보다 많다면 반복한다.
    while (deq.size() > 1)
    {
        // 맨앞의 원소를 삭제하며 출력한다.
        cout << deq[0] << ' ';
        deq.pop_front();
        // 두번째 원소를 삭제하며 맨뒤에 추가한다.
        deq.push_back(deq[0]);
        deq.pop_front();
    }
    // 남은 마지막 원소를 출력한다.
    cout << deq[0] << '\n';
    return 0;
}