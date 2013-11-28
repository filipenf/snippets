#include "shared_ptr_test.hpp"

#include <gtest/gtest.h>

#include <vector>
#include <string>

using std::string;
using std::vector;

using namespace testing;

TEST_F(SharedPtrTest, CompareWithReference)
{
    Customer customer("Filipe");
    vector<CustomerPtr>::iterator it = find_if(
            customerVector.begin(),
            customerVector.end(),
            PointedCustomerEquals(customer));
    ASSERT_FALSE(it==customerVector.end());
    ASSERT_EQ((it->get())->name, customer.name);
}

TEST_F(SharedPtrTest, CompareWithPointer)
{
    Customer *customer = new Customer("Filipe");
    vector<CustomerPtr>::iterator it = find_if(
            customerVector.begin(),
            customerVector.end(),
            PointedCustomerEquals(customer));
    ASSERT_FALSE(it==customerVector.end());
    ASSERT_EQ((it->get())->name, customer->name);
    delete customer;
}

TEST_F(SharedPtrTest, CompareString)
{
   CustomerVector::iterator it = find_if(
           customerVector.begin(),
           customerVector.end(),
           PointedCustomerEqualsStr("Filipe"));
   ASSERT_FALSE(it == customerVector.end());
   CustomerPtr cli = *it;
   ASSERT_EQ(cli->name, "Filipe");
}

//======================================================================
//
//======================================================================
//
void SharedPtrTest::SetUp()
{
   customerVector.push_back(CustomerPtr(new Customer("Customer A")));
   customerVector.push_back(CustomerPtr(new Customer("Customer B")));
   customerVector.push_back(CustomerPtr(new Customer("Customer C")));
   customerVector.push_back(CustomerPtr(new Customer("Customer D")));
   customerVector.push_back(CustomerPtr(new Customer("Customer E")));
   customerVector.push_back(CustomerPtr(new Customer("Customer F")));
   customerVector.push_back(CustomerPtr(new Customer("Filipe")));
}

void SharedPtrTest::TearDown()
{

}

