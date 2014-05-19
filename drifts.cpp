#include "estaticos/includes.h"

Drifts Drifts::Instance;

Drifts::Drifts() {
}
 
int main(int argc, char* argv[]) {
    return Drifts::GetInstance()->Execute(argc, argv);
}