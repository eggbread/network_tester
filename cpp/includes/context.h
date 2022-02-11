#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdint.h>
#include <pthread.h>

#define PROGRAM_ERROR -1

#define IP_ADDRESS_MAX_SIZE 64

typedef struct _context_data {
    char ip_address[IP_ADDRESS_MAX_SIZE];

    uint16_t port;
    //0:receiver, 1:sender
    uint8_t mode;
} context_data;


#endif