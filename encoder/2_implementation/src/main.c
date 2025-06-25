#include "../include/encoder.h"
#include "../include/log.h"
#include <stdio.h>

int main(int argv, char **argc) {
	log_info("Encoder begins");

	Encoder enc = {.key = "123456789101112131415161718192021222324252627282930",
				   .server_host = "192.168.1.1",
				   .server_port = "8080",
				   .target_directory = "/home/user/files"};

	CollectedData data = {.hostname = "machine01",
						  .key = "12345678901234567890123456789012",
						  .mac_addres = "AA:BB:CC:DD:EE:FF"};

	strcpy(data.active_users[0], "user1");
	strcpy(data.active_users[1], "user2");

	log_info("%s\n", encoder_to_string(&enc));
	log_info("%s\n", collected_data_to_string(&data));

	return 0;
}
