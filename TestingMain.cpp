#include <iostream>
#include "Order.h"
#include "DiscountStrategy.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "RegularPrice.h"

#include "PizzaComponent.h"
#include "Topping.h"
#include "ToppingGroup.h"

#include "Pizza.h"
#include "BasePizza.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "PizzaDecorator.h"

int main()
{

    std::cout << "---------------------------STRATEGY TESTING---------------------------" << std::endl;

    std::cout << "--- ORDER 1 ---" << std::endl;

    Order *order1_bulk = new Order(100.0, 5, new BulkDiscount());
    std::cout << "Order 1 Total with Bulk Discount: R" << order1_bulk->calculateTotal() << std::endl;
    delete order1_bulk;

    Order *order1_family = new Order(100.0, 5, new FamilyDiscount());
    std::cout << "Order 1 Total with Family Discount: R" << order1_family->calculateTotal() << std::endl;
    delete order1_family;

    Order *order1_regular = new Order(100.0, 5, new RegularPrice());
    std::cout << "Order 1 Total with Regular Price: R" << order1_regular->calculateTotal() << std::endl;
    delete order1_regular;

    std::cout << "--- ORDER 2 ---" << std::endl;

    Order *order2_bulk = new Order(50.0, 3, new BulkDiscount());
    std::cout << "Order 2 Total with Bulk Discount: R" << order2_bulk->calculateTotal() << std::endl;
    delete order2_bulk;

    Order *order2_family = new Order(50.0, 3, new FamilyDiscount());
    std::cout << "Order 2 Total with Family Discount: R" << order2_family->calculateTotal() << std::endl;
    delete order2_family;

    Order *order2_regular = new Order(50.0, 3, new RegularPrice());
    std::cout << "Order 2 Total with Regular Price: R" << order2_regular->calculateTotal() << std::endl;
    delete order2_regular;

    std::cout << "--- ORDER 3 ---" << std::endl;

    Order *order3_bulk = new Order(20.0, 2, new BulkDiscount());
    std::cout << "Order 3 Total with Bulk Discount: R" << order3_bulk->calculateTotal() << std::endl;
    delete order3_bulk;

    Order *order3_family = new Order(20.0, 2, new FamilyDiscount());
    std::cout << "Order 3 Total with Family Discount: R" << order3_family->calculateTotal() << std::endl;
    delete order3_family;

    Order *order3_regular = new Order(20.0, 2, new RegularPrice());
    std::cout << "Order 3 Total with Regular Price: R" << order3_regular->calculateTotal() << std::endl;
    delete order3_regular;


    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------COMPOSITE TESTING---------------------------" << std::endl;

    Topping cheese("Cheese", 2.50);
    std::cout << "Name: " << cheese.getName() << std::endl;
    std::cout << "Price: R" << cheese.getPrice() << std::endl;
    std::cout << "Type: " << cheese.getType() << std::endl;

    Topping pepperoni("Pepperoni", 3.00);
    std::cout << "Name: " << pepperoni.getName() << std::endl;
    std::cout << "Price: R" << pepperoni.getPrice() << std::endl;

    ToppingGroup emptyGroup("Empty Group", 0);
    std::cout << "Name: '" << emptyGroup.getName() << "'" << std::endl;
    std::cout << "Price: R" << emptyGroup.getPrice() << std::endl;
    std::cout << "Type: " << emptyGroup.getType() << std::endl;

    std::vector<PizzaComponent *> toppings = {&cheese, &pepperoni};
    ToppingGroup meatLovers("Meat Lovers", 0, toppings);
    std::cout << "Name: " << meatLovers.getName() << std::endl;
    std::cout << "Price: R" << meatLovers.getPrice() << std::endl;
    std::cout << "Type: " << meatLovers.getType() << std::endl;

    Topping mushrooms("Mushrooms", 1.50);
    meatLovers.add(&mushrooms); // so like if it works then this should ad hopefullyyyyy.............
    std::cout << "After adding mushrooms - Name: " << meatLovers.getName() << std::endl;
    std::cout << "After adding mushrooms - Price: R" << meatLovers.getPrice() << std::endl;

    // Topping olives("Olives", 1.00);
    // std::vector<PizzaComponent *> veggieToppings = {&mushrooms, &olives};
    // ToppingGroup veggieGroup("Veggie Group", 0, veggieToppings);

    // std::vector<PizzaComponent *> comboToppings = {&meatLovers, &veggieGroup};
    // ToppingGroup comboGroup("Combo Group", 0, comboToppings);
    // std::cout << "Combo Name: " << comboGroup.getName() << std::endl;
    // std::cout << "Combo Price: R" << comboGroup.getPrice() << std::endl;

    std::vector<PizzaComponent *> emptyVector;
    ToppingGroup singleGroup("Single", 0, emptyVector);
    std::cout << "Empty vector group - Name: '" << singleGroup.getName() << "'" << std::endl;
    std::cout << "Empty vector group - Price: R" << singleGroup.getPrice() << std::endl;

    //single topping to empty group......
    singleGroup.add(&cheese);
    std::cout << "After adding cheese - Name: " << singleGroup.getName() << std::endl;
    std::cout << "After adding cheese - Price: R" << singleGroup.getPrice() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "---------------------------DECORATOR TESTING---------------------------" << std::endl;
    Topping* mozzarella = new Topping("Mozzarella", 2.50);
    BasePizza* basicPizza = new BasePizza(mozzarella);//1 topping basic **** one
    
    std::cout << "Pizza: " << basicPizza->getName() << std::endl;
    std::cout << "Price: R" << basicPizza->getPrice() << std::endl;
    std::cout << "Type: " << basicPizza->getType() << std::endl;
    basicPizza->printPizzza();
    std::cout << std::endl << std::endl;
    
    delete basicPizza;
    delete mozzarella;

    Topping* pepperoniTopping = new Topping("Pepperoni", 3.00);
    Topping* pineappleTopping = new Topping("Pineapple", 1.50);//DO NOT JUDGE PINEAPPLE ON PIZZA OKAYYYYY......IM TALKING TO YOU JAITINNN
    
    std::vector<PizzaComponent*> toppingsList = {pepperoniTopping, pineappleTopping};
    ToppingGroup* meatVeggieCombo = new ToppingGroup("Meat Veggie Combo", 0, toppingsList);
    BasePizza* comboPizza = new BasePizza(meatVeggieCombo);
    
    std::cout << "Pizza: " << comboPizza->getName() << std::endl;
    std::cout << "Price: R" << comboPizza->getPrice() << std::endl;
    comboPizza->printPizzza();
    std::cout << std::endl << std::endl;
    
    delete comboPizza;
    delete meatVeggieCombo;
    delete pepperoniTopping;
    delete pineappleTopping;

    Topping* basicCheese = new Topping("Cheese", 2.50);
    BasePizza* plainPizza = new BasePizza(basicCheese);
    ExtraCheese* cheesePizza = new ExtraCheese(plainPizza, 1.50);
    
    std::cout << "Pizza: " << cheesePizza->getName() << std::endl;
    std::cout << "Price: R" << cheesePizza->getPrice() << std::endl;
    std::cout << "Type: " << cheesePizza->getType() << std::endl;
    cheesePizza->printPizzza();
    std::cout << std::endl << std::endl;
    
    delete cheesePizza;
    delete plainPizza;
    delete basicCheese;

    Topping* margheritaTop = new Topping("Tomato Basil", 3.00);
    BasePizza* margheritaBase = new BasePizza(margheritaTop);
    StuffedCrust* stuffedPizza = new StuffedCrust(margheritaBase, 2.00);
    
    std::cout << "Pizza: " << stuffedPizza->getName() << std::endl;
    std::cout << "Price: R" << stuffedPizza->getPrice() << std::endl;
    std::cout << "Type: " << stuffedPizza->getType() << std::endl;
    stuffedPizza->printPizzza();
    std::cout << std::endl << std::endl;
    
    delete stuffedPizza;
    delete margheritaBase;
    delete margheritaTop;

    std::vector<PizzaComponent*> emptyToppings;
    ToppingGroup* emptyGroup = new ToppingGroup("Empty", 0, emptyToppings);
    BasePizza* emptyPizza = new BasePizza(emptyGroup);
    
    std::cout << "Empty Pizza: " << emptyPizza->getName() << std::endl;
    std::cout << "Empty Price: R" << emptyPizza->getPrice() << std::endl;
    emptyPizza->printPizzza();
    std::cout << std::endl << std::endl;
    
    delete emptyPizza;
    delete emptyGroup;

    return 0;
}