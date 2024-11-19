# Programa de Sincronização de Threads e Salas

Este programa simula o controle sincronizado de threads que seguem trajetos por um conjunto de salas, utilizando mutexes e variáveis de condição. Esse programa é uma aplicação prática do uso de **Pthreads** em C/C++ para resolver problemas de concorrência.

O objetivo é que threads percorram um número arbritário de salas, sempre entrando em trios e esperando a sala estar vazia para o próximo trio entraar.
---

## Sumário
- [Introdução](#introdução)
- [Objetivo](#objetivo)
- [Funcionamento](#funcionamento)
  - [Como as Threads Funcionam](#como-as-threads-funcionam)
  - [Regra de Sincronização](#regra-de-sincronização)
  - [Função `passa_tempo`](#função-passa_tempo)
- [Exemplo de Entrada e Saída](#exemplo-de-entrada-e-saída)
- [Compilação e Execução](#compilação-e-execução)
- [Detalhes de Implementação](#detalhes-de-implementação)
- [Dependências](#dependências)
- [Autor](#autor)

---

## Introdução
Este exercício simula um sistema de movimentação onde threads (entidades) seguem trajetos pré-definidos em um ambiente com múltiplas salas. Durante a movimentação:
- Threads esperam condições de 3 na fila para entrar na sala
- Sincronização é garantida por mutexes e variáveis de condição

## Funcionamento

### Como as Threads Funcionam
Cada thread segue os seguintes passos:
1. Aguarda seu tempo inicial de espera.
2. Move-se de uma sala para outra, permanecendo o tempo necessário em cada uma.
3. Respeita as condições para entrar em uma sala:
   - A sala deve estar vazia.
   - Um trio de threads deve ser formado para entrar simultaneamente.
4. Após o trajeto completo, a thread sai do sistema.

### Regra de Sincronização
- Ao se mover de uma sala `S1` para `S2`, a thread deve:
  1. Aguardar até que `S2` esteja vazia.
  2. Garantir que três threads (incluindo ela mesma) possam entrar em `S2` juntas.
  3. Liberar a sala `S1` após entrar em `S2`.


## Exemplo de Entrada e Saída

### Entrada
```plaintext
3 5
10 10 4
    1 40 
    2 10 
    1 20 
    3 20
20 20 3
    1 30
    2 20
    3 40
30 30 1
    1 80
40 40 2
    1 10
    3 30
50 50 2
    2 30
    1 30
```

### Saída Esperada
```plaintext
  30 [ 10 @ 1 z 40
  30 [ 20 @ 1 z 30
  30 [ 30 @ 1 z 80
  60 ) 20 @ 1
  70 ) 10 @ 1
  70 [ 10 @ 2 z 10
  70 [ 20 @ 2 z 20
  70 [ 50 @ 2 z 30
  ...
 170 ) 20 @ 3
```
**Nota:** A saída pode variar dependendo da ordem de movimentação das threads.

---

## Compilação e Execução

### Makefile
Crie um `Makefile` com as seguintes regras:
- **`make build`**: Compila o programa.
- **`make run`**: Executa o programa usando a entrada padrão.
- **`make clean`**: Remove arquivos temporários e binários.

### Exemplo
```bash
make build
./program < data/ent.txt
make clean
```

---

## Detalhes de Implementação

### Sincronização com Pthreads
- **Mutexes**: Garantem exclusão mútua ao acessar estruturas compartilhadas.
- **Variáveis de Condição**: Gerenciam threads bloqueadas até que um trio esteja disponível.

### Estrutura do Programa

**Inicialização das Salas**
   - Para cada sala, inicializa:
     - Um mutex (`salas[i].mutex`) para garantir exclusão mútua.
     - Variáveis de condição (`salas[i].salaVazio` e `salas[i].trioPronto`) para controle de sincronização.
     - Contadores para fila e ocupação atual.

**Configuração das Threads**
   - Cria um vetor `threadsInfo` para armazenar as informações de cada thread, como:
     - Identificador (`id`).
     - Tempo inicial de espera.
     - Trajetória (sequência de salas e tempos de permanência).
   - Para cada thread, lê os dados de entrada e armazena no objeto correspondente.

**Sincronização das Threads**
   - Usa `pthread_join` para esperar que todas as threads terminem sua execução antes de continuar.
---

## Dependências
- **Compilador**: GCC com suporte a `-pthread`.
- **POSIX Threads**: Utilizado para gerenciamento de threads e sincronização.

---

## Autor
Este programa foi desenvolvido por **Tomás Lacerda Muniz** como parte do curso **Fundamentos de Sistemas Paralelos e Distribuídos**.

**Matrícula**: 2021088116
```