#include <iostream>

using namespace std;

bool inorder_check[100000];
int inorder[100000], postorder[100000];
int n;

void func(int in_start, int in_end, int post_start, int post_end)
{
    int pivot(0);
    for(int i = in_start; i <= in_end; i++)
        if(inorder[i] == postorder[post_end]) pivot = i;
    cout << inorder[pivot] << " ";
    inorder_check[pivot] = true;
    if(pivot - 1 >= 0 && !inorder_check[pivot - 1])
        func(in_start, pivot - 1, post_start, post_start + (pivot - 1) - in_start);
    if(pivot + 1 < n && !inorder_check[pivot + 1])
        func(pivot + 1, in_end, post_start + pivot - in_start, post_start - in_start + in_end - 1);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> inorder[i];
    for(int i = 0; i < n; i++) cin >> postorder[i];
    func(0, n - 1, 0, n - 1);
}
