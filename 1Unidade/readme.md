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

<code>gnuplot> set xrange [0:10]<br/><br/></code>
<code>gnuplot> set yrange [-2:2]<br/><br/></code>
<code>gnuplot> plot sin(x) title 'Senóide', cos(x) title 'Cossenóide'<br/><br/></code>
<code>gnuplot> replot <br/><br/></code>

<br/><br/>
Para utilizar coordenadas polares usa-se o comando set polar. Para espaços 3D utiliza-se a função splot no lugar de plot.
  
