#include <stdio.h>
#include <intrin.h>
#include <string.h>
static int i=0;
static int busC=0;

typedef struct Passenger
{
    int id;
    int date;
    char time[6];
    char from_dis[15];
    char to_dis[15];

    struct Passenger* nextp;
}Passenger;

typedef struct Bus
{
    int busId;
    int date;
    char bus_time[6];
    char bus_from[15];
    char bus_to[15];
    double price;
    int capacity;
    Passenger *nextPass;

}Bus;

void PrintList( Passenger * );
struct Passenger* lodepassengerData(Passenger*);
void addLast(struct Passenger *, int ,int,char[],char[] ,char[] );
int IsEmpty( Passenger * );
int IsLast( Passenger * ,  Passenger * );
void lodeBusData(struct Bus[] );
void DeleteList(struct Passenger* );
struct Passenger* MakeEmpty( Passenger * );
void checkPassengers(Passenger *,Bus[] );
int SizeOf(struct Passenger* );
void DeletePass(struct Passenger* pass,struct Bus []);
struct Passenger* FindPrevios(int ,struct Passenger* );
int comparCloser(char [],char []);
void Delete(int ,struct Passenger* );
struct Passenger* copyList(struct Passenger* );
int comp(char [],char []);
void busInfo(struct Bus []);
void PrintSpesList(struct Passenger* );
void addNewPass(struct Passenger*,struct Bus []);
void printUnmached(struct Bus []);
void DeleteBusNumber(struct Bus []);
void chkk(struct Bus[],int ,int ,char [],char [],char [] );
int counter(char []);
int isfirst(Bus [],char [],char [],int);
int isfirstB(Bus[],char[],char [],int );
int main() {

    struct Passenger* pass;
    busC=counter("busses");//find how many bus we have



    int choice;
struct Bus bus[busC];
    do {
        printf("1. Load the bus information file\n"
               "2. Load the passenger information file\n"
               "3. Assign passengers and print assignment information of all busses\n"
              "4. Print a specific bus information along with its passengers information (names and IDs)\n"
              "5. Print unmatched passengers\n"
              "6. Add new passenger\n"
              "7. Delete passenger\n"
              "8. Delete bus number\n"
              "9. Exit\n"
               "Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lodeBusData(bus);

               break;
            case 2:
                pass= MakeEmpty(NULL);
                lodepassengerData(pass);
                PrintList(pass);
                break;
            case 3:
                checkPassengers(pass,bus);
                break;
            case 4:
                busInfo(bus);
                break;
            case 5:
                printUnmached(bus);
                break;
            case 6:
                addNewPass(pass,bus);
                break;
            case 7:
                DeletePass(pass,bus);
                break;
            case 8:
                DeleteBusNumber(bus);
                break;
            case 9:
                printf("thank you !\n");
                return 0;
                break;
            default:
                printf("Please try again");
                break;
        }

    } while (choice != 9);







    return 0;
}
void lodeBusData(struct Bus bus[busC]){//read buss file and lode it to Array.

    FILE * fin;
    fin = fopen("busses", "r");
    if (fin == NULL)
    {
        printf( "Error! File cannot be read");
        exit (1);
    }
char line[100];


char * sr;
    char* ret;
    printf(" ID \t    DATE \t  TIME         FROM \t    TO \t\t PRICE    CAPACITY\n");
    while (fgets(line, 50, fin))
    {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;
      //  printf("%s\n", line);
        sr = strtok(line, "#");
        bus[i].busId= atoi(sr);


        sr = strtok(NULL, "#");
        bus[i].date= atoi(sr);

        sr = strtok(NULL, "#");
        strcpy(bus[i].bus_time, sr);
        if(bus[i].bus_time[0]==' '){
            for (int e = 0; e < strlen(bus[i].bus_time); e++) {
                bus[i].bus_time[e]=bus[i].bus_time[e+1];

            }

        }
        sr = strtok(NULL, "#");
        strcpy(bus[i].bus_from, sr);
if(bus[i].bus_from[0]==' '){
    for (int e = 0; e < strlen(bus[i].bus_from); e++) {
        bus[i].bus_from[e]=bus[i].bus_from[e+1];

    }

}
        sr = strtok(NULL, "#");
        strcpy(bus[i].bus_to, sr);
        if(bus[i].bus_to[0]==' '){
            for (int e = 0; e < strlen(bus[i].bus_to); e++) {
                bus[i].bus_to[e] = bus[i].bus_to[e + 1];
            }
            }
        sr = strtok(NULL, "#");
        bus[i].price = strtod(sr, &ret);

        sr = strtok(NULL, "#");
        bus[i].capacity = strtod(sr, &ret);
        printf("*------------------------------------------------------------------------------------*\n");
        printf(" %d   |   %d   |   %s   |   %-10s   |   %-10s   |   %0.1lf   |  % -10d  \n",bus[i].busId,bus[i].date,bus[i].bus_time,bus[i].bus_from,bus[i].bus_to,bus[i].price,bus[i].capacity);
        i++;
        bus[i].nextPass=NULL;
    }



    fclose(fin);

}

/////////////////////////////////////////2222222222222222222222222222//////////////////////////////////////////////
struct Passenger* lodepassengerData(Passenger* pass) {//read Passenger file and lode it to Linked list.
    int f = 0;
    FILE *fin2;
    fin2 = fopen("Passengers", "r");
    if (fin2 == NULL) {
        printf("Error! File cannot be read");
        exit(1);
    }
    char line[2000];
    char *sr;

    int id, dt;
    char tim[6];
    char from[15];
    char to[15];



    while (fgets(line, 2000, fin2))
    {
        // Remove trailing newline
        line[strcspn(line, "\n")] = 0;

        sr = strtok(line, "#");
        id= atoi(sr);


        sr = strtok(NULL, "#");//split the line based on #
        dt= atoi(sr);//convert from string to int


    sr = strtok(NULL, "#");//split the line based on #
    strcpy(tim, sr);//copy it to other string
        if(tim[0]==' '){
            for (int e = 0; e < strlen(tim); e++) {
                tim[e] = tim[e + 1];
            }
        }
    sr = strtok(NULL, "#");//split the line based on #
    strcpy(from, sr);//copy it to other string
        if(from[0]==' '){
            for (int e = 0; e < strlen(from); e++) {
               from[e]=from[e+1];

            }}
    sr = strtok(NULL, "#");
    strcpy(to, sr);
        if(to[0]==' '){
            for (int e = 0; e < strlen(to); e++) {
                to[e] = to[e + 1];
            }
            }
    addLast(pass, id, dt, tim, from, to);

}



        fclose(fin2);



    return pass;
}



////////////////////////////////////////////////////////////addLast////////////////////////
void addLast(struct Passenger *head, int id,int date,char time[6], char from[15],char to[15])//add nodes to the end of linked list
{
    //create a new node
    struct Passenger* newNode = malloc(sizeof(struct Passenger));//creat a node and copy the data in it
    newNode->id = id;
    newNode->date=date;
    strncpy( newNode->time,time,6);
    strcpy( newNode->from_dis,from);
    strcpy(newNode->to_dis,to);
    newNode->nextp = NULL;

    //if head is NULL, it is an empty list
    if(head == NULL){
        head = newNode;

    }
        //Otherwise, find the last node and add the newNode

    else
    {
        struct Passenger *lastNode = head;

        //last node's next address will be NULL.
        while(lastNode->nextp != NULL)
        {
            lastNode = lastNode->nextp;

        }

        //add the newNode at the end of the linked list
        lastNode->nextp = newNode;

    }


}
////////////////////////////////////////////////
struct Passenger* MakeEmpty( struct Passenger * L){//make empty linked list
    if(L!=NULL)


        DeleteList(L);
    L= ( Passenger*)malloc(sizeof (Passenger));
    if(L==NULL)
        printf("Out of memory");
    L->nextp=  NULL;
    return L;


}
void DeleteList(struct Passenger* L){//delete list
    struct Passenger* temp;
    struct Passenger* P;
    P = L->nextp;
    L->nextp = NULL;
    while(P != NULL){
        temp = P->nextp;
        free(P);
        P=temp;
    }
}




void checkPassengers(Passenger *pass,Bus bus[busC]){//check each passenger and lode it to the closed buss

    struct Passenger* temp0 = copyList(pass);//copy the list to delete added passenger
    struct Passenger* temp,*x;
    int k;

int t2;
    if(pass==NULL) {
        printf("Empty lists \n");
        exit(1);
    }
    for (int z = 0; z <= i; z++) {//creat an empty node for each bus to insert the passengers
        bus[z].nextPass= MakeEmpty(NULL);

    }

    for (int j = 0; j <=i ; j++) {//for buss length
        k= SizeOf(temp0);
        temp=temp0->nextp;
       for (int s = 0; s <k; s++) {//for passenger linked list

                 if(temp->date==bus[j].date &&strcmp(bus[j].bus_from,temp->from_dis) ==0&&strcmp(bus[j].bus_to,temp->to_dis) ==0&&bus[j].capacity>0
                    && isfirstB(bus,bus->bus_time,temp->time,j)>0){//finding the closer bus for each passenger

                    t2=isfirstB(bus,bus->bus_time,temp->time,j);//return the index of the closer bus
                    if( comp(bus[t2].bus_time,temp->time) ==1&&bus[t2].capacity>0) {//check the closer bus again
                        addLast(bus[t2].nextPass, temp->id, temp->date, temp->time, temp->from_dis, temp->to_dis);
                        bus[t2].capacity--;
                        Delete(temp->id, temp0);
                        temp = temp->nextp;

                    }else{
                        if( comp(bus[j].bus_time,temp->time) ==1&&bus[j].capacity>0) {//if the current bus closer
                        addLast(bus[j].nextPass, temp->id, temp->date, temp->time, temp->from_dis, temp->to_dis);
                        bus[j].capacity--;
                        Delete(temp->id, temp0);
                        temp = temp->nextp;

                    }
                        }
                 }//if we didnt find other bus
                 else if(temp->date==bus[j].date &&  comp(bus[j].bus_time,temp->time) ==1&&
                         strcmp(bus[j].bus_from,temp->from_dis) ==0&&strcmp(bus[j].bus_to,temp->to_dis) ==0&&bus[j].capacity>0
                         && isfirstB(bus,bus->bus_time,temp->time,j)==0) {

                     if (comp(bus[t2].bus_time, temp->time) == 1 && bus[t2].capacity > 0) {
                         addLast(bus[j].nextPass, temp->id, temp->date, temp->time, temp->from_dis, temp->to_dis);
                         bus[j].capacity--;
                         Delete(temp->id, temp0);
                         temp = temp->nextp;

                     }
                 }

                 else{
                     temp=temp->nextp;
                 }
        }
    }
    printf("------------------------- ** matched passengers ** ------------------------------\n\n");
    for (int m = 0; m < i; m++) {
        int ip=0;
        //printf("*------------------------------------------------------------------------------------*\n");
        printf("bus ID : %d  \t\n",bus[m].busId);
        PrintList(bus[m].nextPass);
        printf("\n");
    }

    if(SizeOf(temp0)!=0){
        printf("------------------------- ** Unmatched  passengers **  ------------------------------\n");
        bus[i].nextPass =temp0;
        PrintList(temp0);

    }


}

void busInfo(struct Bus bus[busC]){//print buss information
int index;

    printf("Please Enter Bus ID\n");
    scanf("%d",&index);
    int f =0;
    for (int d = 0; d <i ; d++) {
        if(index==bus[d].busId){
            f=1;
            printf("-------------------------------------- *Bus %d INFO *-----------------------------------------\n",index);
            printf("Bus ID:%d\tDate: %d\tTime: %s \t From: %s\tTo:%s\t Price:%0.1lf\tCapacity:%d\n",bus[d].busId,bus[d].date,bus[d].bus_time,bus[d].bus_from,bus[d].bus_to,bus[d].price,bus[d].capacity);
            PrintSpesList(bus[d].nextPass);
            printf("\n");
        }

    }
    if(f==0)
    printf("Bus ID Not exist! \n");
}

void printUnmached(struct Bus bus[busC]){//print unmatched passengers
    printf("-------------------------------- ** Unmatched  passengers **  --------------------------------\n");
    PrintList(bus[i].nextPass);
    }


void DeletePass(struct Passenger* pass,struct Bus bus[busC]){//delete a specific passenger from linked list and busses
    int id;

    struct Passenger*ps;
    printf("please Enter Passenger ID that U want to delete  : ");
    scanf("%d",&id);
    printf("\n");
    Delete(id,pass);//delete the passenger from the linked list

    for (int w = 0; w <=i; w++) {
        ps=bus[w].nextPass->nextp;//find the passenger in the bus then delete it
        for (int a = 0; a < SizeOf(bus[w].nextPass); a++) {

            if (ps->id == id){
                Delete(id, bus[w].nextPass);
                bus[w].capacity++;

            }
            ps=ps->nextp;
        }
    }

    printf("----------------------- ** matched passengers ** -----------------------\n");
    for (int m = 0; m < i; m++) {
        int ip=0;
        printf("bus ID : %d  \t\n",bus[m].busId);
        PrintList(bus[m].nextPass);
        printf("\n");
    }

    printUnmached(bus);




}



void addNewPass(struct Passenger* L,struct Bus bus[busC]) { //add new passenger to the linked list and check it to the best buss
    int id;
    int date;
    char time[6];
    char from[25];
    char to[25];
    char h;
char c[50];
int f=0;

    printf("Please Enter Passenger ID : \n");
    scanf("%d",&id);
    printf(" Please Enter Date .exp(15042022) :\n");
    scanf("%c",&h);
    gets(c);
    date= atoi(c);

    printf("Please Enter time .exp(15:30) : \n");
    gets(c);
    strcpy(time,c);
    printf("Please Enter Leaving town .exp(Birzeit) : \n");
    gets(c);
    strcpy(from,c);
    printf("Please destination .exp(Ramallah) : \n");
    gets(c);
    strcpy(to,c);

    addLast(L, id, date, time, from, to);
    int j=0;
    for (j = 0; j < i; j++) {
//compere pasenger data and add it to the best bus
        if (date == bus[j].date && comp(bus[j].bus_time, time) == 1 &&
            strcmp(bus[j].bus_from, from) == 0 && strcmp(bus[j].bus_to, to) == 0 && bus[j].capacity > 0&&isfirst(bus, bus[j].bus_time, time, j) == 1) {
                addLast(bus[j].nextPass, id, date, time, from, to);
                bus[j].capacity--;
                f = 1;
            printf("-------------------------------------- *Bus %d INFO *-----------------------------------------\n",bus[j].busId);
            printf("Bus ID:%d\tDate: %d\tTime: %s \t From: %s\tTo:%s\t Price:%0.1lf\tCapacity:%d\n",bus[j].busId,bus[j].date,bus[j].bus_time,bus[j].bus_from,bus[j].bus_to,bus[j].price,bus[j].capacity);
            PrintSpesList(bus[j].nextPass);
            printf("\n");


        }


        }


if(f==0){
    addLast(bus[i].nextPass, id, date, time, from, to);

}



}

void PrintList(struct Passenger* L) {

    struct Passenger *P = L;
    if (IsEmpty(L)) {
       // printf("*------------------------------------------------------------------------------------*\n");
    printf("Empty list\n");
    printf("*------------------------------------------------------------------------------------*");
}
    else

        do{
            P=P->nextp;
            printf("\n");
          //  printf("*------------------------------------------------------------------------------------*\n");
            printf(" %d   |   %d   |   %-10s   |   %-10s   |   %-10s\n", P->id,P->date,P->time,P->from_dis,P->to_dis);
            printf("*------------------------------------------------------------------------------------*");

        }while( !IsLast(P, L) );
    printf("\n");
}
///////////////////////////////////////////////////////////

void PrintSpesList(struct Passenger* L){

    struct Passenger* P = L;
    if( IsEmpty(L))
        printf("Empty list\n");
    else
        do{
            P=P->nextp;
            printf("\n");
            printf("Passenger ID : %d\t TIME :%s ", P->id,P->time);

        }while( !IsLast(P, L) );
    printf("\n");
}


int IsEmpty(struct Passenger* L){
    return L->nextp == NULL;
}

//////////////////////////////////////////////////////
int IsLast(struct Passenger* P, struct Passenger* L){
    if(P->nextp == NULL) {

        return 1;
    }
    else
        return 0;
}

int SizeOf(struct Passenger* L){
    struct Passenger* p= L->nextp;
    int count =0;
    while(p!=NULL){
        count++;
        p=p->nextp;

    }
    return count;
}
//////////////////////////////////////////////////

//////////////////////////////////////////find(date for matching with buss)////////////////////////

struct  Passenger* FindD(int x,struct Passenger* L){
    struct Passenger* p;

    p=L->nextp;

    while (p!=NULL&&p->date!=x){
        p=p->nextp;

    }

    return p;
}
//////////////////////////////////////////////////????????
struct Passenger* FindPrevios(int x,struct Passenger* L){
    struct Passenger* p;
    p=L;
    while (p->nextp!=NULL&&p->nextp->id!=x){
        p=p->nextp;
    }


    return p;
}

////////////////////////////////////////////////////////////
void Delete(int x,struct Passenger* L) {
    struct Passenger *p;
    struct Passenger *temp;

    p = FindPrevios(x, L);
    if (!IsLast(p, L)) {
        temp = p->nextp;
        p->nextp = temp->nextp;
        free(temp);//remove the struct from memory


    }
}
struct Passenger* copyList(struct Passenger* head)//copy linked list to save the orginal one
{
    if (head == NULL) {
        return NULL;
    }
    else {

        // Allocate the memory for new Node
        // in the heap and set its data
        struct Passenger* newNode
                = (struct Passenger*)malloc(
                        sizeof(struct Passenger));

        newNode->id = head->id;
        newNode->date = head->date;
        strncpy(  newNode->time,head->time,6);
        strcpy(  newNode->from_dis,head->from_dis);
        strcpy( newNode->to_dis,head->to_dis);

        //ecursively set the next pointer of
        // the new Node by recurring for the
        // remaining nodes
        newNode->nextp = copyList(head->nextp);

        return newNode;
    }
}
int comp(char bus[6],char pas[6]){// comparing time between busses and passengers
    char b[6];
    char p[6];
    char* pt;
    char* pt1;
    strcpy( b,bus);
    pt= strtok(b,":");
    int bus_h= atoi(pt);
    pt=strtok(NULL,"");
    int bus_min=atoi(pt);

    strcpy( p,pas);

    pt1= strtok(p,":");
    int pass_h= atoi(pt1);

    pt1= strtok(NULL,"");
    int pass_min=atoi(pt1);

if((pass_min<=bus_min&&pass_h<=bus_h)||(pass_min>=bus_min&&pass_h<=bus_h)){
    return 1;
}
    return 0;
}

void DeleteBusNumber(struct Bus bus[busC]){ //delete a specific buss and find a buss for the passengers
    struct Passenger *cc;
    int index;
    int id;
    int f=0;
    int pid;
    int date;
    char time[6];
    char from[25];
    char to[25];
    printf("Please Enter Bus ID to Delete :\n");
    scanf("%d",&id);
    for (int z = 0; z < i; z++) {
        if (bus[z].busId == id) {
            index = z;
            cc = bus[z].nextPass->nextp;
        }
    }


    for(int m=index; m<=i;m++)
    {
        bus[m] = bus[m+1];
    }

    /* Decrement array size by 1 */
    i--;
    for (int r = 0; r < i; r++) {
        printf(" %d   |   %d   |   %s   |   %-10s   |   %-10s   |   %0.1lf   |  % -10d  \n",bus[r].busId,bus[r].date,bus[r].bus_time,bus[r].bus_from,bus[r].bus_to,bus[r].price,bus[r].capacity);

    }
    while (cc!=NULL) {
        pid =cc->id;
        date = cc->date;
        strncpy(time, cc->time, 6);
        strcpy(from,cc->from_dis);
        strcpy(to,cc->to_dis);
        chkk(bus, pid, date, time, from, to);
        cc=cc->nextp;
    }


}
void chkk(struct Bus bus[busC],int id,int date,char time[6],char from[15],char to[15] ){//lode the passengers that we deleted there buss
   int f=0;
    for (int j = 0; j < i; j++) {

        if (date == bus[j].date && comp(bus[j].bus_time, time) == 1 &&
            strcmp(bus[j].bus_from, from) == 0 && strcmp(bus[j].bus_to, to) == 0 && bus[j].capacity > 0) {

            addLast(bus[j].nextPass, id, date, time, from, to);
            bus[j].capacity--;
            f=1;
            printf("-------------------------------------- *Bus %d INFO *-----------------------------------------\n",bus[j].busId);
            printf("Bus ID:%d\tDate: %d\tTime: %s \t From: %s\tTo:%s\t Price:%0.1lf\tCapacity:%d\n",bus[j].busId,bus[j].date,bus[j].bus_time,bus[j].bus_from,bus[j].bus_to,bus[j].price,bus[j].capacity);
            PrintSpesList(bus[j].nextPass);
            printf("\n");
            break;
        }

    }
    if(f==0){
        addLast(bus[i].nextPass, id, date, time, from, to);

    }

}
int counter(char filename[50])//count file lines
{

    FILE *fin;
    int count = 0;
    char m;
    fin = fopen(filename, "r");
    if (fin == NULL)
    {
        printf("Could not open file %s", filename);
        return 0;
    }
    for (m = getc(fin); m != EOF; m = getc(fin))
        if (m == '\n') {
            count++;
        }
    return count+1;
    fclose(filename);
}
int comparCloser(char bus[6],char bus2[6]){//// comparing time 2 between busses
    char b[6];
    char p[6];
    char b2[6];
    char* pt;
    char* pt2;
    char* pt1;
    strcpy( b,bus);
    pt= strtok(b,":");
    int bus_h= atoi(pt);
    pt=strtok(NULL,"");
    int bus_min=atoi(pt);
    double x=bus_min/100.0;
    double busSum =x+bus_h;


    strcpy( b2,bus2);
    pt2= strtok(b2,":");
    int bus_h2= atoi(pt2);
    pt2=strtok(NULL,"");
    int bus_min2=atoi(pt2);
    double xxx=bus_min2/100.0;
    double busSum2 =xxx+bus_h2;

    if(busSum>=busSum2){
        return 1;//first bus is later
    }
    return 0;//first bus closer
}
int isfirst(Bus bus[busC],char btime[6],char ptime[6],int x){//check closer buss for passenger
    int min=bus[0].bus_time;


        for (int l = 0; l < i; l++) {
            if (bus[x].date == bus[l].date && strcmp(bus[x].bus_from, bus[l].bus_from) == 0 &&
                strcmp(bus[x].bus_to, bus[l].bus_to) == 0&&l!=x) {
                if (comparCloser(btime, bus[l].bus_time) ==0) {//if the current bus is closer
                    return 1;

                } else
                    return 0;
            }

    }
}
int isfirstB(Bus bus[busC],char btime[6],char ptime[6],int x){
    int min=bus[0].bus_time;


    for (int l = 0; l < i; l++) {
        if (bus[x].date == bus[l].date && strcmp(bus[x].bus_from, bus[l].bus_from) == 0 &&
            strcmp(bus[x].bus_to, bus[l].bus_to) == 0 &&l != x) {
                if (comparCloser(btime, bus[l].bus_time) == 1) {
                    return l;//return the index of the closer bus

                } else
                    return 0;//the current is closer
            }
        }


    return 0;
}