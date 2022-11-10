#include <iostream>

/* Implementar lista em C++ com uma abordagem de Programação Orientada a Objetos */

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class List {
    private:
        Node *head, *tail;
    public:
        List() {
            head = NULL;
            tail = NULL;
        }
        void create_node(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        void display() {
            Node *temp = new Node;
            temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        void insert_start(int value) {
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        void insert_position(int pos, int value) {
            Node *pre = new Node;
            Node *cur = new Node;
            Node *temp = new Node;
            cur = head;
            for (int i = 1; i < pos; i++) {
                pre = cur;
                cur = cur->next;
            }
            temp->data = value;
            pre->next = temp;
            temp->next = cur;
        }
        void delete_first() {
            Node *temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }
        void delete_last() {
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            tail = previous;
            previous->next = NULL;
            delete current;
        }
        void delete_position(int pos) {
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
};

// _______________________________Menu Function______________________________

void menu(int op, List *list) {
    int value, pos;


    do
    {
        cout << "\n___________________________________________\n" << endl;
        cout << "  1. Inserir no inicio" << endl;
        cout << "  2. Inserir no final" << endl;
        cout << "  3. Inserir em uma posicao" << endl;
        cout << "  4. Remover do inicio" << endl;
        cout << "  5. Remover do final" << endl;
        cout << "  6. Remover de uma posicao" << endl;
        cout << "  7. Mostrar lista" << endl;
        cout << "  8. Sair" << endl;
        cout << "  \nOpcao: ";
        cin >> op;

        system("cls || clear");

        switch (op) {
        case 1:
            cout << "Digite um valor: ";
            cin >> value;
            list->create_node(value);
            break;
        case 2:
            cout << "Digite um valor: ";
            cin >> value;
            list->insert_start(value);
            break;
        case 3:
            cout << "Digite a posicao: ";
            cin >> pos;
            cout << "Digite um valor: ";
            cin >> value;
            if (pos == 1) {
                list->insert_start(value);
            } else {
                list->insert_position(pos, value);
            }
            break;
        case 4:
            list->delete_first();
            break;
        case 5:
            list->delete_last();
            break;
        case 6:
            cout << "Digite a posicao: ";
            cin >> pos;
            if (pos == 1) {
                list->delete_first();
            } else {
                list->delete_position(pos);
            }
            break;
        case 7:
            list->display();
            break;
        case 8:
            exit(1);
            break;
        default:
            cout << "Opcao invalida!" << endl;
    }
    } while (op != 8);
}

int main() {
    List *list = new List;
    int op;
    menu(op, list);
    return 0;
}