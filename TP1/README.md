Entrada
Seu programa deve receber três parâmetros de linha de comando. O primeiro será:

• -a: se o problema a ser resolvido é o de avaliação de expressões.
• -s: Se o problema a ser resolvido é o de satisfabilidade.

O segundo sempre será uma string contendo a representação da fórmula e o terceiro outra
string contendo a valoração.

## String p
A string p contém a representação de uma fórmula lógica
e seu tamanho máximo é da ordem de 10^6 caracteres.

## String s
A string s é uma string binária
que contém uma valoração para as variáveis presentes na fórmula. O tamanho de s é no
máximo 100.

## Representação das Formulas
Na representação da fórmula as variáveis são indicadas por inteiros, de forma que a variável
xi é representada pelo inteiro i. Os operadores ∧, ∨ e ¬ serão representados, respecti-
vamente por "&", "|"e "∼". Todos os símbolos da fórmula, incluindo parêntesis estarão
separados por um espaço em branco.
A string s estará codificada de forma que o valor que deverá ser associado a variável xi
seja o i-ésimo caractere da string.
A saída deve ser apenas um inteiro, "0"ou "1", contendo o resultado da avaliação da ex-
pressão. A saída deve ser uma impressão na tela, e deve ser encerrada com uma quebra
de linha.
