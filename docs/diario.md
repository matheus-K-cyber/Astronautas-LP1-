# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`):
- Modelo usado:

## Parte 1: antes de programar

- O que cada classe guarda: 
-a classe dos astonautas(astro.h) recebe informações básicas de cadastro e situação(vivo ou morto, disponível ou não);
-a classe de voo(voo.h) armazena e recebe os dados mais relevantes, executa comandos para os voos e os astronautas, checare valida estes comandos e os astronautas;
-a classe da agência(agencia.h) liga-se as outras e passa os dados para elas e dá as ordens para executar os comandos das duas classes;
- O que acontece em `LANCAR_VOO`, em palavras: a agencia recebe o comando e roda o seu "lancarVoo(int codigo)", dando a ordem para que Voo execute o comando de lançamento e troque o estado atual para "em curso", caso o voo seja validado.
- Uma dúvida que eu tinha antes de começar: como devo, exatamente, separar: declarações de classes e métodos, implementações e a main, como é a estrutura e funcionamento de cada um desses arquivos e o uso de herança entre arquivos.

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): oque é um main.cpp, um arquivo.cpp e um arquivo.h(diferenças, sintaxe, papéis de cada um, limites, implementações e conexão), comandos de compilação para projetos com múltiplos arquivos, configuração do VScode para esse projeto e como funciona a herança com arquivos(Gemini 3.6 flash estendido), e no openCode questionei a utilidade do código.
- O que aprendi: arquivos .h são TAD's que mostram os "contratos", .cpp garante o comprimento dos contratos sem que o contratante saiba os meios, um .h pode receber outros .h como herança, main receberá aas ordens e fará as "convocações" das classes e seus contratos, como fazer arquivos.o e executá-los e detalhes para configurar o ambiente do projeto(usando WSL Ubuntu), isso com o Gemini 3.6 flash estendido, o OpenCode me avisou sobre não ter usado certas variáveis de Agencia(buscarAstronauta e buscarVoo) e que há implementações incompletas no geral.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
- A que escolhi e por quê:
- O que mudou no código, e se os seis testes continuaram passando:
- O que entendi que não sabia antes:

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
