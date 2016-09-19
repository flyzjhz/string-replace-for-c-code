#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *fullstr = "rtsp://1/2/3.ts/tranckID=1 ";                                                                                                  
    char *requeststr = "SETUP rtsp://1/2/3.ts/* RTSP/1.0";
    char *ptr = NULL;
    char newstr[4096] = {0};
    char *start = NULL,*end = NULL;
    printf("full len:%d\n",strlen(requeststr));    
    start = strstr(requeststr,"rtsp");
    end = strstr(requeststr,"RTSP");
    ptr = newstr;
    int len = start - requeststr;
    strncpy(newstr,requeststr,len);
    strncpy(ptr+len,fullstr,strlen(fullstr));
    strncpy(ptr+len+strlen(fullstr),end,strlen(end));
    printf("newstr:%s\n",newstr);

    return 0;
}