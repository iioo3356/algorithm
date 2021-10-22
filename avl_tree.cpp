/**
 * File processing, 2020
 * AVL.cpp
 * implementation of AVL tree
 */



#include <stdio.h>
#include <iostream>
using namespace std;

#define Left 0
#define Right 1

/**
 * Node represents a single node in AVL tree.
 */
typedef struct Node {
  int key, bf;
  struct Node *left, *right;
} Node;

typedef Node *Tree;

// /*
//  * getNode returns a new node.
//  * @return a new node
//  */

Node *getNode() {
  /* write your code here */
  Node* nd = (Node *)malloc(sizeof(Node));
  nd->key = 0;
  nd->bf = 0;
  nd->left = NULL;
  nd->right = NULL;
  return nd;
}

int height(Tree T){
  int h = 0;
  if (T != NULL){
    h = 1 + max(height(T->left), height(T->right));
  }//양쪽 서브트리를 비교해 더 큰 값에 1을 더해줌.
  //노드가 없다면 0 반환
  //leaf node에서 위로 갈 수록 1씩 값이 더해짐.
  return h;
}


int noNodes(Tree T){
  int count = 0;
  if (T!=NULL){
    count = 1 + noNodes(T->left) + noNodes(T->right);
  }
  return count;

}

Node* maxNode(Tree T){
  if (T->right == NULL){
    return T;
  }
  //왼쪽 서브트리만 남아있다면 nd가 최대값
  else{
    return maxNode(T->right);
  }//오른쪽 서브트리가 더이상 없을 때까지 진행.
}

Node* minNode(Tree T){
  if (T->left == NULL){
    return T;
  }
  //오른쪽 서브트리만 남아있다면 nd가 최소값
  else{
    return minNode(T->left);
  }//왼쪽 서브트리가 더이상 없을 때까지 진행.
}
/**
 * updateBF updates balancing factors of nodes in T
 * and finds the unbalanced node nearest to y.
 * @param T: an AVL tree
 * @param y: the inserted/deleted node
 * @param x: the unbalanced node nearest to y
 * @param p: parent node of x
 */
void updateBF(Tree *T, Node *y, Node **x, Node **p) {
  // 새로 삽입된 노드부터 루트 까지의 BF를 계산
  Node* q = *T; // current
  // Node* p = root;
  Node* pq = NULL; //parent
  while (q != NULL){

    int bf = height(q->left) - height(q->right);
    q->bf = bf;
    // cout <<  "키가 " << q->key <<" 인 노드의 bf : " << q->bf << endl;
    if (q->bf >=2 || q->bf <=-2){
      *x = q;
      *p = pq;
    }
    pq = q;
    if (y->key < q->key){
      q = q->left;
    }
    else if (y->key > q->key){
      q = q->right;
    }
    else {
     break;
    }

  }
}
/**
 * rotateLL implements LL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param p: parent node of x
 */
void rotateLL(Tree *T, Node *x, Node *p) {
    Node *nd= x->left;

    if (nd->right != NULL){
        x->left = nd->right;
    // cout << x->key << " 에서 " << nd->right->key << " 로 연결"<<endl;
    }
    else{
        x->left = NULL;
    }
    nd->right = x;
    // cout << nd->key << " 에서 " <<x->key << " 로 연결" << endl;
   
    if (p == NULL){
        // 루트 LL
        *T = nd;
    }
    else if (p->left == x){
        // 부모의 왼쪽
        p->left = nd;
        // cout << p->key << " 에서 " << nd->key << " 로 연결 "<< endl;
    }
    else {
        // 부모의 오른쪽
        p->right = nd;
        // cout << p->key << " 에서 " << nd->key << " 로 연결"<<endl;

    }
}

/**
 * rotateRR implements RR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param p: parent node of x
 */
void rotateRR(Tree *T, Node *x, Node *p) {

    Node *nd = x->right;
    if (nd->left != NULL){
        x->right = nd->left;
        // cout << x->key << " 에서 " << nd->left->key << " 로 연결"<<endl;
    }
    else {
        x->right =  NULL;
    }
    nd->left = x;
    // cout << nd->key << " 에서 " << x->key << " 로 연결"<<endl;
    if (p == NULL){
        // 루트
        *T = nd;
    }
    else if (p->left == x){
        // 부모의 왼쪽
        p->left = nd;
        // cout << p->key << " 에서 " << nd->key << " 로 연결" <<endl;
    }
    else{
        // 부모의 오른쪽
        p->right = nd;
        // cout << p->key << " 에서 " << nd->key << " 로 연결" <<endl;
    
    }

}

/**
 * rotateLR implements LR rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param p: parent node of x
 */
void rotateLR(Tree *T, Node *x, Node *p) {
    Node* nd = x->left->right;
    
    if (nd->left != NULL){
        x->left->right = nd->left;
        // cout << x->left->key << " 에서 " << nd->left->key << " 로 연결"<<endl;
    }
    else {
        x->left->right = NULL;
    }
    nd->left = x->left;
    // cout << nd->key << " 에서 " << x->left->key << " 로 연결"<<endl;
    if (nd->right != NULL){
        x->left = nd->right;
        // cout << x->key << " 에서 " << nd->right->key << " 로 연결"<<endl;
    }
    else {
        x->left = NULL;
    }
    nd->right = x;
    // cout << nd->key << " 에서 " << x->key << " 로 연결"<<endl;

     if (p == NULL){
        // 루트
        *T = nd;
    }
    else if (p->left == x){
        // 부모의 왼쪽
        p->left = nd ;
        // cout << p->key << " 에서 " << nd->key << " 로 연결"<<endl;
     }
    else {
        // 부모의 오른쪽;
        p->right = nd;
    }
}

/**
 * rotateRL implements RL rotation in subtree rooted with x.
 * @param T: an AVL tree
 * @param x: root node of subtree
 * @param p: parent node of x
 */
void rotateRL(Tree *T, Node *x, Node *p) {
    Node* nd = x->right->left;

    if (nd->right != NULL){
        x->right->left = nd->right;
        // cout << x->right->key << " 에서 " << nd->right->key << " 로 연결"<<endl;
    }
    else{
        x->right->left = NULL;
    }    
    nd->right = x->right;
    // cout <<nd->key << " 인 노드에서 "<<x->right->key<< " 로 연결" <<endl;

    if (nd->left != NULL){
        x->right = nd->left;
        // cout << x->key << " 에서 " << nd->left->key << " 로 연결"<<endl;
    }
    else{
        x->right = NULL;    
    }
    nd->left = x;
    // cout << nd->key << " 에서 " << x->key << " 로 연결"<<endl;
    
    if (p == NULL){
      //루트 노드-> 부모가 없음
        *T = nd;

    }
     else if (p->left == x){
        // 부모의 왼쪽
        p->left = nd;
        // cout << p->key << " 에서 "<<nd->key << " 로 연결"<<endl;
    }
    else {
        // 부모의 오른쪽
        p->right = nd;//
        // cout <<p->key << " 인 노드에서 "<<nd->key<< " 로 연결" <<endl;
    }
}

/**
 * insertBST inserts newKey into T
 * and returns the inserted node.
 * @param T: a binary search tree
 * @param newKey: a key to insert
 * @return the inserted node
 */
Node *insertBST(Tree *T, int newKey) {
  /* write your code here */
  Node* p = *T; // current
  Node* q = NULL; //parent
  while (p != NULL){
    // step 1: newKey의 삽입 위치 q를 찾음.
    if (newKey == p->key){
      break;
    }
    q = p;// q는 p의 부모 노드를 지시
    // if (newKey < (*p).key){
    if (newKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }
  // // step 2: newKey를 갖는 노드를 만들음.

  Node* newNode = getNode();
  newNode->key = newKey;

  if (q == NULL){
    *T = newNode;
  }
  else{
    if (newKey < q->key){
      q->left = newNode;
    }
    else{
      q->right =newNode;
    }
  }
  return newNode;
}

/**
 * insertAVL inserts newKey into T.
 * @param T: an AVL tree
 * @param newKey: a key to insert
 */

 // 삽입과 삭제는 모두 BST의 삽입과 삭제를 먼저 실행한 후,
 // 문제가 발생했을 때 rotation (LL, RR, LR, RL)을 실행,
void insertAVL(Tree *T, int newKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */
  /* write your code here */
  Node *wrong = NULL; // bf에 문제가 생긴 노드
  Node *pwrong = NULL; //wrong의 parent
  Node *newNode = insertBST(T, newKey);
  updateBF(T, newNode, &wrong, &pwrong);
  // cout << wrong;
  if (wrong == NULL){
    // 문제가 생긴 노드가 없음.
    cout << "NO";
  }
  else {
    // cout << wrong->key << " 노드 bf 문제-> ";
    if (wrong->bf >= 2){
      //왼쪽 서브트리가 더 큼
      if ((wrong->left)->bf>0){
        cout << "LL";
        rotateLL(T, wrong, pwrong);
      }
      else {
        cout << "LR";
        rotateLR(T, wrong, pwrong);
      }
    }
    else {
      //(*wrong)->bf <= -2) 오른쪽 서브트리가 더 큼
      if ((wrong->right)->bf>0) {
        cout << "RL";
        rotateRL(T,wrong, pwrong);
      }
      else {
        cout << "RR";
        rotateRR(T, wrong, pwrong);
      }
    }
    updateBF(T,newNode, &wrong, &pwrong);
  }
}

/**
 * deleteBST deletes deleteKey from T
 * and returns the parent node of the deleted node.
 * @param T: a binary search tree
 * @param deleteKey: a key to delete
 * @return the parent node of the deleted node
 */
Node *deleteBST(Tree *T, int deleteKey) {
  Node *p = *T;
  Node *q = NULL;

  while (p != NULL){
    // step 1: newKey의 삽입 위치 q를 찾음.
    if (deleteKey == p->key){
      break;
    }
    q = p;// q는 p의 부모 노드 지시
    if (deleteKey < p->key){
      p = p->left;
    }
    else {
      p = p->right;
    }
  }

  if (p == NULL){
    //삭제할 노드가 없음.
      return q;
  }
  else if (p->left == NULL && p->right == NULL){
    //case of leaf
    if (q==NULL){
    //case of root
      *T = NULL;
    }
    else if (q->left == p){
    //   cout << "지울 노드가 부모의 왼쪽에 있습니다" << endl;
      q->left = NULL;
    }
    else {
    //   cout << "지울 노드가 부모의 오른쪽에 있습니다" << endl;
      q->right = NULL;
    }
  free(p);
  return q;
  }
  else if (p->left == NULL || p->right == NULL){
    //case of degree 1
    if (p->right != NULL){
      // cout << "지울 노드의 오른쪽에 자식이 있습니다. 그리고 " << endl;
      if (q == NULL){
        // cout << "이 트리 안에서 맨 위 입니다."<<endl;
        *T = (*T)->right;
        // cout << "루트의 오른쪽을 루트로 합니다." << endl;
        }
      else if (q->left == p) {
        q->left = p->right;
      }
      else {
        q->right = p->right;
      }
    }
    else {
      // p의 left에 있음
      if (q==NULL){
        *T = (*T)->left;
      }
      else if (q->left == p){
        q->left = p->left;
      }
      else{
        q->right = p->left;
      }
    }
    free(p);
    return q;
  }
  else {
    //case of degree 2
    Node* r = getNode();
    int flag;

    if (height(p->left) < height(p->right)){
      r = minNode(p->right);
      flag = Right;
    }
    else if (height(p->left) > height(p->right)){
      r = maxNode(p->left);
      flag =Left;
    }
    else {
      if (noNodes(p->left) < noNodes(p->right)){
        r = minNode(p->right);
        flag = Right;
      }
      else{
        r = maxNode(p->left);
        flag = Left;
      }
    }
    p->key = r->key;
    if (flag == Left){
      deleteBST(&(p->left),r->key);
    }
    else{ // 오른쪽 서브트리에서 다시 삭제
      deleteBST(&(p->right), r->key);
    }
  }  // 삭제할 원소가 없음
}

/**
 * deleteAVL deletes deleteKey from T.
 * @param T: an AVL tree
 * @param deleteKey: a key to delete
 */
void deleteAVL(Tree *T, int deleteKey) {
  /**
   * print "NO" if not rotates
   * print "LL" if rotates LL
   * print "RR" if rotates RR
   * print "LR" if rotates LR
   * print "RL" if rotates RL
   */
  Node *wrong = NULL; // bf에 문제가 생긴 노드
  Node *pwrong = NULL; //wrong의 parent
  Node *pDeleteNode = deleteBST(T, deleteKey);
  if (pDeleteNode != NULL){
    // cout <<"삭제한 노드의 부모의 키는 "<< pDeleteNode->key << endl;
    updateBF(T, pDeleteNode, &wrong, &pwrong);
  }
  else{
    // cout << "삭제한 노드는 해당 서브트리에서 루트입니다." <<endl;
    cout << "NO";
    return;
  }
  // cout << wrong;
  if (wrong == NULL){
    // 문제가 생긴 노드가 없음.
    cout << "NO";
  }
  else {
    // cout << wrong->key << " 노드 bf 문제-> ";
    // cout << "NO가 아님.";
    if (wrong->bf >= 2){
      //왼쪽 서브트리가 더 큼
      int bf = height(wrong->left->left) - height(wrong->left->right);

      if (bf > 0){
        cout << "LL";
        rotateLL(T, wrong, pwrong);
      }
      else {
        cout << "LR";
        rotateLR(T, wrong, pwrong);
      }
    }
    else {
      //(*wrong)->bf <= -2) 오른쪽 서브트리가 더 큼
      int bf = height(wrong->right->left) - height(wrong->right->right);
      if (bf<0) {
        cout << "RR";
        rotateRR(T,wrong, pwrong);
      }
    //   height(q->left) - height(q->right)
      else {
        cout << "RL";
        rotateRL(T, wrong, pwrong);
      }
    }
    updateBF(T, pDeleteNode, &wrong, &pwrong);
  }

}

/**
 * inorderAVL implements inorder traversal in T.
 * @param T: an AVL tree
 */
void inorderAVL(Tree T) {
  /* write your code here */
  if (T!=NULL){
    inorderAVL(T->left);
    cout << T->key << " ";
    inorderAVL(T->right);
  }
}

int main() {
  /* Do not modify the code below */
  int testcase[] = { 40, 11, 77, 33, 20, 90, 99, 70, 88, 80, 66, 10, 22, 30, 44, 55, 50, 60, 25, 49 };
  Tree T = NULL;
  // insertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
  // deletion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
  T = NULL;
  // reinsertion
  for (int i=0; i<20; i++) { printf("%d ", testcase[i]); insertAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
  // redeletion
  for (int i=19; 0<=i; i--) { printf("%d ", testcase[i]); deleteAVL(&T, testcase[i]); printf(" : "); inorderAVL(T); printf("\n"); }
}