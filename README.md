# Shiraga-trabalho-03
Repositório da disciplina de PEE do aluno Shiraga.

O programa do display de 7 segmentos utiliza as entradas de 0 a 9, dada pela variável 'ent', realiza sua leitura em binário (utilizando um truque de multiplicação
por 0x0(2^n)) na forma 'DCBA'.
Esse binário será utilizado para controlar os segmentos 'gfedcba' do display de 7 segmentos, com lógica feita a partir do Mapa de Karnaugh dos mesmos, e produzindo a saída
na variável 'seg'.
Finalmente, essa saída é mostrada ao usuário utilizando o mesmo truque de multiplicação anteriormente mencionado, de forma a mostrar o que acontece com cada segmento do
display em questão.