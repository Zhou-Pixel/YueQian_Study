/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-04 18:50:29
 * @LastEditTime: 2021-08-07 16:41:30
 * @LastEditors: ZhouGuiqing
 * @Description: 
 * @FilePath: \code\Experiment\IO\exp2\exp2_3.c
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
 * @Date: 2021-08-04 18:50:29
 * @LastEditTime: 2021-08-04 20:09:06
 * @LastEditors: ZhouGuiqing
 * @Description:打印时间并且，把序号连续打印出来
 * @FilePath: \code\Experiment\IO\exp2\exp2_3.c
 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

    FILE *fp = fopen("time.txt", "a+");
    setvbuf(fp, NULL, _IONBF, 0);
    fseek(fp, 0, SEEK_SET);
    int count = 0;
    char buf[100];

    do
    {
        count++;
    } while (fgets(buf, 100, fp) != NULL);

    // if(count == 0)
    //     count = 1;//为了保证count从1开始

    while (1)
    {
        time_t t = time(NULL);
        fprintf(fp, "%d, %s", count, ctime(&t));
        printf("%d, %s", count++, ctime(&t));
        sleep(1);
    }

    return 0;
}
