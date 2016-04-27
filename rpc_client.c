/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MESSAGE_LEN 10

char *generate_str();
void _funcget();
void _funcput();

CLIENT *clnt;
char *host;

int main (int argc, char *argv[]) {
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	clnt = clnt_create(host, RPC_PROG, RPC_VER, "tcp");
	if (clnt == (CLIENT *) NULL) {
		clnt_pcreateerror(host);
		exit(EXIT_FAILURE);
	}

	int identifier = getpid();
	printf("Client ID : %d.\n", identifier);
	int i = 0;
	while (i < 5) {
		int *ret_num;
		int filler;

		struct message test;
		strcpy(test.content, generate_str);
		test.ID = identifier;
		printf("put is here\n");

		ret_num = put_1(&test, clnt);
		i++;
		sleep(1);
	}

	sleep(5);

	struct response *ret_val;
	ret_val = get_1(&identifier, clnt);
	printf("get ran.\n");
	exit (0);
}

char *generate_str() {
	const charset[] = "abcdefghijklmnopqrstuvwxyz";
	char *randomstr = NULL;

	size_t size = MESSAGE_LEN - 1;
	size_t i;
	for (i = 0; i < size; i++) {
		int key = rand() % (int) (sizeof(charset) - 1);
		randomstr[i] = charset[key];
	}
	randomstr[size] = '\0';

	return randomstr;
}
