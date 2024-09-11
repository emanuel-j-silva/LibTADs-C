
## Implementação de Tipos Abstratos de Dados (TADs) em C
Este projeto contém a implementação de várias estruturas de dados fundamentais utilizando a linguagem C. O objetivo é fornecer uma base para estudo e experimentação com TADs, incluindo filas, pilhas e listas.

### Estruturas de Dados Implementadas
#### Fila Encadeada (Linked Queue):

Implementação de uma fila utilizando ponteiros, onde cada elemento aponta para o próximo.
Suporta operações de inserção (enqueue) e remoção (dequeue).

#### Fila Estática Circular (Static Circular Queue):

Fila implementada utilizando um array de tamanho fixo, onde o final da fila se conecta ao início para otimizar o uso de espaço.
Suporta operações de enqueue e dequeue, com controle para evitar overflow e underflow.

#### Lista Estática (Static List):

Lista implementada em um array de tamanho fixo, onde os elementos são armazenados em sequência.
Suporta operações de inserção, remoção e busca.

#### Pilha (Stack):

Implementação de uma pilha utilizando um array, onde o último elemento adicionado é o primeiro a ser removido (LIFO). Suporta operações de push e pop.
### Arquivos do Projeto

- `fila_encadeada.c`: Implementação da fila encadeada.
- `fila_est_circ.c`: Implementação da fila estática circular.
- `lista_est.c`: Implementação da lista estática.
- `pilha.c`: Implementação da pilha.
- `programa_teste.c`: Implementação do menu de testes.