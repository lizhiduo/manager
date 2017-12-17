/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 20时22分27秒
 ************************************************************************/

#include<stdio.h>

#include"manager_api.h"

int main(){
    int ret = 0;
    char buf[64]={0};

    recvManagerInit();

    ret = selectRecvDev("dev1_recv");
    if(ret<0){
        printf("no this dev\n");
        return ret;
    }
    recvDevInit();

    ret = getDevData(buf);
    printf("ret:%d data:%s\n", ret, buf);

    return ret;
}

