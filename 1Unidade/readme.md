# Usando gnuplot para gerar gráficos

O gnuplot é um software que facilita a criação de graficos 2D e 3D. Neste documento será mostrado alguns comandos básicos de utilização, e algumas opções que podem incrementar mais resultado final do gráfico.

## Iniciando o gnuplot
<code>
$ gnuplot
Terminal type set to 'x11'
gnuplot> </code>
<br/><br/>
Para encerrar a execução do gnuplot é só precionar <strong>ctrl+D</strong> (mas tome cuidado, pois ele fecha a execução, fiz isso algumas vezes e não gostei muito não kkkk)

## Plotando funções
Usa-se o comando <strong>plot</strong> para plotar funções 2D. No gnuplot existem as variáveis próprias de cada espaço, no caso 2D é utilizada  a variável <strong>x</strong> para coordenadas retangulares e <strong>t</strong> para coordenadas polares.

<code>gnuplot> plot sin(x)</code>
<br/><br/>
Também é possível imprimir mais de uma função separando-as por vírgula.

<code>gnuplot> plot sin(x), log(x), cos(x), x**2</code>
<br/><br/>
Podemos também setar o título da função dentre outros parametros:
<br/><br/>
<code>gnuplot> plot sin(x) title 'Senóide'</code>
<br/><br/>
Alterar os limites do gráfico:

<code>gnuplot> set xrange [0:10]</code><br/>
<code>gnuplot> set yrange [-2:2]</code><br/>
<code>gnuplot> plot sin(x) title 'Senóide', cos(x) title 'Cossenóide'</code><br/>
<code>gnuplot> replot </code><br/>

Para utilizar coordenadas polares usa-se o comando <strong>set polar</strong>. Para espaços 3D utiliza-se a função <strong>splot</strong> no lugar de <strong>plot</strong>.

## Plotando dados de um arquivo
Antes de mostrar como carregar os dados de um arquivo, vamos criar esse arquivo.

<code>$ cat > dados.dat << EOF</code><br/>
<code>> 0.0   0.0   0.0</code><br/>
<code>> 0.1   1.5   2.0</code><br/>
<code>> 0.2   1.2   2.2</code><br/>
<code>> 0.3   1.9   2.1</code><br/>
<code>> 0.5   0.5   0.9</code><br/>
<code>> EOF</code><br/>
<code>$ gnuplot</code><br/>

Carregando os dados do arquivo e imprimindo:

<code>gnuplot> plot 'dados.dat'</code><br/>

Note que foram plotados os pontos (x,y), onde x é a primeira coluna do arquivo, e y a segunda. Podemos selecionar as colunas que desejamos usar:

<code>gnuplot> plot 'dados.dat' using 1:3 title 'Pontos'</code><br/>
Agora foram foram utilizadas as colunas 1 e 3 (x,y). Podemos ainda interpolar linearmente esses pontos utilizando a opção  <strong>with lines</strong>.

<code>  gnuplot> plot 'dados.dat' using 1:2 title 'Coluna 2' with lines, \</code><br/>
<code>> plot 'dados.dat' using 1:3 title 'Coluna 3' with lines </code><br/>
<br/>
Usar interpolação é muito útil quando pretende-se analizar valores intermediários dentre os pontos que se possui nos dados.
  
