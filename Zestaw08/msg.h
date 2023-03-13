#define NAME "/kolejka"
#define QUEUE_PERMISSION 0660
#define MAX_MSG 10
#define MAX_MSG_SIZE 1024
#define MSG_BUFFER_SIZE 1024

struct mq_attr attr;
typedef char komunikat;
int msgCreate(const char *name);
int msgOpen(const char *name);
void msgClose(const char *name);
void msgRm(const char *name);
void msgSend(int msgid, komunikat *msg);
void msgRecv(int msgid, komunikat *msg);
void msgInfo(int msgid);
