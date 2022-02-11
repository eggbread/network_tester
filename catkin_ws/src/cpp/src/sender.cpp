#include "stdio.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "../include/context.h"
#include <typeinfo>
#include <unistd.h>
#include <signal.h>
#include "string.h"
#include "../lib/mavlink/ardupilotmega/mavlink.h"

static int sockfd;
struct sockaddr_in recvaddr;
static unsigned char buffer[256];
static unsigned int buffer_size = 0;

int send(context_data* ctx)
{
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        fprintf(stderr, "ERROR: QGC socket creation failed\n");
        return PROGRAM_ERROR;
    }
    int trueflag = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &trueflag, sizeof(trueflag));
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &trueflag, sizeof(trueflag));
    memset(&recvaddr,0,sizeof(recvaddr));
    recvaddr.sin_family = AF_INET;
    recvaddr.sin_addr.s_addr = inet_addr(ctx->ip_address);
    recvaddr.sin_port = htons(ctx->port);
    while (true){
        printf("SEND HEARTBEAT\n");
        mavlink_message_t message;
        mavlink_heartbeat_t hb;
        memset(&hb, 0 , sizeof(hb));
        mavlink_msg_heartbeat_encode(
            1,1,&message,&hb
        );
        buffer_size = mavlink_msg_to_send_buffer(buffer,(const mavlink_message_t*)&message);
        sendto(sockfd, buffer, buffer_size, MSG_CONFIRM,(const struct sockaddr*)&recvaddr,sizeof(recvaddr));
        sleep(1);
    }
}