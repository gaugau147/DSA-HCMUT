//======================Print Leaves BFT=======================
int heightOfTree(treeNode *root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void printLeavesBFT (treeNode* root) {
    int height = heightOfTree(root);
    for (int i = 0; i <= height; i++)
        printLevelLeavesBFT(root, i);
    return;
}

void printLevelLeavesBFT(treeNode *root, int level) {
    if (root == NULL)
        return;
    if (level == 1) {
        //only prints if node is a leaf
        if (root->left == NULL & root->right == NULL)
            cout << " " << root->data << " ";
    } else if (level > 1) {
        printLevelLeavesBFT(root->left, level - 1);
        printLevelLeavesBFT(root->right, level - 1);
    }
}

//====================Print Leaves LNR (Inorder)=========================
void printLeavesLNR(treeNode *root) {
    if (root == NULL)
        return;
    printLeavesLNR(root->left);
    //only prints if node is a leaf
    if (root->left == NULL && root->right == NULL)
        cout << " " << root->data << " ";
    printLeavesLNR(root->right);
}

//====================Print Leaves NLR (Postoder)=========================
void printLeavesNLR(treeNode *root) {
    if (root == NULL)
        return;
	//only prints if node is a leaf
	if (root->left == NULL && root->right == NULL)
		cout << " " << root->data << " ";
    printLeavesNLR(root->left);
    printLeavesNLR(root->right);
}