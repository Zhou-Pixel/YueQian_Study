/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-04 18:49:29
 * @LastEditTime: 2021-08-06 20:07:10
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \code\Experiment\IO\exp2\exp2_2.c
 */
/*
 *                        _oo0oo_
 *                       o8888888o
 *                       88" . "88
 *                       (| -_- |)
 *                       0\  =  /0
 *                     ___/`---'\___
 *                   .' \\|     |// '.
 *                  / \\|||  :  |||// \
 *                 / _||||| -:- |||||- \
 *                |   | \\\  - /// |   |
 *                | \_|  ''\---/''  |_/ |
 *                \  .-\__  '-'  ___/-. /
 *              ___'. .'  /--.--\  `. .'___
 *           ."" '<  `.___\_<|>_/___.' >' "".
 *          | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *          \  \ `_.   \_ __\ /__ _/   .-` /  /
 *      =====`-.____`.___ \_____/___.-`___.-'=====
 *                        `=---='
 * 
 * 
 *      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * 
 *            佛祖保佑       永不宕机     永无BUG
 */

/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-04 18:49:29
 * @LastEditTime: 2021-08-04 20:09:20
 * @LastEditors: ZhouGuiqing
 * @Description: 测试标准IO缓冲区的大小
 * @FilePath: \code\Experiment\IO\exp2\exp2_2.c
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp1 = fopen("a.txt","w");
    FILE *fp2 = fopen("a.txt","w+");
    // fseek(fp2, 0, SEEK_SET);
    int count = 0;
    while (1)
    {
        // printf("%d\n",ftell(fp));
        fprintf(fp1, "%c", 'a');
        count++;
        if (fgetc(fp2) != EOF)
        {
            // printf("%ld\n",ftell(fp2));
            break;
        }
        

        
    }
    
    printf("%d\n",count);
    // char buf[10];
    // fgets(buf, 10, fp);
    // printf("%d\n",strlen(buf));
    fclose(fp1);
    fclose(fp2);
    return 0;
}