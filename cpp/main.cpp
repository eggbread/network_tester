#include "stdio.h"
#include "sender.h"
#include "receiver.h"
#include <iostream>
#include "string.h"
#include "context.h"

using namespace std;

static context_data context;

int main(int argc, char const *argv[])
{
    if (!strcmp(argv[1],"receiver")){
        context.mode = 0;
        printf("Mode : Receiver\n");
    } else if (!strcmp(argv[1],"sender")) {
        context.mode = 1;
        printf("Mode : Sender\n");
    } else {
        printf("Argument Error\n");
        return 0;
    }
    strncpy(context.ip_address,argv[2],IP_ADDRESS_MAX_SIZE);
    context.port = atoi(argv[3]);
    printf("==========CPP Sender Network Tester==========\n");
    printf("Address : %s:%d\n",context.ip_address, context.port);

    if(context.mode) {
        send(&context);
    } else {
        receive(&context);
    }
    
    return 0;
}
