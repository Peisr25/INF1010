struct trie{
    char letra;
    int termino;
    struct trie *filhos[26];
    int ocupado;
};

typedef struct trie Trie;

Trie* criaNo(char v){
    Trie* temp = (Trie*)malloc(sizeof(Trie));
    temp->letra = v;
    /*calcular posi da letra*/
    return temp;
}
Trie* criaTrie(){
    Trie* temp = (Trie*)malloc(sizeof(Trie));
    temp->letra = 'a';
    temp->ocupado = 0;
    temp->termino = 0;
    return temp;
}