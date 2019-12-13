/*************************************************************************
	> File Name: config.h
	> Author: 
	> Mail: 
	> Created Time: Tue 19 May 2015 11:03:23 PM PDT
 ************************************************************************/

#ifndef _CONF_H
#define _CONF_H

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <libconfig.h>

#define MIRROR

#define USE_HTTP

#define MAXLABEL 2

enum packet_type
{
    M_REQ = 1,
    M_RSP = 2,
    M_UKO = 3
};

struct mconfig
{
    int  enable_http;    //network type IOT/normal HTTP. 1: HTTP, else IOT
    int  enable_hy;      //server platform. 1:Hy,else x86

    /*parse request/response packet in IOT network*/
    int req_label[MAXLABEL];  //labels for request judge
    int resp_label[MAXLABEL]; //labels for response judge
    int label_offset;         //offset of label located in payload 
    int label_count;

    /*indicate request priority in IOT network*/
    int enable_pri;
    int pri_offset;
    int pri_high_label;
    int pri_low_label;

    int enable_python;  //enable python print cdf
    int enable_sql;     //enable sql connected
};

struct mconfig* initConfig();
int getConfig(struct mconfig *conf);

struct mconfig *conf;

uint32_t pkt_num;

char pf[10];

#endif

