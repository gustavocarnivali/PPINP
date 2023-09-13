#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "math.h"

using namespace std;

FILE *arq;

int igual_s(char texto1[100],char texto2[100]){

    for(int i=2;i<100;i++){
        if(texto1[i]!=texto2[i]) return 0;
        if(texto1[i]=='\0' and texto2[i]=='\0') return 1;
    }
    return 1;
}


void verifica(char paux[500]){

    FILE *fha;

    if((fha = fopen("3.fa", "r")) == NULL) {
        printf("Arquivo nao encontrado2!\n");
    }

    char plei[500];
    char plei2[500];
    int it=0;
    char x;
    fscanf(fha, "%c", &x);
    while (!feof(fha)){
        char x;
        fscanf(fha, "%c", &x);
//            cout<<x;
        if(x!='\n'){
            plei[it]=x;
            plei[it+1]='\0';
            it++;
        }

        if(x=='\n'){
            for(int i=0;i<499;i++){
                plei2[i]=plei[i];
            }
            for(int i=0;i<499;i++){
                plei[i+1]=plei2[i];
            }
            plei[0]='>';
            for(int i=0;i<499;i++){
                if(plei[i]==' '){
                    plei[i]='\0';
                    break;
                }
            }
        //    cout<<paux<<" "<<plei2<<endl;
            if(igual_s(paux, plei2)==1){

                cout<<">"<<plei2<<endl;
                //fprintf (arq, ">%s \n", plei);

                while (!feof(fha)){
                    char Linha[1000];
                    char *result;
                    result = fgets(Linha, 1000, fha);  // o 'fgets' lê até 99 caracteres ou até o '\n'
                    if (result[0]!='>'){
                        printf("%s", Linha);
                        //fprintf (arq, "%s", Linha);
                    }
                    if (result[0]=='>'){
                        break;
                    }
                }
            }
            else{
                for(;;){
                    fscanf(fha, "%c", &x);
                    if(x=='*'){
                        fscanf(fha, "%c", &x);
  //                      cout<<endl;
                        break;
                    }
                }
            }
            it=0;
            char x;
            fscanf(fha, "%c", &x);
        }
    }
    fclose(fha);
}


int linha=0;

int main()
{

    FILE *fh2;


    if((fh2 = fopen("output.txt", "r")) == NULL) {
        printf("Arquivo nao encontrado!6\n");
    }

    char texto1[500];

    char x;
    int i=0;
    int linha=0;

    while (!feof(fh2)){

        fscanf(fh2, "%c", &x);

        if(x!='\n'){
            texto1[i]=x;
            texto1[i+1]='\0';
        }

        i++;

        if(x=='\n'){

//            cout<<texto1<<endl;

            linha++;
            //cout<<linha<<endl;

            verifica(texto1);

            i=0;
         }


    }


    fclose(fh2);

    return 0;

}


