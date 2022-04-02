#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/*TODO: put new process to queue[q]  */
	if(q==NULL || q->size == MAX_QUEUE_SIZE ||
			proc == NULL)
		return;
	else{
	q->proc[q->size] = proc;
	q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size == 0) return NULL;
	struct pcb_t * proc = q->proc[0];
	for(int i = 0 ; i < q->size ; i++) {
		if(proc->priority < q->proc[i]->priority) {
			proc = q->proc[i];
		}
	}
	for(int i = 0 ; i < q->size ; i++) {
		if(q->proc[i] == proc) {
			for(int j = i ; j < q->size - 1 ; j++) {
				q->proc[j] = q->proc[j+1];
			}
			q->size--;
			break;
		}
	}
	return proc;
}
