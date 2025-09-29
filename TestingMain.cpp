#include "StandardUser.h"
#include "AdminUser.h"
#include "GuestUser.h"
#include "CtrlCat.h"
#include "Dogorithm.h"

int main()
{
    StandardUser *p1 = new StandardUser("Chinmayi");
    GuestUser *p2 = new GuestUser("Jaitin");
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

    cr2->removeUser(p2);

    p1->send("This is Dogorithm", cr2);
    std::cout << std::endl;

    cr1->searchMessages("Hello");

    delete p1;
    delete p2;
    delete a1;
    delete a2;

    delete cr1;
    delete cr2;
    return 0;
}