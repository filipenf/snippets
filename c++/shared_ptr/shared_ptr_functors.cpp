/**
 * @author Filipe Niero Felisbino < filipenf::gmail::com >
 *
 * */

#ifndef __SHARED_PTR_FUNCTORS_HPP
#define __SHARED_PTR_FUNCTORS_HPP

#include <boost/shared_ptr.hpp>

/*!
 * A classe PointedEquals é um fuctor para facilitar a utilização de
 * boost::shared_ptr com os algoritmos padrão ( ex. find_if ).
 *
 * */
template<typename Pointee, typename Other = boost::shared_ptr<Pointee> >
class PointedEquals {
public:
    PointedEquals(const Other& o) : other(o) {};
    ~PointedEquals() {};

    bool operator()(boost::shared_ptr<Pointee> const &ptr) const {
        if ( ptr.get() == NULL ) return false;
        return (*ptr.get()) == other;
    };
private:
    const Other &other;
};

template<typename Pointee>
class PointedEquals<Pointee, boost::shared_ptr<Pointee> > {
public:
    PointedEquals(const boost::shared_ptr<Pointee>& o) : other(o.get()) {};
    PointedEquals(Pointee* o) : other(o) {};
    PointedEquals(Pointee& o) : other(&o) {};
    ~PointedEquals() {};

    bool operator()(boost::shared_ptr<Pointee> const &ptr) const {
        if ( ptr.get() == NULL ) return false;
        return (*ptr.get()) == *other;
    };

private:
    const Pointee *other;
};

#endif /// __SHARED_PTR_FUNCTORS_HPP
