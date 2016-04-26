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
    struct response get(int) = 1;
    int put(struct message) = 2;
  } = 1;
} = 0x20000001;
