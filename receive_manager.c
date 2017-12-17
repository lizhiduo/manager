/*************************************************************************
	> File Name: receive_manager.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 18时55分31秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#include"receive_manager.h"
#include"manager_api.h"
#include "init.h"

static RECEIVEOPR *listRecvHead = NULL;
static RECEIVEOPR *defDev = NULL;

int registerRecvOpr(RECEIVEOPR *p){
    RECEIVEOPR *listTmp;
    
    if(!listRecvHead){
        listRecvHead = p;
        p->next = NULL;
    }else{
        listTmp = listRecvHead;
        while(listTmp->next){
            listTmp = listTmp->next;
        }
        listTmp->next = p;
        p->next = NULL;
    }
    
    return 0;
}

int selectRecvDev(char *name){
    RECEIVEOPR *listTmp = listRecvHead;
    int len = strlen(name);
    
    while(listTmp){
        if(strlen(listTmp->name) == len){
            if(strcmp(listTmp->name, name) == 0){
                defDev = listTmp;
                return 0;
            }
        }
        listTmp++;
    }

    return -1;
}

int getDevData(char data[]){
    int ret;
    char buf[]="from manager";

    if(defDev){
        /* 使用底层实现 */
        if(defDev->getDevData){
            ret = defDev->getDevData(data);
        }else{
            /* 中间层进行处理 */
            memcpy(data, buf, sizeof(buf));
            ret = sizeof(buf);
        }

    }else{
        return -1;
    }

    return ret;
}

int recvDevInit(){
    
    if(defDev){
        if(defDev->devInit() == 0){
            return 0;
        }else{
            return -1;
        }
    }else{
        return -1;
    }
}

static void module_init(){
    init_fn_t *fn;
    int ret = -1;

    for(fn=&__start_init_sec; fn<&__stop_init_sec; fn++){
        ret = (*fn)();
        printf("ret:%d %p\n", ret, *fn);
    }
}

int recvManagerInit(){
    
    module_init();

    return 0;
}

