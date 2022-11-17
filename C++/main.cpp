#include "lists.hpp"
#include "queue.hpp"
#include "stack.hpp"



void menu(int op1, int op2, List *list, Stack *stack, Queue *queue) {
    int value, pos;
    do {
        cout << "\n----------------------------------------\n" << endl;
        cout << "1 - Lista" << endl;
        cout << "2 - Pilha" << endl;
        cout << "3 - Fila" << endl;
        cout << "4 - Sair" << endl;
        cout << "Opcao: ";
        cin >> op1;
        system("cls || clear");

        switch (op1) {
        case 1:
            do {
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
                cin >> op2;

                system("cls || clear");

                switch (op2) {
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
            } while (op2 != 9);
            break;
        case 2:
            do {
                cout << "\n___________________________________________\n" << endl;
                cout << "  1. Inserir" << endl;
                cout << "  2. Remover" << endl;
                cout << "  3. Mostrar pilha" << endl;
                cout << "  4. Sair" << endl;
                cout << "\n___________________________________________\n" << endl;
                cout << "  \nOpcao: ";
                cin >> op2;

                system("cls || clear");

                switch (op2) {
                case 1:
                    cout << "Digite um valor: ";
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
                    exit(1);
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
            }
            } while (op2 != 4);
            break;
        case 3:
            do {
                cout << "\n___________________________________________\n" << endl;
                cout << "  1. Inserir" << endl;
                cout << "  2. Remover" << endl;
                cout << "  3. Mostrar fila" << endl;
                cout << "  4. Sair" << endl;
                cout << "\n___________________________________________\n" << endl;
                cout << "  \nOpcao: ";
                cin >> op2;

                system("cls || clear");

                switch (op2) {
                case 1:
                    cout << "Digite um valor: ";
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
                    exit(1);
                    break;
                default:
                    cout << "Opcao invalida!" << endl;
            }
            } while (op2 != 4);
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "Opcao invalida!" << endl;
    }
} while (op1 != 4);
}

int main() {
    List *list = new List();
    Stack *stack = new Stack();
    Queue *queue = new Queue();
    int op1, op2;
    menu(op1, op2, list, stack, queue);
    return 0;
}