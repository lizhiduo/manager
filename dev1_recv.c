/*************************************************************************
	> File Name: dev1_recv.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月17日 星期日 20时06分59秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

#include"receive_manager.h"
#include"init.h"

/*
static int getDev1RecvData(char data[]){
    char buf[] = "dev1 test";

    memcpy(data, buf, sizeof(buf));

    return sizeof(buf);
}
*/

static int dev1RecvInit(){
    
    printf("[%s][%s]\n", __FILE__, __func__);
    
    return 0;
}

static RECEIVEOPR dev1Recv = {
    .name = "dev1_recv",
    .devInit = dev1RecvInit,
//    .getDevData = getDev1RecvData,
};

static int dev1Reg(void){
    return registerRecvOpr(&dev1Recv);
}

DECLARE_INIT(dev1Reg);

