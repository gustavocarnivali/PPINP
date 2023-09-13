O PPINP encontra novas conexões entre duas espécies diferentes.
Este pipeline executa todos os programas necessários para este processo.
É necessário para a funcionalidade do pipeline a sequência de nucleotídeos de duas espécies em formato de arquivo fasta. Exemplos de entradas podem ser obtidas na pasta input deste pipeline como 1.fa e 2.fa.
Outras entradas em formato fasta podem ser obtidas em sites como: https://www.ncbi.nlm.nih.gov/
Também é necessário para a funcionalidade do pipeline a sequência de conexões de proteínas e as proteínas do banco de dados utilizado. Exemplos destas entradas podem ser obtidos na pasta input deste pipeline como connections.txt e proteins.fa.
Este pipeline utiliza as conexões proteicas e as proteínas de 9 espécies de referência do portal String disponíveis na pasta input como connections.txt e proteins.fa.
Outros portais podem ser utilizados neste pipeline como o Intact e o Biogrid. Caso o usuário opte por utilizar outro banco de dados o arquivo de conexões e proteínas do banco deve ser renomeado para connections.txt e proteins.fa e colocado na pasta input deste pipeline.
É possível executar este pipeline com as duas saídas do BLAST, neste caso o comando de execução deve ser alterado, como será descrito abaixo. Também será necessário para este comando 5 arquivos: as duas entradas (1.fa e 2.fa), o arquivo de conexões (connections.txt) e as duas saídas do BLAST, exemplificadas na pasta input como s_1_string.out e s_2_string.out. 
Este pipeline não apresenta otimizações, portanto não é indicado o uso de grandes arquivos de entrada. A utilização de grandes arquivos pode desenvolver erros inesperados no pipeline.


Requisitos:
   Install python (sudo apt install python3-pip)
   Install biolib (sudo pip3 install pybiolib)
   
   Todos os programas foram implementados em c++.
   Necessário a execução em Linux.


Uso:
   Execute ./ppinp.sh Par1 Par2 Par3 Par4 Par5 Par6 Par7
  
   Par1 deve assumir o valor 1 ou 2; 1 para o pipeline completo; 2 para não executar o BLAST.
   Para Par1=1
      Par2 deve assumir o nome do primeiro FASTA de entrada.
      Par3 deve assumir o nome do segundo FASTA de entrada. 
      Par4 deve assumir o nome do arquivo de conexões proteicas do banco de dados escolhido.
      Par5 deve assumir o nome do arquivo de nomes das proteínas do banco de dados escolhido.      
      Par6 deve assumir o número de threads escolhido
        
   Para Par1=2
      Par2 deve assumir o nome do primeiro FASTA de entrada.
      Par3 deve assumir o nome do segundo FASTA de entrada. 
      Par4 deve assumir o nome do arquivo de conexões proteicas do banco de dados escolhido.
      Par5 deve assumir o nome do primeiro arquivo de saída do BLAST.
      Par6 deve assumir o nome do segundo arquivo de saída do BLAST.
      Par7 deve assumir o número de threads escolhido
    
    
Exemplos:
   ./ppinp.sh 1 1.fa 2.fa connections.txt proteins.fa 2
      ou
   ./ppinp.sh 2 1.fa 2.fa connections.txt s_1_string.out s_2_string.out 2


Saídas: (todos os arquivos de saída estão na pasta output)
   graph.fa: vértices ou proteínas encontradas no grafo com seus nucleotídeos.
   score.txt: conexões proteicas encontradas no grafo com sua pontuação.
   outputsignalp.txt: saída do SignalP com o nome e a localidade das proteínas encontradas.
   outputtargetp.txt: saída do TargetP com o nome e a localidade das proteínas encontradas.
   outputtmhmm.txt: saída do TMHMM com o nome e a localidade das proteínas encontradas.
