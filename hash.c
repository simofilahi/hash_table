#include "hash.h"
#include "libft/libft.h"
#include <stdio.h>

unsigned int hash(char *key)
{
	int value;

	value = key[0] - 'a';
	return (value % BUFF_SIZE);
}

t_hash *lookup(t_hash *hash_arr[], char *key)
{
    unsigned int index = hash(key);
    t_hash *curr = hash_arr[index];

    while(curr != NULL && ft_strcmp(curr->key, key) != 0)
        curr = curr->next;
    if (curr)
    	printf("curr->key %s\n", curr->key);
    return curr;
}

void insert(t_hash *hash_arr[], char *key, char *value)
{
	t_hash *node;
	unsigned int  index;
	
	if ((node = lookup(hash_arr, key)))
	{
		printf("holla\n");
		node->counter++;
		return ;
	}
	if (!(node = (t_hash *)malloc(sizeof(t_hash))))
		return ;
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->counter++;
	node->next = NULL;
	index = hash(key);
	printf("here index %d\n", index);
	if (!hash_arr[index])
		hash_arr[index] = node;
	else
	{
		t_hash *curr = hash_arr[index];
		while(curr->next)
			curr = curr->next;
		curr->next = node;
		printf("value in curr->next %s\n", curr->next->value);
	}
}


int main()
{
	char *key;
	char *value;
	char buff[100];
	t_hash *hash_arr[BUFF_SIZE + 1] = {0};

	(void)hash_arr;
	int i = 0;
	while (i++ < 2)
	{
		ft_bzero(buff,sizeof(buff));
		read(0, buff, sizeof(buff));
		key = ft_strdup(buff);
		ft_bzero(buff,sizeof(buff));
		read(0, buff, sizeof(buff));
		value = ft_strdup(buff);
		insert(hash_arr, key,value);
	}
	t_hash *node;
	
	i = 0;
	while (i < BUFF_SIZE)
	{
		node = hash_arr[i];
		while (node)
		{
			printf("key ==> %s\nvalue ==> %s\ncounter ==> %d\n", node->key, node->value, node->counter);
			node = node->next;
		}
		i++;
	}
	/*
	node = lookup(hash_arr,"who\n");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"ls\n");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"whoami\n");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"cat\n");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"cut\n");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"wc")\n;
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"df");
	printf("value is %s\n", node->value);
	node = lookup(hash_arr,"ping");
	printf("value is %s\n", node->value);*/
	return (0);
}
