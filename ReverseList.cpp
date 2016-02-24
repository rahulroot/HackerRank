Node* Reverse(Node *head)
{
  
 // cout <<"Orig List: "; printList(head);
  struct Node *new_head = NULL;
  while(head!=NULL)
  {
    int data =  head->data;
    struct Node *tmp = head;
    head = head->next;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
    new_node->data = data;
    new_node->next = NULL;
    free(tmp);

    if(!new_head) {
      new_head = new_node;
     // printList(new_head);
    }
    else
    {
      new_node->next = new_head;
      new_head = new_node;
     // printList(new_head);
    }
  }
  return new_head;
}

