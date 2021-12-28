#include <stdio.h>
#include <stdlib.h>

struct User {
    char nama[20];
    int umur;
    char alamat[30];
};
struct node {
    struct User user;
    struct node *next;
};
struct node *data;

void insert_node(struct User user){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->user = user;
    if(data == NULL){
        temp->next = NULL;
        data = temp;
    } else {
        temp->next = data;
        data = temp;
    }
}

void display_list(){
    if(data == NULL) {
        printf("data kosong");
    } else {
        struct node *temp = data;
        while(temp!=NULL){
            printf("%s %d %s\n", temp->user.nama, temp->user.umur, temp->user.alamat);
            temp = temp->next;
        }
    }
}

void save_node() {
    if(data == NULL) {
        printf("data kosong");
    } else {
        struct node *temp = data;
        FILE *fp = fopen("store.txt", "w");
        while(temp!=NULL){
            fprintf(fp, "%s %d %s\n", temp->user.nama, temp->user.umur, temp->user.alamat);
            temp = temp->next;
        }
        fclose(fp);
    }
}

int main() {
    FILE *f = fopen("store.txt", "r");
    char line[255];
    while(fgets(line, sizeof(line), f)) {
        struct User user;
        sscanf(line, "%s%d%s", user.nama, &user.umur, user.alamat);
        insert_node(user);
    }
    struct User new_user;
    sscanf("muchlish 19 subang", "%s%d%s", new_user.nama, &new_user.umur, new_user.alamat);
    insert_node(new_user);
    display_list();
    
    save_node();
    return 0;
}