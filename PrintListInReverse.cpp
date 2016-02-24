void ReversePrint(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
  if(!head) return;
  ReversePrint(head->next);
  cout << head->data << endl;
}
