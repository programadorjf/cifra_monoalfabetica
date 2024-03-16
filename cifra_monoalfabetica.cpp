/*
Autores: Jo�o Fabricio
Disiplina de Criptografia e seguran�a de Dados
		
		TRABALHO 2
EXERCICIO 3. Crie um programa capaz de criptografar e decriptografar usando uma cifra monoalfab�tica simples.
A chave de criptografia deve ser passada ao programa como uma variavel.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#define generica "nopqrstuvwxyzabcdefghijklm" // Defini��o da chave gen�rica.

char alfabeto[27] = "abcdefghijklmnopqrstuvwxyz"; // Inicializa��o de vetor global.

void mono(char *chave, char *texto_claro, char cript){ // Fun��o monoalfabetica. Recebe os par�metros para criptografar/descriptografar.
	int i, j; // Inicializa��o das variaveis.
	if(cript=='c' || cript=='C'){ // Condi��o para criptografar o texto.
      for (i = 0; i < 100 && texto_claro[i] != '\0'; i++){ // Comando de repeti��o.
      	for (j = 0; j < 27; j++){
      		if (texto_claro[i] != alfabeto[j]){ // Condi��o para verificar a qual letra do alfabeto corresponde a letra do texto_claro.
      			continue; // Continua o comando de repeti��o.
      		}
      		texto_claro[i] = chave[j]; // Coloca no texto_claro a letra conrrespondente da chave.
      		break; // Para o comando de repeti��o.
      	}
      }
    printf("\n\nTEXTO CRIPTOGRAFADO:\n\n %s\n\n", texto_claro); // Imprime o texto criptografado.
    }
    if(cript=='d' || cript=='D'){ // Condi��o para descriptografar o texto.
      for (i = 0; i < 100 && texto_claro[i] != '\0'; i++){ // Comando de repeti��o.
      	for (j = 0; j < 27; j++){
      		if (texto_claro[i] != chave[j]){ // Condi��o para verificar a qual letra da chave corresponde a letra do texto_claro.
      			continue; // Continua o comando de repeti��o.
      		}
      		texto_claro[i] = alfabeto[j]; // Coloca no texto_claro a letra conrrespondente do alfabeto.
      		break; // Para o comando de repeti��o.
      	}
      }
    printf("\n\nTEXTO DESCRIPTOGRAFADO:\n\n %s\n\n", texto_claro); // Imprime o texto descriptografado.
    }
}
int main (int argc, char *argv[]){ // Fun��o que gerencia o c�digo.
	char texto_claro[100], chave[27], cript; int teste;
	printf("CIRPTOGRAFIA E SEGURANCA DE DADOS\nCIFRA MONOALFABETICA - JOAO FABRICIO\n\n"); // Imprime mensagem com informa��es.
	printf("\nDIGITE 'C' SE QUISER CIRPTOGRAFAR OU 'D' SE QUISER DESCRIPTOGRAFAR O TEXTO: "); // Imprime a mensagem para que o usu�rio escolha sua op��o.
	scanf("%c",&cript); // Escaneia o que foi digitado pelo usu�rio e armazena em cript.
	printf("\nESCREVA O TEXTO PARA ENCRIPTACAO / DECRIPTACAO (SEM ESPACO ENTRE AS PALAVRAS):\n\n "); // Imprime a mensagem para que o usu�rio escreva o texto.
	scanf("%s",&texto_claro); // Escaneia o que foi digitado pelo usu�rio e armazena em texto_claro.
	printf("\nDIGITE '1' PARA ESCREVER A PERMUTACAO DO ALFABETO QUE CORRESPONDE A CHAVE OU \nDIGITE '2' PARA UTILIZAR A CHAVE 'nopqrstuvwxyzabcdefghijklm': "); // Imprime a mensagem para que o usu�rio escolha sua op��o.
	scanf("%i",&teste); // Escaneia o que foi digitado pelo usu�rio e armazena em teste.
	if(teste==2){ // Verifica se o usu�rio deseja utilizar a chave gen�rica.
		strcpy(chave,generica); // Coloca o chave generica "nopqrstuvwxyzabcdefghijklm" no vetor chave.
	}
	else{ // caso n�o queira usar a chave generica, poder� digitar o texto.
		printf("\nDIGITE A PERMUTACAO DO ALFABETO QUE CORRESPONDE A CHAVE:\n\n "); // Imprime a mensagem para que o usu�rio escreva a chave.
		scanf("%s",&chave); // Escaneia o que foi digitado pelo usu�rio e armazena em chave.
	}
	mono (chave, texto_claro, cript); // Chama a fun��o mono, passando os par�metros informados pelo usu�rio.
	system("pause"); // Aguarda at� que uma tecla seja pressionada para fechar a tela ap�s a finaliza��o do programa.
	return 0;
}
