# Sistema de Matchmaking para Jogos Online

## Descrição
Sistema para gerenciamento de jogadores em um jogo online. O sistema armazena
jogadores em uma fila de espera e forma grupos de jogadores com níveis de habilidade
semelhantes.

Funcionalidades:
- Inserir e remover jogadores;
- Ordenar os jogadores por score usando insertion sort;
- Ordenar os jogadores por score usando merge sort;
- Formar um grupo de jogadores com scores próximos;
- Recuperar e exibir os jogadores na fila de espera.

## Compilação e Execução

No Windows:

`g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking.exe`

`.\matchmaking.exe`

No Linux / macOS:

`g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking`

`./matchmaking`

## Organização dos Arquivos
O sistema conta com duas classes principais que implementam todas as funcionalidades
do matchmaking: a classe `Player`, que contém todos os atributos de um jogador, e a
classe `Matchmaking`, que gerencia e controla todo o sistema de matchmaking.

### Descrição
**Classe `Player`**

Representa um jogador, que possui por atributos um ID, representado por um `int`;
um nome, representado por uma `std::string`; um score, representado por um `int` 
e um timestamp, representado por um `int`.

**Classe `Matchmaking`**
Implementa o sistema, com os seguintes métodos disponíveis para o usuário:

`insert`: insere um novo jogador na lista de espera do sistema. Caso tenha sido 
possível fazer a inserção, o método retorna `true`, caso contrário, retorna `false`.

`removePlayer`: Procura o jogador com o ID indicado. Caso seja encontrado um jogador 
correspondente, faz a sua remoção e retorna `true`, caso contrário, retorna `false`.

`sortByScoreInsertion`: Ordena de maneira crescente, com base no score, a lista de espera 
dos jogadores utilizando `insertion sort`. Caso haja empate no score de dois ou mais jogadores, 
utiliza o timestamp como critério de desempate, também em ordem crescente.

`sortByScoreMerge`: Ordena de maneira crescente, com base no score, a lista de espera dos 
jogadores utilizando `merge sort`. Caso haja empate no score de dois ou mais jogadores, 
utiliza o timestamp como critério de desempate, também em ordem crescente.

`formGroup`: Forma grupos de jogadores com scores próximos. Caso seja possível formar
um grupo, remove os jogadores da lista de espera e retorna um array de jogadores, que
corresponde ao grupo formado. Caso contrário, retorna `nullptr` sem remover jogadores.

`getWaitingPlayers`: Retorna um array com todos os jogadores que ainda estão na lista 
de espera do sistema. Caso não haja nenhum jogador na lista de espera, retorna `nullptr`.

`printWaitingPlayers`: Imprime a lista de espera do sistema.

## Execução dos Testes

### Testes de desempenho
Por padrão, o arquivo `main.cpp` está configurado para exibir o funcionamento do sistema.
Esta configuração pode ser alterada na função `main`, alterando o valor da variável `system`
de `true` para `false`. Dessa forma, é possível executar os testes de desempenho que foram
criados.

### Funcionamento do sistema
Nos testes de funcionamento, por padrão o sistema está configurado para fazer a ordenação
utilizando insertion sort. Para realizar o teste utilizando merge sort, basta alterar o 
parâmetro `decision_sort`, da função `systemTests` de `false` para `true`.

