#pragma once

#include <type_traits>
#include <exception>
#include <stdexcept>

template <class... Extras> class Traits {
    public:
    template <class U> bool is() {
        return false;
    }

    template <class U> U* as() {
        throw std::logic_error("Called base case of Traits#as...");
    }

    protected:
    template <class U> U* as_unsafe() {
        throw std::logic_error("Got to base case of Traits#as_unsafe before realizing trait isn't implemented...");
    }
};

template <class T, class... Extras > class Traits<T, Extras...> : public T, public Traits<Extras...> {
    public:
    template <class U> bool is() {
        if(std::is_same<T, U>::value) {
            return true;
        }
        
        return Traits<Extras...>::template is<U>();
    }

    template <class U> U* as() {
        if(!this->template is<U>()) {
            throw std::logic_error("Traits#as called with unimplemented trait");
        }

        return as_unsafe<U>();
    }

    protected:
    template <class U> U* as_unsafe() {
        if(std::is_same<T, U>::value) {
            return (U*)this;
        } else {
            return Traits<Extras...>::template as_unsafe<U>();
        }
    }
};