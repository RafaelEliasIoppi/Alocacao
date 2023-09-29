#include <stdio.h>
#include<stdlib.h>



void consultapos(int vetor[13], int ocupados, int pos){
    if(pos >= ocupados){
        printf("\nEssa posicao nao existe na lista atual !!!!");
    }else{
        printf("\nO valor na posicao [%d] = %d", pos, vetor[pos]);
    }
    
}
int Adiciona(int vetor[13], int ocupados){
    int  posicao, valor, i;
    printf("\nDigite em posicao em que desejar inserir: ");
    scanf("%d", &posicao);
    printf("\nDigite o valor: ");
    scanf("%d", &valor);
    
        if(ocupados == 0){
            	printf(" \nO Primeiro valor sera inserido na posicao [0]\n");
            	vetor[0] = valor;
            	
        
      
        }else if(posicao > ocupados){
                printf("\nO valor sera inserido na posicao [%d]\n", ocupados);
        		vetor[ocupados] = valor;
        		
        	
        		
		}
		else{
		        printf("\nO valor sera inserido na posicao [%d]\n",posicao);
                
                for(i = ocupados ; i > posicao; i--){ //os valores vÃƒÂ£o para a proxima posicao do vetor
                    vetor[i] = vetor[i-1];
                
                }
                vetor[posicao] = valor; 
             }
        return 1; //esse valor e adicionado a variavel ocupados, cada vez que se adiciona um elemento no vetor
        }
      

int Remove(int vetor[13], int ocupados){
    int i, posicao;
    
    printf("\nDigite em posicao que desejar remover: ");
    scanf("%d", &posicao);
     	if(posicao >= ocupados){
        		printf("\nEssa posicao nao existe na lista atual\n");
        		
        
        }else {
            for(i = posicao; i < ocupados; i++){
                vetor[i] = vetor[i+1];
                
            }
            return -1; // esse valor eh removido da varivel ocupados, cada vez que se remove um elemento do vetor
        }
        
    
}



void Mostra(int vetor[13], int ocupados){
    int i;
    system("clear");
    printf("\n");
    
    
    for(i = 0; i < ocupados; i++){
        
        printf("\nPosicao[%d]: %d",i, vetor[i]);
    }
    printf("\n");
}



int main (){
    
        int vetor[13];
        int ocupados = 0; //variavel que controla o tamanho da fila
        int i, opcao, pos;
        int cont = 1; //contador para travar o menu quando o vetor estiver cheio
        while(cont){ // cont incia com 1 e quando for 0 ele sai do loop
        printf("\n------------------------------------------------------");
    	printf("\nDigite - 1............. Para adicionar um elemento.\nDigite - 2............. Para excluir um elemento.\nDigite - 3............. Para mostrar a lista.\nDigite - 4............. Para consultar posicao na lista. \nDigite - 5............. Para limpar a tela\nDigite - 6............. Para encerrar");
    	printf("\n-----------------------------------------------------\n");
    	scanf("\n%d", &opcao);
	    switch(opcao){ 
	           case 1:
	           		if(ocupados >= 14){
	           			printf("\nLISTA CHEIA, NOVOS ELEMENTOS NAO PODEM SER INSERIDOS\n");
	           			
	                }else{
					   	ocupados += Adiciona(vetor,ocupados); // variavel que informa o tamanho do vetor atual
			           	
			    	}
			        break;
			        
		    	case 2:
		    	     if(ocupados > 0){
		    	         ocupados += Remove(vetor,ocupados); // variavel que informa o tamanho do vetor atual 
		    	     }
		    	     else{
		    	          printf("\nLISTA VAZIA, NAO E POSSIVEL REMOVER ELEMENTOS\n");
		    	     }
		    	     break;
		    	     
		    	case 3:
		    		
		    		if(ocupados == 0){
		    		    printf("\nLista esta vazia!!!!!!");
		    		} else{
		    		    	Mostra(vetor,ocupados);
		    		    }
		    		
		    		break;
		    		
		    	case 4:
		    		  printf("\nDigite a posicao que seja consultar:");
		    		  scanf("%d",&pos);
		    		  consultapos(vetor, ocupados, pos);
		    	      break;
		    	case 5:
		    	    system("clear");
		    	    break;
		    	case 6:
		    	     printf("\nPROGRAMA ENCERRADO\n");
		    	     printf("\n######## Desenvolvido por: Rafael Elias Ioppi  ###########\n");
		    	      cont = 0;
		    	      break;
		    	default:
		    	
		    		printf("\nOPCAO INVALIDA\n");
		    		
		    	   
    	}
    	
	}
	 
}




