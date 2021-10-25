#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <libtree.h>

struct KV
{
  int key;
  char *value;
};

struct Unit
{
  struct KV kv;
  struct bstree_node node;
};

struct bstree_node *return_node(int key, char *value)
{
	int len = 0;
	struct Unit *unit = (struct Unit*)malloc(sizeof(struct Unit));

	unit->kv.key = key;
  
    if(value)
    {
      len = strlen(value);
    }
  
    unit->kv.value = (char *)malloc(sizeof(char) * (len + 1));
    memcpy(unit->kv.value, value, len);
    unit->kv.value[len] = '\0';
    
    unit->node.left  = 0;
    unit->node.right = 0;
    
	return &(unit->node);
}

struct KV return_kv(const struct bstree_node *node)
{
	/*bstree_container_of 源码: 
	* https://github.com/fbuihuu/libtree/blob/8532e24b3e2774cf0ad312bef539e116a49ddd0d/libtree.h#L28
	*/
	struct Unit *unit = bstree_container_of(node, struct Unit, node);
	return unit->kv;
}

int bstree_cmp(const struct bstree_node *a, const struct bstree_node *b)
{

  struct KV a_kv = return_kv(a);
  struct KV b_kv = return_kv(b);
  
  return a_kv.key - b_kv.key;
}

struct KV* bstree_insert_kv(int key, char* value, struct bstree *tree)
{
	struct bstree_node *insert = return_node(key, value);
	struct bstree_node *retur  = bstree_insert(insert, tree);
	
	if(!retur) return 0;
	struct KV *kv = (struct KV *)malloc(sizeof(struct KV));
	*kv = return_kv(retur);
	return kv;
}

struct KV* bstree_lookup_kv(int key, struct bstree *tree)
{
	struct bstree_node *lookup = return_node(key, NULL);
	struct bstree_node *retur  = bstree_lookup(lookup, tree);

	if(!retur) return 0;
	struct KV *kv = (struct KV *)malloc(sizeof(struct KV));
	*kv = return_kv(retur);
	return kv;
}

struct bstree *bstree_init_kv()
{
	struct bstree *tree = (struct bstree *)malloc(sizeof(struct bstree));
	bstree_init(tree, bstree_cmp, 0);
	
	return tree;
}

void main()
{
  struct bstree *tree = bstree_init_kv();
  
  bstree_insert_kv(1, "1", tree);
  bstree_insert_kv(2, "2", tree);
  bstree_insert_kv(3, "3", tree);
  
  assert(strcmp(bstree_lookup_kv(1, tree)->value, "1") == 0);
}