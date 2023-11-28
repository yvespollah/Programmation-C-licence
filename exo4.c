#include<stdio.h>
#include<string.h>

//1)

void recuperer_ensemble(int n , char tab[n] ){
    int i;

     printf("Entrer de l'ensemble\n");
    for(i=0;i<n;i++){
        scanf("%s",&tab[i]);
    }
}

void Union(int n,int m, char A[n],char B[m],char E[n+m]){

int i,j=0;
int k=n+m;

  for(i=0;i<n;i++){
       E[i] = A[i];
    }

    for(i=n;i<k;i++){
       E[i] = B[j];
       j++;
    }

}


// intersection

void intersection(int n,int m, char A[n],char B[m],char F[n]){

    int i,j,k=0;

       for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(A[i] == B[j]){
                F[k] = A[i];
                k++;
            }
        }
    }

    

}




void Trie(int a, char tab[a]){

    int i,j;
    char temp;

    for(i=0;i<a;i++){
        for(j=i+1;j<=a;j++){
            if(tab[i]>tab[j]){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }

}

void retirer_doublons(int a,char tab1[a],char tab2[a]){
    int i,j=1;
    tab2[0] = tab1[0];

    for(i=1;i<a;i++){
        if(tab1[i]!=tab1[i-1]){
            tab2[j] = tab1[i];
            j++;
        }
    }
}


// 2)

void Afficher(int n , char tab[n]){
    int i;

   
    printf("{");
       for(i=0;i<n;i++){
            printf("%c,",tab[i]);
    }
     printf("}");
     printf("\n");

}

int main(){
    int n,m;

    // ensemble A
    printf("Entrer la taille de l'ensemble A\n");
    scanf("%d",&n);
    char A[n];
    recuperer_ensemble(n,A);
    printf("Ensemble A: \t");
    Afficher(n,A);

    // ensemble B
    printf("Entrer la taille de l'ensemble B\n");
    scanf("%d",&m);
    char B[m];
    recuperer_ensemble(m,B);
    printf("Ensemble B: \t");
    Afficher(m,B);

    char temp[n+m];

    char E[n+m];
    
    // union

    Union(n,m,A,B,temp);
    Trie(n+m,temp);
    retirer_doublons(n+m,temp,E);
    printf("Union E: \t");
    Afficher(n+m,E);

        // intersection
     char temp1[n];
     char F[n];
    intersection(n,m,A,B,temp);
    Trie(n,temp);
    retirer_doublons(n,temp,F);
    printf("Intersection F: \t");
    Afficher(n,F);
    
}