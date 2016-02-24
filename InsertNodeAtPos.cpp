int listSize(struct Node *head)
{
  int cnt = 0;
  while(head != NULL)
  {
    head = head->next;
    cnt++;
  }
  return cnt;
}

void printList(struct Node *head)
  {
 // cout <<"Prining list ";
  while(head!=NULL)
  {
    cout << head->data <<' ';
    head = head->next;
  }
  cout << endl;
}


Node* InsertNth(Node *head, int data, int position)
{
  struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
  tmp->data = data;
  tmp->next = NULL;
  
  //cout <<"list size is : " << listSize(head) <<" pos : " << position << endl;
  if(position > listSize(head))
  {
  // cout <<"Given position is beyond the list size, setting position to listSize() " << endl;
   position = listSize(head);
 //  cout <<" position : " << position << endl;
  }
  if( (position==0) && (!head))
  {
   // cout <<" pos is 0 and head is NULL" << endl;
    head = tmp;
   // printList(head);
    return head;
  }
  else if( (position==0) && head)
  {
  //  cout <<"Pos is 0 and head is not Null" << endl;
    tmp->next = head;
    head = tmp;
   // printList(head);
    return head;
  }
  
  //cout <<"Inserting at pos: " << position << endl;
  int cnt = 0;
  struct Node *cur = head;
  while(cur != NULL)
  {
      cnt++;
      if(cnt == position)
      {
        tmp->next = cur->next;
        cur->next = tmp;
        break;
      }
      else
        cur = cur->next;
  }
 // printList(head);
  return head;
}
