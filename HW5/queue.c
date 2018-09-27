/**
 * @file queue.c
 */

 /*
 320112
 problem_5.4
 Brian Sherif Nazmi Hanna Nasralla
 b.hannanasralla@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void copy_to_node(Item item, Node *pn);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
    Node *newel;
    newel=(Node*)malloc(1*sizeof(Node));
    copy_to_node(item, newel);

    // first element to be entered
    if(pq->front == NULL && pq->rear == NULL)
    {
        pq->front=pq->rear=newel;
        pq->items=1;
    }

    else
    {
        pq->rear->next=newel;
        newel->next=NULL;
        pq->rear=newel;
        pq->items++;
    }
        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
    if (queue_is_empty(pq))
    {
        printf("Queue underflow");
        return -1;
    }

	Node *temp;
	temp=(Node*)malloc(1*sizeof(Node));

	temp=pq->front;
	pq->front=pq->front->next;
	*pitem=temp->item;
	free(temp);
	pq->items--;

        return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}
