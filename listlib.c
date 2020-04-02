#include "listlib.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define TRAV_INIT_SIZE 8

typedef struct list_struct {
	/* data */
	data_t item;
	struct list_struct *next;
} list_t;

static list_t endlist;
static list_t *headptr = NULL;
static list_t *tailptr = NULL;
static list_t **travptrs = NULL;
static int travptrs_size = 0;

int accessdata(void) {
	int i;
	list_t **newptrs;

	if (NULL == headptr) {
		//should not access an empty list
		errno = EINVAL;
		return -1;
	}

	if (0 == travptrs_size) {
		//first time to travel
		travptrs = (list_t **)calloc(TRAV_INIT_SIZE, sizeof(list_t *));
		if (NULL == travptrs) {
			return -1;
		}

		travptrs[0] = headptr;
		travptrs_size = TRAV_INIT_SIZE;
		return 0;
	}

	for (i = 0; i < travptrs_size; i++) {
		if (NULL == travptrs[i]) {
			travptrs[i] = headptr;
			return i;
		}
	}

	//we have not enough space
	//realloc
	newptrs = realloc(travptrs, 2 * travptrs_size * sizeof(list_t *));
	if (NULL == newptrs) {
		return -1;
	}

	travptrs = newptrs;
	travptrs[travptrs_size] = headptr;
	travptrs_size = travptrs_size * 2;

	return travptrs_size / 2;
}

int adddata(data_t data) {
	list_t *newnode;
	int nodesize;

	nodesize = sizeof(list_t) + strlen(data.string) + 1;
	if (NULL == (newnode = (list_t *)(malloc(nodesize)))) {
		return -1;
	}

	newnode->item.time = data.time;
	newnode->item.string = (char *)newnode + sizeof(list_t);
	strcpy(newnode->item.string, data.string);
	newnode->next = NULL;

	if (NULL == headptr) {
		headptr = newnode;
	} else {
		tailptr->next = newnode;
	}
	tailptr = newnode;

	return 0;
}

int getdata(int key, data_t *datap) {
	list_t *t;

	if ( (key < 0) || (key >= travptrs_size) || (NULL == travptrs[key])) {
		errno = EINVAL;
		return -1;
	}

	if (travptrs[key] == &endlist) {
		datap->string = NULL;
		travptrs[key] = NULL;
		return -1;
	}

	t = travptrs[key];
	datap->string = (char *)malloc(strlen(t->item.string) + 1);
	if (NULL == datap->string) {
		return -1;
	}
	datap->time = t->item.time;
	strcpy(datap->string, t->item.string);
	if (NULL == t->next) {
		travptrs[key] = &endlist;
	} else {
		travptrs[key] = t->next;
	}

	return 0;
}

int freekey(int key) {
	if ( (key < 0) || (key >= travptrs_size)) {
		errno = EINVAL;
		return -1;
	}

	travptrs[key] = NULL;
	return 0;
}