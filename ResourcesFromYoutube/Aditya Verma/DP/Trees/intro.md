fun(Node\* root)
base condition

    hypothesis (get answer from left and right subtree)

    induction (use the above answers to calculate final answer)

    return answer

- note the '&' below in res variable
  fun(Node\* root, int &res){
  if(root==NULL)
  return 0;

      int left = fun(root->left);
      int right = fun(root->right);

      temp_ans = some function
      ans = max(temp, some_relation)
      return temp

  }
