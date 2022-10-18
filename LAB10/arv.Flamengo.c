struct _arvrb {
    int info;
    int cor; /*1=rubro, 0=negro*/
    struct _arvrb *pai;
    struct _arvrb *esq;
    struct _arvrb *dir;
};