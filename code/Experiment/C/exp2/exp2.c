#include <stdio.h>

int main(int argc)
{
    switch (argc)//分开每一道题
    {
    //(1)------------------------------------------
    case 1:
    {
    
        int count = 0;
        while (1)
        {
            count++;
            if (count < 0)
            {
                printf("最小值是：%d\n最大值是：%d\n",count,count-1);//一直加1，count小于0时就是最大值加1后变成最小值,count-1即为最大值
                break;
            }
            
        }
        break;
    }

    //(2)--------------------
    case 2:
    {
        int N;
        while (1)
        {
            if (scanf("%d",&N) == 1 && getchar() == '\n')//scanf的输入都是一回车键\n结尾，验证读取的数据下一位是不是\n即可验证输入的数据是否正确和读取完整
            {
                printf("成功\n");
                break;
            }

            else
            {
                char c;
                while ((c = getchar()) != '\n')//清空缓存
                {
                    
                    printf("清空缓存中: %c\n",c);
                }
                
            }
            printf("失败，再试一遍\n");
            
        }
        float i = N/3.02e-23L;
        break;
    }

    //(3)----------------------------------
    case 3:
    {
        //'a'和"a"的不同之处在于 单引号再C语言被认为是字符常量，双引号的则是字符串，且"a"后面会带一个\0
        break;
    }

    //(4)-------------------------------------------
    case 4:
    {
        int sum = 1;
        int n;
        while (1)
        {
            if (scanf("%d",&n) == 1 && getchar() == '\n')
            {

                printf("成功\n");
                break;
            }
            else
            {
                while (getchar() != '\n')
                {
                    
                }
                
            }
            
        }

        int a;
        for( a = 0;sum <= n;sum++ )
        {
            a +=sum;
        }
        printf("a = %d\n",a);
        break;
    }

    //(5)------------------------------
    case 5:
    {

    }
    return 0;



    
    }
}

