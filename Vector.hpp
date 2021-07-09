#ifndef __VECTOR_H__
# define __VECTOR_H__

# include "ft.hpp"

template <class _T, class _Allocator>
class ft::Vector
{
    public:
        typedef _T                                            value_type;
        typedef _Allocator                                    allocator_type;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer        const_pointer;
        typedef typename allocator_type::reference            reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef ptrdiff_t                                    difference_type;

        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;

/*    ITERATOR    */

        class iterator : public ft::iterator_traits<std::random_access_iterator_tag, value_type>
        {
            private:
                pointer        _ptr;
            public:
                iterator() : _ptr(nullptr) {}
                iterator(pointer ptr) : _ptr(ptr) {}
                ~iterator() {}
                iterator(const iterator &other) { *this = other; }

                pointer            getPtr() const { return _ptr; }

                iterator&        operator = (const iterator &other)
                {
                    if (this != &other)
                        _ptr = other._ptr;
                    return *this;
                }

                iterator&        operator ++ () { ++_ptr; return *this; }
                iterator&        operator -- () { --_ptr; return *this; }
                iterator        operator ++ (int) { return iterator(_ptr++); }
                iterator        operator -- (int) { return iterator(_ptr--); }
                iterator&        operator += (difference_type n) { _ptr += n; return *this; }
                iterator&        operator -= (difference_type n) { _ptr -= n; return *this; }
                iterator        operator + (difference_type n) const { return iterator(_ptr + n); }
                iterator        operator - (difference_type n) const { return iterator(_ptr - n); }
                reference&        operator * () { return *_ptr; };
                difference_type    operator - (iterator const &other) const { return _ptr - other._ptr; }
                reference        operator [] (const_reference n) const { return _ptr[n]; }
                pointer            operator -> () { return _ptr; }

                bool            operator == (iterator const &other) const { return _ptr == other._ptr; }
                bool            operator != (iterator const &other) const { return _ptr != other._ptr; }
                bool            operator > (iterator const &other) const{ return _ptr > other._ptr; }
                bool            operator < (iterator const &other) const{ return _ptr < other._ptr; }
                bool            operator >= (iterator const &other) const { return _ptr >= other._ptr; }
                bool            operator <= (iterator const &other) const { return _ptr <= other._ptr; }

                bool            operator == (const_iterator const &other) const { return _ptr == other.getPtr(); }
                bool            operator != (const_iterator const &other) const { return _ptr != other.getPtr(); }
                bool            operator > (const_iterator const &other) const{ return _ptr > other.getPtr(); }
                bool            operator < (const_iterator const &other) const{ return _ptr < other.getPtr(); }
                bool            operator >= (const_iterator const &other) const { return _ptr >= other.getPtr(); }
                bool            operator <= (const_iterator const &other) const { return _ptr <= other.getPtr(); }
        };

/*    CONST_ITERATOR    */

        class const_iterator : public ft::iterator_traits<std::random_access_iterator_tag, const value_type>
        {
            private:
                pointer        _ptr;
            public:
                const_iterator() : _ptr(nullptr) {}
                const_iterator(pointer ptr) : _ptr(ptr) {}
                ~const_iterator() {}
                const_iterator(const const_iterator &other) { *this = other; }

                const_pointer        getPtr() const { return _ptr; }

                const_iterator&        operator = (const const_iterator &other)
                {
                    if (this != &other)
                        _ptr = other._ptr;
                    return *this;
                }

                const_iterator&        operator ++ () { ++_ptr; return *this; }
                const_iterator&        operator -- () { --_ptr; return *this; }
                const_iterator        operator ++ (int) { return const_iterator(_ptr++); }
                const_iterator        operator -- (int) { return const_iterator(_ptr--); }
                const_iterator&        operator += (difference_type n) { _ptr += n; return *this; }
                const_iterator&        operator -= (difference_type n) { _ptr -= n; return *this; }
                const_iterator        operator + (difference_type n) const { return const_iterator(_ptr + n); }
                const_iterator        operator - (difference_type n) const { return const_iterator(_ptr - n); }
                const_reference&    operator * () const { return *_ptr; };
                difference_type        operator - (const_iterator const &other) const { return _ptr - other._ptr; }
                const_reference        operator [] (const_reference n) const { return _ptr[n]; }
                const_pointer        operator -> () const { return _ptr; }

                bool                operator == (const_iterator const &other) const { return _ptr == other._ptr; }
                bool                operator != (const_iterator const &other) const { return _ptr != other._ptr; }
                bool                operator > (const_iterator const &other) const{ return _ptr > other._ptr; }
                bool                operator < (const_iterator const &other) const{ return _ptr < other._ptr; }
                bool                operator >= (const_iterator const &other) const { return _ptr >= other._ptr; }
                bool                operator <= (const_iterator const &other) const { return _ptr <= other._ptr; }

                bool                operator == (iterator const &other) const { return _ptr == other.getPtr(); }
                bool                operator != (iterator const &other) const { return _ptr != other.getPtr(); }
                bool                operator > (iterator const &other) const{ return _ptr > other.getPtr(); }
                bool                operator < (iterator const &other) const{ return _ptr < other.getPtr(); }
                bool                operator >= (iterator const &other) const { return _ptr >= other.getPtr(); }
                bool                operator <= (iterator const &other) const { return _ptr <= other.getPtr(); }
        };

/*    REVERSE_ITERATOR    */

        class reverse_iterator : public ft::iterator_traits<std::random_access_iterator_tag, value_type>
        {
            private:
                pointer        _ptr;
            public:
                reverse_iterator() : _ptr(nullptr) {}
                reverse_iterator(pointer ptr) : _ptr(ptr) {}
                ~reverse_iterator() {}
                reverse_iterator(const reverse_iterator &other) { *this = other; }

                pointer                getPtr() const { return _ptr; }

                reverse_iterator&    operator = (const reverse_iterator &other)
                {
                    if (this != &other)
                        _ptr = other._ptr;
                    return *this;
                }

                reverse_iterator&    operator ++ () { --_ptr; return *this; }
                reverse_iterator&    operator -- () { ++_ptr; return *this; }
                reverse_iterator    operator ++ (int) { return reverse_iterator(_ptr--); }
                reverse_iterator    operator -- (int) { return reverse_iterator(_ptr++); }
                reverse_iterator&    operator += (difference_type n) { _ptr -= n; return *this; }
                reverse_iterator&    operator -= (difference_type n) { _ptr += n; return *this; }
                reverse_iterator    operator + (difference_type n) const { return reverse_iterator(_ptr - n); }
                reverse_iterator    operator - (difference_type n) const { return reverse_iterator(_ptr + n); }
                reference&            operator * () const { return *_ptr; };
                difference_type        operator - (reverse_iterator const &other) const { return other._ptr - _ptr; }
                reference            operator [] (const_reference n) const { return _ptr[n]; }
                pointer                operator -> () { return _ptr; }

                bool                operator == (reverse_iterator const &other) const { return _ptr == other._ptr; }
                bool                operator != (reverse_iterator const &other) const { return _ptr != other._ptr; }
                bool                operator > (reverse_iterator const &other) const{ return _ptr > other._ptr; }
                bool                operator < (reverse_iterator const &other) const{ return _ptr < other._ptr; }
                bool                operator >= (reverse_iterator const &other) const { return _ptr >= other._ptr; }
                bool                operator <= (reverse_iterator const &other) const { return _ptr <= other._ptr; }

                bool                operator == (const_reverse_iterator const &other) const { return _ptr == other.getPtr(); }
                bool                operator != (const_reverse_iterator const &other) const { return _ptr != other.getPtr(); }
                bool                operator > (const_reverse_iterator const &other) const{ return _ptr > other.getPtr(); }
                bool                operator < (const_reverse_iterator const &other) const{ return _ptr < other.getPtr(); }
                bool                operator >= (const_reverse_iterator const &other) const { return _ptr >= other.getPtr(); }
                bool                operator <= (const_reverse_iterator const &other) const { return _ptr <= other.getPtr(); }
        };

/*    CONST_REVERSE_ITERATOR    */

        class const_reverse_iterator : public ft::iterator_traits<std::random_access_iterator_tag, const value_type>
        {
            private:
                pointer        _ptr;
            public:
                const_reverse_iterator() : _ptr(nullptr) {}
                const_reverse_iterator(pointer ptr) : _ptr(ptr) {}
                ~const_reverse_iterator() {}
                const_reverse_iterator(const const_reverse_iterator &other) { *this = other; }

                const_pointer                getPtr() const { return _ptr; }

                const_reverse_iterator&        operator = (const const_reverse_iterator &other)
                {
                    if (this != &other)
                        _ptr = other._ptr;
                    return *this;
                }

                const_reverse_iterator&        operator ++ () { --_ptr; return *this; }
                const_reverse_iterator&        operator -- () { ++_ptr; return *this; }
                const_reverse_iterator        operator ++ (int) { return const_reverse_iterator(_ptr--); }
                const_reverse_iterator        operator -- (int) { return const_reverse_iterator(_ptr++); }
                const_reverse_iterator&        operator += (difference_type n) { _ptr -= n; return *this; }
                const_reverse_iterator&        operator -= (difference_type n) { _ptr += n; return *this; }
                const_reverse_iterator        operator + (difference_type n) const { return const_reverse_iterator(_ptr - n); }
                const_reverse_iterator        operator - (difference_type n) const { return const_reverse_iterator(_ptr + n); }
                const_reference&            operator * () const { return *_ptr; };
                difference_type                operator - (const_reverse_iterator const &other) const { return other._ptr - _ptr; }
                const_reference                operator [] (const_reference n) const { return _ptr[n]; }
                const_pointer                operator -> () const { return _ptr; }

                bool                        operator == (const_reverse_iterator const &other) const { return _ptr == other._ptr; }
                bool                        operator != (const_reverse_iterator const &other) const { return _ptr != other._ptr; }
                bool                        operator > (const_reverse_iterator const &other) const{ return _ptr > other._ptr; }
                bool                        operator < (const_reverse_iterator const &other) const{ return _ptr < other._ptr; }
                bool                        operator >= (const_reverse_iterator const &other) const { return _ptr >= other._ptr; }
                bool                        operator <= (const_reverse_iterator const &other) const { return _ptr <= other._ptr; }

                bool                        operator == (reverse_iterator const &other) const { return _ptr == other.getPtr(); }
                bool                        operator != (reverse_iterator const &other) const { return _ptr != other.getPtr(); }
                bool                        operator > (reverse_iterator const &other) const{ return _ptr > other.getPtr(); }
                bool                        operator < (reverse_iterator const &other) const{ return _ptr < other.getPtr(); }
                bool                        operator >= (reverse_iterator const &other) const { return _ptr >= other.getPtr(); }
                bool                        operator <= (reverse_iterator const &other) const { return _ptr <= other.getPtr(); }
        };

    private:
        allocator_type    _alloc;
        pointer            _arr;
        size_t            _arrSize;
        size_t            _arrCap;

    public:

/*    CONSTRUCTORS    */

        Vector() : _arr(nullptr), _arrSize(0), _arrCap(0) {}

        Vector(size_t n, const_reference value)
            : _arr(_alloc.allocate(n)), _arrSize(n), _arrCap(n)
        {
            for (size_t i = 0; i < _arrSize; ++i)
                _alloc.construct(_arr + i, value);
        }

        Vector(size_t count)
        {
            if (count < 0)
                throw std::out_of_range("vector");
            _arr = _alloc.allocate(count);
            _arrCap = count;
            assign(count, value_type());
        }

        template<class _InputIt>
        Vector( _InputIt first, _InputIt last,
                typename ft::enable_if<std::__is_input_iterator<_InputIt>::value>::type * = nullptr )
        {
            size_t    range = last - first;
            if (last - first < 0)
                throw std::out_of_range("vector");
            _arr = _alloc.allocate(range);
            _arrSize = 0;
            _arrCap = range;
            insert(begin(), first, last);
        }

        Vector(const Vector &other)
            : _alloc(other._alloc), _arrSize(other._arrSize), _arrCap(other._arrCap)
        {
            _arr = _alloc.allocate(_arrCap);
            for (size_t i = 0; i < _arrSize; ++i)
                _alloc.construct(_arr + i, other._arr[i]);
        }

/*    DESTRUCTOR    */

        ~Vector()
        {
            if (_arr)
            {
                clear();
                _alloc.deallocate(_arr, _arrCap);
            }
        }

/*    COPY ASSIGNMENT OPERATOR    */

        Vector&    operator = (const Vector &other)
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

/*    MEMBER FUNCTIONS    */

        iterator                begin() { return iterator(_arr); }
        iterator                end() { return iterator(_arr + _arrSize); }
        const_iterator            begin() const { return const_iterator(_arr); }
        const_iterator            end() const { return const_iterator(_arr + _arrSize); }
        const_iterator            cbegin() const { return const_iterator(_arr); }
        const_iterator            cend() const { return const_iterator(_arr + _arrSize); }
        reverse_iterator        rbegin() { return reverse_iterator(_arr + _arrSize - 1); }
        reverse_iterator        rend() { return reverse_iterator(_arr - 1); }
        const_reverse_iterator    rbegin() const { return const_reverse_iterator(_arr + _arrSize - 1); }
        const_reverse_iterator    rend() const { return const_reverse_iterator(_arr - 1); }
        const_reverse_iterator    crbegin() const { return const_reverse_iterator(_arr + _arrSize - 1); }
        const_reverse_iterator    crend() const { return const_reverse_iterator(_arr - 1); }

        size_t                    size() const { return _arrSize; }
        size_t                    capacity() const { return _arrCap; }
        reference                front() { return _arr[0]; }
        reference                back() { return _arr[_arrSize - 1]; }
        const_reference            front() const { return _arr[0]; }
        const_reference            back() const { return _arr[_arrSize - 1]; }
        bool                    empty() const { return _arrSize ? false : true; }
        size_t                    max_size() const { return _alloc.max_size(); }

        void            clear()
        {
            for (size_t i = 0; i < _arrSize; ++i)
                _alloc.destroy(_arr + i);
            _arrSize = 0;
        }

        void            reserve(size_t n)
        {
            if (n > _arrCap)
            {
                pointer    newArr = _alloc.allocate(n);
                for (size_t i = 0; i < _arrSize; ++i)
                {
                    _alloc.construct(newArr + i, _arr[i]);
                    _alloc.destroy(_arr + i);
                }
                if (_arr)
                    _alloc.deallocate(_arr, _arrCap);
                _arr = newArr;
                _arrCap = n;
            }
        }

        void            resize(size_t n)
        {
            if (n > _arrCap)
                reserve(_arrCap * 2);
            _arrSize = n;
        }

        void            resize(size_t n, const_reference value)
        {
            if (n > _arrCap)
                reserve(_arrCap * 2);
            for (size_t i = _arrSize; i < n; ++i)
                _alloc.construct(_arr + i, value);
            _arrSize = n;
        }

        void            push_back(const_reference value)
        {
            if (_arrSize == _arrCap)
                reserve(_arrSize ? _arrSize * 2 : 1);
            _alloc.construct(_arr + _arrSize, value);
            ++_arrSize;
        }

        void            pop_back()
        {
            if (_arr)
            {
                --_arrSize;
                _alloc.destroy(_arr + _arrSize);
            }
        }

        reference        at(size_t n)
        {
            if (n >= _arrSize)
                throw std::out_of_range("vector");
            return _arr[n];
        }

        const_reference    at(size_t n) const
        {
            if (n >= _arrSize)
                throw std::out_of_range("vector");
            return _arr[n];
        }

        iterator        erase(iterator pos)
        {
            _alloc.destroy(pos.getPtr());
            std::memmove(pos.getPtr(), pos.getPtr() + 1, sizeof(value_type) * (end().getPtr() - pos.getPtr()));
            --_arrSize;
            return pos;
        }

        iterator        erase(iterator first, iterator last)
        {
            for (iterator tmp = first; tmp != last; ++tmp)
                _alloc.destroy(tmp.getPtr());
            std::memmove(first.getPtr(), last.getPtr(), sizeof(value_type) * (end().getPtr() - last.getPtr()));
            _arrSize -= last.getPtr() - first.getPtr();
            return last;
        }

        iterator        insert(iterator pos, const_reference value)
        {
            if (_arrSize == _arrCap)
            {
                size_t    id = (pos.getPtr() - begin().getPtr());
                reserve(_arrSize * 2);
                pos = begin() + id;
            }
            std::memmove(pos.getPtr() + 1, pos.getPtr(), sizeof(value) * (end().getPtr() - pos.getPtr()));
            _alloc.construct(pos.getPtr(), value);
            ++_arrSize;
            return pos;
        }

        void            insert(iterator pos, size_t count, const_reference value)
        {
            if (_arrSize + count > _arrCap)
            {
                size_t    id = (pos.getPtr() - begin().getPtr());
                if (_arrSize + count > _arrCap * 2)
                    reserve(_arrSize + count);
                else
                    reserve(_arrCap * 2);
                pos = begin() + id;
            }
            std::memmove(pos.getPtr() + count, pos.getPtr(), sizeof(value) * (end().getPtr() - pos.getPtr()));
            for (size_t i = 0; i != count; ++i)
                _alloc.construct((pos + i).getPtr(), value);
            _arrSize += count;
        }

        template<class _InputIt>
        void    insert( iterator pos, _InputIt first, _InputIt last,
                        typename ft::enable_if<std::__is_input_iterator<_InputIt>::value>::type * = nullptr )
        {
            size_t    range = last - first;
            if (_arrSize + range > _arrCap)
            {
                size_t    id = (pos.getPtr() - begin().getPtr());
                if (_arrSize + range > _arrCap * 2)
                    reserve(_arrSize + range);
                else
                    reserve(_arrCap * 2);
                pos = begin() + id;
            }
            std::memmove(pos.getPtr() + range, pos.getPtr(), sizeof(value_type) * (end().getPtr() - pos.getPtr()));
            for (size_t i = 0; i != range; ++i)
                _alloc.construct((pos + i).getPtr(), *(first + i));
            _arrSize += range;
        }

        void            assign(size_t n, const_reference value)
        {
            clear();
            if ((int)n < 0)
            {
                _alloc.deallocate(_arr, _arrCap);
                _arr = nullptr;
                _arrCap = 0;
                throw std::out_of_range("vector");
            }
            if (n > _arrCap)
                reserve(n);
            for (size_t i = 0; i < n; i++)
                _alloc.construct(_arr + i, value);
            _arrSize = n;
        }

        template<class _InputIt>
        void    assign( _InputIt first, _InputIt last,
                        typename ft::enable_if<std::__is_input_iterator<_InputIt>::value>::type * = nullptr )
        {
            clear();
            if (last - first < 0)
            {
                _alloc.deallocate(_arr, _arrCap);
                _arr = nullptr;
                _arrCap = 0;
                throw std::out_of_range("vector");
            }
            else if (last - first > static_cast<long>(_arrCap))
                reserve(last - first);
            for ( ; first != last; ++first)
                push_back(*first);
        }

        void            swap(Vector &other)
        {
            if (this != &other)
            {
                allocator_type    tmpAlloc = _alloc;
                pointer            tmpArr = _arr;
                size_t            tmpArrSize = _arrSize;
                size_t            tmpArrCap = _arrCap;

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

        reference        operator [] (size_t n) { return _arr[n]; }
        const_reference    operator [] (size_t n) const { return _arr[n]; }
};

/*    COMPARISON OPERATORS    */

template<class _T, class _Alloc>
bool    operator == (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    if (lhs.size() == rhs.size())
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    return false;
}

template<class _T, class _Alloc>
bool    operator != (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    return !(lhs == rhs);
}

template<class _T, class _Alloc>
bool    operator < (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class _T, class _Alloc>
bool    operator > (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    if (lhs.size() == rhs.size())
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template<class _T, class _Alloc>
bool    operator <= (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    if (lhs == rhs)
        return true;
    return (lhs < rhs);
}

template<class _T, class _Alloc>
bool    operator >= (const ft::Vector<_T, _Alloc> &lhs, const ft::Vector<_T, _Alloc> &rhs)
{
    if (lhs == rhs)
        return true;
    return (lhs > rhs);
}

#endif /* __VECTOR_H__ */
