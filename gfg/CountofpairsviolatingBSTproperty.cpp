#include "../lib/createTree.hpp"
using namespace std;

vector<TreeNode *> getInOrderTraversal(TreeNode *root) {
  vector<TreeNode *> res;
  TreeNode *curr = root;
  while (curr != nullptr) {
    if (!curr->left) {
      res.push_back(curr);
      curr = curr->right;
    } else {
      TreeNode *currNext = curr->left;
      while (currNext->right != curr && currNext->right != nullptr) {
        currNext = currNext->right;
      }
      if (currNext->right == curr) {
        currNext->right = nullptr;
        res.push_back(curr);
        curr = curr->right;
      } else {
        currNext->right = curr;
        curr = curr->left;
      }
    }
  }
  return res;
}

vector<TreeNode *> *merge(vector<TreeNode *> *left, vector<TreeNode *> *right,
                          int &countInversions) {
  vector<TreeNode *> *result = new vector<TreeNode *>;

  int leftSize = left->size();
  int rightSize = right->size();
  // int totalSize = leftSize + rightSize;

  int i = 0;
  int j = 0;

  while (i != leftSize && j != rightSize) {
    if (left->at(i)->val < right->at(j)->val) {
      result->push_back(left->at(i));
      i++;
    } else {
      result->push_back(right->at(j));
      countInversions += leftSize - i;
      j++;
    }
  }

  while (i != leftSize) {
    result->push_back(left->at(i));
    i++;
  }

  while (j != rightSize) {
    result->push_back(right->at(j));
    // countInversions++;
    j++;
  }

  return result;
}

vector<TreeNode *> *mergeSort(vector<TreeNode *> arr, int start, int end,
                              int &countInversions) {
  if (start >= end) {
    return new vector<TreeNode *>(1, arr[start]);
  }

  int mid = (start + end) / 2;
  vector<TreeNode *> *left = mergeSort(arr, start, mid, countInversions);
  vector<TreeNode *> *right = mergeSort(arr, mid + 1, end, countInversions);

  vector<TreeNode *> *result = merge(left, right, countInversions);
  delete left;
  delete right;

  return result;
}

int countPairsVoilatingBSTProperty(TreeNode *root) {
  vector<TreeNode *> arr = getInOrderTraversal(root);
  int inversions = 0;
  vector<TreeNode *> *resultArr = mergeSort(arr, 0, arr.size() - 1, inversions);
  return inversions;
}

int main(int argc, char **argv) {
  string line;
  while (getline(cin, line)) {
    TreeNode *root = stringToTreeNode(line);
    cout << countPairsVoilatingBSTProperty(root) << endl;
  }
}
