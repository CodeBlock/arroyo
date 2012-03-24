#include "ast.h"

#include <stdio.h>

#define WHEN_NODE(node, body) case NODE_##node: { body; break; }
#define NODE_TYPE_FUNCTION(type, var, func) switch (type) {         \
    WHEN_NODE (NIL, var nil_node_##func);                           \
    WHEN_NODE (REAL, var real_node_##func);                         \
    WHEN_NODE (BOOL, var bool_node_##func);                         \
    WHEN_NODE (STRING, var string_node_##func);                     \
    /* WHEN_NODE (ID, var id_node_##func); */                       \
    WHEN_NODE (FN, var fn_node_##func);                             \
    WHEN_NODE (ARRAY, var array_node_##func);                       \
    /* WHEN_NODE (HASH, var hash_node_##func);     */               \
    /* WHEN_NODE (BINARY, var binary_node_##func); */               \
    /* WHEN_NODE (UNARY, var unary_node_##func);   */               \
    /* WHEN_NODE (LOOP, var loop_node_##func);     */               \
    WHEN_NODE (IF, var if_node_##func);                             \
    WHEN_NODE (BLOCK, var block_node_##func);                       \
  default:                                                          \
    puts ("hit default");                                           \
  }


expression_node* expression_node_create (node_type type, void* node_struct)
{
  expression_node* node = calloc (sizeof (expression_node), 1);

  node->type = type;
  node->ast_node = node_struct;
  return node;
}

void expression_node_destroy (expression_node* node)
{
  NODE_TYPE_FUNCTION (node->type, /* NONE */, destroy (node->ast_node));

  node = NULL;
}

expression_node* expression_node_evaluate (expression_node* node)
{
  // TODO
  return NULL;
}

char* expression_node_to_string (expression_node* node)
{
  string_node* string = NULL;

  NODE_TYPE_FUNCTION (node->type, string=, to_string_node (node->ast_node));

  if (!string) return NULL;

  return string->string;
}