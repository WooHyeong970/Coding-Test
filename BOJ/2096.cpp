#include <iostream>

using namespace std;

int n, mx, mn;
int mx_arr[3], mn_arr[3], mx_temp[3], mn_temp[3], nums[3];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> nums[j];
            mx_temp[j] = nums[j];
            mn_temp[j] = nums[j];
        }
        for(int j = 0; j < 3; j++) mx_temp[j] += mx_arr[1];
        for(int j = 0; j < 3; j++) mn_temp[j] += mn_arr[1];
        for(int j = 0; j < 2; j++)
        {
            if(mx_arr[0] + nums[j] > mx_temp[j]) mx_temp[j] = mx_arr[0] + nums[j];
            if(mn_arr[0] + nums[j] < mn_temp[j]) mn_temp[j] = mn_arr[0] + nums[j];
        }
        for(int j = 1; j < 3; j++)
        {
            if(mx_arr[2] + nums[j] > mx_temp[j]) mx_temp[j] = mx_arr[2] + nums[j];
            if(mn_arr[2] + nums[j] < mn_temp[j]) mn_temp[j] = mn_arr[2] + nums[j];
        }
        for(int j = 0; j < 3; j++)
        {
            mx_arr[j] = mx_temp[j];
            mn_arr[j] = mn_temp[j];
        }
    }
    mx = (mx_arr[0] > mx_arr[1]) ? mx_arr[0] : mx_arr[1];
    mx = (mx > mx_arr[2]) ? mx : mx_arr[2];
    mn = (mn_arr[0] < mn_arr[1]) ? mn_arr[0] : mn_arr[1];
    mn = (mn < mn_arr[2]) ? mn : mn_arr[2];
    cout << mx << " " << mn << "\n";
}
