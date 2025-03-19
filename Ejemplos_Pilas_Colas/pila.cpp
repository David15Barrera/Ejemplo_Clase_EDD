#include <stack>
#include <iostream>

int main() {
    std::stack<int> pila;

// Insercion de datos    
    pila.push(10);
    pila.push(20);
    pila.push(30);


    std::cout << "Elemento en la cima: " << pila.top() << std::endl;
    
    pila.pop();

    std::cout << "Elemento en la cima: " << pila.top() << std::endl;
   return 0;
}
