#include <stdio.h>

typedef struct{
	char nome[150];
	char fixo[15];
	char celular[15];
	char endereco[200];
	char anivesariosario[10];
} contato;

void leitura(contato *a){
	printf("Digite o nome: ");	gets((*a).nome);
	printf("Digite a data de nascimento: "); gets(a->aniversario);
	printf("Digite o Celular: ");gets(a->celular);
	printf("Digite o fixo: ");gets(a->fixo);
	printf("Digite o endereco: ");gets(a->endereco);
}


int main(){
    contato* agenda[100];
    int i,ocupados=0,opcao=1;
    for(i=0;i<100;i++) agenda[i]=NULL;
    while(opcao){
        printf("Digite sua opcao: ");
        scanf("%d",&opcao);getchar();
        if(opcao==1){
            agenda[ocupados]=(contato*) malloc(sizeof(contato));
            if(agenda[ocupados]){
                leitura(agenda[ocupados]);
                ocupados++;
            }
        } else if(opcao==2){
            //imprime os dados;
        }
    }
    

}