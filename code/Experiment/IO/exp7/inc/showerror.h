/*
 * @Author: ZhouGuiqing
 * @Date: 2021-08-12 17:04:14
 * @LastEditTime: 2021-08-18 20:35:25
 * @LastEditors: ZhouGuiqing
 * @Description: 错误码 
 * @FilePath: \YueQian\code\Experiment\IO\exp7\inc\showerror.h
 */
#ifndef _SHOWERROR_H
#define _SHOWERROR_H



#define OPENPICFAILED   1   //打开图片失败
#define OPENLCDFAILED   2   //打开lcd文件失败
#define MMAPFAILED      3   //内存映射失败
#define NOTSUPPORTED    4   //暂未支持的图片显示类型
#define SUCCESS         0   //显示图片成功
#define UNKNOWN        -1   //未知错误
#endif