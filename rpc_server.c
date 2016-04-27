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
int generate_num();

struct message messages[100] = {{"", 1}};

int *put_1_svc(struct message *argp, struct svc_req *rqstp) {
	int client_id = argp->ID;
	printf("Server had a put() request from client %d at current local time: %s.\n", client_id, current_local_time());
	int randomindex = generate_num();
	static int result;

	if (argp->content == NULL) {
		result = -1;
		return &result;
	}

	messages[randomindex].ID = client_id;
	strcpy(messages[randomindex].content, argp->content);
	printf("For Client %d, put message: %s\n\n", messages[randomindex].ID, messages[randomindex].content);

	result = 0;
	return &result;
}

struct response *get_1_svc(int *argp, struct svc_req *rqstp) {
	int client_id = *argp;
	printf("Server had a get() request from client %d at current local time: %s.\n", client_id, current_local_time());
	static struct response result;
	int randomindex = generate_num();

	while (messages[randomindex].ID == client_id) {
		randomindex = generate_num()%100;
	}

	if (messages[randomindex].content == "") {
		result.status_code = -1;
	} else {
		result.status_code = 0;
	}

	strcpy(result.content, messages[randomindex].content);

	return &result;
}

char *current_local_time() {
	time_t rawtime;
	time (&rawtime);
	char *current_time = ctime(&rawtime);
	return current_time;
}

int generate_num() {
	srand(time(NULL));
	int r = rand()%(100 - 1);
	return r;
}
