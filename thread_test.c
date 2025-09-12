#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread_routine(void *arg)
{
	int	*i;

	i = (int *)arg;
	while (*i < 1000000)
		i++;
	return (i);
}

int main(void)
{
	pthread_t	thread;
	int			i[1];

	*i = 0;
	pthread_create(&thread, NULL, thread_routine, i);
	pthread_join(thread, NULL);
	while (*i < 500000) {
		printf("%d\n", *i);
	};
	pthread_detach(thread);
	return (0);
}
