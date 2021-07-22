#ifndef __FT_H__
# define __FT_H__

# include <iostream>

namespace ft
{
/*    ENABLE IF    */

    template<bool _B, class _T = void>
    struct    enable_if {};

    template<class _T>
    struct    enable_if<true, _T> { typedef _T type; };

/*    ITERATOR TRAITS    */

    template<class _Category, class _T>
    struct    iterator_traits
    {
            typedef _T            value_type;
            typedef _T*            pointer;
            typedef _T&            reference;
            typedef ptrdiff_t    difference_type;
            typedef _Category    iterator_category;
    };

/*    REVERSE ITERATOR */

    template<class _Iter>
    struct    reverse_iterator
    {
        typedef _Iter                                iterator_type;
        typedef typename _Iter::value_type            value_type;
        typedef typename _Iter::pointer                pointer;
        typedef typename _Iter::reference            reference;
        typedef typename _Iter::difference_type        difference_type;
        typedef typename _Iter::iterator_category    iterator_category;
    };

/*    EQUAL COMPARE    */

    template<class _InputIt1, class _InputIt2>
    bool    equal(_InputIt1 first1, _InputIt1 last1, _InputIt2 first2)
    {
        for ( ; first1 != last1; ++first1, ++first2)
        {
            if (*first1 != *first2)
                return false;
        }
        return true;
    }

/*    LEXICOGRAPHICAL COMPARE    */

    template<class _InputIt1, class _InputIt2>
    bool    lexicographical_compare(_InputIt1 first1, _InputIt1 last1, _InputIt2 first2, _InputIt2 last2)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
        {
            if (*first1 < *first2) return true;
            if (*first2 < *first1) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template<class _InputIt1, class _InputIt2, class _Compare>
    bool    lexicographical_compare(_InputIt1 first1, _InputIt1 last1, _InputIt2 first2, _InputIt2 last2, _Compare comp)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
        {
            if (comp(*first1, *first2)) return true;
            if (comp(*first2, *first1)) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

/*    PAIR    */

    template<class _T1, class _T2>
    struct pair
    {
        typedef _T1    first_type;
        typedef _T2    second_type;

        first_type    first;
        second_type    second;

    /*    CONSTRUCTORS    */

        /*    default constructor    */
        pair() : first(first_type()), second(second_type()) {}

        /*    filling    constructor    */
        pair(const first_type &x, const second_type &y) : first(x), second(y) {}

        /*    converting constructor    */
        template<class _U1, class _U2>
        pair(const pair<_U1, _U2> &p) : first(p.first), second(p.second) {}

        /*    copy constructor    */
        pair(const pair &other) { *this = other; }

        /*    assignment operator    */
        pair&    operator = (const pair &other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return *this;
        }
    };

/*    MAKE PAIR    */

    template<class _T1, class _T2>
    pair<_T1, _T2>    make_pair(_T1 t, _T2 u) { return pair<_T1, _T2>(t, u); }

/*    CONTAINER PROTOTYPES    */

    template <    class _T,
                class _Allocator = std::allocator<_T> >
    class Vector;

    template <    class _T,
                class _Container = Vector<_T> >
    class Stack;

    template <    class _Key,
                class _T,
                class _Compare = std::less<_Key>,
                class _Allocator = std::allocator<pair<const _Key, _T> > >
    class Map;
};

#endif /* __FT_H__ */
