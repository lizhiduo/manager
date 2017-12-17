/*************************************************************************
	> File Name: manager_api.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 19时07分23秒
 ************************************************************************/

#ifndef _MANAGER_API_H
#define _MANAGER_API_H

extern int recvDevInit();
extern int recvManagerInit();
extern int selectRecvDev(char *name);
extern int getDevData(char data[]);

#endif
