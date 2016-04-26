CC = gcc
C_FLAGS = -Wall -Wextra
CSTUFF = rpc_client.c rpc_clnt.c rpc_xdr.c
SSTUFF = rpc_server.c rpc_svc.c rpc_xdr.c
GEN = rpc.h rpc_clnt.c rpc_svc.c rpc_xdr.c
RPC = rpc.x

all: client server

client: rpc_client.c rpc_clnt.c rpc_xdr.c $(GEN)
	$(CC) $(CSTUFF) -o client

server: rpc_server.c rpc_svc.c rpc_xdr.c $(GEN)
	$(CC) $(SSTUFF) -o server

$(GEN):  $(RPC)
	rpcgen $(RPC)
