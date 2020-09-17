/*Create a DFA that accepts input starting with ab
    L={a,b}*/

#include<stdio.h>
#include<string.h>

enum STATES {q0,q1,q2,qd};
enum INPUT {a,b};
int curr_state = q0;
int table[3][2];
void def_transition(){
    table[q0][a] = q1;
    table[q0][b] = qd;
    table[q1][a] = qd;
    table[q1][b] = q2;
    table[q2][a] = q2;
    table[q2][b] = q2; 
}

void trans_table(){
    printf("Transiton table\n");
    printf("State\ta\tb\n");
    for(int i=0;i<3;i++){
        printf("\nq%d",i);
        for(int j = 0;j<2;j++){
            printf("\tq%d",table[i][j]);
        }
        printf("\n");
    }
}

int validate(char *input){
    printf("q%d",curr_state);
    for(int i =0;i<strlen(input);i++){
        if(curr_state != 3){
            if(input[i]=='a' || input[i]=='b'){
                if(input[i]=='a'){
                    curr_state = table[curr_state][a];
                    printf("->q%d",curr_state);
                    continue;
                }
                else if(input[i]=='b'){
                    curr_state = table[curr_state][b];
                    printf("->q%d",curr_state);
                    continue;
                }
            }
            else {
                printf("Invalid input");

                return 0;
            }
        }
        
    }
    return 1;
}

void main(){
    int flag;
    char inp[10];
    printf("DFA accepts input starting with ab \n");
    printf("Enter your input: ");
    scanf("%s", &inp);
    def_transition();
    trans_table();
    flag = validate(inp);
    if(flag == 1){
        if(curr_state != 2)printf("\nNot Accepted");
        else if(curr_state == 2)printf("\nAccepted");
    }
    else{
        printf("\nInput type does not match given dfa language");
    }
}