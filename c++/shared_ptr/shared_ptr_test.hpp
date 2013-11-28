#ifndef __SHARED_PTR_TEST_HPP_
#define __SHARED_PTR_TEST_HPP_

#include <string>
#include <boost/shared_ptr.hpp>
#include <gtest/gtest.h>
#include "shared_ptr_functors.cpp"

struct Customer {
    std::string name;

    Customer(const std::string &n) : name(n) {};

    bool operator==(const Customer &other) {
        return this->name == other.name;
    };

    virtual bool operator==(const std::string &other) {
        return this->name == other;
    };
};

typedef boost::shared_ptr<Customer> CustomerPtr;
typedef std::vector<CustomerPtr> CustomerVector;
typedef PointedEquals<Customer> PointedCustomerEquals;
typedef PointedEquals<Customer, std::string> PointedCustomerEqualsStr;

class SharedPtrTest : public testing::Test {
public:
    void SetUp();
    void TearDown();
protected:
    CustomerVector customerVector;
};

#endif  //// __SHARED_PTR_TEST_HPP_
