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

