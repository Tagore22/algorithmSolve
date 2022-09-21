#include <iostream>
#include <vector>
#include <algorithm>

//������ 686�������� Ǯ��ô� �����̴�. �ٸ� ������ ����ϴ� vector 2���� �Ű������� �ϴ� Ǯ�̴� ����ð� ��������
//�ð� �ʰ��� ���ͼ� ��¿������ ���۰� ���� �ǹ��ϴ� �ε����� 4���� �ٲ�����ߴ�.

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