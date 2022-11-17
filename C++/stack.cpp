#include <iostream>

/* Implementar pilha em C++ com uma abordagem de Programação Orientada a Objetos */

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
        cout << "Sobrecarga operador + no" << endl;
        cout << this->data << endl;
        this->next = &node;
        return *this;
    }
};

class Stack {
    private:
        Node *head, *tail;
    public:
        Stack() {
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
        void push(int value) {
            Node *temp = new Node(value);
            if (head == NULL) {
                head = temp;
                tail = temp;
            } else {
                temp->next = head;
                head = temp;
            }
        }
        void pop() {
            Node *temp;
            temp = head;
            head = head->next;
            delete temp;
        }
};


void menu(int op, Stack *stack) {
    int value;

    do {
        cout << "\n----------------------------------------\n" << endl;
        cout << "1 - Empilhar" << endl;
        cout << "2 - Desempilhar" << endl;
        cout << "3 - Exibir" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> op;

        system("cls || clear");

        switch (op) {
            case 1:
                cout << "Digite o valor a ser empilhado: ";
                cin >> value;
                stack->push(value);
                break;
            case 2:
                stack->pop();
                break;
            case 3:
                stack->display();
                break;
            case 4:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    } while (op != 4);
}


int main() {
    Stack *stack = new Stack;
    int op;

    menu(op, stack);

    return 0;
}