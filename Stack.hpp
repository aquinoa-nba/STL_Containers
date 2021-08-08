#pragma once

#include "Vector.hpp"
#include "ft.hpp"

template<class _T, class _Container>
class ft::stack
{
public:
/*    MEMBER TYPES    */
        typedef _Container                                container_type;
        typedef typename _Container::value_type            value_type;
        typedef typename _Container::reference            reference;
        typedef typename _Container::const_reference    const_reference;

        container_type    c;

/*    CONSTRUCTORS    */
        stack(const _Container &cont = _Container()) : c(cont) {}
        stack(const stack &other) : c(other.c) {}
/*    DESTRUCTOR    */
        ~stack() {}
/*    ASSIGNATION OPERATOR OVERLOAD    */
        stack&    operator = (const stack &other)
        {
            c = other.c;
            return *this;
        }
/*    MEMBER FUNCTIONS    */
        reference         top() { return c.back(); }
        const_reference    top() const {return c.back(); }
        void            pop() { c.pop_back(); }
        void             push(const_reference value) { c.push_back(value); }
        bool            empty() const { return c.empty(); }
        size_t            size() const { return c.size(); }
        void            swap(stack<_T, _Container> &other) { c.swap(other.c); }
};

/*    COMPARISON OPERATORS    */
template<class _T, class _Container>
bool    operator == (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c == rhs.c;
}

template<class _T, class _Container>
bool    operator != (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c != rhs.c;
}

template<class _T, class _Container>
bool    operator < (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c < rhs.c;
}

template<class _T, class _Container>
bool    operator > (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c > rhs.c;
}

template<class _T, class _Container>
bool    operator <= (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c <= rhs.c;
}

template<class _T, class _Container>
bool    operator >= (const ft::stack<_T, _Container> &lhs, const ft::stack<_T, _Container> &rhs)
{
    return lhs.c >= rhs.c;
}
