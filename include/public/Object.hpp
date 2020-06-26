/**
 * Root class of the class hierarchy.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "api.Object.hpp"
#include "Allocator.hpp"

namespace eoos
{
    /**
     * Primary template implementation.
     *
     * @param A - heap memory allocator class.
     */
    template <class A = Allocator>
    class Object : public api::Object
    {

    public:

        /**
         * Constructor.
         */
        Object() :
            isConstructed_ (true){
        }

        /**
         * Destructor.
         */
        virtual ~Object()
        {
            isConstructed_ = false;
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        virtual bool_t isConstructed() const = 0;

        #ifdef EOOS_NO_STRICT_MISRA_RULES

        /**
         * Operator new.
         *
         * @param size - a number of bytes to allocate.
         * @return allocated memory address or a null pointer.
         */
        void* operator new(size_t const size)
        {
            return A::allocate(size);
        }

        /**
         * Operator new.
         *
         * @param size - unused.
         * @param ptr - a pointer to reserved memory area.
         * @return given pointer.
         */
        void* operator new(size_t, void* const ptr)
        {
            return ptr;
        }

        /**
         * Operator delete.
         *
         * @param ptr - an address of allocated memory block or a null pointer.
         */
        void operator delete(void* const ptr)
        {
            A::free(ptr);
        }

        #endif // EOOS_NO_STRICT_MISRA_RULES

    protected:

        /**
         * Sets the object constructed flag.
         *
         * @param flag - a new constructed flag.
         */
        void setConstructed(bool_t const flag)
        {
            if( isConstructed_ == true )
            {
                isConstructed_ = flag;
            }
        }

    private:

        /**
         * This object constructed flag.
         */
        bool_t isConstructed_;

    };

    /**
     * Tests if this object has been constructed.
     *
     * NOTE: This is an implementation of the pure virtual function.
     * It has to be called for getting the default state of objects,
     * otherwise developers have to implement their own behaviors of
     * the interface function.
     *
     * @return true if object has been constructed successfully.
     */
    template <class A>
    inline bool_t Object<A>::isConstructed() const
    {
        return isConstructed_;
    }

}
#endif // OBJECT_HPP_