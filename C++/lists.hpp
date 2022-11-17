#include <iostream>

/* Implementar lista em C++ com uma abordagem de Programação Orientada a Objetos */

using namespace std;


class Node {
    public:
        int data;
        Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    /* sobrecarga operador + nó */
    Node operator+(Node &node) {
        if(this->next == NULL) {
            this->next = &node;
            cout << "No adicionado com sucesso!" << endl;
        } 
    }
};


class List {
    private:
        Node *head, *tail;
    public:
        List() {
            head = NULL;
            tail = NULL;
        }
        void display() {
            Node *temp;
            temp = head;
            while (temp != NULL) {
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        void insert_start(int value) {
            Node *temp = new Node(value);
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head = temp;
            }
        }
        void insert_end(int value) {
            Node *temp = new Node(value);
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        void insert_position(int pos, int value) {
            Node *pre;
            Node *cur;
            Node *temp = new Node(value);
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
            Node *temp;
            temp = head;
            head = head->next;
            delete temp;
        }
        void delete_last() {
            Node *current;
            Node *previous;
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
            Node *current;
            Node *previous;
            current = head;
            for (int i = 1; i < pos; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
        void plus_node() {
            int value1, value2, value3;
            cout << "Digite o valor do no 1: ";
            cin >> value1;
            cout << "Digite o valor do no 2: ";
            cin >> value2;
            cout << "Digite o valor do no 3: ";
            cin >> value3;
            Node *node1 = new Node(value1);
            Node *node2 = new Node(value2);
            Node *node3 = new Node(value3);
            *node1 + *node2;
            *node2 + *node3;
            cout << "No 1: " << node1->data << endl;
            cout << "No 2: " << node1->next->data << endl;
            cout << "No 3: " << node2->next->data << endl;
        }
};

// _______________________________Menu Function______________________________

/* void menu(int op, List *list) {
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
        cout << "  8. Sobrecarga +" << endl;
        cout << "  9. Sair" << endl;
        cout << "\n___________________________________________\n" << endl;
        cout << "  \nOpcao: ";
        cin >> op;

        system("cls || clear");

        switch (op) {
        case 1:
            cout << "Digite um valor: ";
            cin >> value;
            list->insert_start(value);
            break;
        case 2:
            cout << "Digite um valor: ";
            cin >> value;
            list->insert_end(value);
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
            list->plus_node();
            break;
        case 9:
            exit(1);
            break;
        default:
            cout << "Opcao invalida!" << endl;
    }
    } while (op != 9);
} */

/* int main() {
    List *list = new List;
    int op;
    menu(op, list);
    return 0;
} */