#ifndef __STACK_H__
# define __STACK_H__

# include "Vector.hpp"
# include "ft.hpp"

template<class _T, class _Container>
class ft::Stack
{
	private:
		typedef _Container								container_type;
		typedef typename _Container::value_type			value_type;
		typedef typename _Container::reference			reference;
		typedef typename _Container::const_reference	const_reference;

	public:
		container_type	_c;

/*	CONSTRUCTORS	*/

		explicit Stack(const _Container &cont = _Container()) : _c(cont) {}

		Stack(const Stack &other) : _c(other._c) {}

/*	DESTRUCTOR	*/

		~Stack() {}

/*	COPY ASSIGNMENT OPERATOR	*/

		Stack&	operator = (const Stack &other)
		{
			_c = other._c;
			return *this;
		}

/*	MEMBER FUNCTIONS	*/

		reference 		top() { return _c.back(); }

		const_reference	top() const {return _c.back(); }

		bool			empty() const { return _c.empty(); }

		size_t			size() const { return _c.size(); }

		void 			push(const_reference value) { _c.push_back(value); }

		void			pop() { _c.pop_back(); }

		void			swap(Stack<_T, _Container> &other) { _c.swap(other._c); }
};

/*	COMPARISON OPERATORS	*/

template<class _T, class _Container>
bool	operator == (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c == rhs._c;
}

template<class _T, class _Container>
bool	operator != (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c != rhs._c;
}

template<class _T, class _Container>
bool	operator < (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c < rhs._c;
}

template<class _T, class _Container>
bool	operator > (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c > rhs._c;
}

template<class _T, class _Container>
bool	operator <= (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c <= rhs._c;
}

template<class _T, class _Container>
bool	operator >= (const ft::Stack<_T, _Container> &lhs, const ft::Stack<_T, _Container> &rhs)
{
	return lhs._c >= rhs._c;
}

#endif /* __STACK_H__ */
