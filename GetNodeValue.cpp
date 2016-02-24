NODE * GetNode(NODE *head,int positionFromTail)
{
  NODE *slow, *fast;
  slow = fast = head;
  printList(head);
  cout << slow <<' '<< fast <<' '<< head << endl;
  if(positionFromTail > 0) {
    cout <<"pos is > 0 " << positionFromTail << endl;
    while(positionFromTail--) {
      fast = fast->next;
      cout <<"fast : " << fast << endl;
    }
  }
  cout <<"slow : " << slow <<' '<<"fast :" << fast << endl;
  while(fast!=NULL)
  {
    fast = fast->next;
    cout <<"fast : " << fast << endl;
    if(fast)
      slow = slow->next;
    cout <<"fast : " << fast <<" slow : " << slow << endl;
  }
  cout <<"final data: " << slow->data << endl;
  return slow;
}

