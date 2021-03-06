/**
 * @file      api.Queue.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_QUEUE_HPP_
#define API_QUEUE_HPP_

#include "api.Collection.hpp"
#include "api.IllegalValue.hpp"

namespace eoos
{
namespace api
{
    
/**
 * @class Queue<T>
 * @brief Queue interface.
 *
 * @tparam T Data type of queue element.
 */
template <typename T>
class Queue : public Collection<T>, public IllegalValue<T>
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~Queue() = 0;

    /**
     * @brief Tests if this object has been constructed.
     *
     * @return True if object has been constructed successfully.
     */
    virtual bool_t isConstructed() const = 0;

    /**
     * @brief Inserts a new element to this container.
     *
     * @note A passed element must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the element
     * might be invalidated after the function called.
     *
     * @param element An inserting element.
     * @return True if element is added.
     */
    virtual bool_t add(const T& element) = 0;

    /**
     * @brief Removes the head element of this container.
     *
     * @return True if an element is removed successfully.
     */
    virtual bool_t remove() = 0;

    /**
     * @brief Examines the head element of this container.
     *
     * @return The head element.
     */
    virtual T& peek() const = 0;

};

template <typename T>
inline Queue<T>::~Queue() {}
        
} // namespace api
} // namespace eoos
#endif // API_QUEUE_HPP_
