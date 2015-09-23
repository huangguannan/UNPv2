#include	"svmsg.h"

void	client(int, int);

int
main(int argc, char **argv)
{
	int		readid, writeid;

	/* server must create its well-known queue */
	writeid = Msgget(MQ_KEY1, 0);
	/* we create our own private queue, and in client() we tranport our queue id to server */
	readid = Msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

	client(readid, writeid);

	/* work done , and delete our private queue */
	Msgctl(readid, IPC_RMID, NULL);

	exit(0);
}
