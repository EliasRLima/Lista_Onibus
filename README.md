# Lista_Onibus
Codigo para ler arquivos log de um sistema metropolitano de onibus e fazer a manipulação desses dados para geração de realatórios.

Esse projeto ultiliza listas dinamicas para fazer a alocação de dados extraidos de um arquivo. </br>
Neste arquivo estão "n" linhas no padrão "ID DDMMYYY HHMI PLACA TERMINAL" e a partir destas são feitos relátorios como:
  -Tempo médio que cada veiculo levou para realizar a viagem
  -Valor que cada empresa deve receber
  -Número de viagens

Sobre a estrutura do projeto:
O projeto está dividido em ultilização e implementação, de forma que, o desenvolvedor não necessita conhecer ou entender como é 
feita a criação e manutenção das listas. 
Bastando dessa forma apenas importar o arquivo "tad_list2.c" e ultilizar os métodos que esses disponibilizam.
    Metodos implementados no arquivo de lista:
       void inicializa_lista(lista_encadeada *le);
       int tamanho(lista_encadeada le); 
       int incluir_elemento(lista_encadeada *le, int i, elemento e);
       int obter_elemento(lista_encadeada le, int i, elemento *e);
       int alterar_elemento(lista_encadeada *le, int i, elemento e);
       int excluir_elemento(lista_encadeada *le, int i);
       int inverte(tipo_lista *l);
       int tamanho_quantidade_nodos(lista_encadeada le);
       
 *existe dois metodos "tamanho" a diferença está no algoritmo de contagem, o "tamanho_quantidade_nodos" é feita uma contagem dinamica enquanto que no "tamanho"
 é retornado apenas o valor salvo na lista que se esperar se atualizado a cada inclusão/exclusao.
