/*
Autores: João Fabricio
Disiplina de Criptografia e segurança de Dados
		
		TRABALHO 2
EXERCICIO 3. Crie um programa capaz de criptografar e decriptografar usando uma cifra monoalfabética simples.
A chave de criptografia deve ser passada ao programa como uma variavel.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctype.h>
#define generica "nopqrstuvwxyzabcdefghijklm" // Definição da chave genérica.

char alfabeto[27] = "abcdefghijklmnopqrstuvwxyz"; // Inicialização de vetor global.

void mono(char *chave, char *texto_claro, char cript){ // Função monoalfabetica. Recebe os parâmetros para criptografar/descriptografar.
	int i, j; // Inicialização das variaveis.
	if(cript=='c' || cript=='C'){ // Condição para criptografar o texto.
      for (i = 0; i < 100 && texto_claro[i] != '\0'; i++){ // Comando de repetição.
      	for (j = 0; j < 27; j++){
      		if (texto_claro[i] != alfabeto[j]){ // Condição para verificar a qual letra do alfabeto corresponde a letra do texto_claro.
      			continue; // Continua o comando de repetição.
      		}
      		texto_claro[i] = chave[j]; // Coloca no texto_claro a letra conrrespondente da chave.
      		break; // Para o comando de repetição.
      	}
      }
    printf("\n\nTEXTO CRIPTOGRAFADO:\n\n %s\n\n", texto_claro); // Imprime o texto criptografado.
    }
    if(cript=='d' || cript=='D'){ // Condição para descriptografar o texto.
      for (i = 0; i < 100 && texto_claro[i] != '\0'; i++){ // Comando de repetição.
      	for (j = 0; j < 27; j++){
      		if (texto_claro[i] != chave[j]){ // Condição para verificar a qual letra da chave corresponde a letra do texto_claro.
      			continue; // Continua o comando de repetição.
      		}
      		texto_claro[i] = alfabeto[j]; // Coloca no texto_claro a letra conrrespondente do alfabeto.
      		break; // Para o comando de repetição.
      	}
      }
    printf("\n\nTEXTO DESCRIPTOGRAFADO:\n\n %s\n\n", texto_claro); // Imprime o texto descriptografado.
    }
}
int main (int argc, char *argv[]){ // Função que gerencia o código.
	char texto_claro[100], chave[27], cript; int teste;
	printf("CIRPTOGRAFIA E SEGURANCA DE DADOS\nCIFRA MONOALFABETICA - JOAO FABRICIO\n\n"); // Imprime mensagem com informações.
	printf("\nDIGITE 'C' SE QUISER CIRPTOGRAFAR OU 'D' SE QUISER DESCRIPTOGRAFAR O TEXTO: "); // Imprime a mensagem para que o usuário escolha sua opção.
	scanf("%c",&cript); // Escaneia o que foi digitado pelo usuário e armazena em cript.
	printf("\nESCREVA O TEXTO PARA ENCRIPTACAO / DECRIPTACAO (SEM ESPACO ENTRE AS PALAVRAS):\n\n "); // Imprime a mensagem para que o usuário escreva o texto.
	scanf("%s",&texto_claro); // Escaneia o que foi digitado pelo usuário e armazena em texto_claro.
	printf("\nDIGITE '1' PARA ESCREVER A PERMUTACAO DO ALFABETO QUE CORRESPONDE A CHAVE OU \nDIGITE '2' PARA UTILIZAR A CHAVE 'nopqrstuvwxyzabcdefghijklm': "); // Imprime a mensagem para que o usuário escolha sua opção.
	scanf("%i",&teste); // Escaneia o que foi digitado pelo usuário e armazena em teste.
	if(teste==2){ // Verifica se o usuário deseja utilizar a chave genérica.
		strcpy(chave,generica); // Coloca o chave generica "nopqrstuvwxyzabcdefghijklm" no vetor chave.
	}
	else{ // caso não queira usar a chave generica, poderá digitar o texto.
		printf("\nDIGITE A PERMUTACAO DO ALFABETO QUE CORRESPONDE A CHAVE:\n\n "); // Imprime a mensagem para que o usuário escreva a chave.
		scanf("%s",&chave); // Escaneia o que foi digitado pelo usuário e armazena em chave.
	}
	mono (chave, texto_claro, cript); // Chama a função mono, passando os parâmetros informados pelo usuário.
	system("pause"); // Aguarda até que uma tecla seja pressionada para fechar a tela após a finalização do programa.
	return 0;
}
