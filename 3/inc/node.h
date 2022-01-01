#pragma once

#include <iostream>

namespace ns_LLIST
{
    template <typename T>
    class BaseNode
    {
    public:
        BaseNode<T> *next;
        BaseNode<T> *prev;

    public:
        BaseNode() : next(nullptr), prev(nullptr) {}
        virtual ~BaseNode() = default;

    public:
        virtual T &getData() { throw std::runtime_error("Pleaase, Dont Dereference Me, I am a smol node :=("); }
        virtual void setData(const T &_data) { throw std::runtime_error("Pleaase, Dont Dereference Me, I am a smol node :=( "); }
    };

    template <typename T>
    class Node : public BaseNode<T>
    {
    public:
        using BaseNode<T>::next;
        using BaseNode<T>::prev;

    private:
        T data;

    public:
        explicit Node(const T &_data) : BaseNode<T>{}, data(_data) {}
        explicit Node(T &&_data) : BaseNode<T>{}, data(std::move(_data)) {}

    public:
        virtual T &getData() override
        {
            return data;
        }

        virtual void setData(const T &_data) override
        {
            data = _data;
        }
    };
}