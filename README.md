# Lista_Onibus</br>
Codigo para ler arquivos log de um sistema metropolitano de onibus e fazer a manipulação desses dados para geração de realatórios.</br>
</br>
Esse projeto ultiliza listas dinamicas para fazer a alocação de dados extraidos de um arquivo. </br>
Neste arquivo estão "n" linhas no padrão "ID DDMMYYY HHMI PLACA TERMINAL" e a partir destas são feitos relátorios como: </br>
  -Tempo médio que cada veiculo levou para realizar a viagem</br>
  -Valor que cada empresa deve receber</br>
  -Número de viagens</br>
</br>
Sobre a estrutura do projeto:</br>
O projeto está dividido em ultilização e implementação, de forma que, o desenvolvedor não necessita conhecer ou entender como é </br>
feita a criação e manutenção das listas. </br>
Bastando dessa forma apenas importar o arquivo "tad_list2.c" e ultilizar os métodos que esses disponibilizam.</br>
    Metodos implementados no arquivo de lista:</br>
       void inicializa_lista(lista_encadeada *le);</br>
       int tamanho(lista_encadeada le); </br>
       int incluir_elemento(lista_encadeada *le, int i, elemento e);</br>
       int obter_elemento(lista_encadeada le, int i, elemento *e);</br>
       int alterar_elemento(lista_encadeada *le, int i, elemento e);</br>
       int excluir_elemento(lista_encadeada *le, int i);</br>
       int inverte(tipo_lista *l);</br>
       int tamanho_quantidade_nodos(lista_encadeada le);</br>
</br>
 *existe dois metodos "tamanho" a diferença está no algoritmo de contagem, o "tamanho_quantidade_nodos" é feita uma contagem dinamica enquanto que no "tamanho"</br>
 é retornado apenas o valor salvo na lista que se esperar se atualizado a cada inclusão/exclusao.</br>
