//Aluna: Riane Carla Gomes Alves 
//Matricula: 508771
//Turma 1

#include <stdio.h>
#include <string.h>


 int main(){													//Colocando todas as variáveis globais e seu tipo
	 int escolha;
	 char mensagem[100];
	 char v;
	 long int chave, c;
																
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");				
	printf("~~~~~~~~ CIFRA DE CÉSAR ~~~~~~~~\n");				//PEQUENO MENU
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");				//Iniciando o programa
	printf("O que precisa fazer com sua mensagem: \n"			//Perguntando ao usuário o que deseja fazer
			"1 - Criptografar\n"								//Apresentando as opções de escolha
			"2 - Descriptografar\n"
			"3 - Sair\n"
			"Escolha uma das opções: ");						//Ao fim ocorre um a entrada do teclado
	scanf("%d", &escolha);										//Nessa linha se lê a entrada da escolha
																
	switch (escolha){											//Usando o Switch como laço principal
		case 1:													//Primeira opção, caso a entrada tenha sido 1
		printf("Digite sua mensagem: ");						//O usuário digita sua mensagem
		__fpurge(stdin);										//__fpurge é utilizado para limpar o buffer da entrada do teclado
		scanf("%[^\n]s", mensagem);								//Nessa linha se lê a mensagem
		printf("Digite a chave: ");								//O usuário digita a chave
		scanf("%ld", &chave);									//Nessa linha se lê a chave
		
		while (c > 26)
		{ c -= 26;}

		for (c = 0; mensagem[c] != '\0'; c ++)					//LAÇO PARA CRIPTOGRAFAR
		{v = mensagem[c];										//Utilizando o for que inicia se chave = 0, termina quando todos os caracteres acabarem
		if (v >= 'a' && v <= 'z')								//Usa-se um if para verificar se os caracteres estão entre a e z
			{v = v + chave;										//Fazendo o calculo para um novo valor de v, que será o índice do caractere mais a chave
			if (v > 'z')										//Outro if caso esse novo valor seja maior que z
			{v = v - 'z' + 'a' - 1;}							//Iremos gerar um novo valor para v, que será o vetor menos o índice do caractere z mais a - 1
			mensagem[c] = v;}									//Para não aparecer simbolos caso utrapasse z, e esse será o novo valor de mensagem[c]
		else if (v >= 'A' && v <= 'Z')							//A condição do else if  é o mesmo só que para maiúsculas
			{v = v + chave;                                     //Fazendo o calculo para um novo valor de v, que será o índice do caractere mais a chave
			if (v > 'Z')										//Outro if caso esse novo valor seja maior que Z
			{v = v - 'Z' + 'A' - 1;}							//Iremos gerar um novo valor para v, que será o vetor menos o índice do caractere Z mais A - 1
			mensagem[c] = v;}}									//E esse será o novo valor de mensagem[c]
	
		printf("Mensagem cifrada: %s \n", mensagem);			//Printamos a mensagem cifrada
		printf("\n");											//Pula linha
		printf("\n");
		return main();											//Volta para o menu

		case 2:													//Segunda opção do Switch, caso a entrada tenha sido 2
		printf("Digite sua mensagem: ");						//O usuário digita sua mensagem
		__fpurge(stdin);										//__fpurge é utilizado para limpar o buffer da entrada do teclado
		scanf("%[^\n]s", mensagem);								//Nessa linha se lê a mensagem
		printf("Digite a chave: ");								//O usuário digita a chave
		scanf("%ld", &chave);									//Nessa linha se lê a chave

		for (c = 0; mensagem[c] != '\0'; c++)					//LAÇO PARA DESCRIPTOGRAFAR
		{v = mensagem[c];										//Utilizando o for que inicia se chave = 0, termina quando todos os caracteres acabarem
		if (v >= 'a' && v < 'z')								//Usa-se um if para verificar se os caracteres estão entre a e z
			{v = v - chave;										//Fazendo o calculo para um novo valor de v, que será o índice do caractere menos a chave
			if (v < 'a')										//Outro if caso esse novo valor seja maior que a
			{v = v + 'z' - 'a' + 1;}							//Iremos gerar um novo valor para v, que será o vetor mais o índice do caractere z menos a + 1
			mensagem[c] = v;}									//E esse será o novo valor de mensagem[c]
		else if (v >= 'A' && v <= 'Z')							//A condição do else if  é o mesmo só que para maiúsculas
			{v = v - chave;										//Fazendo o calculo para um novo valor de v, que será o índice do caractere menos a chave
			if (v < 'A')										//Outro if caso esse novo valor seja maior que A
			{v = v + 'Z' - 'A' + 1;}							//Iremos gerar um novo valor para v, que será o vetor mais o índice do caractere Z menos A + 1
			mensagem[c] = v;}}									//E esse será o novo valor de mensagem[c]
		
		printf("Mensagem descriptografada: %s \n", mensagem);	//Printamos a mensagem descriptograda
		printf("\n");											//Pula linha
		printf("\n");
		return main();											//Volta para o menu

		case 3:													//Terceira opção do Switch, caso a entrada tenha sido 3
		printf("Você saiu do programa.\n");						//Informa ao usuário que ele decidiu sair do programa 
		printf("\n");
		printf("\n");

		break;													//E quebra o programa saindo do mesmo

	}


 }
