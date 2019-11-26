#ifndef MQ_H
#define MQ_H

#define MQ_SEND_MSG 840
#define MQ_RECV_MSG 841

#pragma pack(push, 1)
struct mq_reg
{
    char* data;
    int size;
};
#pragma pack(pop)

#endif