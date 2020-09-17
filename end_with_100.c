/*Create a DFA that accepts input ending with 100
    L={0,1}*/

#include<stdio.h>
#include<string.h>

enum STATES {q0,q1,q2,q3};
int curr_state = q0;
int table[4][2];
void def_transition(){
    table[q0][0] = q0;
    table[q0][1] = q1;
    table[q1][0] = q2;
    table[q1][1] = q1;
    table[q2][0] = q3;
    table[q2][1] = q1; 
    table[q3][0] = q0;
    table[q3][1] = q1;
}

void trans_table(){
    printf("Transiton table\n");
    printf("State\t0\t1\n");
    for(int i=0;i<4;i++){
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
        if(input[i]=='0' || input[i]=='1'){
            if(input[i]=='0'){
                curr_state = table[curr_state][0];
                printf("->q%d",curr_state);
                continue;
            }
            else if(input[i]=='1'){
                curr_state = table[curr_state][1];
                printf("->q%d",curr_state);
                continue;
            }
        }
        else {
            printf("Invalid input");

            return 0;
        }
        
    }
    return 1;
}

void main(){
    int flag;
    char inp[10];
    printf("DFA accepts input ending with \n");
    printf("Enter your input: ");
    scanf("%s", &inp);
    def_transition();
    trans_table();
    flag = validate(inp);
    if(flag == 1){
        if(curr_state != 3)printf("\nNot Accepted");
        else if(curr_state == 3)printf("\nAccepted");
    }
    else{
        printf("\nInput type does not match given dfa language");
    }
}