#include <iostream>
#include <vector>
#include <algorithm>

//종만북 686페이지서 풀어봤던 문제이다. 다만 기존에 사용하던 vector 2개를 매개변수로 하는 풀이는 복사시간 때문인지
//시간 초과가 나와서 어쩔수없이 시작과 끝을 의미하는 인덱스값 4개로 바꿔줘야했다.

using namespace std;

vector<int> preorder;
vector<int> inorder;
int T, n;

void PostOrder(int first_from, int first_to, int second_from, int second_to)
{
    if (first_from > first_to || second_from > second_to)
        return;
    int root = preorder[first_from];
    int L = find(inorder.cbegin() + second_from, inorder.cbegin() + second_to + 1, root) - inorder.cbegin() - second_from;
    PostOrder(first_from + 1, first_from + L, second_from, second_from + L - 1);
    PostOrder(first_from + L + 1, first_to, second_from + L + 1, second_to);
    cout << root << ' ';
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        preorder.clear();
        inorder.clear();
        cin >> n;
        for (int j = 0; j < n; ++j)
        {
            int a;
            cin >> a;
            preorder.push_back(a);
        }
        for (int j = 0; j < n; ++j)
        {
            int a;
            cin >> a;
            inorder.push_back(a);
        }
        PostOrder(0, preorder.size() - 1, 0, inorder.size() - 1);
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}