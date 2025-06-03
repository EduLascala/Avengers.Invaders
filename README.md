# Avengers.Invaders

---

## Visão Geral

Este repositório contém um jogo inspirado no clássico "Space Invaders", reimaginado com personagens e elementos do universo dos Vingadores. O objetivo do jogo é defender a Terra de uma invasão de inimigos, controlando um herói Vingador e eliminando as ondas de invasores.

---

## Funcionalidades

* **Gameplay Clássico de Space Invaders:** Mecânica de jogo familiar onde o jogador controla uma nave (ou herói) na parte inferior da tela, movendo-se lateralmente e atirando em inimigos que avançam.
* **Temática dos Vingadores:** Substituição dos elementos gráficos e sonoros tradicionais por personagens e sons do universo Marvel.
* **Múltiplas Fases/Níveis:** Progressão através de níveis com aumento de dificuldade e novos tipos de inimigos.
* **Sistema de Pontuação:** Registro de pontos com base nos inimigos destruídos.
* **Sons e Música:** Efeitos sonoros para tiros, explosões e música de fundo temática.
* **Telas de Início e Fim de Jogo:** Interface de usuário para iniciar o jogo e exibir o resultado final.

---

## Tecnologias Utilizadas

* **Linguagem de Programação:** Python
* **Bibliotecas/Frameworks:**
    * **Pygame:** Essencial para gráficos 2D, áudio e manipulação de eventos.
    * *(Adicione outras bibliotecas específicas que você utilizou, se houver.)*

---

## Estrutura do Projeto

A estrutura do projeto está organizada da seguinte forma:

Avengers.Invaders/
├── src/
│ ├── main.py             # Arquivo principal do jogo
│ ├── player.py           # Lógica do jogador (herói Vingador)
│ ├── enemy.py            # Lógica dos inimigos (invasores)
│ ├── projectile.py       # Lógica dos projéteis (tiros do jogador e inimigos)
│ ├── game.py             # Lógica central do jogo (estados, loop, etc.)
│ ├── constants.py        # Constantes do jogo (tamanhos, velocidades, etc.)
│ └── ui.py               # (Opcional) Lógica para elementos de UI como pontuação, menu
├── assets/
│ ├── images/             # Imagens dos heróis, inimigos, fundo, explosões
│ │ ├── hero_ironman.png
│ │ ├── enemy_chitauri.png
│ │ └── ...
│ ├── sounds/             # Efeitos sonoros (tiro, explosão, etc.)
│ │ ├── shoot.wav
│ │ ├── explosion.wav
│ │ └── ...
│ └── music/              # Música de fundo
│ └── bg_music.mp3
├── .gitignore            # Arquivo para ignorar arquivos e pastas no Git
├── README.md             # Este arquivo de documentação
└── LICENSE               # Arquivo de licença (se aplicável)

---

## Como Instalar e Executar

Para rodar este jogo em sua máquina local, siga os passos abaixo:

1.  **Pré-requisitos:**
    * **Python 3.x** instalado. Você pode baixá-lo em [python.org](https://www.python.org/downloads/).
    * `pip` (gerenciador de pacotes do Python) instalado (geralmente já vem com o Python).

2.  **Clonar o Repositório:**
    Abra seu terminal ou prompt de comando e execute:

    ```bash
    git clone [https://github.com/EduLascala/Avengers.Invaders.git](https://github.com/EduLascala/Avengers.Invaders.git)
    cd Avengers.Invaders
    ```

3.  **Instalar Dependências:**
    Acesse a pasta do projeto (se você já executou `cd Avengers.Invaders`, já está nela) e instale as bibliotecas necessárias:

    ```bash
    pip install pygame
    # pip install alguma_outra_lib (Se houver outras bibliotecas)
    ```

4.  **Executar o Jogo:**
    Dentro da pasta principal do projeto (`Avengers.Invaders`), execute o arquivo principal:

    ```bash
    python src/main.py
    ```

---

## Como Jogar

* **Movimento:** Use as setas do teclado **esquerda** e **direita** (ou **A** e **D**) para mover seu herói Vingador horizontalmente.
* **Tiro:** Pressione a tecla **espaço** para atirar nos inimigos.
* **Objetivo:** Destruir todas as ondas de invasores sem que eles cheguem à parte inferior da tela ou atinjam seu herói.
* **Pontuação:** Ganhe pontos por cada inimigo destruído.

*(Ajuste as instruções de controle e jogabilidade conforme o seu jogo funciona.)*

---


