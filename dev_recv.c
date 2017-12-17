/*************************************************************************
	> File Name: dev_recv.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 20时06分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#include"receive_manager.h"
#include"init.h"

static int getDevRecvData(char data[]){
    char buf[] = "dev test";

    memcpy(data, buf, sizeof(buf));

    return sizeof(buf);
}

static int devRecvInit(){
    
    printf("[%s][%s]\n", __FILE__, __func__);
    
    return 0;
}

static RECEIVEOPR devRecv = {
    .name = "dev_recv",
    .devInit = devRecvInit,
    .getDevData = getDevRecvData,
};

static int devReg(void){
    return registerRecvOpr(&devRecv);
}

DECLARE_INIT(devReg);

