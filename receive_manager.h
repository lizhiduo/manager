/*************************************************************************
	> File Name: receive_manager.h
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 19时00分05秒
 ************************************************************************/

#ifndef _RECEIVE_MANAGER_H
#define _RECEIVE_MANAGER_H
typedef struct ReceiveOpr{
    char *name;
    int (*getDevData)(char data[]);
    int (*devInit)();
    struct ReceiveOpr *next;
}RECEIVEOPR;

extern int registerRecvOpr(RECEIVEOPR *p);

#endif
