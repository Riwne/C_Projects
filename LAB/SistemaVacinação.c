//@Riwne

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    char email[50];
    long int cpf;
    char profissao[20];
    char endereco[50];
    char bairro[20];
    int numero;
}Funcionario;

typedef struct{
    char nome[50];
    int idade;
    char sexo[2];
    char vacina[12];
    int dia,mes,ano;
    int dia2,mes2,ano2;
}Paciente;

typedef struct{
    char tipo[15];
    int quantidade;
    int dia,mes,ano;
}repor;

typedef struct{
    char nome[50];
    int idade;
    int dia,mes,ano;
}Agendamento;

void Preencher_dados_funcionario(Funcionario *dados){
    printf("Nome:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->nome);

    printf("email:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->email);

    printf("cpf:\n ");
    scanf("%ld",&dados->cpf);

    printf("profissao:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->profissao);

    printf("Rua:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->endereco);

    printf("bairro:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->bairro);

    printf("numero:\n ");
    scanf("%d",&dados->numero);
    
}

void Preencher_dados_Paciente(Paciente *dados){
    printf("Nome:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->nome);

    printf("Idade:\n ");
    scanf("%d",&dados->idade);

    printf("Sexo:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->sexo);

    printf("Vacina\n[CoronaVac] - [AstraZenica] - [Pfizer] - [Janssen]\n");
    fflush(stdin);
    scanf("%[^\n]s",dados->vacina);

    printf("Dia da primeira vacina:\n ");
    scanf("%d",&dados->dia);

    printf("Mes da primeira vacina:\n");
    scanf("%d",&dados->mes);    

    printf("Digite o ano da primeira vacina:\n");
    scanf("%d",&dados->ano);    
    
    if(strcmp("CoronaVac",dados->vacina) == 0){
        dados->dia2 = dados->dia + 21;
        dados->mes2 = dados -> mes;
        dados->ano2 = dados->ano;
        if (dados->dia2 > 30){
            dados->dia2 -= 30;
            dados->mes2 = dados-> mes2 + 1;
            if (dados->mes2 > 12){
                dados->ano2 += 1;
                dados->mes2 -=  12;
            }
        }
        printf("Data da SEGUNDA DOSE: %02d/%02d/%d", dados->dia2,dados->mes2,dados->ano2);
    }
    if(strcmp("Pfizer",dados->vacina) == 0){
        dados->dia2 = dados->dia + 21;
        dados->mes2 = dados -> mes;
        dados->ano2 = dados->ano;
        if (dados->dia2 > 30){
            dados->dia2 -= 30;
            dados->mes2 = dados-> mes2 + 1;
            if (dados->mes2 > 12){
                dados->ano2 += 1;
                dados->mes2 -=  12;
            }
        }
        printf("Data da SEGUNDA DOSE: %02d/%02d/%d", dados->dia2,dados->mes2,dados->ano2);
    }

    if (strcmp(dados->vacina,"Janssen") == 0){
        dados->dia2 = dados->dia + 150;
        dados->mes2 = dados->mes;
        for(int i = 0 ;i < 5; i++)
            dados->mes2 += 1;
        dados->dia2 -= 150;
        if (dados->mes2 > 12){
            dados->ano2 += 1;
            dados->mes2 -= 12;
        }
        if (dados->mes2 < 13){
            dados ->ano2 = dados->ano;
        }
        printf("Data da SEGUNDA DOSE: %02d/%02d/%d", dados->dia2,dados->mes2,dados->ano2);
    }

    if (strcmp(dados->vacina,"AstraZenica") == 0){
        dados->dia2 = dados->dia + 26;
        dados->mes2 = dados->mes + 1;
        dados->ano2 = dados ->ano;
        if (dados->dia2 > 30){
            dados->mes2 += 1;
            dados->dia2 -= 30;
        }
        if (dados->mes2 > 12){
            dados->ano2 += 1;
            dados->mes2 -= 12;
        }
        printf("Data da SEGUNDA DOSE: %02d/%02d/%d", dados->dia2,dados->mes2,dados->ano2);
    }
    
    
}

void cadastrar_paciente(Paciente pac[],int *valor){
    Preencher_dados_Paciente(&pac[*valor]);
    *valor +=1;
}

void Exibir_Funcionarios(Funcionario funcio[], int tamanho){
    for(int i = 0;i < tamanho; i +=1 )
    {
         printf("     FUNCIONARIO[%d]\n"
               "*NOME: %s\n"
               "*EMAIL: %s\n"
               "*CPF: %ld\n"
               "*PROFISSAO: %s\n"
               "*RUA: %s\n"
               "*BAIRRO: %s\n"
               "*NUMERO: %d\n\n",(i + 1)
                                ,funcio[i].nome
                                ,funcio[i].email
                                ,funcio[i].cpf
                                ,funcio[i].profissao
                                ,funcio[i].endereco
                                ,funcio[i].bairro
                                ,funcio[i].numero);
    }
}

void Mostrar_arquivo(char nome_arquivo[30]){
    FILE *arquivo;
    arquivo = fopen(nome_arquivo,"r");
    char frase[400];
    if(arquivo == NULL){
        printf("Nao foi possivel ler o arquivo");
        exit(1);
    }
    while(fgets(frase,400,arquivo) != NULL){
        printf("%s",frase);
    }    
    fclose(arquivo);
}

void Mostrar_arquivo_paciente(){
    FILE *arquivo;
    arquivo = fopen("Paciente.txt","r");
    char frase[400];
    if(arquivo == NULL){
        printf("Nao foi possivel ler o arquivo");
        exit(1);
    }
    while(fgets(frase,400,arquivo) != NULL){
        printf("%s",frase);
    }    
    fclose(arquivo);
}

void Salvar_arquivo_funcionario(Funcionario funcio[], int quant, char nome_arq[30]){
    FILE *arq;
    arq = fopen(nome_arq,"a");
    if(arq == NULL){
        printf("Nao foi possivel ler o arquivo\n");
        exit(1);
    }
    for(int i = 0;i < quant;i+=1){
        fprintf(arq,
               "NOME: %s\n"
               "EMAIL: %s\n"
               "CPF: %ld\n"
               "PROFISSAO: %s\n"
               "RUA: %s\n"
               "BAIRRO: %s\n"
               "NUMERO: %d\n\n",funcio[i].nome
                               ,funcio[i].email
                               ,funcio[i].cpf
                               ,funcio[i].profissao
                               ,funcio[i].endereco
                               ,funcio[i].bairro
                               ,funcio[i].numero);


    }
    fclose(arq);

}

void Salvar_arquivo_Paciente(Paciente paci[], int quant){
    FILE *arq;
    arq = fopen("Paciente.txt","a");
    if(arq == NULL){
        printf("Nao foi possivel ler o arquivo\n");
        exit(1);
    }
    for(int i = 0;i < quant;i+=1){
        fprintf(arq,"NOME: %s\n"
               "IDADE: %d\n"
               "SEXO: %s\n"
               "VACINA: %s\n"
               "DATA DA PRIMEIRA DOSE: %02d/%02d/%d\n"
               "DATA DA SEGUNDA DOSE: %02d/%02d/%d\n\n",paci[i].nome
                                                   ,paci[i].idade
                                                   ,paci[i].sexo
                                                   ,paci[i].vacina
                                                   ,paci[i].dia
                                                   ,paci[i].mes
                                                   ,paci[i].ano
                                                   ,paci[i].dia2
                                                   ,paci[i].mes2
                                                   ,paci[i].ano2);

    }
    fclose(arq);

}

void Exibir_pacientes(Paciente paci[],int qnt_paciente){

    for(int i = 0;i < qnt_paciente; i+=1 ){
        printf("NOME: %s\n"
               "IDADE: %d\n"
               "SEXO: %s\n"
               "VACINA: %s\n"
               "DATA DA PRIMEIRA DOSE: %02d/%02d/%d\n"
               "DATA DA SEGUNDA DOSE: %02d/%02d/%d\n\n",paci[i].nome
                                                   ,paci[i].idade
                                                   ,paci[i].sexo
                                                   ,paci[i].vacina
                                                   ,paci[i].dia
                                                   ,paci[i].mes
                                                   ,paci[i].ano
                                                   ,paci[i].dia2
                                                   ,paci[i].mes2
                                                   ,paci[i].ano2);

    }
}

void reposicao(repor estoque){
    
    while(1){
        printf("\n[CoronaVac] -> 5 dias para que a entrega seja realizada\n"
               "[AstraZenica] -> 10 dias para que a entrega seja realizada\n"
               "[Pfizer] -> 4 dias para que a entrega seja realizada\n"
               "[Janssen] -> 15 dias para que a entrega seja realizada\n");
        printf("Digite o tipo:\n ");
        fflush(stdin);
        scanf("%[^\n]s",estoque.tipo);
        if(strcmp("CoronaVac",estoque.tipo) == 0){
            estoque.dia = 5;
            break;
        }
        if(strcmp("AstraZenica",estoque.tipo) == 0){
            estoque.dia = 10;
            break;
        }
        if(strcmp("Pfizer",estoque.tipo) == 0){
            estoque.dia = 4;
            break;
        }
        if(strcmp("Janssen",estoque.tipo) == 0){
           estoque.dia = 15;
           break;
        }
        else
        {
            printf("Tipo invalido");
        }
    }

    printf("Quantidade :\n ");
    scanf("%d",&estoque.quantidade);

    int dia, mes, ano;
    printf("data xx/xx/xx: ");
    scanf("%2d/%2d/%d",&dia,&mes,&ano);

    puts("\n");
    printf("Tipo: %s\n",estoque.tipo);
    printf("Quantidade: %d\n",estoque.quantidade);
    estoque.dia += dia;
    estoque.mes = mes;
    estoque.ano = ano;
    if(estoque.dia > 30){
        estoque.dia -= 30;
        estoque.mes +=1;
    }
    if (estoque.mes > 12){
       estoque.mes -= 12;
       estoque.ano +=1;
    }
    printf("Data da Entrega:  %2d/%2d/%d\n",estoque.dia,estoque.mes,estoque.ano);


}

void Agendar(Agendamento *dados){
    printf("Nome:\n ");
    fflush(stdin);
    scanf("%[^\n]s",dados->nome);

    printf("Idade do paciente:\n ");
    scanf("%d",&dados->idade);

    printf("Data da primeira dose (deve ser colocado dessa forma -> XX/XX/XXXX):\n ");
    scanf("%d/%d/%d",&dados->dia,&dados->mes,&dados->ano);
}

void cadastrar_o_agendamento(Agendamento agen[], int *valor){
    Agendar(&agen[*valor]);
    *valor +=1;
}

void Salvar_agendamento(Agendamento agen[], int valor){
    FILE *arquivo;
    arquivo = fopen("Agenda_Vacinas.txt","a");
    if(arquivo == NULL){
        printf("Nao foi possivel salvar o arquivo\n");
        exit(1);
    }
    for(int i = 0; i < valor;i+=1){
        fprintf(arquivo,"Nome: %s\n"
                    "Idade: %d\n"
                    "Data da primeira dose: %02d/%02d/%d\n\n",agen[i].nome
                                                     ,agen[i].idade
                                                     ,agen[i].dia
                                                     ,agen[i].mes
                                                     ,agen[i].ano);
    }
    fclose(arquivo);

}

void abertura_do_sistema(){
    puts("\t\t*********************************");
    puts("\t\t*                               *");
    puts("\t\t*       BEM VINDO AO SVAT       *");
    puts("\t\t*                               *");
    puts("\t\t*      SISTEMA DE VACINACAO     *");
    puts("\t\t*         ALAN TURING           *");
    puts("\t\t*                               *");
    puts("\t\t********************************");
    puts("\n");
}

int main(){

    abertura_do_sistema();

    char funcao = '0';
    while (funcao != '4'){
            printf("************************\n"
                   "*Entrar como:          *\n"
                   "*[1] Admin             *\n"
                   "*[2] Funcionario       *\n"
                   "*[3] Paciente          *\n"
                   "*[4] Encerrar programa *\n"
                   "************************\n");
            printf("OPCAO = ");
            fflush(stdin);
            scanf("%c",&funcao);
            puts("\n");
        if(funcao == '1'){
            char escolha;
            while(1){   
                printf("****************************************************************\n"
                    "*                   BEM VINDO (ADM)                            *\n"
                    "*MENU:                                                         *\n"
                    "*[1] Cadastrar funcionario/Mostrar/Salvar                      *\n"
                    "*[2] Ler o arquivo dos funcionarios salvos                     *\n"
                    "*[3] Repor estoque                                             *\n"
                    "*[4] Ver lista dos vacinados registrdos nos arquivos           *\n"
                    "*[5] Encerrar programa                                         *\n"
                    "****************************************************************\n");
                printf("O que deseja fazer hoje ? ");
                fflush(stdin);
                scanf("%c",&escolha);
                int qnt_funcionarios;
                Funcionario *Funcionarios;

                if(escolha == '1'){
                    printf("Deseja salvar os dados de quantos funcionarios: ");
                    scanf("%d",&qnt_funcionarios);
                    Funcionarios = malloc(qnt_funcionarios * sizeof(Funcionario));

                    for(int i = 0; i < qnt_funcionarios;i+=1){
                        printf("\nFUNCIONARIO[%d]:\n",i+1);
                        Preencher_dados_funcionario(&Funcionarios[i]);
                    }
                    while(1){
                        int opcao = 0;
                        printf("\n**********************************************\n"
                            "*[0] Sair                                    *\n"
                            "*[1] Mostrar funcionarios cadastrados        *\n"
                            "*[2] Salvar o cadastro em um arquivo de texto*\n"
                            "**********************************************\n");
                        printf("OPCAO = ");
                        scanf("%d",&opcao);

                        if(opcao == 1){
                            Exibir_Funcionarios(Funcionarios,qnt_funcionarios);
                        }
                        else if(opcao == 2){
                            char nome_arquivo[30];
                            printf("Digite o nome que deseja colocar como titulo do arquivo: ");
                            fflush(stdin);
                            scanf("%[^\n]s",nome_arquivo);
                            Salvar_arquivo_funcionario(Funcionarios,qnt_funcionarios, nome_arquivo);
                        }
                        else if(opcao == 0)
                            break;

                        else{
                            printf("Opcao invalida, digite novamente\n");
                        }
                    }
                        
                }
                if(escolha == '2'){
                    char nome_arquivo[30];
                    printf("Digite o nome do arquivo que deseja ler:");
                    fflush(stdin);
                    scanf("%[^\n]s",nome_arquivo);
                    Mostrar_arquivo(nome_arquivo);
                }
                if(escolha == '3'){
                    repor est;
                    reposicao(est);      
                }

                if (escolha == '4')
                    Mostrar_arquivo_paciente();
                
                
                if(escolha == '5')
                    break;
                

            }    
        }
        if (funcao == '2'){
            char Escolha_2;
            while(1){
                printf("****************************************************************\n"
                    "*                BEM VINDO (FUNCIONARIO)                       *\n"
                    "*MENU:                                                         *\n"
                    "*[1] Cadastrar Paciente/Mostrar/Salvar                         *\n"
                    "*[2] Mostar o arquivo dos vacinados salvos                     *\n"
                    "*[3] Mostrar o arquivo de agendamento das vacinas              *\n"
                    "*[4] Encerrar                                                  *\n"
                    "****************************************************************\n");

                int qnt_pacientes = 0;
                Paciente paciente[100];
                printf("O que deseja fazer hoje ? ");
                fflush(stdin);
                scanf("%c",&Escolha_2);

                if (Escolha_2 == '1'){
                    cadastrar_paciente(paciente,&qnt_pacientes);

                    while(1){
                        int opcao = 0;
                        printf("\n***********************************************\n"
                            "*[0] Sair                                        *\n"
                            "*[1] Mostrar paciente cadastrado                 *\n"
                            "*[2] Salvar o cadastro em um arquivo de texto    *\n"
                            "**************************************************\n");
                        printf("OPCAO = ");
                        scanf("%d",&opcao);
                        if(opcao == 1)
                            Exibir_pacientes(paciente,qnt_pacientes);
                        
                        else if(opcao == 2)
                            Salvar_arquivo_Paciente(paciente,qnt_pacientes);
                        
                        else if(opcao == 0)
                            break;
                        
                        else{
                            printf("Opcao invalida, digite novamente\n");
                        }
                    }

                }
                if (Escolha_2  == '2')
                    Mostrar_arquivo_paciente();
                
                if(Escolha_2 == '3')
                        Mostrar_arquivo("Agenda_Vacinas.txt");

                if(Escolha_2 == '4')
                    break;
                
            }    
        }
        if (funcao == '3'){
            char escolha_3 = '0';
            while(1){
                printf("\n****************************************************************\n"
                    "*                BEM VINDO (PACIENTE)                          *\n"
                    "*MENU:                                                         *\n"
                    "*[1] Agendar vacinacao                                         *\n"
                    "*[2] Motivos para se vacinar                                   *\n"
                    "*[3] Encerrar                                                  *\n"
                    "****************************************************************\n");
                printf("O que deseja fazer hoje ? ");
                fflush(stdin);
                scanf("%c",&escolha_3);
                Agendamento vacina_agenda[50];
                int quant = 0;
                
                if (escolha_3 == '1'){
                    cadastrar_o_agendamento(vacina_agenda,&quant);
                    Salvar_agendamento(vacina_agenda,quant);
                
                }
                if (escolha_3 == '2'){
                    Mostrar_arquivo("Seja_conciente.txt");
                }
                
                if(escolha_3 == '3')
                        break;
            }
            
        }
    }
}
