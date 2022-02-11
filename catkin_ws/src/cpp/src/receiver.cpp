#include "stdio.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include "string.h"
#include "../include/context.h"
#include "../lib/mavlink/ardupilotmega/mavlink.h"

static int sockfd;
static struct sockaddr_in servaddr;
static unsigned char buffer[256];
static unsigned int buffer_size = 0;

int receive(context_data* ctx)
{
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        fprintf(stderr, "ERROR: QGC socket creation failed\n");
        return PROGRAM_ERROR;
    }
    int trueflag = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &trueflag, sizeof(trueflag));
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &trueflag, sizeof(trueflag));
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ctx->ip_address);
    servaddr.sin_port = htons(ctx->port);
    if(bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(struct sockaddr_in)) < 0) {
        fprintf(stderr, "ERROR: QGC socket bind failed\n");
        return PROGRAM_ERROR;
    }
    
    int bytes_read = 0;
    socklen_t addrlen = sizeof(servaddr);
    unsigned char write_data_buffer[1024];
    mavlink_message_t msg;
    mavlink_status_t status;
    unsigned int rx_drop_count = 0;
    int msg_received = 0;
    while (true) {
        bytes_read = recvfrom(sockfd, (char*) write_data_buffer,
                                1024, MSG_WAITALL, 
                                (struct sockaddr*) &servaddr, &addrlen);
        if (bytes_read > 0) {
            int i = 0;
            for (; i < bytes_read; i++) {
                msg_received = mavlink_parse_char(0, write_data_buffer[i], &msg, &status);

                // check for dropped packets
                if (status.packet_rx_drop_count != rx_drop_count) {
                    fprintf(stderr,"DROPPED %d PACKETS\n", status.packet_rx_drop_count);
                }
                rx_drop_count = status.packet_rx_drop_count;

                // Send valid messages to the message handler
                if (msg_received) {
                    if (msg.msgid == MAVLINK_MSG_ID_HEARTBEAT){
                        printf("RECEIVE\n");
                    }
                }
            }
        }
    }

}