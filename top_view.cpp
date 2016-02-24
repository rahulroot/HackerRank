void print_left(node *root)
{
  if(!root) return;
  print_left(root->left);
  cout << root->data <<' ';
}

void print_right(node *root)
  {
  if(!root) return;
  cout << root->data <<' ';
  print_right(root->right);
  
}

void top_view(node * root)
{
  print_left(root->left);
  cout << root->data <<' ';
  print_right(root->right);
  
}
