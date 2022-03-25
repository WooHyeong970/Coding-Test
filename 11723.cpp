#include <iostream>

using namespace std;

bool arr[20];
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d", &n);
    while(n--)
    {
        int x;
        char c[7];
        scanf("%s", c);
        if(c[1] == 'l' || c[1] == 'm')
        {
            switch (c[1])
            {
                case 'l':
                    for(int i = 0; i < 20; i++)
                        arr[i] = true;
                    break;
                case 'm':
                    for(int i = 0; i < 20; i++)
                        arr[i] = false;
                    break;
            }
        }
        else
        {
            scanf("%d", &x);
            switch (c[1])
            {
                case 'd':
                    arr[x - 1] = true;
                    break;
                case 'e':
                    arr[x - 1] = false;
                    break;
                case 'o':
                    if(arr[x - 1] == true)
                        arr[x - 1] = false;
                    else
                        arr[x - 1] = true;
                    break;
                case 'h':
                    if(arr[x - 1] == true)
                        printf("1\n");
                    else
                        printf("0\n");
                    break;
            }
        }
    }
}
