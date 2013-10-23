#include "pa07.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints a linked-list "head" into the output fie "out"
 *
 * NOTE: we have given the code for this function
 */
void List_print(FILE * out, Node * head)
{
 while(head != NULL)
	{
	    fprintf(out, "%5d: %6d\n", head -> index, head -> value);
	    head = head -> next;
	}
    printf("\n");
}


/**
 * Please fill in the code below
 */

/**
 * Destroys a linked list.
 * Arguments:
 * head    A pointer pointing to the first element of the linked list.
 *
 * Returns:
 * void
 *
 * Destroys (frees memory for) the whole linked list. 
 * You can either use recursion or a while loop.
 */
void List_destroy(Node * head)
{
  if(head == NULL)
    {
      return;
    }

  List_destroy(head->next) ;
  free(head) ;

}

/**
 * Create and initialize a linked list. 
 *
 * Arguments:
 * value     The "value" of the new node
 * index     The "index" of the new node
 *
 * Returns:
 * Returns a newly constructed node. The node can be the head of a
 * linked list.
 * 
 * You should allocate memory in this function. 
 */
Node * List_create(int value, int index)
{
  Node *point ;
  point = malloc(sizeof(Node)) ;
  point->value = value ;
  point->index = index ;
  point->next = NULL ;

    return point;
}

/**
 * Build a sparse array from the given indices and values with 
 * specific length.
 *
 * Arguments:
 * value    Array of values
 * index    Array of indices
 * length   Length of the above arrays
 *
 * Returns:
 * A sparse array.
 *
 * If a sparse array node has { value = 1000, index = 2 }, then that means that
 * the index "2" caries the value "1000". This is meant to convey an array of 1000 
 * "2s", but instead of creating 1000 nodes in your linked list, you only create
 * 1 node, and that note conceptually has 1000 "copies" of it. Hence 
 * each node in a sparse array has a "value" in addition to its "index".
 *
 * Note that an index can never carry the value of "0", because this would not make
 * any sense; however, negative values are fine. A negative value may seem odd
 * at first blush; however, this is like substraction, and makes sense for certain
 * cases.
 *
 * You need to insert nodes in ascending order by index.
 * See the notes to "List_insert_ascend"
 */
Node * List_build(int * value, int * index, int length)
{
  int i ;
  // Node *head = malloc(sizeof(Node)) ;
  Node *head = NULL ;
  if(length == 0)
    {
      return head ;
    } 
  
  for(i = 0  ; i < length ; i++)
    {

      head =  List_insert_ascend(head, value[i], index[i] ) ;
    }
 
  return head ;
   
 
}


/**
 * Inserting "value" and "index" into the correct location in the 
 * sparse array "head"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the linked list.
 * value     The "value" of the value
 * index     The "value" of the index
 *
 * Returns:
 * A sparse array
 *
 * This function inserts the node ["value", "index"] into the sparse
 * array "head", and ensures that the nodes remain in ascending order
 * by their "index".
 *
 * Before and after the call to this function, "head" must be in
 * ASCENDING order by the "index" of each node.
 */
Node * List_insert_ascend(Node * head, int value, int index)
{
  if (head == NULL)
    {
      head =  List_create(value, index);
      return head ; 
    }


     else if ((head -> index) == index)
	{
	  head -> value += value;
	  if(head->value == 0 )
	    {
	      head = List_delete(head,index);
	    }
	   return head ;
	}
     else if ((head->index) > index && head->value != 0)
	{
	  Node * bud = List_create(value, index);
	  bud -> next = head;
	  return bud;
	}
      head -> next = List_insert_ascend(head->next, value, index);
	
      return head ;

}




/**
 * This function deletes the node with the passed "index"
 * 
 * Arguments: 
 * head      A pointer pointing to the first element of the sparse array.
 * index     The index to be deleted
 *
 * Returns: 
 * A sparse array with the node removed (the one with index)
 */
Node * List_delete(Node * head, int index)
{
  Node * p = head ;
  if (p == NULL) /* empty list, do nothing */
    {
      return p ;
    }
/* delete the first node (i.e. head node)? */
  if ((p -> index) == index)
    {
      p = p -> next ;
      free (head) ;
      return p ;
    }
/* not deleting the first node */
  Node * q = p -> next ;
  while ((q != NULL) && ((q -> index) != index))
    {
/* must check whether q is NULL
before checking q -> value */
      p = p -> next ;
      q = q -> next ;
    }
  if (q != NULL)
    {
/* find a node whose value is v */
      p -> next = q -> next ;
      free (q) ;
}
  return head ;

}

/**
 * Copy a list
 *
 * Arguments:
 * head      A pointer pointing to the first element of the sparse array
 *
 * Returns:
 * A copy sparse array
 *
 * This function will copy the sparse array that is passed to it. The
 * copy will be made into new memory. 
 *
 * This is useful, for example, when we want to merge
 * two linked lists together. We can make a copy of one of the linked
 * lists, and then merge the second into the copy. In this way the
 * original copy of the list is not "mutated".
 */
Node * List_copy(Node * head)
{
 Node *head_copy = NULL ;
  if(head == NULL)
    {
      
      return head_copy ;
    }


   head_copy = List_create(head->value,head->index);
   head = head->next ;
   Node *temp =head_copy ;
  

while(head != NULL )
    {
      temp->next = List_create(head->value,head->index);
      temp = temp->next ;
      head = head->next ;

    }
    return head_copy;
}


/**
 * Merged two linked list together
 * 
 * Arguments:
 * head1      A pointer pointing to linked list 1
 * head2      A pointer pointing to linked list 2
 *
 * Returns:
 * A merged sparse array
 *
 * This function will merge two linked lists. Before merging, you 
 * should make a copy of "head1" so that you will still have the 
 * original array while modifying (merging) the second linked list. 
 *
 * Please refer to the README file for detailed instructions on how to
 * merge two lists.
 *
 * This function should not modify either "head1" or "head2". You only
 * need to make a clone of "head1".
 */
Node * List_merge(Node * head1, Node * head2)
{
  Node *merged_lists = List_copy(head1) ;
  Node *temp = head2 ;
  while(temp != NULL)
    {
      merged_lists = List_insert_ascend(merged_lists,temp->value,temp->index) ;
      temp = temp->next ;
    }
  return merged_lists;
}



/* #ifndef MYTEST */

/* int main(int argc, char** argv) */
/* { */
  
/*   Node* head3 = malloc(sizeof(Node)); */
/*   head3->next = malloc(sizeof(Node)); */
/*   head3->value = 10; */
/*   head3->index = 2; */
/*   head3->next->value = 10; */
/*   head3->next->index = 3; */
/*   head3->next->next = NULL; */
/*   head3 = List_insert_ascend(head3,10,1) ; */

/*  /\* Node * head = NULL ; *\/ */

/*   /\* head = List_insert_ascend(head, 100, 5); *\/ */
/*   /\* head = List_insert_ascend(head,100,6) ; *\/ */
/*   /\* head = List_insert_ascend(head,100,9) ; *\/ */
/*   /\* head = List_insert_ascend(head,100,7) ; *\/ */
/*   /\* head = List_insert_ascend(head,100,4) ; *\/ */

/*   Node * head2 = NULL ; */
/*   int *a = malloc(sizeof(int)*2); */
/*   int *b = malloc(sizeof(int)*2) ; */
/*   * a = 1 ; */
/*   * b = 1 ; */
/*   *(a+1) = 2 ; */
/*   *(b+1) = 1 ; */
  
/*   Node * head = NULL ; */
/*   Node * lists = NULL ; */
/*   // head = List_insert_ascend(head,1,1); */
/*   head = List_build(b,a,2); */
/*   head = List_insert_ascend(head,4,1) ; */
/*   List_print(stdout, head); */
/*   head2 = List_copy(head) ; */
/*   printf("copied List") ; */
/*   List_print(stdout, head2); */
/*   lists = List_merge(head,head3); */
/*   printf("Merged List"); */
/*   List_print(stdout,lists); */
/*   free(a); */
/*   free(b) ; */

/*   List_destroy(head); */
/*   List_destroy(head2) ; */
/*   List_destroy(head3) ; */
/*   List_destroy(lists); */
/*   return(0); */
/* } */




/* #endif */
