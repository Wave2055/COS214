#include <iostream>
#include "Order.h"
#include "DiscountStrategy.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "RegularPrice.h"

int main()
{

std::cout<<"---------------------------STRATEGY TESTING---------------------------"<<std::endl;

std::cout<<"--- ORDER 1 ---"<<std::endl;

Order* order1_bulk = new Order(100.0, 5, new BulkDiscount());
std::cout << "Order 1 Total with Bulk Discount: R" << order1_bulk->calculateTotal() << std::endl;
delete order1_bulk;

Order* order1_family = new Order(100.0, 5, new FamilyDiscount());
std::cout << "Order 1 Total with Family Discount: R" << order1_family->calculateTotal() << std::endl;
delete order1_family;

Order* order1_regular = new Order(100.0, 5, new RegularPrice());
std::cout << "Order 1 Total with Regular Price: R" << order1_regular->calculateTotal() << std::endl;
delete order1_regular;

std::cout<<"--- ORDER 2 ---"<<std::endl;

Order* order2_bulk = new Order(50.0, 3, new BulkDiscount());
std::cout << "Order 2 Total with Bulk Discount: R" << order2_bulk->calculateTotal() << std::endl;
delete order2_bulk;

Order* order2_family = new Order(50.0, 3, new FamilyDiscount());
std::cout << "Order 2 Total with Family Discount: R" << order2_family->calculateTotal() << std::endl;
delete order2_family;

Order* order2_regular = new Order(50.0, 3, new RegularPrice());
std::cout << "Order 2 Total with Regular Price: R" << order2_regular->calculateTotal() << std::endl;
delete order2_regular;


std::cout<<"--- ORDER 3 ---"<<std::endl;

Order* order3_bulk = new Order(20.0, 2, new BulkDiscount());
std::cout << "Order 3 Total with Bulk Discount: R" << order3_bulk->calculateTotal() << std::endl;
delete order3_bulk;

Order* order3_family = new Order(20.0, 2, new FamilyDiscount());
std::cout << "Order 3 Total with Family Discount: R" << order3_family->calculateTotal() << std::endl;
delete order3_family;

Order* order3_regular = new Order(20.0, 2, new RegularPrice());
std::cout << "Order 3 Total with Regular Price: R" << order3_regular->calculateTotal() << std::endl;
delete order3_regular;



return 0;

std::cout<<"---------------------------COMPOSITE TESTING---------------------------"<<std::endl;


}