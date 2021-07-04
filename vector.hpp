#ifndef __VECTOR_H__
# define __VECTOR_H__

# include <iostream>

namespace ft
{
	template <class _T, class _Allocator = std::allocator<_T> >
	class vector
	{
		public:
			typedef _T											value_type;
			typedef _Allocator									allocator_type;
			typedef	typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef ptrdiff_t         							difference_type;
			
			class const_iterator;
			class const_reverse_iterator;

			class iterator
			{
				private:
					pointer		_curObj;
				public:
					iterator() : _curObj(nullptr) {}
					
					iterator(pointer ptr) : _curObj(ptr) {}

					~iterator() {}

					iterator(iterator const &other) { *this = other; }

					iterator&	operator = (iterator const &other)
					{
						if (this != &other)
							_curObj = other._curObj;
						return *this;
					}

					pointer			getObj() const { return _curObj; }

					iterator&		operator ++ () { ++_curObj; return *this; }
					iterator&		operator -- () { --_curObj; return *this; }
					iterator		operator ++ (int) { return iterator(_curObj++); }
					iterator		operator -- (int) { return iterator(_curObj--); }
					iterator&		operator += (difference_type n) { _curObj += n; return *this; }
					iterator&		operator -= (difference_type n) { _curObj -= n; return *this; }
					iterator		operator + (difference_type n) const { return iterator(_curObj + n); }
					iterator		operator - (difference_type n) const { return iterator(_curObj - n); }
					reference&		operator * () { return *_curObj; };
					difference_type	operator - (iterator const &other) const { return _curObj - other._curObj; }
					reference		operator [] (const_reference n) const { return _curObj[n]; }

					bool			operator == (iterator const &other) const { return _curObj == other._curObj; }
					bool			operator != (iterator const &other) const { return _curObj != other._curObj; }
					bool			operator > (iterator const &other) const{ return _curObj > other._curObj; }
					bool			operator < (iterator const &other) const{ return _curObj < other._curObj; }
					bool			operator >= (iterator const &other) const { return _curObj >= other._curObj; }
					bool			operator <= (iterator const &other) const { return _curObj <= other._curObj; }

					bool			operator == (const_iterator const &other) const { return _curObj == other.getObj(); }
					bool			operator != (const_iterator const &other) const { return _curObj != other.getObj(); }
					bool			operator > (const_iterator const &other) const{ return _curObj > other.getObj(); }
					bool			operator < (const_iterator const &other) const{ return _curObj < other.getObj(); }
					bool			operator >= (const_iterator const &other) const { return _curObj >= other.getObj(); }
					bool			operator <= (const_iterator const &other) const { return _curObj <= other.getObj(); }
			};
			
			class const_iterator
			{
				private:
					pointer		_curObj;
				public:
					const_iterator() : _curObj(nullptr) {}

					const_iterator(pointer ptr) : _curObj(ptr) {}

					~const_iterator() {}

					const_iterator(const_iterator const &other) { *this = other; }

					const_iterator&	operator = (const_iterator const &other)
					{
						if (this != &other)
							_curObj = other._curObj;
						return *this;
					}

					const_pointer		getObj() const { return _curObj; }

					const_iterator&		operator ++ () { ++_curObj; return *this; }
					const_iterator&		operator -- () { --_curObj; return *this; }
					const_iterator		operator ++ (int) { return const_iterator(_curObj++); }
					const_iterator		operator -- (int) { return const_iterator(_curObj--); }
					const_iterator&		operator += (difference_type n) { _curObj += n; return *this; }
					const_iterator&		operator -= (difference_type n) { _curObj -= n; return *this; }
					const_iterator		operator + (difference_type n) const { return const_iterator(_curObj + n); }
					const_iterator		operator - (difference_type n) const { return const_iterator(_curObj - n); }
					const_reference&	operator * () const { return *_curObj; };
					difference_type		operator - (const_iterator const &other) const { return _curObj - other._curObj; }
					const_reference		operator [] (const_reference n) const { return _curObj[n]; }

					bool				operator == (const_iterator const &other) const { return _curObj == other._curObj; }
					bool				operator != (const_iterator const &other) const { return _curObj != other._curObj; }
					bool				operator > (const_iterator const &other) const{ return _curObj > other._curObj; }
					bool				operator < (const_iterator const &other) const{ return _curObj < other._curObj; }
					bool				operator >= (const_iterator const &other) const { return _curObj >= other._curObj; }
					bool				operator <= (const_iterator const &other) const { return _curObj <= other._curObj; }

					bool				operator == (iterator const &other) const { return _curObj == other.getObj(); }
					bool				operator != (iterator const &other) const { return _curObj != other.getObj(); }
					bool				operator > (iterator const &other) const{ return _curObj > other.getObj(); }
					bool				operator < (iterator const &other) const{ return _curObj < other.getObj(); }
					bool				operator >= (iterator const &other) const { return _curObj >= other.getObj(); }
					bool				operator <= (iterator const &other) const { return _curObj <= other.getObj(); }
			};
			
			class reverse_iterator
			{
				private:
					pointer		_curObj;
				public:
					reverse_iterator() : _curObj(nullptr) {}

					reverse_iterator(pointer ptr) : _curObj(ptr) {}

					~reverse_iterator() {}

					reverse_iterator(reverse_iterator const &other) { *this = other; }

					reverse_iterator&	operator = (reverse_iterator const &other)
					{
						if (this != &other)
							_curObj = other._curObj;
						return *this;
					}

					pointer				getObj() const { return _curObj; }

					reverse_iterator&	operator ++ () { --_curObj; return *this; }
					reverse_iterator&	operator -- () { ++_curObj; return *this; }
					reverse_iterator	operator ++ (int) { return reverse_iterator(_curObj--); }
					reverse_iterator	operator -- (int) { return reverse_iterator(_curObj++); }
					reverse_iterator&	operator += (difference_type n) { _curObj -= n; return *this; }
					reverse_iterator&	operator -= (difference_type n) { _curObj += n; return *this; }
					reverse_iterator	operator + (difference_type n) const { return reverse_iterator(_curObj - n); }
					reverse_iterator	operator - (difference_type n) const { return reverse_iterator(_curObj + n); }
					reference&			operator * () const { return *_curObj; };
					difference_type		operator - (reverse_iterator const &other) const { return other._curObj - _curObj; }
					reference			operator [] (const_reference n) const { return _curObj[n]; }

					bool				operator == (reverse_iterator const &other) const { return _curObj == other._curObj; }
					bool				operator != (reverse_iterator const &other) const { return _curObj != other._curObj; }
					bool				operator > (reverse_iterator const &other) const{ return _curObj > other._curObj; }
					bool				operator < (reverse_iterator const &other) const{ return _curObj < other._curObj; }
					bool				operator >= (reverse_iterator const &other) const { return _curObj >= other._curObj; }
					bool				operator <= (reverse_iterator const &other) const { return _curObj <= other._curObj; }

					bool				operator == (const_reverse_iterator const &other) const { return _curObj == other.getObj(); }
					bool				operator != (const_reverse_iterator const &other) const { return _curObj != other.getObj(); }
					bool				operator > (const_reverse_iterator const &other) const{ return _curObj > other.getObj(); }
					bool				operator < (const_reverse_iterator const &other) const{ return _curObj < other.getObj(); }
					bool				operator >= (const_reverse_iterator const &other) const { return _curObj >= other.getObj(); }
					bool				operator <= (const_reverse_iterator const &other) const { return _curObj <= other.getObj(); }
			};
			
			class const_reverse_iterator
			{
				private:
					pointer		_curObj;
				public:
					const_reverse_iterator() : _curObj(nullptr) {}

					const_reverse_iterator(pointer ptr) : _curObj(ptr) {}

					~const_reverse_iterator() {}

					const_reverse_iterator(const_reverse_iterator const &other) { *this = other; }

					const_reverse_iterator&	operator = (const_reverse_iterator const &other)
					{
						if (this != &other)
							_curObj = other._curObj;
						return *this;
					}

					const_pointer				getObj() const { return _curObj; }

					const_reverse_iterator&		operator ++ () { --_curObj; return *this; }
					const_reverse_iterator&		operator -- () { ++_curObj; return *this; }
					const_reverse_iterator		operator ++ (int) { return const_reverse_iterator(_curObj--); }
					const_reverse_iterator		operator -- (int) { return const_reverse_iterator(_curObj++); }
					const_reverse_iterator&		operator += (difference_type n) { _curObj -= n; return *this; }
					const_reverse_iterator&		operator -= (difference_type n) { _curObj += n; return *this; }
					const_reverse_iterator		operator + (difference_type n) const { return const_reverse_iterator(_curObj - n); }
					const_reverse_iterator		operator - (difference_type n) const { return const_reverse_iterator(_curObj + n); }
					const_reference&			operator * () const { return *_curObj; };
					difference_type				operator - (const_reverse_iterator const &other) const { return other._curObj - _curObj; }
					const_reference				operator [] (const_reference n) const { return _curObj[n]; }

					bool						operator == (const_reverse_iterator const &other) const { return _curObj == other._curObj; }
					bool						operator != (const_reverse_iterator const &other) const { return _curObj != other._curObj; }
					bool						operator > (const_reverse_iterator const &other) const{ return _curObj > other._curObj; }
					bool						operator < (const_reverse_iterator const &other) const{ return _curObj < other._curObj; }
					bool						operator >= (const_reverse_iterator const &other) const { return _curObj >= other._curObj; }
					bool						operator <= (const_reverse_iterator const &other) const { return _curObj <= other._curObj; }

					bool						operator == (reverse_iterator const &other) const { return _curObj == other.getObj(); }
					bool						operator != (reverse_iterator const &other) const { return _curObj != other.getObj(); }
					bool						operator > (reverse_iterator const &other) const{ return _curObj > other.getObj(); }
					bool						operator < (reverse_iterator const &other) const{ return _curObj < other.getObj(); }
					bool						operator >= (reverse_iterator const &other) const { return _curObj >= other.getObj(); }
					bool						operator <= (reverse_iterator const &other) const { return _curObj <= other.getObj(); }
			};

		private:
			allocator_type	_alloc;
			pointer			_arr;
			size_t			_arrSize;
			size_t			_arrCap;

		public:
			vector() : _arr(nullptr), _arrSize(0), _arrCap(0) {}

			vector(size_t n, const_reference value)
				: _arr(_alloc.allocate(n)), _arrSize(n), _arrCap(n)
			{
				for (size_t i = 0; i < _arrSize; ++i)
					_alloc.construct(_arr + i, value);
			}

			vector(vector const &other)
				: _alloc(other._alloc), _arrSize(other._arrSize), _arrCap(other._arrCap)
			{
				_arr = _alloc.allocate(_arrCap);
				for (size_t i = 0; i < _arrSize; ++i)
					_alloc.construct(_arr + i, other._arr[i]);
			}

			vector&	operator = (vector const &other)
			{
				if (this != &other)
				{
					if (_arr)
					{
						clear();
						_alloc.deallocate(_arr, _arrCap);
					}
					_alloc = other._alloc;
					_arrSize = other._arrSize;
					_arrCap = other._arrCap;
					_arr = _alloc.allocate(_arrCap);
					for (size_t i = 0; i < _arrSize; ++i)
						_alloc.construct(_arr + i, other._arr[i]);
				}
				return *this;
			}

			~vector()
			{
				if (_arr)
				{
					clear();
					_alloc.deallocate(_arr, _arrCap);
				}
			}

			iterator				begin() { return iterator(_arr); }
			iterator				end() { return iterator(_arr + _arrSize); }
			const_iterator			cbegin() const { return const_iterator(_arr); }
			const_iterator			cend() const { return const_iterator(_arr + _arrSize); }
			reverse_iterator		rbegin() { return reverse_iterator(_arr + _arrSize - 1); }
			reverse_iterator		rend() { return reverse_iterator(_arr - 1); }
			const_reverse_iterator	crbegin() const { return const_reverse_iterator(_arr + _arrSize - 1); }
			const_reverse_iterator	crend() const { return const_reverse_iterator(_arr - 1); }

			size_t					size() const { return _arrSize; }
			size_t					capacity() const { return _arrCap; }
			reference				front() { return _arr[0]; }
			reference				back() { return _arr[_arrSize - 1]; }
			const_reference			front() const { return _arr[0]; }
			const_reference			back() const { return _arr[_arrSize - 1]; }
			bool					empty() const { return _arrSize ? false : true; }
			size_t					max_size() const { return _alloc.max_size(); }

			iterator		insert(iterator pos, const_reference value)
			{
				if (_arrSize == _arrCap)
				{
					size_t	id = (pos.getObj() - begin().getObj());
					reserve(_arrSize * 2);
					pos = begin() + id;
				}
				std::memmove(pos.getObj() + 1, pos.getObj(), sizeof(value) * (end().getObj() - pos.getObj()));
				_alloc.construct(pos.getObj(), value);
				++_arrSize;
				return pos;
			}

			void			insert(iterator pos, size_t count, const_reference value)
			{
				if (_arrSize + count > _arrCap)
				{
					size_t	id = (pos.getObj() - begin().getObj());
					if (_arrSize + count > _arrCap * 2)
						reserve(_arrSize + count);
					else
						reserve(_arrCap * 2);
					pos = begin() + id;
				}
				std::memmove(pos.getObj() + count, pos.getObj(), sizeof(value) * (end().getObj() - pos.getObj()));
				for (size_t i = 0; i != count; ++i)
				{
					_alloc.construct((pos + i).getObj(), value);
				}
				_arrSize += count;
			}

			template <class InputIt> void	insert(iterator pos, InputIt first, InputIt last)
			{
				size_t	range = last - first;
				if (_arrSize + range > _arrCap)
				{
					size_t	id = (pos.getObj() - begin().getObj());
					if (_arrSize + range > _arrCap * 2)
						reserve(_arrSize + range);
					else
						reserve(_arrCap * 2);
					pos = begin() + id;
				}
				std::memmove(pos.getObj() + range, pos.getObj(), sizeof(value_type) * (end().getObj() - pos.getObj()));
				for (size_t i = 0; i != range; ++i)
				{
					_alloc.construct((pos + i).getObj(), *(first + i));
				}
				_arrSize += range;
			}

			iterator		erase(iterator pos)
			{
				_alloc.destroy(pos.getObj());
				std::memmove(pos.getObj(), pos.getObj() + 1, sizeof(value_type) * (end().getObj() - pos.getObj()));
				--_arrSize;
				return pos;
			}

			iterator		erase(iterator first, iterator last)
			{
				for (iterator tmp = first; tmp != last; ++tmp)
					_alloc.destroy(tmp.getObj());
				std::memmove(first.getObj(), last.getObj(), sizeof(value_type) * (end().getObj() - last.getObj()));
				_arrSize -= last.getObj() - first.getObj();
				return last;
			}

			void			clear()
			{
				for (size_t i = 0; i < _arrSize; ++i)
					_alloc.destroy(_arr + i);
				_arrSize = 0;
			}

			void			reserve(size_t n)
			{
				if (n > _arrCap)
				{
					pointer	newArr = _alloc.allocate(n);
					for (size_t i = 0; i < _arrSize; ++i)
					{
						_alloc.construct(newArr + i, _arr[i]);
						_alloc.destroy(_arr + i);					// protecting from exception ???
					}
					if (_arr)
						_alloc.deallocate(_arr, _arrCap);
					_arr = newArr;
					_arrCap = n;
				}
			}

			void			resize(size_t n)
			{
				if (n > _arrCap)
					reserve(_arrCap * 2);
				_arrSize = n;
			}

			void			resize(size_t n, const_reference value)
			{
				if (n > _arrCap)
					reserve(_arrCap * 2);
				for (size_t i = _arrSize; i < n; ++i)
					_alloc.construct(_arr + i, value);
				_arrSize = n;
			}

			void			push_back(const_reference value)
			{
				if (_arrSize == _arrCap)
					reserve(_arrSize ? _arrSize * 2 : 1);
				_alloc.construct(_arr + _arrSize, value);
				++_arrSize;
			}

			void			pop_back()
			{
				if (_arr)
				{
					--_arrSize;
					_alloc.destroy(_arr + _arrSize);
				}
			}

			reference		at(size_t n)
			{
				if (n >= _arrSize)
					throw std::out_of_range("Out of range");			//	exception ????
				return _arr[n];
			}

			void			assign(size_t n, const_reference value)
			{
				// clear();
				// insert(begin(), n, value);
				if (n < 0)
					throw std::out_of_range("Out of range");			//	exception ????
				if (n > _arrCap)
					reserve(n);
				for (size_t i = 0; i < n; i++)
					_alloc.construct(_arr + i, value);
				_arrSize = n;
			}

			void			swap(vector &other)
			{
				if (this != &other)
				{
					allocator_type	tmpAlloc = _alloc;
					pointer			tmpArr = _arr;
					size_t			tmpArrSize = _arrSize;
					size_t			tmpArrCap = _arrCap;

					_alloc = other._alloc;
					_arr = other._arr;
					_arrSize  = other._arrSize;
					_arrCap  = other._arrCap;

					other._alloc = tmpAlloc;
					other._arr = tmpArr;
					other._arrSize = tmpArrSize;
					other._arrCap = tmpArrCap;
				}
			}

			reference		operator [] (size_t n)
			{
				// if (n >= _arrCap)
				// 	throw std::out_of_range("Out of range");			//	exception ????
				return _arr[n];
			}
	};
}

#endif /* __VECTOR_H__ */
