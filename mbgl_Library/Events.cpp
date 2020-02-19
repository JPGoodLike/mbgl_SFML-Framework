#pragma once

#include <unordered_set>

namespace mbgl {
    template <typename Signature>
    class Callable;
    template <typename Signature>
    class Function;
    template <typename Signature, typename ClassT>
    class Delegate;
    template <typename Signature>
    class Event;

    template <typename Signature>
    using fun = Function<Signature>;
    template <typename Signature, typename ClassT>
    using delegate = Delegate<Signature, ClassT>;
    template <typename Signature>
    using event = Event<Signature>;

    template <typename ReturnT, typename... Args>
    class Callable<ReturnT(Args...)> {
    public:
        virtual ReturnT Call(Args... args) = 0;
    };

    template <typename ReturnT, typename... Args>
    class Function<ReturnT(Args...)> : public Callable<ReturnT(Args...)> {
    private:
        ReturnT (*fn)(Args...);
    public:
        Function(ReturnT (*fn)(Args...))
        : fn(fn) {}

        ReturnT Call(Args... args) override {
            return fn(args...);
        }
        ReturnT operator()(Args... args) {
            return fn(args...);
        }
    };

    template <typename ReturnT, typename ClassT, typename... Args>
    class Delegate<ReturnT(Args...), ClassT> : public Callable<ReturnT(Args...)> {
    private:
        ClassT* obj;
        ReturnT (ClassT::*mem_fn)(Args...);
    public:
        Delegate() : obj(nullptr), mem_fn(nullptr) {}
        Delegate(ClassT& obj, ReturnT (ClassT::*mem_fn)(Args...))
        : obj(&obj), mem_fn(mem_fn) {}
        Delegate(ClassT* obj, ReturnT (ClassT::*mem_fn)(Args...))
        : obj(obj), mem_fn(mem_fn) {}

        void Bind(ClassT& obj, ReturnT (ClassT::*mem_fn)(Args...)) {
            this->obj = &obj;
            this->mem_fn = mem_fn;
        }
        void Bind(ClassT* obj, ReturnT (ClassT::*mem_fn)(Args...)) {
            this->obj = obj;
            this->mem_fn = mem_fn;
        }

        ReturnT Call(Args... args) override {
            return (obj->*mem_fn)(args...);
        }

        ReturnT operator()(Args... args) {
            return (obj->*mem_fn)(args...);
        }
    };

    template <typename ReturnT, typename... Args>
    class Event<ReturnT(Args...)> : public Callable<ReturnT(Args...)> {
    private:
        std::unordered_set<Callable<ReturnT(Args...)>*> delegates;

    public:
        void Bind(Callable<ReturnT(Args...)>& fn) {
            delegates.insert(&fn);
        }
        void Bind(Callable<ReturnT(Args...)>* fn) {
            delegates.insert(fn);
        }

        void Unbind(Callable<ReturnT(Args...)>& fn) {
            delegates.erase(&fn);
        }
        void Unbind(Callable<ReturnT(Args...)>* fn) {
            delegates.erase(fn);
        }

        void Call(Args... args) override {
            for (auto& d : delegates)
                d->Call(args...);
        }

        void operator+=(Callable<ReturnT(Args...)>& fn) {
            Bind(&fn);
        }
        void operator+=(Callable<ReturnT(Args...)>* fn) {
            Bind(fn);
        }

        void operator-=(Callable<ReturnT(Args...)>& fn) {
            Unbind(&fn);
        }
        void operator-=(Callable<ReturnT(Args...)>* fn) {
            Unbind(fn);
            delete fn;
        }

        void operator()(Args... args) {
            Call(args...);
        }
    };
}


