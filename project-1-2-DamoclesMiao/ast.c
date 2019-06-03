#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "utils.h"

/*
   Creates a new AST from a given type filename and linenum. You should not
   assume that filename will remain a legal pointer after this function
   terminates.
*/
AST* MakeAST(enum NodeType type, char* filename, int linenum) {
    char* temp = (char*)malloc((1+strlen(filename))*sizeof(char));
    if(temp==NULL){
        allocation_failed();
    }
    AST* x=(AST*)malloc(sizeof(AST));
    if(x==NULL){
        allocation_failed();
    }
    strcpy(temp, filename);
    x->filename=temp;
    x->linenum=linenum;
    x->type=type;
    x->size=0;
    x->capacity=INITIAL_CAPACITY;
    x->children = (AST**)malloc(INITIAL_CAPACITY*sizeof(AST*));
    if(x->children==NULL){allocation_failed();}
 

  /* YOUR CODE HERE. */
    return x;
}

/*
   Takes in a given AST and mallocs a new AST with the exact same details as the
   original. Again you should assume the original may be freed at any point
   after this function terminates.
*/
AST* CopyAST(AST* original) {
  AST* ast = MakeAST(original->type, original->filename, original->linenum);
  ast->size = original->size;
  ast->capacity = original->capacity;
  ast->children = (AST**)realloc(ast->children, sizeof(AST*) * ast->capacity);
  if (ast->children == NULL) {
    allocation_failed();
  }
  for (int i = 0; i < ast->size; i++) {
    ast->children[i] = CopyAST(original->children[i]);
  }

  /* Start Unique to Copy */
  if (ast->type == NODETYPE_ID) {
    ast->data.identifier =
        (char*)malloc(sizeof(char) * (strlen(original->data.identifier) + 1));
    if (ast->data.identifier == NULL) {
      allocation_failed();
    }
    strcpy(ast->data.identifier, original->data.identifier);
  } else if (ast->type == NODETYPE_CONSTANT_STRING) {
    ast->data.string =
        (char*)malloc(sizeof(char) * (strlen(original->data.string) + 1));
    if (ast->data.string == NULL) {
      allocation_failed();
    }
    strcpy(ast->data.string, original->data.string);
  }
  /* End of Unique to Copy */
  return ast;
}

/*
   Takes in an two ASTs and concatenates the two by making node a child
   of tree.
*/
void AppendAST(AST* tree, AST* node) {
	
	
   if(tree->size >= tree->capacity){
	tree->capacity+=10;
	AST** temp = (AST**)realloc(tree->children, (tree->capacity)*sizeof(AST*));
       	
	if(temp==NULL){allocation_failed();}
	tree->children=temp;
      }

   tree->children[tree->size]=node;
   tree->size++;      
   return;
   
  /* YOUR CODE HERE */
}

/*
   Frees the memory allocated by a single AST node.
*/
void FreeNode(AST* ast) {
  if((ast->data).string==NODETYPE_CONSTANT_STRING){
      free((ast->data.string));
}
  if((ast->data).identifier==NODETYPE_ID){
      free((ast->data.identifier));
  }
  free(ast->filename);
  for(int i = 0;i<ast->size;i++){
     free(ast->children[i]);
  }
  free(ast->children);
  free(ast);
}

/*
   Frees all the memory allocated by an AST.
*/
void FreeAST(AST* ast) {
    if(!ast->children){FreeNode(ast);}

    for(int i=0;i<ast->size;i++){
        FreeAST(ast->children[i]);
      
    }
    
}
