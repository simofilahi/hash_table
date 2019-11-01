#ifndef HASH_H
#define HASH_H

#define BUFF_SIZE 50

typedef struct s_hash t_hash;

struct s_hash
{
	char *key;
	char *value;
	int   counter;
	t_hash *next;
};
#endif
