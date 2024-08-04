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

  bool insert_at(unsigned int index, int value) {} //NÃO FEITA
  bool remove_at(unsigned int index) {} //NÃO FEITA
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
    lista_presidiaria(); //chamando o construtor pra zerar tudo
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
      this-> tail = novo; //atualiza de fato que agora a nossa nova "cauda" ou seja ultimo elemento é o novo elemento
    }
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
  }
  bool pop_back() {
    if (this->tail == nullptr) { //verificando se a lista ta vazia
      return; //se tiver retorna sem remover ne, ja q n tem nada pra remover
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
      return;
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
      return;
    } else { 
      return this->tail->valor; // se n tiver vai retornar o valor do ultimo elemento que é nossa "caudinha"
    }
  }
  int front(){
    if(this->head == nullptr) { //verifica se a lista n ta vazia
      return;
    } else {
      return this->head->valor; //se n tiver vai retornar o valor da "cabeça"
    }
};
#endif