#ifndef __FT_H__
# define __FT_H__

# include <iostream>

namespace ft
{

/*    ENABLE IF    */

    template <bool _B, class _T = void>
    struct    enable_if {};

    template <class _T>
    struct    enable_if<true, _T> { typedef _T type; };

    template <typename _Category, typename _T>
    struct    iterator_traits
    {
            typedef _T            value_type;
            typedef _T*            pointer;
            typedef _T&            reference;
            typedef ptrdiff_t    difference_type;
            typedef _Category    iterator_category;
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

/*    CONTAINER PTOTOTYPES    */

    template < class _T, class _Allocator = std::allocator<_T> >
    class Vector;
};

#endif /* __FT_H__ */
