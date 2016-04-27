/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "rpc.h"

char *current_local_time();

char *messages[39999];

int *put_1_svc(struct message *argp, struct svc_req *rqstp) {
	int client_id = argp->ID;
	printf("Server had a put() request from client %d at current local time: %s.\n", client_id, current_local_time());
	int result;

	char *message = argp->content;
	if (message == NULL) {
		result = -1;
		return &result;
	}

	messages[client_id] = message;
	printf("For Client %d, put message: %s\n", client_id, messages[client_id]);

	result = 0;
	return &result;
}

struct response *get_1_svc(int *argp, struct svc_req *rqstp) {
	printf("Server had a get() request from client %d at current local time: %s.\n", (int) argp, current_local_time());
	static struct response result;



	return &result;
}

char *current_local_time() {
	time_t rawtime;
	time (&rawtime);
	char *current_time = ctime(&rawtime);
	return current_time;
}
