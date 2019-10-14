#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *printNumber(void *argv)
{
	int upper = atoi(argv);
	for(int i=0;i<upper;i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
	pthread_exit(0);
}

int main(int argc, char *argv[])
{
	pthread_t td;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&td, &attr, printNumber, argv[1]);
	
	//pthread_join(td, NULL);

	fprintf(stderr, "%s\n", "Success");

}
