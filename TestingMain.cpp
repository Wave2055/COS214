#include "StandardUser.h"
#include "AdminUser.h"
#include "CtrlCat.h"
#include "Dogorithm.h"

int main()
{
    StandardUser *p1 = new StandardUser("Chinmayi");
    StandardUser *p2 = new StandardUser("Jaitin");
    AdminUser *a1 = new AdminUser("Admin1");
    AdminUser *a2 = new AdminUser("Admin2");

    CtrlCat *cr1 = new CtrlCat();
    Dogorithm *cr2 = new Dogorithm();

    cr1->registerUser(p1);
    cr1->registerUser(a1);
    cr1->registerUser(p2);

    cr2->registerUser(a2);
    cr2->registerUser(p1);
    cr2->registerUser(p2);

    a1->send("Test", cr1);

    std::cout << std::endl;

    p2->send("Hello world", cr1);
    std::cout << std::endl;
    p2->send("How are you?", cr2);
    std::cout << std::endl;

    cr1->displayMessageHistory();

    cr1->undoLastMessage();

    cr1->displayMessageHistory();

    cr1->redoMessage();

    cr1->displayMessageHistory();
}