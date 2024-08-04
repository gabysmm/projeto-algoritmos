#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_d {
  private:
    int *p_lista; //criar ponteiro q vai apontar para os espaços de memoria do nosso array
    unsigned int tamanho, capacidade; //criando variavel que vai determinar tamanho e a capacidade do array
    void increase_capacity() { //vai aumentar a capacidade do array
      capacidade = 1000;
      int *novo_array = new int[capacidade];
      for(unsigned i = 0; i < tamanho; i++){  //como percorre todo array, vai ser O(N)
        novo_array[i] = p_lista[i];
      }
      delete [] p_lista; 
      p_lista = novo_array;
    } 

  public:  //O(1) talvez ja que tem valores "fixos"
    array_d () { //construtor que vai estabelecer os valores iniciais do array
      this->tamanho = 0;
      this->capacidade = 1000;
      this->p_lista = new int[capacidade];
    }
    ~array_d() { //destrutor que vai liberar a memoria do array
      delete [] p_lista; 
    }
    unsigned int size() { //vai retornar a quantidade de elementos armazenados no array
      return this->tamanho; 
    }
    unsigned int capacity() { //vai retornar a capacidade do array
      return this->capacidade;
    }
    double percent_occupied() { //vai retornar um valor entre 0 e 1 que representa a porcentagem de espaço ocupado
      if (this->capacidade == this->tamanho) { //q dizer q ta usando 100% do espaço
        return 1.0;
      } else {
        return (double) this->tamanho / (double) this->capacidade; //estaria usando x% do espaço
      }
    }

    bool insert_at(unsigned int index, int value) { //vai inserir um valor em um determinado indice
      if (index > this-> tamanho) { 
        return false; 
      } 
      if (this->tamanho == this->capacidade) { 
        increase_capacity(); 
      } //vai aumentar a capacidade do array caso esteja cheio
      for (unsigned int i = this->tamanho; i > index; --i) { //vai percorrer a lista desde o ultimo numero
        p_lista[i] = p_lista[i-1]; //vai meio q ocorrer um deslocamento de indice, do ultimo pro anterior, percorrendo até chegar no indice que queremos //O(N)
      }
      p_lista[index] = value; //o index escolhido vai receber o valor novo. Ou seja, vai ser meio q inserido um novo elemento. 
      tamanho += 1; //vamos aumentar nosso tamanhozinho do array 
      return true;
    }
    bool remove_at(unsigned int index) {
      if (index >= this->tamanho) {
        return false;
      }
      for (unsigned int i = index; i < this->tamanho - 1; i++) { //vai percorrer a lista desde o indice escolhido até o elemente anterior ao ultimo
        p_lista[i] = p_lista[i+1]; //vai deslocar os elementos para a esquerda, percorrendo até chegar no ultimo elemento
      }
      tamanho -= 1;
      return true;
    }
    int get_at(unsigned int index) {
      if (index >= this->tamanho) {
        return -1; //basicamente vai retornar -1 caso o indice escolhido seja maior que o tamanho do array pq né não vai existir, logo inválido
      } else {
        return p_lista[index]; //se o indice escolhido for válido, vai retornar o nosso elementozinho. 
      }
    }

  void clear() { //vai remover os elementos adicionados, deixando o array original
    delete [] p_lista; //vai liberar a memória alocada pro array atual
    tamanho = 0;  //vai retornar os valores que estabelecemos no construtor. Acho que daria pra chamar o construtor novamente? provavelmente, mas medo. 
    capacidade = 100;
    p_lista = new int[capacidade];
  }
  void push_back(int value){ //vai adicionar um elemento no final do array
    if (this->tamanho == this->capacidade) { 
      increase_capacity();
    } else {
      p_lista[this->tamanho] = value; //vai adicionar o valor novo no final do array
    }
    this->tamanho += 1; 
  }
  void push_front(int value) { //vai adicionar um elemento no inicio do array
    if (this->tamanho == this->capacidade) increase_capacity();
    this->tamanho ++;
    for (unsigned int i = this->tamanho; i > 0; i--){ //vai deslocar nosso array 
        p_lista[i] = p_lista[i-1]; //deslocando os elementos
      }
      p_lista[0] = value; //vai adicionar o valor novo no inicio do array
   }
  bool pop_back() {
    if (this->tamanho == 0) { //verificar se a lista ta vazia
      return false;
    } else {
      tamanho -= 1; //se n tiver vazia, literalmente só remover o ultimo elemento diminuindo a lista
      return true;
    }
  }

  bool pop_front() { //logica igual ao de remove_at
    if (this->tamanho == 0){ //de novo verificando se a lista não ta vazia
      return false;
    } else {
      for (unsigned int i = 0; i < this->tamanho - 1; i++) { //deslocar os elementos 1 posição para a esquerda
        p_lista[i] = p_lista[i+1]; //deslocando os elementos
      }
    }
    tamanho -= 1;
    return true;
  }
  int back() {
    if (this->tamanho == 0) { 
      return -1;
    } else {
      return p_lista[this->tamanho - 1]; //retornando o ultimo elemento
    }
  }
  int front(){
    if (this->tamanho == 0) {
      return -1;
    } else {
      return p_lista[0]; //literalmente só pegar o primeiro elemento da lista
    }
  }
  bool remove(int value) {
    int index = find(value);
    if (index != -1) {
        remove_at(index);
        return true;
    }
    return false;
}
    
  int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente
      for (unsigned int i = 0; i < this->tamanho; i++) { 
        if (p_lista[i] == value) {
          return i;
        } else {
          return -1;
      }
    } 
  }
  int count(int value) { //contador
    int contador = 0;
    for (unsigned int i = 0; i < this->tamanho; i++) {
      if (p_lista[i] == value) {
        contador += 1;
      } else {
        return contador;
    }
   }
  }
  int sum(){
    int contador = 0;
    for (unsigned int i = 0; i < this->tamanho; i++) {
      contador = contador + p_lista[i];
    }
    return contador;
  }
};
#endif // __ARRAY_LIST_IFRN__