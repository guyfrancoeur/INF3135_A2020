# Démonstration atelier 07

### Mise en garde
 + Le code ou les exemples sont purement académiques, ils peuvent contenir des erreurs.
 + Ils ne sont pas destinés pour un usage commercial. La prudence est de mise.

#### Vous devez toujours tenter vos propres expériences afin d'en avoir le coeur net.

### Référence
 + notes de cours
 
### Contribution
 - merci au démonstrateur

### Execice 2 - TAD Ensemble

```c
typedef struct BinaryNode BinaryNode;

struct BinaryNode {
  int data;
  int depth;
  BinaryNode* left;
  BinaryNode* right;
  BinaryNode* parent;
};

void initTree(BinaryNode* _root);
void initNode(BinaryNode* _node);
BinaryNode* insertValue(BinaryNode* node, BinaryNode* parent, bool is_left, int data);
BinaryNode* searchValue(BinaryNode* node, BinaryNode* parent, bool is_left, int data);
void removeValue(BinaryNode* root, int data);
void clean(BinaryNode* root);


void initTree(BinaryNode* _root) {
  initNode(_root);
  _root->parent = 0;
  _root->depth = 0;
}

void initNode(BinaryNode* _node) {
  _node->left = 0;
  _node->right = 0;
  _node->data = 0;
}
BinaryNode* insertValue(BinaryNode* node, BinaryNode* parent, bool is_left, int data) {
  // si le noeud n'existe pas, il faut le creer
  if (!node) {
    // en attendant:
    BinaryNode* next = (BinaryNode*)malloc(sizeof(BinaryNode));
    if (next) {
      initNode(next);
      // placement dans l'arbre
      if (is_left) {
        parent->left = next;
      }
      else {
        parent->right = next;
      }
      next->parent = parent;
    }
    else {
      // erreur
    }
  }
  else {
    if (node->depth == 0 && !node->left && !node->right) {
      node->data = data;// insert first value only
      return node;
    }
    else {
      if (node->data < data) {
        insertValue(node->left, node, true, data);// appel recursif sur le fils de "gauche"
      }
      else {
        if (node->data > data) {
          return insertValue(node->right, node, false, data);// appel recursif sur le fils de "droite"
        }
      }
    }
  }
}

BinaryNode* searchValue(BinaryNode* root, int data) {
  // todo
}

void removeValue(BinaryNode* root, int data) {
  // recursive too, 
  // utiliser la meme mecanique que add/search
  // pour trouver le bon noeud a delete
  // free(node)
}

void clean(BinaryNode* root) {
  // si on delete les fils de la racine, on peut pas y accer
  // depth first postfix traversal du binary tree
}

int main(int argc, char** argv){
 BinaryNode* root = (BinaryNode*)malloc(sizeof(BinaryNode));
  if (root != 0) {
    initTree(root);
    insertValue(root, 5);
    insertValue(root, 3000);
    insertValue(root, 71);

    BinaryNode* test1 = searchValue(root, 3000);
    BinaryNode* test2 = searchValue(root, 65465);

    removeValue(root, 5);

    clean(root);
  }
  return 0;
}
```
