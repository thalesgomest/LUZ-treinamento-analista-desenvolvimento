#include <iostream>

/* Implementar fila em C++ com uma abordagem de Programação Orientada a Objetos */

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

class Queue {
    public:
        Node *front, *rear;
        Queue() {
            front = NULL;
            rear = NULL;
        }
        void enqueue(int value);
        void dequeue();
        void display();
};

void Queue::enqueue(int value) {
    Node *temp = new Node(value);
    if (front == NULL) {
        front = temp;
        rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void Queue::dequeue() {
    Node *temp;
    temp = front;
    front = front->next;
    delete temp;
}

void Queue::display() {
    Node *temp;
    temp = front;
    while (temp != NULL) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

void menu(int op, Queue *queue) {
    int value;

    do {
        cout << "\n----------------------------------------\n" << endl;
        cout << "1 - Enfileirar" << endl;
        cout << "2 - Desenfileirar" << endl;
        cout << "3 - Exibir" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> op;

        system("clear || cls");
        
        switch (op) {
            case 1:
                cout << "Digite o valor: ";
                cin >> value;
                queue->enqueue(value);
                break;
            case 2:
                queue->dequeue();
                break;
            case 3:
                queue->display();
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
    Queue *queue = new Queue;
    int op;

    menu(op, queue);
    return 0;
}