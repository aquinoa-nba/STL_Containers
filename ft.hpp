#ifndef __FT_H__
# define __FT_H__

# include <iostream>

namespace ft
{
	template <bool B, class T = void>
	struct	enable_if {};

	template <class T>
	struct	enable_if<true, T> { typedef T type; };

	template <typename _Category, typename _T>
	struct	iterator_traits
	{
			typedef _T			value_type;
			typedef _T*			pointer;
			typedef _T&			reference;
			typedef ptrdiff_t	difference_type;
			typedef _Category	iterator_category;
	};

	template<class InputIt1, class InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for ( ; first1 != last1; ++first1, ++first2)
		{
			if (*first1 != *first2)
				return false;
		}
		return true;
	}

	template<class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class _T, class _Allocator = std::allocator<_T> >
	class Vector;
};

#endif /* __FT_H__ */
