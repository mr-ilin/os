#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct tree tree;
typedef tree* treeptr;
typedef struct tree_value tree_value;

struct tree {
 	int val;
	pid_t pid;
	tree *l;
	tree *r;
}; 

treeptr tree_add(treeptr node, int val);
treeptr find_node(treeptr root, int to_find);
treeptr delete_node(treeptr root, int val);

treeptr find_parent(treeptr root, int val);
void print_tree(treeptr root);
void delete_tree(treeptr root);
