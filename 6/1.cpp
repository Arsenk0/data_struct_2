#include <iostream>
#include <string>

using namespace std;

    struct ST{
    string city;
    int distance;
    ST* next;
};
    ST* createST(string city, int distance){
        ST* newST = new ST();
        if (!newST){
            cout<<"ERROR\n";
            return NULL;
        }
        newST->city = city;
        newST->distance = distance;
        newST->next = NULL;
        return newST;
    }

    ST* insertST(ST* head, string city,int distance){
        ST*newST = createST(city,distance);
        if (head==NULL){
            return newST;
        }
        else{
            ST* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newST;
            return head;
        }
    }
void printFarthest(ST* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }
    ST* first = head;
    ST* second = NULL;
    ST* temp = head->next;
    while (temp != NULL) {
        if (temp->distance > first->distance) {
            second = first;
            first = temp;
        } else if (second == NULL || temp->distance > second->distance) {
            second = temp;
        }
        temp = temp->next;
    }
    cout << "2 mista naibalshi vid  capital : " << first->city << " and " << second->city << "\n";
}

void free(ST* head) {
    ST* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
        ST* head = NULL;
        head = insertST(head,"Lviv",    540);
        head = insertST(head,"Odessa",  475);
        head = insertST(head,"Dnipro",  477);
        head = insertST(head,"Kharkiv", 480);

        printFarthest(head);
        head = insertST(head, "Warsaw", 689);
        printFarthest(head);
        free(head);
        return 0;
    }














































