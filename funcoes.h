

typedef struct matricula Matricula;

typedef struct AVL AVL;

void cria(int *lista_criada, AVL* *a);

void inserir(Matricula *x, AVL* *a);

void balancear(AVL* *p);

void simples_esquerda(AVL* *p);

void simples_direita(AVL* *p);

void dupla_esquerda(AVL* *p);

void dupla_direita(AVL* *p);

void retirar(Matricula x, AVL* *p);

void antecessor(AVL* q, AVL* *r);

int buscar(Matricula *x, AVL* p);

void central(AVL* p);

