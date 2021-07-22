#ifndef __MAP_H__
# define __MAP_H__

# include "ft.hpp"

template<    class _Key,
            class _T,
            class _Compare,
            class _Allocator >
class ft::Map
{
    private:

/*    TYPES    */

        typedef _Key                        key_type;
        typedef _T                            mapped_type;
        typedef _Compare                    key_compare;
        typedef _Allocator                    allocator_type;
        typedef ft::pair<const _Key, _T>    value_type;
        typedef value_type*                    pointer;
        typedef const value_type*            const_pointer;
        typedef value_type&                    reference;
        typedef const value_type&            const_reference;
        typedef std::ptrdiff_t                difference_type;

        // typedef ft::reverse_iterator<iterator>            reverse_iterator;
        // typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

        struct    node    /*    узел дерева    */
        {
            value_type    value;        /*    пара ключ - значение            */
            size_t        height;        /*    высота поддерева                */
            node        *left;        /*    указатель на левое поддерево    */
            node        *right;        /*    указатель на правое поддерево    */
            node        *parent;    /*    указатель на родителя            */
            /*    конструкторы нового узла    */
            node()
                : value(ft::make_pair(key_type(), mapped_type())),
                height(1),
                left(nullptr), right(nullptr), parent(nullptr) {}
            node(const_reference val)
                : value(ft::make_pair(val.first, val.second)),
                height(1),
                left(nullptr), right(nullptr), parent(nullptr) {}
        };

        size_t    height(node *p)    /*    получение высоты поддерева    */
        {
            return p ? p->height : 0;
        }

        int        b_factor(node *p)    /*    balance factor        (-1, 0 или 1) - поддерево сбалансированно    */
        {
            return height(p->right) - height(p->left);    /*    (-2 или 2) - требуется балансировка левого или правого поддерева , соответственно    */
        }

        void    fix_height(node *p)    /*    корректировка высоты поддерева после вставки или удаления узла    */
        {
            size_t    hl = height(p->left);
            size_t    hr = height(p->right);
            p->height = (hl > hr ? hl : hr) + 1;
        }

        /*    повороты вокруг узла, balance factor корого == 2 или == -2,
        т.е. возникает расбалансировка одного из поддеревьев    */

        node*    rotate_right(node *p)    /*    правый поворот вокруг узла 'p'    */
        {
            node*    q = p->left;    /*    узел, который после поворота займёт место 'p' и станет корнем данного поддерева    */
            /*    поворот    */
            p->left = q->right;
            q->right = p;
            /*    меняем местами родителей повёрнутых узлов    */
            q->parent = p->parent;
            p->parent = q;
            if (q->right->left)
                q->right->left->parent = p;
            /*    корректировка высот новых поддеревьев    */
            fix_height(p);
            fix_height(q);
            return q;    /*    возвращаем новый корень данного поддерева    */
        }

        node*    rotate_left(node *q)    /*    левый поворот вокруг узла 'q'    */
        {
            node*    p = q->right;    /*    узел, который после поворота займёт место 'q' и станет корнем данного поддерева    */
            /*    поворот    */
            q->right = p->left;
            p->left = q;
            /*    меняем местами родителей повёрнутых узлов    */
            p->parent = q->parent;
            q->parent = p;
            if (p->left->right)
                p->left->right->parent = q;
            /*    корректировка высот новых поддеревьев    */
            fix_height(q);
            fix_height(p);
            return p;    /*    возвращаем новый корень данного поддерева    */
        }

        node*    balance(node *p)    /*    балансировка узла 'p'    */
        {
            node    *tmp = p->parent;    /*    запоминаем родителя данного узла    */
            fix_height(p);    /*    корректировка высоты данного поддерева    */
            if (b_factor(p) == 2)    /*    правое поддерево от 'p' выше левого    */
            {
                if (b_factor(p->right) < 0)    /*    требуется поворот правого поддерева от 'p'    */
                    p->right = rotate_right(p->right);
                if (!tmp)    /*    т.е. 'p' - корень всего дерева    */
                    return _tree = rotate_left(p);    /*    балансировка корня всего дерева    */
                /*    балансировка поддерева с корнем 'p'    */
                if (tmp->left == p)
                    return (tmp->left = rotate_left(p));
                else
                    return (tmp->right = rotate_left(p));
            }
            if (b_factor(p) == -2)    /*    левое поддерево от 'p' выше правого    */
            {
                if (b_factor(p->left) > 0)    /*    требуется поворот левого поддерева от 'p'    */
                    p->left = rotate_left(p->left);
                if (!tmp)    /*    т.е. 'p' - корень всего дерева    */
                    return _tree = rotate_right(p);    /*    балансировка корня всего дерева    */
                /*    балансировка поддерева с корнем 'p'    */
                if (tmp->right == p)
                    return (tmp->right = rotate_right(p));
                else
                    return (tmp->left = rotate_right(p));
            }
            return p;    /*    балансировка не потребовалась    */
        }

        node*    find_min(node *p) // поиск узла с минимальным ключом в дереве 'p'
        {
            return p->left ? find_min(p->left) : p;
        }

        node*    find_max(node *p) // поиск узла с максимальным ключом в дереве 'p'
        {
            return p->right ? find_max(p->right) : p;
        }

        node*    remove_min(node *p) // удаление узла с минимальным ключом из дерева p
        {
            if (p->left == 0) // найден минимальный элемент
                return p->right; // замена минимального элемента на его правое поддерево
            p->left = remove_min(p->left); // рекурсивный поиск минимального элемента
            return balance(p); // рекурсивная балансировка всех пройденных узлов
        }

        node*    remove(node *p, int k) // удаление узла с ключом 'k' из дерева с корнем 'p'
        {
            if (!p) // если узла с данным ключом 'k' не существует удалять нечего
                return 0;
            // рекурсивно ищем узел с искомым ключом 'k'
            if (k < p->value->first)
                p->left = remove(p->left, k);
            else if (k > p->value->first)
                p->right = remove(p->right, k);
            else // k == p->key - найден узел 'p' с искомым ключом 'k'
            {
                node *q = p->left; // запоминаем корень левого поддерева узла 'p'
                node *r = p->right; // запоминаем корень правого поддерева узла 'p'
                delete p; // удаляем узел 'p'
                if (!r)    // если правое поддерево пустое, то возвращаем указатель на левое поддерево
                    return q; // слеав от 'p' может быть один дочерний узел (height == 1), либо узел 'p' - лист, т.е. замена не требуется
                node *min = find_min(r); // если правое поддерево не пустое, то находим там элемент 'min' и ставим его на место 'p'
                min->right = remove_min(r); // справа к 'min' подвешиваем 'r'
                min->left = q; // слева к 'min' подвешиваем 'q'
                return balance(min); // возвращаем сбалансированный 'min'
            }
            return balance(p); // рекурсивная балансировка всех пройденных узлов
        }

        node*    find_node(node* p, int k)
        {
            if (k < p->value.first)
            {
                if (p->left)
                    return find_node(p->left, k);
            }
            else if (k > p->value.first)
            {
                if (p->right)
                    return find_node(p->right, k);
            }
            return p;
        }

        void    delete_tree(node *p)
        {
            if (p->left != nullptr)
            {
/*    !!!    */        std::cout << p->left->value.second << " <- " << p->value.second << std::endl;
                delete_tree(p->left);
            }
            if (p->right != nullptr)
            {
/*    !!!    */        std::cout << p->value.second << " -> " << p->right->value.second << std::endl;
                delete_tree(p->right);
            }
/*    !!!    */        std::cout << "delete\t" << p->value.second << std::endl;
            delete p;
        }

/*    VARIABLES    */

        node            *_tree;
        size_t            _treeSize;
        allocator_type    _alloc;

    public:

/*    ITERATORS    */

        class const_iterator;

        class    iterator : ft::iterator_traits<std::bidirectional_iterator_tag, value_type>
        {
            private:
                node    *_node;
            public:
                iterator() : _node(nullptr) {}
                iterator(node *ptr) : _node(ptr) {}
                ~iterator() {}
                iterator(const iterator &other) { *this = other; }

                node*            getNode() const { return _node; }

                iterator&        operator = (const iterator &other)
                {
                    if (this != &other)
                        _node = other._node;
                    return *this;
                }

                bool            operator != (iterator other) { return this != &other; }

                value_type&        operator * () { return _node->value; }

                iterator&        operator ++ ()
                {
                    if (_node->right)
                        _node = find_min(_node->right);
                    else // if (_node != _tree)
                    {
                        node    *tmp = _node->parent;
                        while (tmp && tmp->value.first < _node->value.first)
                            tmp = tmp->parent;
                        _node = tmp;
                    }
                    return *this;
                }

                iterator&        operator ++ (int)
                {
                        node    *tmp = _node;
                        ++_node;
                        return iterator(tmp);
                }

                iterator&        operator -- ()
                {
                    // if (_node->left)
                        _node = _node->left;
                    return *this;
                }

                iterator&        operator -- (int)
                {
                    node    *tmp = _node;
                    --_node;
                    return iterator(tmp);
                }
        };

        Map() : _tree(nullptr), _treeSize(0) {}

        // template<class _InputIt>
        // Map(_InputIt first, _InputIt last)
        // {
        // }

        mapped_type&    operator [] (const key_type key)
        {
            return find_node(_tree, key)->value.second;
        }

        iterator    begin() { return iterator(find_min(_tree)); }

        iterator    end() { return ++iterator(find_max(_tree)); }

        bool    insert(const value_type &value)
        {
            if (!_tree)
            {
                _tree = new node(value);
                // iterato it(_tree);
            }
            else
            {
                node    *newNode = find_node(_tree, value.first);
                if (value.first == newNode->value.first)
                    return false;
                if (value.first < newNode->value.first)
                {
                    newNode->left = new node(value);
                    newNode->left->parent = newNode;
                    // iterato it(newNode->left);
                }
                else if (value.first > newNode->value.first)
                {
                    newNode->right = new node(value);
                    newNode->right->parent = newNode;
                    // iterato it(newNode->right);
                }
                while (newNode)
                {
                    newNode = balance(newNode);
                    newNode = newNode->parent;
                }
            }
            _treeSize++;
            return true;
        }

        size_t    size() const { return _treeSize; }

        void    clear()
        {
            delete_tree(_tree);
            _treeSize = 0;
        }
};

#endif /*  __MAP_H__ */
