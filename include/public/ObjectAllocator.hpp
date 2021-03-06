/**
 * @file      ObjectAllocator.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2021, Sergey Baigudin, Baigudin Software
 */
#ifndef OBJECT_ALLOCATOR_HPP_
#define OBJECT_ALLOCATOR_HPP_

#include "Allocator.hpp"

namespace eoos
{

/**
 * @class ObjectAllocator<A>
 * @brief Object memory allocator.
 *
 * @param A Heap memory allocator class.
 */
template <class A = Allocator>
class ObjectAllocator
{

public:

    #ifdef EOOS_NO_STRICT_MISRA_RULES

    /**
     * @brief Operator new.
     *
     * @param size A number of bytes to allocate.
     * @return Allocated memory address or a null pointer.
     */
    void* operator new(size_t const size)
    {
        return A::allocate(size);
    }

    /**
     * @brief Operator delete.
     *
     * @param ptr An address of allocated memory block or a null pointer.
     */
    void operator delete(void* const ptr)
    {
        A::free(ptr);
    }    

    /**
     * @brief Operator new.
     *
     * @param ptr A pointer to reserved memory area.
     * @return The given pointer.
     */
    void* operator new(size_t, void* const ptr)
    {
        return ptr;
    }
    
    /**
     * @brief Operator delete.
     */
    void operator delete(void*, void*)
    {
    }

    #endif // EOOS_NO_STRICT_MISRA_RULES
    
protected:

    /**
     * @brief Constructor.
     */
    ObjectAllocator()
    {
    }

    /**
     * @brief Destructor.
     */
    ~ObjectAllocator()
    {
    }    

};

} // namespace eoos
#endif // OBJECT_ALLOCATOR_HPP_
