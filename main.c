/*
 I, Fung Chung Ho, am submitting the assignment for
 an individual project.
 I declare that the assignment here submitted is original except for
 source material explicitly acknowledged, the piece of work, or a part
 of the piece of work has not been submitted for more than one purpose
 (i.e. to satisfy the requirements in two different courses) without
 declaration. I also acknowledge that I am aware of University policy
 and regulations on honesty in academic work, and of the disciplinary
 guidelines and procedures applicable to breaches of such policy and
 regulations, as contained in the University website
 http://www.cuhk.edu.hk/policy/academichonesty/.
 It is also understood that assignments without a properly signed
 declaration by the student concerned will not be graded by the
 teacher(s).
 */

#include <stdio.h>
#include <stdlib.h>
char maze[100][100]; //Declaring the fixed size 2d-array maze, used to represent the actual structure of the maze//
int mark[100][100]; //Declaring the fixed size 2d-array mark, used to mark down the paths visited with the structure of the maze recorded//

typedef enum {FALSE = 0, TRUE = 1}Boolean;

typedef struct{
    int x;
    int y;
    char dir;
}position; //Constructing data position, which contains the current coordinates of the position and the next direction to be proceeded//

typedef struct{
    int size;
    int top;
    position *stack;
}stack;

stack *createS(int size){ //setting a stack with elements of positions
    stack *s;
    s = (stack*)malloc(sizeof(stack));
    s->size = size;
    s->stack = (position*)malloc(size*sizeof(position));
    s->top = -1;
    return s;
}

Boolean IsFull(stack *s){
    if (s->top == s->size - 1)
        return TRUE;
    else return FALSE;
}

Boolean IsEmpty(stack *s){
    if (s->top == -1)
        return TRUE;
    else return FALSE;
}

void push(stack *s, position p){
    if (!IsFull(s)) {
        s->top++;
        s->stack[s->top] = p;
    }
}

position pop(stack *s){
    position i;
    if (!IsEmpty(s)) {
        i = (s->stack)[s->top];
        s->top--;
        return i; //pop out the position in the top//
    } else {
        printf("error\n");
        i.x = -1;
        i.y = -1;
        i.dir = 'Z';
        return i; //if the stack is already empty, returning with position and direction that are invalid//
    }
}

position top(stack *s){
    return s->stack[s->top];
}

position direction(position* p){
    p->dir = 'Y';
    if ((maze[p->x][(p->y) + 1] != '1')&&(mark[p->x][(p->y) + 1] != 1)) {
        p->dir = 'E';
    } else {
        if ((maze[(p->x) + 1][p->y] != '1')&&(mark[p->x + 1][(p->y)] != 1)) {
            p->dir = 'S';
        } else {
            if ((maze[p->x][(p->y) - 1] != '1')&&(mark[p->x][(p->y) - 1] != 1)) {
                p->dir = 'W';
            } else {
                if ((maze[(p->x) - 1][p->y] != '1')&&(mark[(p->x) - 1][p->y] != 1)) {
                    p->dir = 'N';
                }
            }
        }
    }
    return *p;
}//function that used to find whether there are avaliable univisited direction, in order of E -> S -> W -> N//

position new_coordinates(position* pos, position* new_pos){
    if (pos->dir == 'E') {
        new_pos->x = pos->x;
        new_pos->y = pos->y + 1;
    }
    if (pos->dir == 'S') {
        new_pos->x = pos->x + 1;
        new_pos->y = pos->y;
    }
    if (pos->dir == 'W') {
        new_pos->x = pos->x;
        new_pos->y = pos->y - 1;
    }
    if (pos->dir == 'N') {
        new_pos->x = pos->x - 1;
        new_pos->y = pos->y;
    }
    return *new_pos;
}//function used to return new coordinates for the new_pos according to the next direction given in pos, i.e. pos.dir//

char opps_direction(position *p){
    char opps_pos;
    if (p->dir == 'E') {opps_pos = 'W';}
    if (p->dir == 'S') {opps_pos = 'N';}
    if (p->dir == 'W') {opps_pos = 'E';}
    if (p->dir == 'N') {opps_pos = 'S';}
    return opps_pos;
}//function used to return the opposite direction of the current direction//



int main(){
    freopen("10.in", "r", stdin);
    int key_a_x = -1; int key_a_y = -1; int key_b_x = -1; int key_b_y = -1; int key_c_x = -1; int key_c_y = -1; int key_d_x = -1; int key_d_y = -1;
    int door_A_x = -1; int door_A_y = -1; int door_B_x = -1; int door_B_y = -1; int door_C_x = -1; int door_C_y = -1; int door_D_x = -1; int door_D_y = -1;
    int R;
    int C;
    scanf("%d %d", &R, &C);
    int entryX = -1;
    int entryY = -1;
    int exitX = -1;
    int exitY = -1;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            scanf("%s",&maze[i][j]); //inputting the maze with specificed size R*C using strings//
        }//recording the coordinates of the place of the doors and keys, and temporaryily setting doors as walls (making them as 1 in the maze), and paths (making them as 0 in the maze), respectively//
    }
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (maze[i][j] == '1') {
                mark[i][j] = 1;
            } else {
                mark[i][j] = 0;
            }
        }
    }//creating the 2d-array mark with walls set as 1, and paths set as 0 initially//
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (maze[i][j] == 'E') {
                entryX = i;
                entryY = j;
            }
        }
    }//extracting entries of the entrance//
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'X') {
                exitX = i;
                exitY = j;
            }
        }
    }//extracting entries of the exit//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'A') {
                door_A_x = i; door_A_y = j; maze[i][j] = '1';
            }
        }
    }
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'B') {
                door_B_x = i; door_B_y = j; maze[i][j] = '1';
            }
        }
    }//Extracting the entries of B and treating B as a wall//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'C') {
                door_C_x = i; door_C_y = j; maze[i][j] = '1';
            }
        }
    }//Extracting the entries of C and treating C as a wall//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'D') {
                door_D_x = i; door_D_y = j; maze[i][j] = '1';
            }
        }
    }//Extracting the entries of D and treating D as a wall//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'a') {
                key_a_x = i; key_a_y = j; maze[i][j] = '0';
            }
        }
    }//Extracting the entries of a and treating a as a path//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'b') {
                key_b_x = i; key_b_y = j; maze[i][j] = '0';
            }
        }
    }//Extracting the entries of b and treating b as a path//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'c') {
                key_c_x = i; key_c_y = j; maze[i][j] = '0';
            }
        }
    }//Extracting the entries of c and treating c as a path//
    for (int i = 0; i < R; i ++ ) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'd') {
                key_d_x = i; key_d_y = j; maze[i][j] = '0';
            }
        }
    }//Extracting the entries of d and treating d as a path//
    position intial_pos;
    intial_pos.x = entryX;
    intial_pos.y = entryY;
    direction(&intial_pos);
    if (intial_pos.dir == 'Y') {
        printf("NO ANSWER\n");
        return 0;
    }
    stack *path = createS(R*C);//creating the stack called path to store the paths visited//
    push(path, intial_pos);
    while (!IsEmpty(path)) {
        position pos = pop(path); //pop out the top element in stack, i.e. the current position with next direction included//
        mark[pos.x][pos.y] = 1;
        while ((maze[pos.x][pos.y + 1] != '1')||(maze[pos.x + 1][pos.y] != '1')||(maze[pos.x][pos.y - 1] != '1')||(maze[pos.x - 1][pos.y] != '1')) {
            position new_pos;
            new_coordinates(&pos, &new_pos);
            if ((new_pos.x == exitX)&&(new_pos.y == exitY)) { //Used to print out the all the steps used in the path//
                stack *ordered_path = createS(R*C);//created another stack to store the elements in the stack path with reversed order//
                push(path, pos);
                while (!IsEmpty(path)) {
                    position p = pop(path);
                    push(ordered_path, p);
                }
                while (!IsEmpty(ordered_path)) {
                    position p = pop(ordered_path);
                    printf("%c", p.dir); //printing out the actual paths//
                }
                printf("\n");
                return 0;
            } else {
                if ((maze[new_pos.x][new_pos.y] == '0')&&(mark[new_pos.x][new_pos.y] == 0)) {
                    mark[new_pos.x][new_pos.y] = 1;
                    push(path, pos);
                    pos.x = new_pos.x; pos.y = new_pos.y; //Update the current position, while keeping the direction until determined in the start of the while-loop//
                    if ((pos.x == key_a_x)&&(pos.y == key_a_y)) {
                        maze[door_A_x][door_A_y] = '0';
                    }
                    if ((pos.x == key_b_x)&&(pos.y == key_b_y)) {
                        maze[door_B_x][door_B_y] = '0';
                    }
                    if ((pos.x == key_c_x)&&(pos.y == key_c_y)) {
                        maze[door_C_x][door_C_y] = '0';
                    }
                    if ((pos.x == key_d_x)&&(pos.y == key_d_y)) {
                        maze[door_D_x][door_D_y] = '0';
                    } //"Opening" the door by changing maze[door_EG_x][door_EG_y] from '1' to '0', where EG = A,B,C,D//
                    direction(&pos);
                } else {
                    direction(&pos);
                    printf("pos.dir = %c\n", pos.dir);
                    if (pos.dir == 'Y') { //Meaning that if all the neighbouring avaliable paths were visited, we move backwards and search for avaliable paths that are not visited yet//
                        stack* temp_position = createS(200*200);
                        *temp_position = *path;
                        while ((pos.dir == 'Y')&&(!IsEmpty(temp_position))) {
                            position prev_pos = pop(temp_position);
                            pos.dir = opps_direction(&prev_pos);
                            push(path, pos);
                            new_coordinates(&pos, &new_pos);
                            direction(&new_pos);
                            pos.x = new_pos.x; pos.y = new_pos.y; pos.dir = new_pos.dir;
                        }
                    }
                }
            }
        }
    }
    printf("NO ANSWER\n");
}
