#include "Btree.h"
extern Btree Create_Btree();
extern int isEmpty_Btree(Btree B);
extern Btree Construct(element e, Btree L, Btree R);
extern int Root(Btree B, element *e);
extern int Right(Btree B, Btree *R);
extern int Left(Btree B, Btree *L);