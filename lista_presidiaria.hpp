#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

class lista_presidiaria {
  private:
    struct node { //vai definir um nó
      int valor; //valor do elemento armazenado no nosso elemento
      node *proximo, *anterior; //ponteiros pra acessar o anterior e o proximo elemento da lista
    };
    node *head, *tail; //ponteiros para acessar o primeiro nó da lista (head) e o ultimo (tail)
    unsigned int tamanho; 
  public: 
    lista_presidiaria() { //Construtor
      this->head == nullptr;
      this->tail == nullptr;
      this->tamanho = 0;
    }
    ~lista_presidiaria() { //Destrutor
      clear();
    } 
    unsigned int size() { 
      return this->tamanho;
    }
    unsigned int capacity() { 
      return this->size(); //tamo retornando o tamanho pq como é lista e a disposição delas na memória é aleatória, não é como de array que é sequencial
    }
    double percent_occupied() {
      return 1.0; //numa lista ligada como capacidade = tamanho meio que sempre, independente se a gente adicionar ou tirar memória, então podemos dizer que o percentual ocupado é sempre 100% que é = 1
    }

  bool insert_at(unsigned int index, int value) {
    unsigned int x = 0;
    node *elemento = this->head;
    while (elemento != nullptr){
      if (x == index - 1){
        node *novo = new node;
        novo->valor = value;
        novo->proximo = elemento->proximo;
        elemento->proximo = novo;
        novo->anterior = elemento;
        this->tamanho++;
        return true;
      }
      elemento = elemento->proximo;
      x++;
    }
    return false;
  }
  bool remove_at(unsigned int index) { //QUE FUNÇÂO CHATAAAAA TO QUASE CHRANDO
    if (index >= this->tamanho) return false;
    node *atual = this->head;
    for (unsigned int i = 0; i < index; ++i){
      atual = atual->proximo;
    }
    if (atual->anterior) atual->anterior->proximo = atual->proximo;
    if (atual->proximo) atual->proximo->anterior = atual->anterior;
    if (atual == this->head) this->head = atual->proximo;
    if (atual == this->tail) this->tail = atual->anterior;
    delete atual;
    this->tamanho -= 1;
    return true;
  }
  int get_at(unsigned int index) {
    node *atual = this->head; //cria um novo ponteiro q vai percorrer nossa lista, ele vai inicializar no head
    for (unsigned int i = 0; i < index; i++) { //for pra percorrer a lista até o indice escolhido
      atual = atual->proximo; //o ponteiro atual vai apontar pro proximo elemento da lista, meio q se deslocando
    }
    return atual->valor; //vai retornar o valor que tá no indice que foi escolhido e o atual parou.
  }

  void clear() {
    node *atual = this->head; //ponteiro q vai se inicializar no head
    while(atual != nullptr) { //se o atual for diferente de nulo, vai continuar percorrendo a lista
      node *remover = atual; //ponteiro novo q vai receber o atual, pra ser removido dps
      atual = atual->proximo; //atual vai receber o proximo elemento da lista
      delete remover; //vai remover elemento do atual
    }
    this->head = nullptr; //chamando o construtor pra zerar tudo
    this->tail = nullptr;
    this->tamanho = 0;
  }
  void push_back(int value) {
    node *novo = new node; //novo nó da lista
    novo->valor = value; //vai receber o valor
    novo->proximo = nullptr; //como é o ultimo elemento, não existiria proximo por isso o null
    novo->anterior = this->tail; //anterior vai ser o antigo ultimo elemento q seria nossa "cauda" do array
    if (this->head == nullptr){ //verificando se a lista ta vazia pq n existiria primeiro elemtno
      this->head = novo; //se a lista ta vazia, o novo elemento vai ser o primeiro elemento da lista e consequetemente o ultimo tbm
    } else {
      this->tail->proximo = novo; //ai se tiver cheia, o ponteiro do proximo vai apontar pro novo elemento
    }
    this-> tail = novo; //atualiza de fato que agora a nossa nova "cauda" ou seja ultimo elemento é o novo elemento
    this->tamanho++;
  }
  void push_front(int value) {
    node *novo = new node; //vamos criar um novo nó na lista
    novo->valor = value; //atribuir valor desse nó aí
    novo->proximo = this->head; //o proximo do novo nó vai ser o head da lista LEMBRAR Q É DUPLAMENTE ENCADEADA
    novo->anterior = nullptr; //o anterior não vai existir pq queremos que seja o primeiro
    if (this->head == nullptr){
      this->tail = novo; //se a lista tiver vazia, e adicionamos um elemento, ent o novo elemento será o ultimo pq só tem ele
    } else {
      this->head->anterior = novo; //se a lista não tiver vazia, o anterior do head vai ser o novo elemento
    }
    this->head = novo; //vai atualizar o head pra apontar pro novo nó LEMBRAR DUPLAMENTE ENCADEADA
    this->tamanho++;
  }
  bool pop_back() {
    if (this->tail == nullptr) { //verificando se a lista ta vazia
      return -1;//se tiver retorna sem remover ne, ja q n tem nada pra remover
    }
    if (this->head == this->tail) { //verificar se só tem um elemento
      delete this->head; //se tiver head e tail são iguais, ai deleta head deletando o unico elemento
      //o que deixa tanto head como tail vazios
      this->head = nullptr;
      this->tail = nullptr;
    }
    this->tail = this->tail->anterior; //atualiza o tail para o anterior, para que quando apaguemos o ultimo elemento exista um novo ultimo
    delete this->tail->proximo; //como tail agora é o "penultimo" elemento, o ultimo vai ser o proximo e vamos deletar ele
    this->tail->proximo = nullptr; //atualiza o proximo do atual tail para null, já que apagamos esse "prox" antigo ultimo elemento
  }
  bool pop_front() {
    if(this->head == nullptr) { //verificar se a lista não ta vazia
      return -1;
    }
    if (this->head == this->tail) { //verificar se só tem um elemento
      delete this->head; //se tiver head e tail são iguais, ai deleta head deletando o unico elemento
      this->head = nullptr; //atualiza os valores de head e tail que agora estão vazios pq n tem elemento
      this->tail = nullptr;
    }
    this->head = this->head->proximo; //atualiza o head para o proximo, para que quando apaguemos o primeiro elemento exista um novo
    delete this->head->anterior; //como head agora é o "segundo" elemento, o primeiro vai ser o anterior e vamos deletar ele
    this->head->anterior = nullptr; //agora o anterior do head é null ebaa
  }
  int back(){
    if(this->tail == nullptr) { //verifica se a lista n ta vazia
      return -1;
    } else { 
      return this->tail->valor; // se n tiver vai retornar o valor do ultimo elemento que é nossa "caudinha"
    }
  }
  int front(){
    if(this->head == nullptr) { //verifica se a lista n ta vazia
      return -1;
    } else {
      return this->head->valor; //se n tiver vai retornar o valor da "cabeça"
    }
  }
  bool remove(int value) {
   node *atual = this->head;
   while(atual == nullptr && atual->valor != value){
    atual = atual->proximo;
   }
   if (atual == nullptr) {
    return false;
   }
   if (atual->proximo != nullptr) {
    atual->anterior->proximo = atual->proximo;
   } else {
    this->head = atual->proximo;
   }
   if (atual->proximo != nullptr) {
    atual->proximo->anterior = atual->anterior;
   } else {
    this->tail = atual->anterior;
   }
   delete atual;
   return true;
  }
    int find(int value) {
      node *atual = this->head; //vai inicializar a partir do head nosso ponteiro auxiliar atual
      int index = 0;
      while (atual != nullptr) { //percorre a lista
        if (atual->valor == value) { //se o valores forem iguais
          return index; //retornar o index q se encontra o valor 
        }
        atual = atual->proximo; //se não vai só continuar deslocando
        index++; //e aumentando esse index ai
      }
      return -1; //se o valor n foi encontrado
    }
    int count(int value) {
      node *atual = this->head; //criação de ponteiro que vai ser inciailizado na cabeça ou seja inicio da lista
      int contador = 0;
      while (atual != nullptr) { //vai percorrer a lista
        if (atual->valor == value) { //valor do elemento atual se for igual ao valor que foi pedido
          contador++; //vai adicionar ao contador
        }
        atual = atual->proximo; //vai ficar deslocando 
      }
      return contador;
    }

    int sum() {
      node *atual = this->head; //criando um nó que vai se inicializar na cabeça
      int total=0; 
      while (atual != nullptr){ //vai percorrer a lista adicionando 
        total += atual->valor; //variavel total vai somando os valores que o atual chega
        atual = atual->proximo; //vai deslocar o ponteiro auxilir atual pros proximos
      }
      return total; 
    }
};
#endif