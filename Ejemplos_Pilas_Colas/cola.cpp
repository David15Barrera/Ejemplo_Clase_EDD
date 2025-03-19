#include <queue>
#include <iostream>

int main() {
    std::queue<int> cola;

//Insercion de elementos    
    cola.push(1);
    cola.push(2);
    cola.push(3);

    std::cout << "Frente de la cola: " << cola.front() << std::endl;
    std::cout << "Atras de la cola: " << cola.back() << std::endl;
    
    cola.pop();

   std::cout << "Frente de la cola: " << cola.front() << std::endl;
 
    return 0;
}