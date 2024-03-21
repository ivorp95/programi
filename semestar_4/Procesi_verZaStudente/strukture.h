#define MAXTIME 21

#ifndef STRUKTURE_H_
#define STRUKTURE_H_

typedef struct
{
	char pID[4];
	int arrivalTime;
	int burstTime;

	int startTime;
	int completionTime;
	int turnaroundTime;
	int waitingTime;
	int remainingTime;
	int flag;
	int order;
} Proces;


typedef struct
{
	float att;
	float awt;
	int quantum;
} Algoritam;


#endif