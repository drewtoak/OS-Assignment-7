struct message {
  char content[7999];
  int ID;
};

struct response {
  char content[7999];
  int status_code;
};

program RPC_PROG {
  version RPC_VER {
    int put(struct message) = 1;
    struct response get(int) = 2;
  } = 1;
} = 0x20000001;
