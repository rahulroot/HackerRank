Node* Delete(Node *head, int position)
{
  // Complete this method
  if(!head) return NULL;
  
  if(position == 0) {
    struct Node *tmp = head->next;
    free(head); head = NULL;
    head = tmp;
    return head;
   // printList(head);
  }
  
  struct Node *cur = head;
  struct Node *prev = head;
  int cnt = 0;
  while(cur != NULL)
  {
   // cnt++;
    if(cnt == position)
    {
      prev->next = cur->next;
      free(cur); cur=NULL;
      //deleteNode(cur);
      break;
    }
    else
    {
      cnt++;
        prev = cur;
        cur = cur->next;
    }
  }
 // printList(head);
  return head;
}

