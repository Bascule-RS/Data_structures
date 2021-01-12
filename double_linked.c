//Doubly linked list:
//By Nicolas Tercé


#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

typedef char * string ;

// Data structure for double linked lists
typedef struct node
{
  struct node * List_back;
  char * string;
  struct node* List_forth;
}node_bf,*list;

//string car(list node);
// 17.7 redefinition du type node, pour construire la liste
typedef struct node_f { void * car ; struct node_f * cdr ; } node_f, * list_f;
list node_reader_forth(list node);
list cons_bf(list  List_back,char * string,list List_forth);
list_f cons_f(string car, list_f L);

//function to build a forward and backward pointed node:
list cons_bf(list  List_back,char * string,list List_forth)
{
  list new  = malloc(sizeof(node_bf));
  if (! new) perror("malloc ") ;
  if(List_back ){
    new -> List_back = List_back;
    List_back -> List_forth = new;
  }else{
    new -> List_back = List_back;
  }
  new -> string  =string ;
  if(List_forth)
  {
    List_forth -> List_back = new;
    new -> List_forth = List_forth;
  }else new -> List_forth = List_forth;

  return new;
}

//function to build a backward(forward?) pointed node:
list_f cons(string car, list_f L)
{
  list_f new = malloc(sizeof(node_f)) ;
  if (! new) perror("malloc ") ;
  new -> car = car ;
  new -> cdr = L ;
  return new;
}

//function that changes the string of a node
string node_change(list node, string str){
  printf("%s become %s",node->string,str);
  node->string = str;
  return "string";
}

list node_reader_forth(list node){
  printf("node string contains:%s\n", node->string);
  sleep(1);
  return node -> List_forth;
}

list node_reader_back(list node)
{
  printf("node string contains:%s\n", node->string);
  sleep(1);
  return node -> List_back;
}

int main (int argc , char *argv []){
  // first node of a list:
  list premier_node =cons_bf(NULL,"node_1",NULL);
  list deuxieme_node=cons_bf(premier_node,"node_2",NULL);
  list troisieme_node=cons_bf(deuxieme_node,"node_3",NULL);
  list quatrieme_node=cons_bf(troisieme_node,"node_4",premier_node);
  for (int i=0; i<8;i++){
  premier_node=node_reader_forth(premier_node);}
  printf("lecture en sens inverse:\n");
  for (int i=0; i<8;i++){
  premier_node=node_reader_back(premier_node);}
  return 0;
}
