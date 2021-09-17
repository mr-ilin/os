#include "bin_tree.h"

treeptr tree_add(treeptr node, int v) {
	if (node == NULL) {
		node = malloc(sizeof(tree));
		if (node == NULL) {
			fprintf(stderr, "[%d] ", getpid());
			perror("ERROR tree_add ");
			return false;;
		}
		node->val = v;
		node->l = NULL;
		node->r = NULL;
		return node;
	}

	if (v < node->val) {
		node->l = tree_add(node->l, v);
	} else if(v > node->val) {
		node->r = tree_add(node->r, v);
	}
	return node;
}

treeptr find_node(treeptr root, int to_find) {
	if (root == NULL) {
		return NULL;
	}

	if (root->val < to_find) {
		return find_node(root->r, to_find);
	} else 
	if (root->val > to_find) {
		return find_node(root->l, to_find);
	} else {
		return root;
	}
}

treeptr find_parent(treeptr root, int val) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == val) {
		return NULL;
	}

	if (root->l) {
		if (root->l->val == val) {
			return root;
		}
	}
	if (root->r) {
		if (root->r->val == val) {
			return root;
		}
	}

	treeptr lefr_res = find_parent(root->l, val);
	treeptr right_res = find_parent(root->r, val);
	if (lefr_res) {
		return lefr_res;
	}
	return right_res;
}

// void remove_node(treeptr *t) {
// 	treeptr tofree = *t;
// 	treeptr l = (*t)->l;
// 	treeptr r = (*t)->r;

// 	if (r == NULL) {
// 		*t = l;
// 	}
// 	else if(l == NULL) {
// 		*t = r; 
// 	} else {
// 		treeptr *new_tree = &(*t)->l;
// 		while ((*new_tree)->r != NULL) {
// 			new_tree = &(*new_tree)->r;
// 		}

// 		treeptr l_max = *new_tree;
// 		*new_tree = (*new_tree)->l;
// 		l_max->l = l;
// 		l_max->r = r;
// 		*t = l_max;
// 	}
// 	free(tofree);
// }

treeptr min_value_node(treeptr node) {
    treeptr current = node;
    while (current && current->l != NULL) {
		current = current->l;
	}
    return current;
}
 
treeptr delete_node(treeptr root, int val) {
    if (root == NULL) { return root; }
        
    if (val < root->val) {
		root->l = delete_node(root->l, val);
	} else 
	if (val > root->val) {
        root->r = delete_node(root->r, val);
	} else {
        if (root->l == NULL) {
			treeptr temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL) {
            treeptr temp = root->l;
            free(root);
            return temp;
        }

        treeptr temp = min_value_node(root->r);
        root->val = temp->val;
        root->r = delete_node(root->r, temp->val);
    }
    return root;
}

void delete_tree(treeptr root) {
	if (root == NULL) {
		return;
	}

	delete_tree(root->l);
	delete_tree(root->r);

	free(root);
}

void _print_tree(treeptr root, int level) {
	if (!root) { return; }
	_print_tree(root->r, level+1);
	for (int i = 0; i < level; ++i) { printf("\t"); }
	printf("%d, %d\n", root->val, root->pid);
	_print_tree(root->l, level+1);
}

void print_tree(treeptr root) {
	_print_tree(root, 0);
}
